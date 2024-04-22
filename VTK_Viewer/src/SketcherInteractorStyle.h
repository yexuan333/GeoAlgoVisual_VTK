#pragma once
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkCommand.h>
#include <vtkSphereSource.h>
#include <vtkGlyph3D.h>
#include <vtkRendererCollection.h>
#include <vtkPointPicker.h>
#include <vtkCoordinate.h>
#include "CommandInterface.h"

class SketcherInteractorStyle : public vtkInteractorStyleTrackballCamera
{
public:
    static SketcherInteractorStyle* New();
    vtkTypeMacro(SketcherInteractorStyle, vtkInteractorStyleTrackballCamera);

    virtual void OnLeftButtonDown() override
    {
        if(m_cmd){
            std::cout << "Pressed left mouse button. ";
            vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
            vtkSmartPointer<vtkCoordinate> pCoorPress = vtkSmartPointer<vtkCoordinate>::New();
            pCoorPress->SetCoordinateSystemToDisplay();
            auto pos = GetInteractor()->GetEventPosition();
            pCoorPress->SetValue((int)pos[0], (int)pos[1]);
            double* worldCoord = pCoorPress->GetComputedWorldValue(this->GetInteractor()->GetRenderWindow()->GetRenderers()->GetFirstRenderer());

            double nearPoint[3], direction[3];
            vtkCamera* camera = this->GetInteractor()->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera();
            camera->GetPosition(nearPoint);
            for (int i = 0; i < 3; i++) {
                direction[i] = worldCoord[i] - nearPoint[i];
            }

            double t = -nearPoint[2] / direction[2];
            worldCoord[0] = nearPoint[0] + t * direction[0];
            worldCoord[1] = nearPoint[1] + t * direction[1];
            worldCoord[2] = 0;  //

            std::cout << worldCoord[0] << " " << worldCoord[1] << " " << worldCoord[2] << std::endl;
            points->InsertNextPoint(worldCoord[0], worldCoord[1], worldCoord[2]);

            vtkSmartPointer<vtkPolyData> pointsPolydata = vtkSmartPointer<vtkPolyData>::New();
            pointsPolydata->SetPoints(points);

            vtkSmartPointer<vtkVertexGlyphFilter> glyphFilter = vtkSmartPointer<vtkVertexGlyphFilter>::New();
            glyphFilter->SetInputData(pointsPolydata);
            glyphFilter->Update();

            vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
            mapper->SetInputConnection(glyphFilter->GetOutputPort());

            vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
            actor->SetMapper(mapper);
            actor->GetProperty()->SetRepresentationToPoints();
            actor->GetProperty()->SetPointSize(2);

            this->GetInteractor()->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->AddActor(actor);
            this->GetInteractor()->GetRenderWindow()->Render();
            }
            // Forward events.
            vtkInteractorStyleTrackballCamera::OnLeftButtonDown();
        }
    }

    virtual void OnMiddleButtonDown() override
    {
        std::cout << "Pressed middle mouse button." << std::endl;
        // Forward events.
        vtkInteractorStyleTrackballCamera::OnMiddleButtonDown();
    }

    virtual void OnRightButtonDown() override
    {
        std::cout << "Pressed right mouse button." << std::endl;
        // Forward events.
        vtkInteractorStyleTrackballCamera::OnRightButtonDown();
    }
    virtual void OnMouseMove() override
    {
        vtkInteractorStyleTrackballCamera::OnMouseMove();
    }
    double* currentPos()
    {
        int x = GetInteractor()->GetEventPosition()[0];
        int y = GetInteractor()->GetEventPosition()[1];

        vtkNew<vtkPointPicker> picker;
        picker->SetTolerance(0.001);
        picker->Pick(x, y, 0, this->GetInteractor()->GetRenderWindow()->GetRenderers()->GetFirstRenderer());
        return picker->GetPickPosition();
    }
    void setCurrentCommand( CommandInterface* cmd){m_cmd = cmd;}
private:
    CommandInterface* m_cmd = nullptr;
};
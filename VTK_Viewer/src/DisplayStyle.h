#pragma once
#include "Stdafx.h"
//color Name https://htmlpreview.github.io/?https://github.com/Kitware/vtk-examples/blob/gh-pages/VTKNamedColorPatches.html
class DisplayStyle {
public:
	DisplayStyle(){
		vtkNew<vtkNamedColors> colors;
		defaultFaceStyle = vtkProperty::New();
		defaultFaceStyle->SetColor(colors->GetColor3d("Snow").GetData());
		defaultFaceStyle->SetRepresentationToSurface();

		defaultEdgeStyle = vtkProperty::New();
		defaultEdgeStyle->SetColor(colors->GetColor3d("Black").GetData());
		defaultEdgeStyle->SetRepresentationToWireframe();
		defaultEdgeStyle->SetRenderLinesAsTubes(true);
		defaultEdgeStyle->SetLineWidth(3);

		defaultVertexStyle = vtkProperty::New();
		defaultVertexStyle->SetColor(colors->GetColor3d("White").GetData());
		defaultVertexStyle->SetRepresentationToPoints();
		defaultVertexStyle->SetRenderPointsAsSpheres(true);
		defaultVertexStyle->SetPointSize(5);

		selectedFaceStyle = vtkProperty::New();
		selectedFaceStyle->SetColor(colors->GetColor3d("gold").GetData());
		selectedFaceStyle->SetRepresentationToSurface();

		selectedEdgeStyle = vtkProperty::New();
		selectedEdgeStyle->SetColor(colors->GetColor3d("gold").GetData());
		selectedEdgeStyle->SetRepresentationToWireframe();
		selectedEdgeStyle->SetRenderLinesAsTubes(true);
		selectedEdgeStyle->SetLineWidth(5);

		selectedVertexStyle = vtkProperty::New();
		selectedVertexStyle->SetColor(colors->GetColor3d("gold").GetData());
		selectedVertexStyle->SetRepresentationToPoints();
		selectedVertexStyle->SetRenderPointsAsSpheres(true);
		selectedVertexStyle->SetPointSize(8);
	}
	vtkProperty* GetDefautProperty(int demision) const{
		switch (demision) {
			case 0:
				return copy(defaultVertexStyle);
			case 1:
				return copy(defaultEdgeStyle);
			case 2:
				return copy(defaultFaceStyle);
			default:
				throw std::runtime_error("没这个维度");
		}
	}
	vtkProperty* GetSelectedProperty(int demision) const {
		switch (demision) {
			case 0:
				return copy(selectedVertexStyle);
			case 1:
				return copy(selectedEdgeStyle);
			case 2:
				return copy(selectedFaceStyle);
			default:
				throw std::runtime_error("没这个维度");
		}
	}
	~DisplayStyle() {
		defaultFaceStyle->Delete();
		defaultEdgeStyle->Delete();
		defaultVertexStyle->Delete();
		selectedFaceStyle->Delete();
		selectedEdgeStyle->Delete();
		selectedVertexStyle->Delete();
	}
private:
	vtkProperty* copy(vtkProperty* tocopy) const{
		vtkProperty* copyed = vtkProperty::New();
		copyed->DeepCopy(tocopy);
		return copyed;
	}
	vtkProperty* defaultFaceStyle = nullptr;
	vtkProperty* defaultEdgeStyle = nullptr;
	vtkProperty* defaultVertexStyle = nullptr;
	vtkProperty* selectedFaceStyle = nullptr;
	vtkProperty* selectedEdgeStyle = nullptr;
	vtkProperty* selectedVertexStyle = nullptr;
};
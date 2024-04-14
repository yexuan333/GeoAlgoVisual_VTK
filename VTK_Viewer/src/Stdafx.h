#pragma once

#ifndef CAPI
#define CAPI extern "C" __declspec(dllexport) 
#endif
#ifndef DLLExport
#define DLLExport __declspec(dllexport) 
#endif

#include <vtkCamera.h>
#include <vtkDoubleArray.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkLookupTable.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPlatonicSolidSource.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkPolyDataNormals.h>
#include <vtkPolygon.h>
#include <vtkPolyLine.h>
#include <vtkProperty.h>
#include <vtkPointData.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkAssembly.h>
#include <vtkTriangle.h>
#include <vtkVersion.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkTexture.h>
#include <vtkArrowSource.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>

#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QApplication>
#include <QComboBox>
#include <QDateTime>
#include <QFile>
#include <QFileDialog>
#include <QIODevice>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>
#include <QMainWindow>
#include <QMutex>
#include <QPushButton>
#include <QScreen>
#include <QSplitter>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QStringListModel>
#include <QSurfaceFormat>


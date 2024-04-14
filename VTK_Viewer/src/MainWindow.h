#pragma once
#include "Stdafx.h"
#include "ui_MainWindow.h"
#include <QVTKOpenGLNativeWidget.h>
#include "LogStream.h"
#include "DisplayStyle.h"
#include "BVH.h"
#include "SketcherInteractorStyle.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  // Constructor/Destructor
  explicit MainWindow(QWidget* parent = nullptr);
  virtual ~MainWindow();
public slots:
  void slotExit();
  void on_updateView();
  void on_resetCamera();
  void on_displayBVH();
private:
  // Designer form
  Ui::MainWindow* ui;
  QVTKOpenGLNativeWidget* qvtkWidget = nullptr;
  vtkNew<vtkRenderer> m_renderer;
  LogStream* m_logStream = nullptr;
  DisplayStyle m_style;
};

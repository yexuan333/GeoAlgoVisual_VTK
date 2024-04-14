#include "MainWindow.h"

#if VTK_VERSION_NUMBER >= 89000000000ULL
#define VTK890 1
#endif

MainWindow::MainWindow(
    QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
  this->ui->setupUi(this);
  qvtkWidget = new QVTKOpenGLNativeWidget();

  vtkNew<vtkNamedColors> colors;
  vtkNew<vtkRenderer> renderer;
  renderer->SetBackground(colors->GetColor3d("SlateGray").GetData());
  //renderer->AddActor(actor);

  vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
  
  vtkNew<SketcherInteractorStyle> style;
  
  qvtkWidget->setRenderWindow(renderWindow);
  qvtkWidget->renderWindow()->AddRenderer(renderer);
  qvtkWidget->renderWindow()->SetWindowName("MouseEvents");
  qvtkWidget->renderWindow()->GetInteractor()->SetInteractorStyle(style);
  
  qvtkWidget->renderWindow()->Render();
  
  auto spliter = new QSplitter(Qt::Orientation::Vertical);
  this->setCentralWidget(spliter);
  auto text = new QTextBrowser();
  spliter->addWidget(text);
  spliter->addWidget(qvtkWidget);
  spliter->setStretchFactor(0, 1);
  spliter->setStretchFactor(1, 10);
  m_logStream = new LogStream(std::cout, text);
  std::cout << "kaishi" << std::endl;


  vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
  points->InsertNextPoint(0, 0, 0);

  vtkSmartPointer<vtkPolyData> pointsPolydata = vtkSmartPointer<vtkPolyData>::New();
  pointsPolydata->SetPoints(points);

  vtkSmartPointer<vtkVertexGlyphFilter> glyphFilter = vtkSmartPointer<vtkVertexGlyphFilter>::New();
  glyphFilter->SetInputData(pointsPolydata);
  glyphFilter->Update();

  // 创建一个映射器和actor
  vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(glyphFilter->GetOutputPort());

  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
  //
  //actor->GetProperty()->SetRepresentationToPoints();
  actor->GetProperty()->SetPointSize(40);
  renderer->AddActor(actor);
  qvtkWidget->renderWindow()->Render();
  renderer->ResetCamera();

  connect(ui->actionzoom, &QAction::trigger, this, &MainWindow::on_resetCamera);
}

MainWindow::~MainWindow()
{
  delete this->ui;
  //delete m_logStream;
  delete qvtkWidget;
  m_logStream = nullptr;
}
void MainWindow::on_displayBVH()
{
    BVH<Point3d> bvh;
    //CALCULATE_ELAPSED_TIME(
    //    bvh.Init(part, bodies);
    //    auto pairs = bvh.collisionDetection();
    //    std::cout << "总共"<<pairs.size()<<"面对" << std::endl;
    //);
    //for (auto body : bvh.toDisplay(*part)) {
    //    CATCGMTessellateParam tessParam(2);
    //    auto ac = PartModel::createWireBodyActor(part, tessParam, body, "red", 2);
    //    for (auto& a: ac) {
    //        m_renderer->AddActor(a);
    //    }
    //}
    on_resetCamera();
    on_updateView();
}


void MainWindow::slotExit()
{
  qApp->exit();
}

void MainWindow::on_updateView() {
    qvtkWidget->renderWindow()->Render();
}
void MainWindow::on_resetCamera() {
    m_renderer->ResetCamera();
}
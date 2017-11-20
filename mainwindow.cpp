#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    std::vector<QString> fileName;
    QString name [2];
    name[0] = "/home/cty/workspace/OPENGL/OpenGL_Shader/opengl_shaderLesson02/build/Terrain.bmp";
    name[1] = "/home/cty/workspace/OPENGL/OpenGL_Shader/opengl_shaderLesson02/build/z3n.jpg";

    for(int i=0;i<sizeof(name)/sizeof(name[0]);++i)
    {
        fileName.push_back(name[i]);
    }

    ui->widget->init_QGW(fileName);

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
    timer->start(20);

}

MainWindow::~MainWindow()
{
    timer->deleteLater();
    delete ui;
}

void MainWindow::onTimeout()
{
    ui->widget->drawImage();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    camera = new basler();
    camera->connect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    camera->start();
//    uchar mydata[800*600] ;
//    memcpy(mydata, (uchar*)camera->pImageBuffer, 800*600);
    QImage *myimage = new QImage((uchar*)camera->globalImageBuffer, 800, 600, QImage::Format_Indexed8);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->addPixmap(QPixmap::fromImage(*myimage));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

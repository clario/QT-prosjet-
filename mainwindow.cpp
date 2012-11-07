#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  //  QLabel * label = new QLabel("Hei",this);
    QLabel * idiot = new QLabel("label nr 2",this);




}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel * label = new QLabel("Hei",this);



}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  //  QLabel * label = new QLabel("Hei",this);
  //  QLabel * idiot = new QLabel("label nr 2",this);
    QPushButton *knapp = new QPushButton("knapp",this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() {

    ui->infoLabel->setText("Hwi!");

}

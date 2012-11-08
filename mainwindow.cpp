#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>

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

    ui->infoLabel->setText("TADAAA!");
    QMessageBox::about(this,"HEHE","BASJ!");

}

void MainWindow::on_anotherPushButton_clicked() {

    QMessageBox::question(this,"Question:", "Har du mista en tusj noengang da?", QMessageBox::Yes, QMessageBox::No);

}



#include "calenderview.h"
#include <QTextEdit>


CalenderView::CalenderView(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle("Kalender");

    mainLayout = new QGridLayout(this);



    QWidget * mainWidget = new QWidget();
    setCentralWidget(mainWidget);
    createSideBar();


}

void CalenderView::createSideBar(){

    mainLayout->addWidget(new QTextEdit,0,0,1,2);


}

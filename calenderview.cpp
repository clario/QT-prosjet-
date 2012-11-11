#include "calenderview.h"


CalenderView::CalenderView(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle("Kalender");

    mainLayout = new QGridLayout(this);



    QWidget * mainWidget = new QWidget();
    setCentralWidget(mainWidget);


}

void CalenderView::createSideBar(){

    mainLayout->addWidget(widget,0,0,1,2);


}

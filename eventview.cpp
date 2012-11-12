#include "eventview.h"

EventView::EventView(QWidget *parent) :
    QWidget(parent)


{

    setWindowTitle("Avtaler");
    //gridLayout = new QGridLayout(this);
    eventTitle = QString("Brazillian Wax");
    setViewMode();


}


void EventView::setViewMode(){
    mainLayout = new QVBoxLayout(this);

    eventTitleLabel = new QLabel(eventTitle);
    eventTitleLabel->setFont(QFont("",25));
    //From-stuff
    fromLabel = new QLabel("Fra:");
    fromLabel->setFont(QFont("",18));
    fromDateEdit = new QDateEdit();
    fromDateEdit->setDate(QDate(QDate::currentDate()));
    fromTimeEdit = new QTimeEdit();
    fromTimeEdit->setTime(QTime(QTime::currentTime()));
    fromTimeLabel = new QLabel("Tid:");
    fromDateLabel = new QLabel("Dato:");
    //To-stuff
    toLabel = new QLabel("Til:");
    toLabel->setFont(QFont("",18));
    toDateLabel = new QLabel("Dato:");
    toDateEdit = new QDateEdit();
    toDateEdit->setDate(QDate(QDate::currentDate()));
    toTimeLabel = new QLabel("Tid:");
    toTimeEdit = new QTimeEdit(QTime(QTime::currentTime()));


    firstGridLayout = new QGridLayout();
    firstGridLayout->addWidget(eventTitleLabel,0,0,3,1,Qt::AlignLeft);
    firstGridLayout->addWidget(fromLabel,4,0);
    firstGridLayout->addWidget(fromDateLabel,5,0);
    firstGridLayout->addWidget(fromDateEdit,5,1);
    firstGridLayout->addWidget(fromTimeLabel,5,2);
    firstGridLayout->addWidget(fromTimeEdit,5,3);
    firstGridLayout->addWidget(toLabel,6,0);
    firstGridLayout->addWidget(toDateLabel,7,0);
    firstGridLayout->addWidget(toDateEdit,7,1);
    firstGridLayout->addWidget(toTimeLabel,7,2);
    firstGridLayout->addWidget(toTimeEdit,7,3);

    //Repeat

    repeatCheckBox = new QCheckBox("Repeter");

    mainLayout->addLayout(firstGridLayout);

    firstHLayout = new QHBoxLayout();

  //  mainLayout->addLayout(firstHLayout);



   //all inside mainlayout

}


void EventView::setEditMode(){


}




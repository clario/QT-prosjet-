#include "eventwidget.h"

EventWidget::EventWidget(QWidget *parent) :
    QWidget(parent)
{

    content = new QLabel("GHUUHUH");
    content->setFrameShadow(QFrame::Sunken);
}

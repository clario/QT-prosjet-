#include "contactview.h"

ContactView::ContactView(QWidget *parent) :
    QWidget(parent)
{
    QLabel *nameLabel = new QLabel(tr("Name"));
    nameLine = new QLineEdit;

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(nameLabel,0,0);
    line = new QLineEdit();
    test= "Hei";
    line->setText(test);
    mainLayout->addWidget(line,0,1);
    setLayout(mainLayout);
    setWindowTitle(tr("Contacts"));
    connect(line,SIGNAL(returnPressed()),this,SLOT(updateString()));
}

QString ContactView::getString()
{
    return test;
}

void ContactView::updateString()
{
    test = line->text();
    qDebug() << test;
}

#include "contactview.h"

ContactView::ContactView(QWidget *parent) :
    QWidget(parent)
{
    QLabel *nameLabel = new QLabel(tr("Name"));
    nameLine = new QLineEdit;

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(nameLabel,0,0);
    mainLayout->addWidget(nameLine,0,1);

    setLayout(mainLayout);
    setWindowTitle(tr("Contacts"));
}

#include "contactview.h"
#include <QDebug>

ContactView::ContactView(QWidget *parent) :
    QWidget(parent)
{
}

ContactView::ContactView(ContactHandler *ch, QWidget *parent) :
    QWidget(parent)
{

    //Buttons
    fName = new QLineEdit("First Name");
    lName = new QLineEdit("Last Name");
    phoneNumber = new QLineEdit("Phone Number");
    eMail = new QLineEdit("e-Post");
    edit = new QPushButton("edit");
    save = new QPushButton("save");
    remove = new QPushButton("delete");
    add = new QPushButton("add");
    close = new QPushButton("close");

    //Layouts
    main = new QHBoxLayout(this);
    ll = new QVBoxLayout();
    rl = new QVBoxLayout();
    rbl = new QHBoxLayout();
    main->addLayout(ll);
    main->addLayout(rl);

    //Lager kontaklista
    tv = new QTableView();
    ll->addWidget(tv);
    mdl = new ContactListModel(ch);
    tv->setModel(mdl);
    tv->setSelectionBehavior(QTableView::SelectRows);
    tv->setSelectionMode(QTableView::SingleSelection);

    //Setter storrelset på vindu, knapper o.l.
    tv->setMinimumWidth(450);
    tv->wordWrap();

    //Adder knapper og layouts til rl og ll
    rl->addWidget(fName);
    rl->addWidget(lName);
    rl->addWidget(phoneNumber);
    rl->addWidget(eMail);
    rl->insertSpacing(4,5);
    rl->addLayout(rbl);
    rbl->addWidget(edit);
    rbl->addWidget(save);
    rbl->addWidget(remove);
    rbl->addWidget(add);
    rbl->insertSpacing(3,5);
    rbl->addWidget(close);

    //gjømmer knapper
    save->hide();

    //Ekle feltvariablar
    cHandler = ch;
    selectedRow = -1;

    //Connects
    connect(edit,SIGNAL(clicked()),this,SLOT(editRow()));
    connect(save,SIGNAL(clicked()),this,SLOT(saveRow()));
    connect(close,SIGNAL(clicked()),this,SLOT(close()));

}

void ContactView::editRow()
{
    selectedRow = tv->currentIndex().row();
    fName->setText((*cHandler)[selectedRow].getFName());
    lName->setText((*cHandler)[selectedRow].getLName());
    phoneNumber->setText((*cHandler)[selectedRow].getPhoneNumber());
    eMail->setText((*cHandler)[selectedRow].getEmail());
    edit->hide();
    save->show();
}

void ContactView::saveRow()
{
    qDebug() << (*cHandler)[selectedRow].toString();
    (*cHandler)[selectedRow].setFName(fName->text());
    (*cHandler)[selectedRow].setLName(lName->text());
    (*cHandler)[selectedRow].setPhoneNumber(phoneNumber->text());
    (*cHandler)[selectedRow].setEmail(eMail->text());
    qDebug() << (*cHandler)[selectedRow].toString();
    save->hide();
    edit->show();
}

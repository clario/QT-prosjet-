#include "contactview.h"
#include <QDebug>

ContactView::ContactView(QWidget *parent) :
    QDialog(parent)
{
}

ContactView::ContactView(ContactHandler *ch, QWidget *parent) :
    QDialog(parent)
{
    //Labels
    fName_lbl   = new QLabel("Fornavn:");
    lName_lbl   = new QLabel("Etternavn:");
    phoneN_lbl  = new QLabel("Tlf:");
    eMail_lbl   = new QLabel("e-post:");

    //LineEdit
    fName = new QLineEdit();
    lName = new QLineEdit();
    phoneNumber = new QLineEdit();
    eMail = new QLineEdit();

    //PushButtons
    edit = new QPushButton("Rediger");
    save = new QPushButton("Lagre");
    remove = new QPushButton("Slett");
    add = new QPushButton("Legg til");
    close = new QPushButton("Lukk");

    //Layouts
    main = new QHBoxLayout(this);
    setLayout(main);
    leftmain = new QVBoxLayout();
    rightmain = new QVBoxLayout();
    rightlabel = new QVBoxLayout();
    rightedit = new QVBoxLayout();
    bottomright = new QHBoxLayout();
    firstright = new QHBoxLayout();
    main->addLayout(leftmain);
    main->addLayout(rightmain);
    firstright->addLayout(rightlabel);
    firstright->addLayout(rightedit);
    rightmain->addLayout(firstright);
    rightmain->addLayout(bottomright);


    //Lager kontaklista
    tv = new QTableView();
    leftmain->addWidget(tv);
    mdl = new ContactListModel(ch,this);
    tv->setModel(mdl);
    tv->setSelectionBehavior(QTableView::SelectRows);
    tv->setSelectionMode(QTableView::SingleSelection);

    //Setter storrelset på vindu, knapper o.l.
    tv->setMinimumWidth(598);
    tv->setColumnWidth(0,150);
    tv->setColumnWidth(1,150);
    tv->setColumnWidth(2,120);
    tv->setColumnWidth(3,150);

    //Adder knapper og layouts til rl og ll
    rightlabel->addWidget(fName_lbl);
    rightlabel->addWidget(lName_lbl);
    rightlabel->addWidget(phoneN_lbl);
    rightlabel->addWidget(eMail_lbl);

    rightedit->addWidget(fName);
    rightedit->addWidget(lName);
    rightedit->addWidget(phoneNumber);
    rightedit->addWidget(eMail);
    rightedit->insertSpacing(4,5);

    bottomright->addWidget(edit);
    bottomright->addWidget(save);
    bottomright->addWidget(remove);
    bottomright->addWidget(add);
    bottomright->insertSpacing(3,5);
    bottomright->addWidget(close);

    //gjømmer knapper
    save->hide();

    //Ekle feltvariablar
    cHandler = ch;
    selectedRow = -1;

    //Connects
    connect(edit,SIGNAL(clicked()),this,SLOT(editRow()));
    connect(save,SIGNAL(clicked()),this,SLOT(saveRow()));
    connect(add,SIGNAL(clicked()),this,SLOT(addCont()));
    connect(remove,SIGNAL(clicked()),this,SLOT(deleteRow()));
    connect(close,SIGNAL(clicked()),this,SLOT(saveToFile()));
    connect(this,SIGNAL(end()),this,SLOT(close()));

    //Widget settings
    setWindowTitle("Kontakter");

}

void ContactView::editRow()
{
    if (cHandler->getSize() > 0) {
        selectedRow = tv->currentIndex().row();
        fName->setText((*cHandler)[selectedRow].getFName());
        lName->setText((*cHandler)[selectedRow].getLName());
        phoneNumber->setText((*cHandler)[selectedRow].getPhoneNumber());
        eMail->setText((*cHandler)[selectedRow].getEmail());
        edit->hide();
        save->show();
    }
}

void ContactView::saveRow()
{
    (*cHandler)[selectedRow].setFName(fName->text());
    (*cHandler)[selectedRow].setLName(lName->text());
    (*cHandler)[selectedRow].setPhoneNumber(phoneNumber->text());
    (*cHandler)[selectedRow].setEmail(eMail->text());
    (*cHandler).sort();
    save->hide();
    edit->show();
}

void ContactView::addCont()
{
    qDebug() << "add";
    (*cHandler).add(fName->text(),lName->text(),phoneNumber->text(),eMail->text());
}

void ContactView::deleteRow(){
    cHandler->remove(tv->currentIndex().row());
}

void ContactView::saveToFile()
{
    cHandler->save();
    emit end();
}

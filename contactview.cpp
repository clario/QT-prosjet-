#include "contactview.h"

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
    rbl->addWidget(remove);
    rbl->addWidget(add);
    rbl->insertSpacing(3,5);
    rbl->addWidget(close);
}

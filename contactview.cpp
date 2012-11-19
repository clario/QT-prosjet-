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

    //Layouts
    main = new QHBoxLayout(this);
    ll = new QVBoxLayout();
    rl = new QVBoxLayout();
    main->addLayout(ll);
    main->addLayout(rl);

    //Lager kontaklista
    tv = new QTableView();
    ll->addWidget(tv);
    mdl = new ContactListModel(ch);
    tv->setModel(mdl);
    tv->setSelectionBehavior(QTableView::SelectRows);
    tv->setSelectionMode(QTableView::SingleSelection);

    //Adder knapper
    rl->addWidget(fName);
    rl->addWidget(lName);
    rl->addWidget(phoneNumber);
    rl->addWidget(eMail);

}

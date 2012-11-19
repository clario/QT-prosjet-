#ifndef CONTACTVIEW_H
#define CONTACTVIEW_H

#include <QtGui>
#include "contactlistmodel.h"



class ContactView : public QWidget
{
    Q_OBJECT
public:
    explicit ContactView(QWidget *parent = 0);
    ContactView(ContactHandler* ch, QWidget *parent = 0);

private:
    QLineEdit *fName;
    QLineEdit *lName;
    QLineEdit *phoneNumber;
    QLineEdit *eMail;

    QHBoxLayout *main;
    QVBoxLayout *ll;
    QVBoxLayout *rl;

    QTableView *tv;
    ContactListModel *mdl;

signals:
    
public slots:

/*
//Main metode for main.cpp:
#include <QtGui>
#include "contacthandler.h"
#include "contactview.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ContactHandler ch;
    qDebug() << ch.getSize();
    ch.add("Lars","Lie","96044050","lars@fuckyou.com");
    ch.add("Lars2","Lie","96044050","lars@fuckyou.com");
    ch.add("Lars3","Lie","96044050","lars@fuckyou.com");
    ch.add("Lars4","Lie","96044050","lars@fuckyou.com");
    ch.add("Lars5","Lie","96044050","lars@fuckyou.com");
    qDebug() << ch.toString();
    qDebug() << ch.getSize();
    ContactView test(&ch);
    test.show();
    return app.exec();
}
*/
};

#endif // CONTACTVIEW_H

#ifndef CONTACTVIEW_H
#define CONTACTVIEW_H

#include <QtGui>
#include <QModelIndex>
#include "contactlistmodel.h"
#include "contact.h"


class ContactView : public QWidget
{
    Q_OBJECT
public:
    explicit ContactView(QWidget *parent = 0);
    ContactView(ContactHandler* ch, QWidget *parent = 0);

private:
    QLabel *fName_lbl;
    QLabel *lName_lbl;
    QLabel *phoneN_lbl;
    QLabel *eMail_lbl;

    QLineEdit *fName;
    QLineEdit *lName;
    QLineEdit *phoneNumber;
    QLineEdit *eMail;

    QPushButton *edit;
    QPushButton *remove;
    QPushButton *add;
    QPushButton *close;
    QPushButton *save;

    QHBoxLayout *main;
    QVBoxLayout *leftmain;
    QVBoxLayout *rightlabel;
    QVBoxLayout *rightedit;
    QVBoxLayout *rightmain;
    QHBoxLayout *bottomright;
    QHBoxLayout *firstright;

    QTableView *tv;
    ContactListModel *mdl;

    //Ekle feltvariablar som vi må bruke fordi vi ikkje har peiling
    int selectedRow;
    ContactHandler *cHandler;

signals:
    
public slots:
    void editRow();
    void saveRow();
    void deleteRow();
    void addCont();


/*
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

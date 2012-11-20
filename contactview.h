#ifndef CONTACTVIEW_H
#define CONTACTVIEW_H

#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QTableView>
#include <QDialog>
#include "contactlistmodel.h"
#include "contact.h"


class ContactView : public QDialog
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
    void end();
    
public slots:
    void editRow();
    void saveRow();
    void deleteRow();
    void addCont();
    void saveToFile();
};

#endif // CONTACTVIEW_H

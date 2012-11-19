#ifndef CONTACTMODEL_H
#define CONTACTMODEL_H

#include <QAbstractListModel>
#include "contacthandler.h"


class ContactListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ContactListModel(QObject *parent = 0);
    ContactListModel(ContactHandler* in, QObject *parent = 0);
    
    int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
//    bool QAbstractItemModel::setinput ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole );
//    Qt::ItemFlags ContactModel::flags ( const QModelIndex & index ) const; //  << Kun nødvendig for editing
    int columnCount ( const QModelIndex & parent = QModelIndex() ) const; // << Default er 1 når metoden ikkje er definert

signals:
    
public slots:
    
private:
    ContactHandler *input;
};

//#include <QtGui>
//#include "contacthandler.h"
//#include "contactmodel.h"

//int main(int argc, char *argv[])
//{
//    QApplication app(argc, argv);
//    ContactHandler ch;
//    qDebug() << ch.getSize();
//    ch.add("Lars","Lie","96044050","lars@fuckyou.com");
//    ch.add("Lars2","Lie","96044050","lars@fuckyou.com");
//    ch.add("Lars3","Lie","96044050","lars@fuckyou.com");
//    ch.add("Lars4","Lie","96044050","lars@fuckyou.com");
//    ch.add("Lars5","Lie","96044050","lars@fuckyou.com");
//    qDebug() << ch.toString();
//    qDebug() << ch.getSize();
//    QTableView tableView;
//    ContactModel cm(&ch);
//    tableView.setModel(&cm);
//    tableView.show();
//    return app.exec();
//    //app.exit();
//    //return app.exec();
//}


#endif // CONTACTMODEL_H

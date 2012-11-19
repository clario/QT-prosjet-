#include "contactlistmodel.h"
#include <QDebug>

ContactListModel::ContactListModel(QObject *parent) :
    QAbstractListModel(parent)
{
    input = new ContactHandler();
}

ContactListModel::ContactListModel(ContactHandler* in, QObject *parent) :
    QAbstractListModel(parent)
{
    input = in;
}

int ContactListModel::rowCount(const QModelIndex &parent) const
{
    return input->getSize();
}

int ContactListModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}
QVariant ContactListModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole) {
        int col = index.column();
        switch(col) {
        case 0:
            return (*input)[index.row()].getLName();
            break;
        case 1:
            return (*input)[index.row()].getFName();
            break;
        case 2:
            return (*input)[index.row()].getPhoneNumber();
            break;
        case 3:
            return (*input)[index.row()].getEmail();
            break;
        }

        //        if(index.column() == 0)
        //            return list.at(index.row()).getStr();
        //        else
        //            return list.at(index.row()).getNr();
    } else {
        return QVariant();
    }
}

//Qt::ItemFlags ContactModel::flags(const QModelIndex &index) const
//{
//    return QAbstractTableModel::flags(index) | Qt::ItemIsSelectable;
//}

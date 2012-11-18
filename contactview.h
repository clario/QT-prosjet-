#ifndef CONTACTVIEW_H
#define CONTACTVIEW_H

#include <QWidget>
#include <QtGui>



class ContactView : public QWidget
{
    Q_OBJECT
public:
    explicit ContactView(QWidget *parent = 0);
    QString getString();

private:
    QLineEdit *nameLine;
    QLineEdit *line;
    QString test;

signals:
    
public slots:
    void updateString();
    
};

#endif // CONTACTVIEW_H

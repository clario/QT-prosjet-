#ifndef CONTACTVIEW_H
#define CONTACTVIEW_H

#include <QWidget>
#include <QtGui>



class ContactView : public QWidget
{
    Q_OBJECT
public:
    explicit ContactView(QWidget *parent = 0);

private:
    QLineEdit *nameLine;
    
signals:
    
public slots:
    
};

#endif // CONTACTVIEW_H

// VOID!!

#ifndef EVENTWIDGET_H
#define EVENTWIDGET_H

#include <QWidget>
#include <QLabel>

class EventWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EventWidget(QWidget *parent = 0);
    
private:

    QLabel *title;

signals:
    
public slots:
    
};

#endif // EVENTWIDGET_H

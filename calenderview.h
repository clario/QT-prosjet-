#ifndef CALENDERVIEW_H
#define CALENDERVIEW_H

#include <QMainWindow>
#include <QGridLayout>


class CalenderView : public QMainWindow
{
    Q_OBJECT
public:
    explicit CalenderView(QWidget *parent = 0);


    
signals:
    
public slots:

private:
    QGridLayout *mainLayout;
    void createSideBar();


    
};

#endif // CALENDERVIEW_H

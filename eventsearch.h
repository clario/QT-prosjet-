// VOID!!

#ifndef EVENTSEARCH_H
#define EVENTSEARCH_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QDateEdit>
#include <QCheckBox>

#include "eventhandler.h"

class EventSearch : public QWidget
{

    Q_OBJECT

public:
    explicit EventSearch(QWidget *parent = 0);

signals:
    void queryArgs(const EventHandler::QueryArgs& args);

public slots:
    void clearFields();
    void setDateFieldState(bool toggled);
    void searchClicked();
    void debugQuery(const EventHandler::QueryArgs& args);

private:
    QGridLayout *mainLayout;

    QPushButton *search;
    QPushButton *clear;
    QCheckBox *includeDates;

    QLabel *fromLabel;
    QDateEdit *fromSearch;

    QLabel *toLabel;
    QDateEdit *toSearch;

    QLabel *titleLabel;
    QLineEdit *titleSearch;

    QLabel *descriptionLabel;
    QLineEdit *descriptionSearch;

    QLabel *participantLabel;
    QLineEdit *participantSearch;

    QLineEdit *eventTypeLabel;
    QLineEdit *eventTypeSearch;
};

#endif // EVENTSEARCH_H

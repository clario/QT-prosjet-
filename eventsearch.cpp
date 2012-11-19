#include "eventsearch.h"

#include <QDate>
#include "eventhandler.h"
#include <QDebug>

EventSearch::EventSearch(QWidget *parent) :
    QWidget(parent)
{

    // Heisann
    mainLayout = new QGridLayout(this);
    setLayout(mainLayout);

    includeDates = new QCheckBox(QString("Inkluder datoområde?"));
    mainLayout->addWidget(includeDates, 0, 0, 1, 2);

    fromLabel = new QLabel("&Fra:", this);
    fromSearch = new QDateEdit(this);
    fromLabel->setBuddy(fromSearch);
    mainLayout->addWidget(fromLabel, 1, 0);
    mainLayout->addWidget(fromSearch, 1, 1);

    toLabel = new QLabel("&Til:", this);
    toSearch = new QDateEdit(this);
    toLabel->setBuddy(toSearch);
    mainLayout->addWidget(toLabel, 2, 0);
    mainLayout->addWidget(toSearch, 2, 1);

    titleLabel = new QLabel("T&ittel:", this);
    titleSearch = new QLineEdit(this);
    titleLabel->setBuddy(titleSearch);
    mainLayout->addWidget(titleLabel, 3, 0);
    mainLayout->addWidget(titleSearch, 3, 1);

    descriptionLabel = new QLabel("&Beskrivelse:", this);
    descriptionSearch = new QLineEdit(this);
    descriptionLabel->setBuddy(descriptionSearch);
    mainLayout->addWidget(descriptionLabel, 4, 0);
    mainLayout->addWidget(descriptionSearch, 4, 1);

    participantLabel = new QLabel("&Deltager:", this);
    participantSearch = new QLineEdit(this);
    participantLabel->setBuddy(participantSearch);
    mainLayout->addWidget(participantLabel, 5, 0);
    mainLayout->addWidget(participantSearch, 5, 1);

    search = new QPushButton("&Søk", this);
    mainLayout->addWidget(search, 6, 0);

    clear = new QPushButton("&Rens", this);
    mainLayout->addWidget(clear, 6, 1);

    connect(clear, SIGNAL(clicked()), this, SLOT(clearFields()));
    connect(search, SIGNAL(clicked()), this, SLOT(searchClicked()));

    connect(includeDates, SIGNAL(toggled(bool)), this, SLOT(setDateFieldState(bool)));
    includeDates->setChecked(false);
    setDateFieldState(false);

    //connect(this, SIGNAL(queryArgs(const EventHandler::QueryArgs&)), this, SLOT(debugQuery(const EventHandler::QueryArgs&)));

    clearFields();
}

void EventSearch::clearFields() {
    fromSearch->clear();
    toSearch->clear();
    fromSearch->setDate(QDate::currentDate());
    toSearch->setDate(QDate::currentDate());

    titleSearch->clear();
    descriptionSearch->clear();
    participantSearch->clear();
}

void EventSearch::setDateFieldState(bool toggled) {
    if (!toggled) {
        fromSearch->setEnabled(false);
        toSearch->setEnabled(false);
    } else {
        fromSearch->setEnabled(true);
        toSearch->setEnabled(true);
    }
}

void EventSearch::searchClicked() {
    bool thingsAreChanged = false;
    EventHandler::QueryArgs q;

    qDebug() << "søk klikket på";

    if (includeDates->isChecked()) {
        thingsAreChanged = true;
        q.from = fromSearch->dateTime();
        q.to = toSearch->dateTime();
    }

    if (!titleSearch->text().isEmpty()) {
        thingsAreChanged = true;
        q.title = titleSearch->text();
    }

    if (!descriptionSearch->text().isEmpty()) {
        thingsAreChanged = true;
        q.description = descriptionSearch->text();
    }

    if (!participantSearch->text().isEmpty()) {
        thingsAreChanged = true;
        q.participant = participantSearch->text();
    }

    if (thingsAreChanged) {
        qDebug() << "sender ut søkesignal";
        emit queryArgs(q);
    }
}

void EventSearch::debugQuery(const EventHandler::QueryArgs& q) {
    qDebug() << q.from << q.to << q.title << q.description << q.eventType << q.participant << q.location;
}

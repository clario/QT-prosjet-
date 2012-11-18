#include "eventview.h"
#include <QStringListModel>

EventView::EventView(QWidget *parent) :
    QWidget(parent)
{
    inViewMode = true;
    changed = false;

    setWindowTitle("Avtaler");
    eventTitle = QString("Brazillian Wax");


    mainLayout = new QVBoxLayout(this);

    eventTitleLabel = new QLabel(eventTitle);
    eventTitleLabel->setFont(QFont("",25));

    editModeToggle = new QPushButton(this);
    connect(editModeToggle, SIGNAL(clicked()), this, SLOT(modeToggler()));

    //From-stuff
    fromLabel = new QLabel("Fra:");
    fromLabel->setFont(QFont("",18));

    fromDateLabel = new QLabel("Dato:");
    fromDateEdit = new QDateEdit();
    fromDateEdit->setDate(QDate(QDate::currentDate()));
    //fromDateEdit->setReadOnly(true);

    fromTimeLabel = new QLabel("Tid:");
    fromTimeEdit = new QTimeEdit();
    fromTimeEdit->setTime(QTime(QTime::currentTime()));
    //fromTimeEdit->setReadOnly(true);

    //To-stuff
    toLabel = new QLabel("Til:");
    toLabel->setFont(QFont("",18));

    toDateLabel = new QLabel("Dato:");
    toDateEdit = new QDateEdit();
    toDateEdit->setDate(QDate(QDate::currentDate()));
    //toDateEdit->setReadOnly(true);

    toTimeLabel = new QLabel("Tid:");
    toTimeEdit = new QTimeEdit(QTime(QTime::currentTime()));
    //toTimeEdit->setReadOnly(true);

    firstGridLayout = new QGridLayout();

    firstGridLayout->addWidget(eventTitleLabel, 0, 0, 3, 1, Qt::AlignLeft);
    firstGridLayout->addWidget(editModeToggle, 0, 4, 1, 1, Qt::AlignRight);

    firstGridLayout->addWidget(fromLabel,4,0);
    firstGridLayout->addWidget(fromDateLabel,5,0);
    firstGridLayout->addWidget(fromDateEdit,5,1);
    firstGridLayout->addWidget(fromTimeLabel,5,2);
    firstGridLayout->addWidget(fromTimeEdit,5,3);

    firstGridLayout->addWidget(toLabel,6,0);
    firstGridLayout->addWidget(toDateLabel,7,0);
    firstGridLayout->addWidget(toDateEdit,7,1);
    firstGridLayout->addWidget(toTimeLabel,7,2);
    firstGridLayout->addWidget(toTimeEdit,7,3);

    //Repeat

    repeatCheckBox = new QCheckBox("Repeter");

    mainLayout->addLayout(firstGridLayout);

    repeatLayout = new QHBoxLayout();

    mainLayout->addLayout(repeatLayout);

    //Title
    miniEventTitleLabel = new QLabel("Tittel:");
    eventTitleEdit = new QLineEdit("Brazilian Waxing");
    connect(eventTitleEdit, SIGNAL(textEdited(const QString&)), this, SLOT(fieldsAreChanged()) );
    connect(eventTitleEdit, SIGNAL(textEdited(const QString&)), eventTitleLabel, SLOT(setText(const QString&)) );

    titleLayout = new QHBoxLayout();
    titleLayout->addWidget(miniEventTitleLabel);
    titleLayout->addWidget(eventTitleEdit);
    mainLayout->addLayout(titleLayout);

    //Participants
    participantLabel = new QLabel("Deltakere:");
    participantModel = new QStringListModel();
    participantView = new QListView();
    participantView->setModel(participantModel);
    participantAdd = new QPushButton("Legg til");
    participantRemove = new QPushButton("Fjern");

    participantLayout = new QGridLayout();
    participantLayout->addWidget(participantLabel, 0, 0, Qt::AlignTop);
    participantLayout->addWidget(participantView, 0, 1, 3, 4);
    participantLayout->addWidget(participantAdd, 4,1,2,2);
    participantLayout->addWidget(participantRemove, 4,3,2,2);
    mainLayout->addLayout(participantLayout);

    setViewMode();
}

EventView::~EventView() {

}

void EventView::modeToggler() {
    if (!inViewMode) {
        setViewMode();
    } else {
        setEditMode();
    }
}

void EventView::fieldsAreChanged() {
    changed = true;
}

void EventView::setViewMode(){
    inViewMode = true;
    editModeToggle->setText("Rediger");

    fromDateEdit->setReadOnly(true);
    fromTimeEdit->setReadOnly(true);
    toDateEdit->setReadOnly(true);
    toTimeEdit->setReadOnly(true);

    participantAdd->setEnabled(false);
    participantRemove->setEnabled(false);

    miniEventTitleLabel->hide();
    eventTitleEdit->hide();
}


void EventView::setEditMode(){
    inViewMode = false;
    editModeToggle->setText("Vis");

    fromDateEdit->setReadOnly(false);
    fromTimeEdit->setReadOnly(false);
    toDateEdit->setReadOnly(false);
    toTimeEdit->setReadOnly(false);

    participantAdd->setEnabled(true);
    participantRemove->setEnabled(true);

    miniEventTitleLabel->show();
    eventTitleEdit->show();
}

void EventView::setNewMode(){
    setEditMode();
    editModeToggle->setEnabled(false);
}

bool EventView::isChanged() const {
    return changed;
}

Event EventView::getEvent() const {
    Event e = event;
    e.setTitle(eventTitleEdit->text());

    e.setStartDate(fromDateEdit->date());
    e.setStartTime(fromTimeEdit->time());

    e.setEndDate(toDateEdit->date());
    e.setEndTime(toTimeEdit->time());

    return e;
}

void EventView::setEvent(const Event& _event) {
    event = _event;
    populateFields();
}

void EventView::populateFields() {

    eventTitleEdit->setText(event.getTitle());

    // Denne er til for å sørge for at labelen blir oppdatert, signal avfyres ikke hvis vinduet ikke vises
    eventTitleLabel->setText(event.getTitle());

    blockSignals(true);

    fromDateEdit->setDate(event.getStartDate());
    fromTimeEdit->setTime(event.getStartTime());

    toDateEdit->setDate(event.getEndDate());
    toTimeEdit->setTime(event.getEndTime());

    blockSignals(false);
}

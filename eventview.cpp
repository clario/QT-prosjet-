#include "eventview.h"
#include <QStringListModel>
#include <QSizePolicy>

EventView::EventView(QWidget *parent) :
    QDialog(parent)
{
    setModal(true);

    inViewMode = true;
    changed = false;

    setWindowTitle("Avtaler");
    eventTitle = QString("Brazillian Wax");


    mainLayout = new QVBoxLayout(this);

    headerLabel = new QLabel(eventTitle);
    headerLabel->setFont(QFont("",25));
    headerLabel->setWordWrap(true); // Brekker linjene

    editModeToggle = new QPushButton(this);
    connect(editModeToggle, SIGNAL(clicked()), this, SLOT(modeToggler()));

    //From-stuff
    fromLabel = new QLabel("Fra:");
    fromLabel->setFont(QFont("",18));

    fromDateLabel = new QLabel("Dato:");
    fromDateEdit = new QDateEdit();
    fromDateEdit->setDate(QDate(QDate::currentDate()));

    fromTimeLabel = new QLabel("Tid:");
    fromTimeEdit = new QTimeEdit();
    fromTimeEdit->setTime(QTime(QTime::currentTime()));

    //To-stuff
    toLabel = new QLabel("Til:");
    toLabel->setFont(QFont("",18));

    toDateLabel = new QLabel("Dato:");
    toDateEdit = new QDateEdit();
    toDateEdit->setDate(QDate(QDate::currentDate()));

    toTimeLabel = new QLabel("Tid:");
    toTimeEdit = new QTimeEdit(QTime(QTime::currentTime()));

    headerLayout = new QHBoxLayout();
    headerLayout->addWidget(headerLabel);
    headerLayout->addStretch(1000);
    //headerLayout->addItem(new QSpacerItem(1,1,QSizePolicy::Expanding));
    headerLayout->addWidget(editModeToggle, Qt::AlignRight);
    mainLayout->addLayout(headerLayout);

    firstGridLayout = new QGridLayout();
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
    eventTitleLabel = new QLabel("Tittel:");
    eventTitleEdit = new QLineEdit("Brazilian Waxing");
    connect(eventTitleEdit, SIGNAL(textEdited(const QString&)), this, SLOT(fieldsAreChanged()) );
    connect(eventTitleEdit, SIGNAL(textChanged(const QString&)), headerLabel, SLOT(setText(const QString&)) );

    titleLayout = new QHBoxLayout();
    titleLayout->addWidget(eventTitleLabel);
    titleLayout->addWidget(eventTitleEdit);
    mainLayout->addLayout(titleLayout);

    //Description
    descriptionLabel = new QLabel("Beskrivelse");
    descriptionText = new QLabel();
    descriptionTextEdit = new QTextEdit();
    connect(descriptionTextEdit, SIGNAL(textChanged()), this, SLOT(fieldsAreChanged()));
    connect(descriptionTextEdit, SIGNAL(textChanged()), this, SLOT(updateDescription()));

    descriptionLayout = new QHBoxLayout();
    descriptionLayout->addWidget(descriptionLabel, Qt::AlignTop);
    descriptionLayout->addWidget(descriptionText, Qt::AlignLeft);
    descriptionLayout->addWidget(descriptionTextEdit);
    mainLayout->addLayout(descriptionLayout);

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

void EventView::updateDescription() {
    descriptionText->setText(descriptionTextEdit->toPlainText());
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

    eventTitleLabel->hide();
    eventTitleEdit->hide();

    descriptionText->show();
    descriptionTextEdit->hide();
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

    eventTitleLabel->show();
    eventTitleEdit->show();

    descriptionText->hide();
    descriptionTextEdit->show();
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

    e.setDescription(descriptionTextEdit->toPlainText());

    QStringList myParticipants(participantModel->stringList());
    e.setParticipants(myParticipants.toVector().toStdVector());

    return e;
}

void EventView::setEvent(const Event& _event) {
    event = _event;
    populateFields();
}

void EventView::populateFields() {

    eventTitleEdit->setText(event.getTitle());

    // Denne er til for å sørge for at labelen blir oppdatert, signal avfyres ikke hvis vinduet ikke vises
    // headerLabel->setText(event.getTitle());

    blockSignals(true);

    descriptionTextEdit->setPlainText(event.getDescription());
    descriptionText->setText(event.getDescription());

    fromDateEdit->setDate(event.getStartDate());
    fromTimeEdit->setTime(event.getStartTime());

    toDateEdit->setDate(event.getEndDate());
    toTimeEdit->setTime(event.getEndTime());

    participants = QStringList::fromVector(QVector<QString>::fromStdVector(event.getParticipants()));
    participantModel->setStringList(participants);

    blockSignals(false);
}

#include "eventview.h"
#include <QStringListModel>
#include <QSizePolicy>

EventView::EventView(QWidget *parent) :
    QDialog(parent)
{
    setModal(true);

    inViewMode = true;
    changed = false;
    buttonVisible = false;

    setWindowTitle("Avtaler");
    eventTitle = QString("Yogatime");


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
    headerLayout->addWidget(editModeToggle, Qt::AlignRight);
    mainLayout->addLayout(headerLayout);

    firstGridLayout = new QGridLayout();
    firstGridLayout->addWidget(fromLabel,0,0);

    firstGridLayout->addWidget(fromDateLabel,1,0);
    firstGridLayout->addWidget(fromDateEdit,1,1);
    firstGridLayout->addWidget(fromTimeLabel,1,2);
    firstGridLayout->addWidget(fromTimeEdit,1,3);

    firstGridLayout->addWidget(toLabel,2,0);
    firstGridLayout->addWidget(toDateLabel,3,0);
    firstGridLayout->addWidget(toDateEdit,3,1);
    firstGridLayout->addWidget(toTimeLabel,3,2);
    firstGridLayout->addWidget(toTimeEdit,3,3);

    //Repeat

    repeatCheckBox = new QCheckBox("Repeter");


    mainLayout->addLayout(firstGridLayout);

    repeatLayout = new QHBoxLayout();
    repeatLayout->addWidget(repeatCheckBox);
    repeatSpinBox = new QSpinBox();
    repeatSpinBox->setMaximum(20);
    repeatLabel = new QLabel("Uker");
    repeatLayout->addWidget(repeatSpinBox);
    repeatLayout->addWidget(repeatLabel);
    connect(repeatCheckBox,SIGNAL(clicked(bool)),repeatSpinBox,SLOT(setEnabled(bool)));




    mainLayout->addLayout(repeatLayout);

    //Title
    eventTitleLabel = new QLabel("Tittel:");
    eventTitleLabel->setFont(QFont("",18));
    eventTitleEdit = new QLineEdit(eventTitle);
    connect(eventTitleEdit, SIGNAL(textEdited(const QString&)), this, SLOT(fieldsAreChanged()) );
    connect(eventTitleEdit, SIGNAL(textChanged(const QString&)), headerLabel, SLOT(setText(const QString&)) );

    titleLayout = new QHBoxLayout();
    titleLayout->addWidget(eventTitleLabel);
    titleLayout->addWidget(eventTitleEdit);
    mainLayout->addLayout(titleLayout);

    //Description
    descriptionLabel = new QLabel("Beskrivelse:");
    descriptionLabel->setFont(QFont("",18));
    descriptionText = new QLabel();
    descriptionTextEdit = new QTextEdit();
    connect(descriptionTextEdit, SIGNAL(textChanged()), this, SLOT(fieldsAreChanged()));
    connect(descriptionTextEdit, SIGNAL(textChanged()), this, SLOT(updateDescription()));

    descriptionLayout = new QHBoxLayout();
    descriptionLayout->addWidget(descriptionLabel, Qt::AlignTrailing);
    descriptionLayout->addWidget(descriptionText, Qt::AlignLeft);
    descriptionLayout->addWidget(descriptionTextEdit);
    mainLayout->addLayout(descriptionLayout);

    //Participants
    participantLabel = new QLabel("Deltakere:");
    participantLabel->setFont(QFont("",18));
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

    //Event-type
    eventTypeGridLayout = new QGridLayout();
    eventTypeLabel = new QLabel("Type");
    eventTypeLabel->setFont(QFont("",18));
    typeRadioLayout = new QHBoxLayout();
    eventRadioButton = new QRadioButton("Avtale");
    absenceRadioButton = new QRadioButton("Fravear");
    typeRadioLayout->addWidget(eventRadioButton);
    typeRadioLayout->addWidget(absenceRadioButton);
    typeLabel = new QLabel("Type:");
    typeLabel->setFont(QFont("",18));
    typeComboBox = new QComboBox();
     absenceType << "Ferie" << "Avspasering" << "Kurs";
    typeEvent << "Shopping" << "Utflukt" << "Arrangement" <<
                 "Underholding" << "Foredrag" << "Diverse"
              << "Kurs";


    typeComboBox->addItems(typeEvent);



    eventTypeGridLayout->addWidget(eventTypeLabel,0,0,1,1);
    eventTypeGridLayout->addLayout(typeRadioLayout,0,1,1,1);
    eventTypeGridLayout->addWidget(typeLabel,1,0,1,1);
    eventTypeGridLayout->addWidget(typeComboBox,1,1,1,1);
    eventRadioButton->setChecked(true);


    mainLayout->addLayout(eventTypeGridLayout);

    connect(absenceRadioButton,SIGNAL(toggled(bool)),this,SLOT(setAbsenceMode(bool)));
    connect(eventRadioButton,SIGNAL(toggled(bool)),this,SLOT(eventMode(bool)));

    buttonLayout = new QHBoxLayout();
    okButton = new QPushButton("Save");
    cancelButton = new QPushButton("Cancel");
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    mainLayout->addLayout(buttonLayout);

    okButton->hide();
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(closedCancelClick()));
    connect(okButton,SIGNAL(clicked()),this,SLOT(closedSaveClick()));

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
    descriptionTextEdit->setEnabled(false);
    repeatCheckBox->setEnabled(false);

    eventRadioButton->setEnabled(false);
    absenceRadioButton->setEnabled(false);
    typeComboBox->setEnabled(false);



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
    descriptionTextEdit->setEnabled(true);
    repeatCheckBox->setEnabled(true);

    eventRadioButton->setEnabled(true);
    absenceRadioButton->setEnabled(true);
    typeComboBox->setEnabled(true);
    showButtons(true);
    if(!absence){
        absence = true;
        repeatCheckBox->show();
        repeatLabel->show();
        repeatSpinBox->show();
        participantView->show();
        repeatSpinBox->setEnabled(false);
        participantAdd->show();
        participantRemove->show();
        participantLabel->show();

        typeLabel->show();
        typeComboBox->show();

    }



}

bool EventView::showButtons(bool flag){
    if(!(buttonVisible) && flag){
    okButton->show();
    buttonVisible = true;

    }
    else if(!flag && buttonVisible){

        okPushButton->hide();
        cancelPushButton->hide();
        buttonVisible = false;


    }


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

    e.setAbsence(absenceRadioButton->isChecked());

    e.setRepeats(repeatSpinBox->value());

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

    if(event.getAbsence()){
       absenceRadioButton->setChecked(true);
    }



    blockSignals(false);
}

void EventView::setAbsenceMode(bool bo){
    if(bo){

    absence = true;
    repeatCheckBox->hide();
    repeatLabel->hide();
    repeatSpinBox->hide();
    participantView->hide();
    repeatSpinBox->hide();
    participantAdd->hide();
    participantRemove->hide();
    participantLabel->hide();
    typeComboBox->clear();
    typeComboBox->addItems(absenceType);



    }
}


void EventView::setEditMode(bool bo){
    if(bo){
        setEditMode();
    }
}

void EventView::eventMode(bool bol){
    if(!inViewMode){
        absence = false;
        repeatCheckBox->show();
        repeatLabel->show();
        repeatSpinBox->show();



        participantView->show();
        repeatSpinBox->show();
        participantAdd->show();
        participantRemove->show();
        participantLabel->show();
        typeLabel->show();
        typeComboBox->show();
        typeComboBox->clear();
        typeComboBox->addItems(typeEvent);


    }


}

void EventView::closedCancelClick(){
    changed = false;
    close();
}

void EventView::closedSaveClick(){
    changed = true;
    close();
}



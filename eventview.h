#ifndef EVENTVIEW_H
#define EVENTVIEW_H
#include <QLabel>
#include <QTimeEdit>
#include <QDateEdit>
#include <QCheckBox>
#include <QTextEdit>
#include <QLineEdit>
#include <QRadioButton>
#include <QComboBox>
#include <QTextEdit>
#include <QListView>
#include <QAbstractItemModel>
#include <QStringList>
#include <QButtonGroup>
#include <QPushButton>
#include <QDialog>
#include <QGroupBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>

#include "event.h"

class EventView : public QDialog
{
    Q_OBJECT
public:
    explicit EventView(QWidget *parent = 0);

    ~EventView();

    void setViewMode();
    void setEditMode();
    void setNewMode();

    // Returnerer om noe er endret
    bool isChanged() const;

    // Returnerer en kopi av det nye objektet;
    Event getEvent() const;

    void setEvent(const Event& event);

signals:

public slots:
    void modeToggler();
    void fieldsAreChanged();

private:
    bool inViewMode;
    bool changed;

    Event event;

    QString eventTitle;

    QPushButton *editModeToggle;

    QLabel *headerLabel;
    QCheckBox *allDayEvent;
    QLabel *allDayEventLabel;
    QLabel *fromLabel;
    QLabel *fromDateLabel;
    QDateEdit *fromDateEdit;
    QLabel *fromTimeLabel;
    QTimeEdit *fromTimeEdit;
    QLabel *toLabel;
    QLabel *toDateLabel;
    QDateEdit *toDateEdit;
    QLabel * toTimeLabel;
    QTimeEdit *toTimeEdit;

    QCheckBox *repeatCheckBox;
    QComboBox * repeatComboBox;
    QLabel * repeatLabel;

    QLabel * eventTitleLabel;
    QLineEdit * eventTitleEdit;

    QLabel * eventTypeLabel;
    QGroupBox * eventTypeRadioBoxContainer;

    QRadioButton * eventRadioButton;
    QRadioButton * absenceRadioButton;

    QLabel * typeLabel;
    QComboBox *typeComboBox;

    QLabel * eventDescriptionLabel;
    QTextEdit * eventDescriptionTextBox;

    QLabel * participantsLabel;
    QTextEdit * textEditAttending;

    QStringList participants;
    QLabel * participantLabel;
    QAbstractItemModel * participantModel;
    QListView * participantView;
    QPushButton * participantAdd;
    QPushButton * participantRemove;

    QPushButton * addContact;
    QGridLayout * gridLayout;
    QPushButton * okPushButton;

    QPushButton * cancelPushButton;
    QPushButton * savePushButton;

    QGridLayout * firstGridLayout;
    QHBoxLayout * headerLayout;
    QHBoxLayout * repeatLayout;
    QHBoxLayout * titleLayout;
    QGridLayout * participantLayout;
    QHBoxLayout * descriptionLayout;

    QVBoxLayout * mainLayout;

    void populateFields();
};




#endif // EVENTVIEW_H

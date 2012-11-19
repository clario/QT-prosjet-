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
#include <QStringListModel>
#include <QButtonGroup>
#include <QPushButton>
#include <QDialog>
#include <QGroupBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QSpinBox>
#include <QStringList>

#include "event.h"

class EventView : public QDialog
{
    Q_OBJECT
public:
    explicit EventView(QWidget *parent = 0);

    ~EventView();



   // void setViewMode();
 //   void setEditMode();
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
    void updateDescription();
    void setEditMode();
    void setViewMode();
    void setAbsenceMode(bool);
    void setEditMode(bool);
    void eventMode(bool);

private:
    bool inViewMode;
    bool changed;
    bool absence;

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
    QSpacerItem * spacer;

    QCheckBox *repeatCheckBox;
    QSpinBox * repeatSpinBox;
    QSpinBox * uker;
    QLabel * repeatLabel;



    QLabel * eventTitleLabel;
    QLineEdit * eventTitleEdit;

    QLabel * descriptionLabel;
    QLabel * descriptionText;
    QTextEdit * descriptionTextEdit;

    QLabel * eventTypeLabel;


    QRadioButton * eventRadioButton;
    QRadioButton * absenceRadioButton;
    QHBoxLayout * typeRadioLayout;

    QLabel * typeLabel;
    QComboBox *typeComboBox;
    QGridLayout * eventTypeGridLayout;
    QStringList typeEvent;



    QLabel * participantsLabel;
    QStringList participants;
    QLabel * participantLabel;
    QStringListModel * participantModel;
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
    QHBoxLayout * descriptionLayout;
    QGridLayout * participantLayout;




    QVBoxLayout * mainLayout;

    void populateFields();
};




#endif // EVENTVIEW_H

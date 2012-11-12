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
#include <QButtonGroup>
#include <QPushButton>
#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>

class EventView : public QWidget
{
    Q_OBJECT
public:
    explicit EventView(QWidget *parent = 0);
    void setViewMode();
    void setEditMode();



signals:

public slots:

private:

    QString eventTitle;

    QLabel *eventTitleLabel;
    QPushButton *editModeToggle;
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
    QLabel * miniEventTitleLable;
    QLineEdit * eventTitleEdit;
    QLabel * eventTypeLabel;
    QGroupBox * eventTypeRadioBoxContainer;
    QRadioButton * eventRadioButton;
    QRadioButton * absenceRadioButton;
    QLabel * typeLabel;
    QComboBox *typeComboBox;
    QLabel * eventDescriptionLabel;
    QTextEdit * eventDescriptionTextBox;
    QLabel * attendingLabel;
    QTextEdit * textEditAttending;
    QPushButton * addContact;
    QGridLayout * gridLayout;
    QPushButton * okPushButton;
    QPushButton * cancelPushButton;
    QPushButton * savePushButton;
    QGridLayout * firstGridLayout;
    QHBoxLayout * firstHLayout;
    QHBoxLayout * secondHLayout;
    QHBoxLayout * thirdHLayout;
    QHBoxLayout * fourthHLayout;
    QVBoxLayout * mainLayout;
};




#endif // EVENTVIEW_H

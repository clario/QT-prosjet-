#include "filewriter.h"
#include <QDebug>


FileWriter::FileWriter(QString &source)
{

    target.setFileName(source);

}

FileWriter::~FileWriter()
{
}

bool FileWriter::save(QVector<Contact*> &source)
{
    bool isWritable = target.open(QFile::WriteOnly);
    if (isWritable) {
        //qDebug() << "isWritable = true";
        //Bygger dokument strukturen
        QDomDocument doc;
        QDomElement root = doc.createElement("contacts");
        doc.appendChild(root);
        foreach (Contact* e, source) {
            QDomElement contact = doc.createElement("contact");
            contact.setAttribute("cid", QString::number(e->getCId()));
            QDomElement fName = doc.createElement("fName");
            fName.appendChild(doc.createTextNode(e->getFName()));
            contact.appendChild(fName);
            QDomElement lName = doc.createElement("lName");
            lName.appendChild(doc.createTextNode(e->getLName()));
            contact.appendChild(lName);
            QDomElement phoneNumber = doc.createElement("phoneNumber");
            phoneNumber.appendChild(doc.createTextNode(QString::number(e->getPhoneNumber())));
            contact.appendChild(phoneNumber);
            QDomElement email = doc.createElement("email");
            email.appendChild(doc.createTextNode(e->getEmail()));
            contact.appendChild(email);
            root.appendChild(contact);
        }
        qint64 wr = target.write(doc.toByteArray(4));
        target.close();
        return true;
    }
    else {
        //qDebug() << "isWritable = true";
        target.close();
        return false;
    }
}

bool FileWriter::save(std::set<Event> &source)
{
    bool isWritable = target.open(QIODevice::WriteOnly);
    if (isWritable) {
        //Bygger dokument strukturen
        QDomDocument doc;
        QDomElement root = doc.createElement("events");
        doc.appendChild(root);

        foreach (Event e, source) {
            QDomElement event = doc.createElement("event");
            QDomElement title = doc.createElement("title");
            QDomElement location = doc.createElement("location");
            std::vector<QString> participants = e.getParticipants();

            event.setAttribute("from", e.getEndAsString());
            event.setAttribute("to", e.getStartAsString());
            event.setAttribute("eventType", e.getEventType());

            title.appendChild(doc.createTextNode(e.getTitle()));
            event.appendChild(title);

            location.appendChild(doc.createTextNode(e.getLocation()));
            event.appendChild(location);

            if (participants.size() > 0) {
                for (std::vector<QString>::const_iterator it = participants.begin(); it != participants.end(); it++) {
                    QDomElement participant = doc.createElement("participant");
                    participant.appendChild(doc.createTextNode(*it));
                    event.appendChild(participant);
                }
            }

            root.appendChild(event);
        }

        target.write(doc.toByteArray());

        target.close();
        return true;
    }
    else {
        return false;
    }
}

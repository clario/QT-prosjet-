#include "filewriter.h"

FileWriter::FileWriter(QString &source)
{
    target.setFileName(source);
}

FileWriter::~FileWriter()
{
}

bool FileWriter::save(QVector<Contact*> &source)
{
    bool isWritable = target.open(QIODevice::WriteOnly);
    if (isWritable) {
        //Bygger dokument strukturen
        QDomDocument doc;
        QDomElement root = doc.createElement("contacts");
        doc.appendChild(root);
        QDomElement *contact = new QDomElement();
        QDomElement *variable= new QDomElement();
        foreach (Contact* e, source) {
            contact->setTagName("contact");
            contact->setAttribute("cid", e->getCId());
            root.appendChild(*(contact));
        }
        target.write(doc.toByteArray());
        target.close();
        return true;
    }
    else {
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

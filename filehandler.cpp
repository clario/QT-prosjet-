#include "filehandler.h"
#include <QDebug>


FileHandler::FileHandler(QString &source)
{
    target.setFileName(source);
}

FileHandler::~FileHandler()
{
}

bool FileHandler::save(QVector<Contact*> &source)
{
    bool isWritable = target.open(QFile::WriteOnly);
    if (isWritable) {
        //qDebug() << "isWritable = true";
        //Bygger dokument strukturen (Meir detaljert forklart korleis i event sin lagre metode)
        QDomDocument doc;
        QDomElement root = doc.createElement("contacts");
        doc.appendChild(root);
        foreach (Contact* e, source) {
            QDomElement contact = doc.createElement("contact");
            contact.setAttribute("cid", QString::number(e->getCId()));

            if (e->hasFName()) {
                QDomElement fName = doc.createElement("fName");
                fName.appendChild(doc.createTextNode(e->getFName()));
                contact.appendChild(fName);
            }

            if (e->hasLName()) {
                QDomElement lName = doc.createElement("lName");
                lName.appendChild(doc.createTextNode(e->getLName()));
                contact.appendChild(lName);
            }

            if (e->hasPhoneNumber()) {
                QDomElement phoneNumber = doc.createElement("phoneNumber");
                phoneNumber.appendChild(doc.createTextNode(e->getPhoneNumber()));
                contact.appendChild(phoneNumber);
            }

            if (e->hasEmail()) {
                QDomElement email = doc.createElement("email");
                email.appendChild(doc.createTextNode(e->getEmail()));
                contact.appendChild(email);
            }

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

bool FileHandler::save(std::set<Event> &source)
{
    bool isWritable = target.open(QIODevice::WriteOnly);
    if (isWritable) {
        //Bygger dokument strukturen
        QDomDocument doc;
        QDomElement root = doc.createElement("events");
        doc.appendChild(root);
        foreach (Event e, source) {
            QDomElement event = doc.createElement("event");
            //Begynder og legge inn tekstnoder for event
            std::vector<QString> participants = e.getParticipants();

            QDomElement endDate = doc.createElement("endDate");
            endDate.appendChild(doc.createTextNode(e.getStartAsString()));
            event.appendChild(endDate);

            QDomElement toDate = doc.createElement("toDate");
            toDate.appendChild(doc.createTextNode(e.getStartAsString()));
            event.appendChild(toDate);

            if (e.hasEventType()) {
                QDomElement type = doc.createElement("type");
                type.appendChild(doc.createTextNode(e.getEventType()));
                type.appendChild(type);
            }

            if (e.hasTitle()) {
                QDomElement title = doc.createElement("title");
                title.appendChild(doc.createTextNode(e.getTitle()));
                event.appendChild(title);
            }

            if (e.hasLocation()) {
                QDomElement location = doc.createElement("location");
                location.appendChild(doc.createTextNode(e.getLocation()));
                event.appendChild(location);
            }

            if (participants.size() > 0) {
                for (std::vector<QString>::const_iterator it = participants.begin(); it != participants.end(); it++) {
                    QDomElement participant = doc.createElement("participant");
                    participant.appendChild(doc.createTextNode(*it));
                    event.appendChild(participant);
                }
            }

            //Legger barnet event (a.k.a. ein event fra settet) til root elementet
            root.appendChild(event);
        }

        qint64 wr = target.write(doc.toByteArray(4));
        target.close();
        return true;
    }
    else {
        target.close();
        return false;
    }
}

bool FileHandler::load(QVector<Contact *> &source) {
    QDomDocument doc;
    doc.setContent(&target);
    QDomElement root = doc.firstChildElement();
    QDomNodeList nodes = root.childNodes();
    for (int i = 0; i < nodes.size(); i++) {
        QString fName, lName, eMail;
        int cID, phoneNumber;
        QDomElement current = nodes.at(i).toElement();
        Contact *tmp = new Contact(current.attribute("cid").toInt());
        if (current.firstChildElement("phoneNumber").hasChildNodes()) {
            tmp->setPhoneNumber(current.firstChildElement("phoneNumber").firstChild().nodeValue());
        }
        if (current.firstChildElement("fName").hasChildNodes()) {
            tmp->setFName(current.firstChildElement("fName").firstChild().nodeValue());
        }
        if (current.firstChildElement("lName").hasChildNodes()) {
            tmp->setLName(current.firstChildElement("lName").firstChild().nodeValue());
        }
        if (current.firstChildElement("email").hasChildNodes()) {
            tmp->setEmail(current.firstChildElement("email").firstChild().nodeValue());
        }
        source.push_back(tmp);
    }
    return false;
}

bool FileHandler::load(std::set<Event> &source) {
    QDomDocument doc;
    doc.setContent(&target);
    QDomElement root = doc.firstChildElement();
    QDomNodeList nodes = root.childNodes();
    for (int i = 0; i < nodes.size(); i++) {
        Event tmp();
        QString endDate, toDate, type, title, location;
        QDomElement current = nodes.at(i).toElement();
        if (current.firstChildElement("endDate").hasChildNodes()) {
            qDebug() << current.firstChildElement("endDate").firstChild().nodeValue();
        }
        if (current.firstChildElement("startDate").hasChildNodes()) {
            qDebug() << current.firstChildElement("startDate").firstChild().nodeValue();
        }
        if (current.firstChildElement("type").hasChildNodes()) {
            qDebug() << current.firstChildElement("type").firstChild().nodeValue();
        }
        if (current.firstChildElement("title").hasChildNodes()) {
            qDebug() << current.firstChildElement("title").firstChild().nodeValue();
        }
        if (current.firstChildElement("location").hasChildNodes()) {
            qDebug() << current.firstChildElement("location").firstChild().nodeValue();
        }
        QDomElement firstParticipant();
        while (firstParticipant().nextSiblingElement() != NULL) {
            //tmp. firstParticipant().firstChild().nodeValue()
        }

    }
    return false;
}

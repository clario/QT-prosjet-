#include "filewriter.h"

FileWriter::FileWriter(QIODevice *targetFile)
{
    target=targetFile;
}

FileWriter::~FileWriter()
{
}

bool FileWriter::save(QVector<Contact*> &source)
{
    bool isWritable = target->open(QIODevice::WriteOnly);
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
        target->close();
        return true;
    }
    else {
        return false;
    }
}

bool FileWriter::save(std::set<Event> &source)
{
    return true;
}

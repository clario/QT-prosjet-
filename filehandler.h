#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <QtCore/QIODevice>
#include <QtCore/QFile>
#include <QtXml/QDomDocument>
#include <QtXml/QXmlStreamWriter>
#include <QtXml/QXmlSimpleReader>
#include <set>
#include <QVector>
#include "contact.h"
#include "event.h"

class FileHandler
{
public:
    /*@input QFile(targetFile), std::iterator from container, const static inputFlag to identify content.
    */
    FileHandler(QString &source);
    ~FileHandler();

    const static char typeIsContact='c';
    const static char typeIsEvent='e';

    bool save(QVector<Contact> &source);
    bool save(std::set<Event> &source);

    bool load(QVector<Contact> &source);
    bool load(std::set<Event> &source);

private:
    QFile target;
};

#endif // FILEHANDLER_H

/*
*****************************************************************************************************
* Eit lite eksempel på korleis save funksjonen skal brukast i ContactHandler.
* Framgangsmåten i EventHandler burde være ganske lik.
*****************************************************************************************************

bool save() {
    QString source = QDir::currentPath() << "contacts.xml";
    FileHandler fw(source);                  //Opretta filewriter med stien til current path + navnet på kildefila
    bool result = fw.save(&container);      //Kaller FileWriter::save(xxx)
    return result;                          //Returnerer resultatet fra FileWriter sin save operasjon
}

bool load() {
    QString source = QDir::currentPath() << "contacts.xml";
    FileHandler fw(source);                  //Opretta filewriter med stien til current path + navnet på kildefila
    bool result = fw.save(&container);      //Kaller FileWriter::save(xxx)
    return result;                          //Returnerer resultatet fra FileWriter sin save operasjon
}
*/

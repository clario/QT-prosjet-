#ifndef FILEWRITER_H
#define FILEWRITER_H
#include <QtCore/QIODevice>
#include <QtCore/QFile>
#include <QtXml/QDomDocument>
#include <set>
#include <QVector>
#include "contact.h"
#include "event.h"

class FileWriter
{
public:
    /*@input QFile(targetFile), std::iterator from container, const static inputFlag to identify content.
    */
    FileWriter(QString &source);
    ~FileWriter();

    const static char typeIsContact='c';
    const static char typeIsEvent='e';

    bool save(QVector<Contact*> &source);
    bool save(std::set<Event> &source);

private:
    QFile target;
};

#endif // FILEWRITER_H

/*
*****************************************************************************************************
* Eit lite eksempel på korleis save funksjonen skal brukast i ContactHandler.
* Framgangsmåten i EventHandler burde være ganske lik.
*****************************************************************************************************

bool save() {
    QFile("") source;
    FileWriter fw(source);               //Opretta filewriter
    bool result = fw.save(&container);      //Kaller FileWriter::save(xxx)
    return result;                          //Returnerer resultatet fra FileWriter sin save operasjon
}
*/

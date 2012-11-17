#ifndef FILEWRITER_H
#define FILEWRITER_H
#include <QtCore/QFile>
#include <iterator>
#include <contact>
#include <event>

class FileWriter
{
public:
    /*@input QFile(targetFile), std::iterator from container, const static inputFlag to identify content.
    */
    FileWriter(QFile targetFile, auto endOfIterator, std::iterator itr, char inputTypeFlag);
    ~FileWriter();

    const static char typeIsContact='c';
    const static char typeIsEvent='e';

    /*@output Returns true if the current save was sucsessfull
    */
    bool save(void);

private:
    const QFile target;
    const std::iterator source;
    const char sourceType;
    auto end;

};

#endif // FILEWRITER_H

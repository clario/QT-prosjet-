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
    return true;
}

bool FileWriter::save(std::set<Event> &source)
{
    return true;
}

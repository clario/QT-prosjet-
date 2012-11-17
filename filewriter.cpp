#include "filewriter.h"
#include "contact.h"
#include "event.h"

FileWriter::FileWriter(QFile targetFile, auto endOfIterator, std::iterator itr, char inputTypeFlag)
{
    target=targetFile;
    source=itr;
    targetType=inputTypeFlag;
}

FileWriter::~FileWriter()
{
}

bool FileWriter::save()
{
    if (targetType='c') {
        while (c!=end) {
            Contact c = (*source);

        }
    } else if(targetType='e') {

    } else {
        return false;
    }
}

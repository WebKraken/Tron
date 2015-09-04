#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <dirent.h>
#include <stdexcept>
#include <vector>


class FileReader
{
    public:
        FileReader();
        FileReader( std::string );
        virtual ~FileReader();
        std::vector<std::string> getContent( std::string );
        std::string getExt( std::string );
        std::string getBody( std::string );
    private:
        std::vector<std::string> content;

};

#endif // FILEREADER_H

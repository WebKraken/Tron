#include "FileReader.h"

FileReader::FileReader()
{
}

FileReader::FileReader( std::string relativePath )
{
    getContent( relativePath );
}

FileReader::~FileReader()
{
}

std::vector<std::string> FileReader::getContent( std::string relativePath )
{
    struct dirent *ent = NULL;
    DIR *dir = NULL;
    dir = opendir ( relativePath.c_str() );
    if (dir == NULL)
    {
        throw std::runtime_error( "Can't read path, dir could not be initialised correctly." );
    }

    // while there is still something in the directory to list
    while ( ( ent = readdir( dir ) ) )
    {
        if ( ent == NULL )
        {
            throw std::runtime_error( "Can't read file, ent could not be initialised correctly." );
        }
        // Populate content
        content.push_back( ent->d_name );
    }

    closedir ( dir );
    delete( ent );
    return content;
}

// Returns the extension component of the specified file name. If
// the file name has no extension, this function returns an empty
// string
std::string FileReader::getExt( std::string filename )
{
	int pos;
	std::string ext;

	// Find the last occurence of a period in the file name
	// If filename is a valid file name, the string following
	// the period should be the file extension
	pos = filename.find_last_of( '.' );

	if( pos == -1 ) // There was no '.' in the file name
		return ""; // Return an empty string

	// Get the string following the period including the period
	// and store it in ext
	ext = filename.substr( pos + 1, -1 );

	return ext;
}

// Returns the body component of the specified file name.
std::string FileReader::getBody( std::string filename )
{
	int pos;
	std::string body;

	// Find the last occurence of a period in the file name
	pos = filename.find_first_of( '.' );

	// Get the string until the period excluding the period
	// and store it in ext
	body = filename.substr( 0, pos );

	return body;
}


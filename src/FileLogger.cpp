#include "FileLogger.hpp"

#include "LogFormatter.hpp"

namespace foo
{

FileLogger::FileLogger( std::ostream& output )
: output{ output }
{
}

FileLogger::~FileLogger()
{
}

void FileLogger::write( const std::string& log )
{
    output << "[" << LogFormatter::getTimeStamp() << "] " << log << '\n';
}

} // namespace foo

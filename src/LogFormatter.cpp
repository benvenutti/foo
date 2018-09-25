#include "LogFormatter.hpp"

#include <chrono>
#include <iomanip>
#include <sstream>

namespace foo
{

std::string LogFormatter::getTimeStamp()
{
    const auto now     = std::chrono::system_clock::now();
    const auto nowTime = std::chrono::system_clock::to_time_t( now );

    return std::to_string( nowTime );
}

} // namespace foo

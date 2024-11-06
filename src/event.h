
#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

#include <string>
#include <chrono>

#include <ostream>

#include "settings.h"
using namespace std;
namespace seneca
{

    class Event
    {
        string m_name{};
        std::chrono::nanoseconds m_duration{};

    public:
        Event();
        Event(const char* name, const std::chrono::nanoseconds&);
        friend std::ostream& operator<<(std::ostream&, const Event&);
    };

}
#endif //SENECA_EVENT_H
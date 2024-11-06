#include "event.h"
#include <iomanip>
using namespace std;
namespace seneca
{

    Event::Event() = default;

    Event::Event(const char* name, const std::chrono::nanoseconds& duration)
    {
        m_name = name;
        m_duration = duration;
    }

    ostream& operator <<(ostream& os, const Event& event)
    {
        int counter = 0;
        ++counter;

        os << std::setw(2) << counter << ":";
        os << std::setw(40) << event.m_name << " ->";
        if (g_settings.m_time_units == "seconds")
        {
            os << std::setw(2) << event.m_duration.count() <<
                " " << g_settings.m_time_units;
        }
        else if (g_settings.m_time_units == "milliseconds")
        {
            os << std::setw(5) << event.m_duration.count() <<
                " " << g_settings.m_time_units;
        }
        else if (g_settings.m_time_units == "microseconds")
        {
            os << std::setw(8) << event.m_duration.count() <<
                " " << g_settings.m_time_units;
        }
        else if (g_settings.m_time_units == "nanoseconds")
        {
            os << std::setw(11) << event.m_duration.count() <<
                " " << g_settings.m_time_units;
        }

        return os;
    }
}
#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H

#include <string>
#include <iostream>

#include "logger.h"
using namespace std;
namespace seneca
{

    struct Settings {
        bool  m_show_all{};
        bool m_verbose{};
        string m_time_units = "nanoseconds";
    };

    extern Settings g_settings;

}
#endif //SENECA_SETTINGS_H
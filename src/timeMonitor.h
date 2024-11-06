#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H
#include "event.h"
#include "logger.h"

#include <chrono>
using namespace std;
namespace seneca
{
	class TimeMonitor
	{
		const char* m_event_name;
		std::chrono::steady_clock::time_point m_start{};

	public:
		void startEvent(const char* name);
		Event stopEvent();
	};

}
#endif // TIMEMONITOR_H

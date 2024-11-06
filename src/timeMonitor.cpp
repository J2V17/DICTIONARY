#include "settings.h"
#include "event.h"
#include "timeMonitor.h"

namespace seneca
{
	//start of new event
	void TimeMonitor::startEvent(const char* name)
	{
		m_event_name = name;
		m_start = chrono::steady_clock::now();
	}

	Event TimeMonitor::stopEvent()
	{
		//finding end time
		//std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		auto end = std::chrono::steady_clock::now();
		//calculate in nanoseconds
		chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - m_start);
		return Event(m_event_name, duration);
	}
}
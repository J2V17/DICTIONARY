#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H

#include <iostream>
#include "event.h"
#include <cstddef>   // Include this for size_t

namespace seneca
{
	class Logger
	{
		Event* m_event{};
		size_t m_size;
		//array size or cap
		//size_t m_capacity;

	public:
		Logger();
		~Logger();
		//disable
		Logger(const Logger&);
		Logger& operator=(const Logger&) = delete;
		//move
		Logger(Logger&&) noexcept;
		Logger& operator= (Logger&&) noexcept;
		void addEvent(const Event& event);

		friend std::ostream& operator<<(std::ostream& os, const Logger& log);

	};

}


#endif // LOGGER_H

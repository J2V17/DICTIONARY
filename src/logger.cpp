#include <iostream>
#include <iomanip>
#include "logger.h"
#include "event.h"
#include "settings.h"

using namespace std;
namespace seneca
{
	Logger::Logger()
	{
		m_event = nullptr;
		m_size = 0;
		//m_capacity = 0;
	}

	Logger::~Logger()
	{
		delete[] m_event;
		m_event = nullptr;
		m_size = 0;
		//m_capacity = 0;
	}
	//move constructor
	Logger::Logger(Logger&& other)noexcept
	{
		m_event = other.m_event;
		m_size = other.m_size;
		//m_capacity = other.m_capacity;

		other.m_event = nullptr;
		other.m_size = 0;
		//other.m_capacity = 0;
	}
	Logger& Logger::operator=(Logger&& other)noexcept
	{
		if (this != &other)
		{
			delete[]m_event;
			m_event = other.m_event;
			//m_capacity = other.m_capacity;
			m_size = other.m_size;

			other.m_event = nullptr;
			other.m_size = 0;
			//other.m_capacity = 0;
			return *this;
		}


		return *this;
	}


	void Logger::addEvent(const Event& event)
	{
		/*
		if (m_size >= m_capacity)
		{
			size_t new_capacity=0;
			//is the capacity zero
			if (m_capacity == 0)
			{
				new_capacity = 1;
			}
			else
				//increase it by double the original capacity
			{
				new_capacity = m_capacity * 2;
			}
			*///so store new capacity and create new
		Event* addedEvent = new Event[m_size + 1];
		//
		//
		//
		for (size_t i = 0; i < m_size; i++)
		{

			addedEvent[i] = m_event[i];
		}
		addedEvent[m_size] = event;
		m_size++;
		delete[] m_event;
		m_event = addedEvent;
		//m_capacity = new_capacity;


	}
	//new event after capacity has been cleared
	//m_event[m_size++] = event;


	std::ostream& operator<<(ostream& os, const Logger& log)
	{
		for (int i = 0; i < log.m_size; i++)
		{
			os << log.m_event[i] << endl;
		}
		return os;
	}

}
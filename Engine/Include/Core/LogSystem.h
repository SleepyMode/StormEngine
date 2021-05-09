
#pragma once

#include <vector>
#include <string>
#include "Core/Platform.h"
#include "Core/ILogListener.h"

class LogSystem
{
public:
	LogSystem() = delete;

	static void write(std::string message);

	template <typename T>
	inline static bool hasListener();

	template <typename T>
	inline static bool addListener(bool allowDuplicates = false);

	template <typename T>
	inline static void removeListener();

	template <typename T>
	inline static T* getListener();

private:
	static std::vector<ILogListener*> listeners;
};

template<typename T>
inline bool LogSystem::hasListener()
{
	for (auto listener : this->listeners)
	{
		if (dynamic_cast<T*>(listener))
			return true;
	}

	return false;
}

template<typename T>
inline bool LogSystem::addListener(bool allowDuplicates)
{
	if (!allowDuplicates)
	{
		if (LogSystem::hasListener<T>())
			return false;
	}

	LogSystem::listeners.push_back(reinterpret_cast<ILogListener*>(new T()));
	return true;
}

template <typename T>
inline void LogSystem::removeListener()
{
	for (auto it = LogSystem::listeners.begin(); it != LogSystem::listeners.end(); ++it)
	{
		if (dynamic_cast<T*>(*it))
		{
			LogSystem::listeners.erase(it);
			break;
		}
	}
}

template<typename T>
inline T* LogSystem::getListener()
{
	for (auto listener : LogSystem::listeners)
	{
		T* castListener = dynamic_cast<T*>(listener);
		if (castListener != nullptr)
			return castListener;
	}

	return nullptr;
}

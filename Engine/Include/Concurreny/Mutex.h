
#pragma once

#include "Wrappers/Windows.h"

//
// We should look into 
//
#if SE_OS_LINUX
#	include <pthread.h>
#	include <errno.h>
#elif !SE_OS_WINDOWS
#	error "[Storm Engine] Mutexes are not supported on this OS yet."
#endif

class Mutex
{
public:
	Mutex();
	~Mutex();

	void lock();
	void unlock();
	bool tryLock();

private:
#if SE_OS_WINDOWS
	CRITICAL_SECTION criticalSection;
#elif SE_OS_LINUX
	pthread_mutex_t threadMutex;
#endif
};

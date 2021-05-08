
#pragma once

#include "Core/Platform.h"
#include "Concurreny/Mutex.h"

class ScopedMutex
{
public:
	FORCEINLINE ScopedMutex(Mutex* mutex)
	{
		this->mutex = mutex;
		this->mutex->lock();
	}

	FORCEINLINE ~ScopedMutex()
	{
		this->mutex->unlock();
		this->mutex = nullptr;
	}

private:
	Mutex* mutex;
};

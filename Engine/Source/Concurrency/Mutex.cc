
#include "Concurreny/Mutex.h"
#include "Core/Config.h"

#if SE_OS_WINDOWS
Mutex::Mutex()
{
	//
	// Context switching to kernel makes this a bit heavy on performance.
	// Perhaps we should place a fair warning on Mutex and ScopedMutex docs.
	//
	InitializeCriticalSection(&this->criticalSection);
	SetCriticalSectionSpinCount(&this->criticalSection, SE_CS_SPIN_COUNT);
}

Mutex::~Mutex()
{
	//
	// Same with the constructor. Context switching to kernel makes this heavy.
	//
	DeleteCriticalSection(&this->criticalSection);
}

void Mutex::lock()
{
	EnterCriticalSection(&this->criticalSection);
}

void Mutex::unlock()
{
	LeaveCriticalSection(&this->criticalSection);
}

bool Mutex::tryLock()
{
	return static_cast<bool>(TryEnterCriticalSection(&this->criticalSection));
}
#elif SE_OS_LINUX
Mutex::Mutex()
{
	pthread_mutex_init(&this->threadMutex, nullptr);
}

Mutex::~Mutex()
{
	pthread_mutex_destroy(&this->threadMutex);
}

void Mutex::lock()
{
	pthread_mutex_lock(&this->threadMutex);
}

void Mutex::unlock()
{
	pthread_mutex_unlock(&this->threadMutex);
}

bool Mutex::tryLock()
{
	return (pthread_mutex_trylock(&this->threadMutex) != EBUSY);
}
#endif

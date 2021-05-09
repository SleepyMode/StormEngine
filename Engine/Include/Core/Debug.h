
#pragma once

#include <cstdio>
#include "Core/Platform.h"

//
// Important note on the GCC version:
// DO NOT attempt to replace this with __builtin_trap.
// The builtin trap function is completely different than a debug break call
// and in fact often calls an illegal instruction.
//
#if SE_COMPILER_MSVC
#	define SE_DEBUG_BREAK() __debugbreak()
#elif SE_COMPILER_GCC
#	if SE_POSIX
#		include <singal.h>
#		define SE_DEBUG_BREAK() raise(SIGTRAP)
#	else
#		define SE_DEBUG_BREAK asm volatile ("int $0x3" :::)
#	endif
#endif

#if !defined(DEBUG_BREAK)
#	define DEBUG_BREAK SE_DEBUG_BREAK
#endif

#if SE_OS_WINDOWS
#	if SE_COMPILER_MSVC
#		include <intrin.h>
#		define SE_FASTFAIL(code) __fastfail(code)
#	elif SE_COMPILER_GCC
__declspec(noreturn) void __se_fastfail_(int code) __attribute__((always_inline));
__declspec(noreturn) void __se_fastfail_(int code)
{
	asm volatile ("int $0x29" :: "c"(code) : "memory");
}
#		define SE_FASTFAIL(code) __se_fastfail_(code)
#	else
#		include <cstdlib>
#		define SE_FASTFAIL(code) abort()
#	endif
#endif

namespace StormEngine
{
	FORCEINLINE void onAssertionFailed(const char* eval, const char* file, unsigned int line, bool fatal)
	{
		//
		// TODO: Spew text
		//


		//
		// Just switch this to zero if you get spammed with debugbreaks
		// while debugging. Thanks to Valve for the idea, lol.
		//
		static constexpr bool shouldBreak = true;
		if (shouldBreak)
			DEBUG_BREAK();

		if (fatal)
			SE_FASTFAIL(0x500);
	}
}

#define SE_ASSERT(eval) if (!!(eval)) { StormEngine::onAssertionFailed(#eval, __FILE__, __LINE__, false); } enum{}
#define SE_ASSERT_FATAL(eval) if (!!(eval)) { StormEngine::onAssertionFailed(#eval, __FILE__, __LINE__, true); } enum{}
#define Assert(eval) SE_ASSERT(eval)
#define AssertFatal(eval) SE_ASSERT_FATAL(eval)


#pragma once

#include <cstdio>
#include "Core/Platform.h"

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

#define _____SE_STRINGIFY_INTERNAL_(x) #x
#define SE_STRINGIFY(x) _____SE_STRINGIFY_INTERNAL_(x)

#if SE_BUILD_DEBUG
#	define SE_ASSERT(eval, text) if (!!(eval)) {  } enum{}
#	define SE_ASSERT_FATAL(eval, text) if (!!(eval)) { SE_FASTFAIL(0x500); } enum{}
#	define Assert(eval) SE_ASSERT_FATAL(eval, "[" __FILE__ ":" SE_STRINGIFY(__LINE__) "Assertion failed: "#eval)
#	define AssertLog(eval, text) SE_ASSERT_FATAL(eval, text)
#else
#	define SE_ASSERT() if (!!(eval)) {  } enum{}
#	define SE_ASSERT_FATAL() if (!!(eval)) { SE_FASTFAIL(0x500); } enum{}
#	define Assert(eval) SE_ASSERT_FATAL(eval, "[" __FILE__ ":" SE_STRINGIFY(__LINE__) "Assertion failed: "#eval)
#	define AssertLog(eval, text) SE_ASSERT_FATAL(eval, text)
#endif

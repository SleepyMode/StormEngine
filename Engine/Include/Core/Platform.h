
#pragma once

//
// [Compilers]
//
#if defined(_MSC_VER)
#	define SE_COMPILER_MSVC 1
#elif defined(__GNUC__)
#	define SE_COMPILER_GCC 1
#else
#	error [Storm Engine] Your compiler is not supported.
#endif

//
// [Operating System]
//
#if defined(_WIN32)
#	define SE_OS_WINDOWS 1
#elif defined(__APPLE__)
#	define SE_OS_MAC 1
#elif defined(__linux__)
#	define SE_OS_LINUX 1
#else
#	error [Storm Engine] The target operating system is not supported.
#endif

#if SE_OS_MAC or SE_OS_LINUX
#	define SE_POSIX 1
#endif

//
// [Helpers]
//
#if SE_COMPILER_MSVC
#	define SE_NOVTABLE						__declspec(novtable)
#	define SE_INTERFACE						class SE_NOVTABLE
#	define SE_FORCEINLINE					__forceinline
#	define SE_UNREACHABLE					__assume(0)
#	define SE_UNREFERENCED_PARAMETER(x)		(x)
#elif SE_COMPILER_GCC
#	define SE_NOVTABLE						
#	define SE_INTERFACE						class
#	define SE_FORCEINLINE					__attribute__((always_inline))
#	define SE_UNREACHABLE					__builtin_unreachable()
#	define SE_UNREFERENCED_PARAMETER(x)		(x)
#else
#	define SE_NOVTABLE
#	define SE_INTERFACE
#	define SE_FORCEINLINE					inline
#	define SE_UNREACHABLE
#	define SE_UNREFERENCED_PARAMETER(x)		(x)
#endif

#if !defined(NOVTABLE)
#	define NOVTABLE SE_NOVTABLE
#endif

#if !defined(INTERFACE)
#	define INTERFACE SE_INTERFACE
#endif

#if !defined(FORCEINLINE)
#	define FORCEINLINE SE_FORCEINLINE
#endif

#if !defined(UNREACHABLE)
#	define UNREACHABLE SE_UNREACHABLE
#endif

#if !defined(UNREFRENCED_PARAMETER) and !defined(SE_NO_WIN32_DEFINES)
#	define UNREFERENCED_PARAMETER(x) SE_UNREFERENCED_PARAMETER(x)
#endif

//
// [Build]
//
#if defined(_DEBUG)
#	define SE_BUILD_DEBUG 1
#else
#	define SE_BUILD_RELEASE 1
#endif

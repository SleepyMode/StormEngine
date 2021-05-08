
#pragma once

//
// This is a temporary wrapper to be replaced with <format> in C++20 once it is supported.
// IMAGINE needing Microsoft to actually implement new stuff.
// (jk I love you guys we're still using c++17 anyways).
//

#include <cstdarg>
#include <string>
#include <fmt/core.h>

namespace std
{
	template <class... Args>
	string format(string_view fmt, const Args&... args)
	{
		fmt::format_args fmtArgs = fmt::make_format_args(args...);
		return fmt::vformat(fmt, fmtArgs);
	}
}

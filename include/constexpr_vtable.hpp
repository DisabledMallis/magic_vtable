#pragma once

#ifndef CONSTEXPR_VTABLE_LIB
#define CONSTEXPR_VTABLE_LIB

#include <charconv>
#include <optional>
#include <string>

namespace cvft
{
	template<auto func>
	constexpr std::optional<size_t> get_virtual_index_msvc()
	{
		std::string match = "::`vcall'{";
		const std::string fstr = __FUNCSIG__;
		auto pos = fstr.find("::`vcall'{");
		if (pos == std::string::npos)
			return std::nullopt;

		std::string offset_str = fstr.substr(pos);
		auto terminate = offset_str.find('}');
		if (terminate == std::string::npos)
			return std::nullopt;

		offset_str = offset_str.substr(match.size(), terminate);
		size_t offset;
		auto result = std::from_chars(offset_str.data(), offset_str.data() + offset_str.size(), offset);

		if (result.ec == std::errc{})
			return offset / sizeof(size_t);
		return std::nullopt;
	}

	template<auto func>
	constexpr std::optional<size_t> get_virtual_index()
	{
#if _MSC_VER && !__INTEL_COMPILER
		return get_virtual_index_msvc<func>();
#endif
	}
}

#endif
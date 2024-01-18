#pragma once

#ifndef CONSTEXPR_VTABLE_LIB
#define CONSTEXPR_VTABLE_LIB

#include <charconv>
#include <optional>
#include <string>

namespace magic_vft
{
	template<auto func>
	constexpr std::optional<size_t> vtable_index_msvc()
	{
		constexpr std::string_view match = "::`vcall'{";
		constexpr std::string_view fstr = __FUNCSIG__;
		constexpr auto pos = fstr.find("::`vcall'{");
		static_assert(pos != std::string::npos, "'func' is not a virtual function");

		std::string_view offset_str = fstr.substr(pos);
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
	constexpr std::optional<size_t> vtable_index()
	{
#if _MSC_VER && !__INTEL_COMPILER
		return vtable_index_msvc<func>();
#endif
	}
}

#endif
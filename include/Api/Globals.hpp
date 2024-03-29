#pragma once

#define STRINGIZE(x)	  (#x)
#define TO_STRING(x)	  STRINGIZE(x)
#define JOIN_TOKENS(x, y) (x##y)

#pragma region // Compile-time type information! (Thanks to [ https://arduino.stackexchange.com/a/3080 ].)

template <typename TypeT>
struct TypeInfo {
	static const char *name;
}; // Can't be kept in `PROGMEM`...

template <typename TypeT>
const char *TypeInfo<TypeT>::name = "Unknown";

#define TYPE_NAME(var) TypeInfo<typeof(var)>::name
#define MAKE_TYPE_INFO(type) \
	template <>              \
	const char *TypeInfo<type>::name = #type;
#pragma endregion

#pragma region // Global function declarations.
// void (*restart)(void) = 0;
#pragma endregion

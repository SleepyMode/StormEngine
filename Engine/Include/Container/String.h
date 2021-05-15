
#pragma once

#include <cstddef>
#include <vector>

class String
{
public:
	String();
	String(char c);
	String(const String& copy);
	String(const char* cstr);
	~String();

	const char* getCString() const;
	std::size_t getLength() const;

	void toUpperCase();
	void toLowerCase();
	void toTitleCase();

	void trim();
	void trimRight();
	void trimLeft();

	bool compare(const String& value) const;
	bool compare(const String& value, std::size_t start) const;
	bool compare(const String& value, std::size_t start, std::size_t end) const;
	bool compare(const char* value) const;
	bool compare(const char* value, std::size_t start) const;
	bool compare(const char* value, std::size_t start, std::size_t end) const;

	bool compareIgnoreCase(const String& value) const;
	bool compareIgnoreCase(const String& value, std::size_t start) const;
	bool compareIgnoreCase(const String& value, std::size_t start, std::size_t end) const;
	bool compareIgnoreCase(const char* value) const;
	bool compareIgnoreCase(const char* value, std::size_t start) const;
	bool compareIgnoreCase(const char* value, std::size_t start, std::size_t end) const;

	char at(std::size_t index) const;
	char& at(std::size_t index);

	void concat(const String& value);
	void concat(const char* value);
	void concat(char value);

	String& sub(std::size_t startPos) const;
	String& sub(std::size_t startPos, std::size_t endPos) const;

	std::vector<String> split(const String& separator) const;
	std::vector<String> split(const char* separator) const;
	std::vector<String> split(char separator) const;

	static String& toUpperCase(const String& value);
	static String& toLowerCase(const String& value);
	static String& toTitleCase(const String& value);

	static String& trim(const String& value);
	static String& trimRight(const String& value);
	static String& trimLeft(const String& value);

	static bool compare(const String& lhs, const String& rhs);
	static bool compare(const String& lhs, const String& rhs, std::size_t start);
	static bool compare(const String& lhs, const String& rhs, std::size_t start, std::size_t end);
	static bool compare(const String& lhs, const char* rhs);
	static bool compare(const String& lhs, const char* rhs, std::size_t start);
	static bool compare(const String& lhs, const char* rhs, std::size_t start, std::size_t end);
	static bool compare(const char* lhs, const String& rhs);
	static bool compare(const char* lhs, const String& rhs, std::size_t start);
	static bool compare(const char* lhs, const String& rhs, std::size_t start, std::size_t end);

	static bool compareIgnoreCase(const String& lhs, const String& rhs);
	static bool compareIgnoreCase(const String& lhs, const String& rhs, std::size_t start);
	static bool compareIgnoreCase(const String& lhs, const String& rhs, std::size_t start, std::size_t end);
	static bool compareIgnoreCase(const String& lhs, const char* rhs);
	static bool compareIgnoreCase(const String& lhs, const char* rhs, std::size_t start);
	static bool compareIgnoreCase(const String& lhs, const char* rhs, std::size_t start, std::size_t end);
	static bool compareIgnoreCase(const char* lhs, const String& rhs);
	static bool compareIgnoreCase(const char* lhs, const String& rhs, std::size_t start);
	static bool compareIgnoreCase(const char* lhs, const String& rhs, std::size_t start, std::size_t end);

	static char at(const String& value, std::size_t index);
	static char& at(String& value, std::size_t index);

	static void concat(String& lhs, const String& rhs);
	static void concat(String& lhs, const char* rhs);
	static void concat(String& lhs, char rhs);

	static String& sub(const String& value, std::size_t startPos);
	static String& sub(const String& value, std::size_t startPos, std::size_t endPos);

	static std::vector<String> split(const String& value, String separator);
	static std::vector<String> split(const String& value, const char* separator);
	static std::vector<String> split(const String& value, char separator);

	char	operator[](std::size_t index) const;
	char&	operator[](std::size_t index);
	String& operator= (const String& value);
	String& operator= (const char* value);
	String& operator= (char value);
	String& operator+=(const String& value);
	String& operator+=(const char* value);
	String& operator+=(char value);

	friend inline String operator+(const String& lhs, const String& rhs);
	friend inline String operator+(const String& lhs, const char* rhs);
	friend inline String operator+(const String& lhs, char rhs);
	friend inline String operator+(const char* lhs, const String& rhs);
	friend inline String operator+(char lhs, const String& rhs);

	friend inline bool operator==(const String& lhs, const String& rhs);
	friend inline bool operator==(const String& lhs, const char* rhs);
	friend inline bool operator==(const char* lhs, const String& rhs);
	friend inline bool operator==(const String& lhs, char rhs);
	friend inline bool operator==(char lhs, const String& rhs);
	friend inline bool operator!=(const String& lhs, const String& rhs);
	friend inline bool operator!=(const String& lhs, const char* rhs);
	friend inline bool operator!=(const char* lhs, const String& rhs);
	friend inline bool operator!=(const String& lhs, char rhs);
	friend inline bool operator!=(char lhs, const String& rhs);

private:
	char* data;
	std::size_t length;
};

inline String operator+(const String& lhs, const String& rhs)
{
	String string(lhs);
	string.concat(rhs);

	return string;
}

inline String operator+(const String& lhs, const char* rhs)
{
	String string(lhs);
	string.concat(rhs);

	return string;
}

inline String operator+(const String& lhs, char rhs)
{
	String string(lhs);
	string.concat(rhs);

	return string;
}

inline String operator+(const char* lhs, const String& rhs)
{
	String string(lhs);
	string.concat(rhs);

	return string;
}

inline String operator+(char lhs, const String& rhs)
{
	String string(lhs);
	string.concat(rhs);

	return string;
}

inline bool operator==(const String& lhs, const String& rhs)
{
	return lhs.compare(rhs);
}

inline bool operator==(const String& lhs, const char* rhs)
{
	return lhs.compare(rhs);
}

inline bool operator==(const char* lhs, const String& rhs)
{
	return rhs.compare(lhs);
}

inline bool operator==(const String& lhs, char rhs)
{
	return lhs.compare(rhs);
}

inline bool operator==(char lhs, const String& rhs)
{
	return rhs.compare(lhs);
}

inline bool operator!=(const String& lhs, const String& rhs)
{
	return !lhs.compare(rhs);
}

inline bool operator!=(const String& lhs, const char* rhs)
{
	return !lhs.compare(rhs);
}

inline bool operator!=(const char* lhs, const String& rhs)
{
	return !rhs.compare(lhs);
}

inline bool operator!=(const String& lhs, char rhs)
{
	return !lhs.compare(rhs);
}

inline bool operator!=(char lhs, const String& rhs)
{
	return !rhs.compare(lhs);
}

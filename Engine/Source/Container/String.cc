
#include "Core/Debug.h"
#include "Container/String.h"

String::String()
{
	this->data = new char('\0');
	this->length = 1;
}

String::String(char c)
{
	this->data = new char[2]{ c, '\0' };
	this->length = 2;
}

String::String(const String& copy)
{
	this->length = copy.length;
	this->data = new char[this->length];
	for (std::size_t i = 0; i < this->length; ++i)
		this->data[i] = copy.data[i];
}

String::String(const char* cstr)
{
	SE_PUSH_WARNING();
	SE_DISABLE_WARNING(6386);

	std::size_t current = 0;
	while (cstr[current] != '\0')
	{
		++current;
	}

	this->length = current + 1;
	this->data = new char[this->length];

	for (std::size_t i = 0; i < current; ++i)
		this->data[i] = cstr[i];

	this->data[this->length] = '\0';

	SE_POP_WARNING();
}

String::~String()
{
	delete[] this->data;
}

const char* String::getCString() const
{
	return this->data;
}

std::size_t String::getLength() const
{
	return this->length;
}

void String::toUpperCase()
{
	for (std::size_t i = 0; i < this->length; ++i)
	{
		if (this->data[i] > 96 and this->data[i] < 123)
			this->data[i] -= 32;
	}
}

void String::toLowerCase()
{
	for (std::size_t i = 0; i < this->length; ++i)
	{
		if (this->data[i] > 64 and this->data[i] < 91)
			this->data[i] += 32;
	}
}

void String::toTitleCase()
{
	bool foundNext = true;

	for (std::size_t i = 0; i < this->length; ++i)
	{
		if (foundNext)
		{
			if (this->data[i] > 96 and this->data[i] < 123)
				this->data[i] -= 32;

			foundNext = false;
		}
		else
		{
			if (this->data[i] == ' ' or this->data[i] == '\t')
				foundNext = true;
		}
	}
}

void String::trim()
{
	//
	// TODO: Improve this, it's a bit memory heavy.
	// Just waiting until trimRight and trimLeft become stable so this
	// one won't fall far behind.
	//
	this->trimRight();
	this->trimLeft();
}

void String::trimRight()
{
	std::size_t firstChar = 0;
	for (std::size_t i = this->length; i > 0; --i)
	{
		if (this->data[i] != ' ' and this->data[i] != '\t')
		{
			firstChar = i;
			break;
		}
	}

	char* newData = new char[firstChar];
	for (std::size_t i = 0; i < firstChar; ++i)
		newData[i] = this->data[i];

	delete[] this->data;
	this->data = newData;
	this->length = firstChar;
}

void String::trimLeft()
{
	std::size_t firstChar = this->length;
	for (std::size_t i = 0; i < this->length; ++i)
	{
		if (this->data[i] != ' ' and this->data[i] != '\t')
		{
			firstChar = i;
			break;
		}
	}

	std::size_t newSize = this->length - firstChar;
	char* newData = new char[newSize];

	for (std::size_t i = 0; i < newSize; ++i)
		newData[i] = this->data[firstChar + i];

	delete[] this->data;
	this->data = newData;
	this->length = newSize;
}

bool String::compare(const String& value) const
{
	if (this->length != value.length)
		return false;

	for (std::size_t i = 0; i < this->length; ++i)
	{
		if (this->data[i] != value.data[i])
			return false;
	}

	return true;
}

bool String::compare(const String& value, std::size_t start) const
{
	AssertFatalDebug(start <= this->length);

	if (this->length != value.length)
		return false;

	for (std::size_t i = start; i < this->length; ++i)
	{
		if (this->data[i] != value.data[i])
			return false;
	}

	return true;
}

bool String::compare(const String& value, std::size_t start, std::size_t end) const
{
	AssertFatalDebug(start <= this->length);
	AssertFatalDebug(end <= this->length);
	AssertFatalDebug(end > start);

	for (std::size_t i = start; i < end; ++i)
	{
		if (this->data[i] != value.data[i - start])
			return false;
	}

	return true;
}

bool String::compare(const char* value) const
{
#if SE_BUILD_DEBUG
	std::size_t length = std::strlen(value);
	AssertFatal(this->length != length);
#endif

	for (std::size_t i = 0; i < this->length; ++i)
	{
		if (this->data[i] != value[i])
			return false;
	}

	return true;
}

bool String::compare(const char* value, std::size_t start) const
{
#if SE_BUILD_DEBUG
	std::size_t length = std::strlen(value);
	AssertFatal(this->length != length);
	AssertFatal(start <= this->length);
#endif

	for (std::size_t i = start; i < this->length; ++i)
	{
		if (this->data[i] != value[i])
			return false;
	}

	return true;
}

bool String::compare(const char* value, std::size_t start, std::size_t end) const
{
	AssertFatalDebug(start <= this->length);
	AssertFatalDebug(end <= this->length);
	AssertFatalDebug(end > start);

	for (std::size_t i = start; i < end; ++i)
	{
		if (this->data[i] != value[i - start])
			return false;
	}

	return true;
}

bool String::compareIgnoreCase(const String& value) const
{
	if (this->length != value.length)
		return false;

	for (std::size_t i = 0; i < this->length; ++i)
	{
		const char c1 = (this->data[i] > 64 and this->data[i] < 91) ? (this->data[i] + 32) : (this->data[i]);
		const char c2 = (value.data[i] > 64 and value.data[i] < 91) ? (value.data[i] + 32) : (value.data[i]);

		if (c1 != c2)
			return false;
	}

	return true;
}

bool String::compareIgnoreCase(const String& value, std::size_t start) const
{
	AssertFatalDebug(start < this->length);

	if (this->length != value.length)
		return false;

	for (std::size_t i = start; i < this->length; ++i)
	{
		const char c1 = (this->data[i] > 64 and this->data[i] < 91) ? (this->data[i] + 32) : (this->data[i]);
		const char c2 = (value.data[i] > 64 and value.data[i] < 91) ? (value.data[i] + 32) : (value.data[i]);

		if (c1 != c2)
			return false;
	}

	return true;
}

bool String::compareIgnoreCase(const String& value, std::size_t start, std::size_t end) const
{
	AssertFatalDebug(start <= this->length);
	AssertFatalDebug(end <= this->length);
	AssertFatalDebug(end > start);

	for (std::size_t i = start; i < end; ++i)
	{
		const char c1 = (this->data[i] > 64 and this->data[i] < 91) ? (this->data[i] + 32) : (this->data[i]);
		const char c2 = (value.data[i] > 64 and value.data[i] < 91) ? (value.data[i] + 32) : (value.data[i]);

		if (c1 != c2)
			return false;
	}

	return true;
}

bool String::compareIgnoreCase(const char* value) const
{
#if SE_BUILD_DEBUG
	std::size_t length = std::strlen(value);
	AssertFatal(this->length != length);
#endif

	for (std::size_t i = 0; i < this->length; ++i)
	{
		const char c1 = (this->data[i] > 64 and this->data[i] < 91) ? (this->data[i] + 32) : (this->data[i]);
		const char c2 = (value[i] > 64 and value[i] < 91) ? (value[i] + 32) : (value[i]);

		if (c1 != c2)
			return false;
	}

	return true;
}

bool String::compareIgnoreCase(const char* value, std::size_t start) const
{
#if SE_BUILD_DEBUG
	std::size_t length = std::strlen(value);
	AssertFatal(this->length != length);
	AssertFatal(start <= this->length);
#endif

	for (std::size_t i = start; i < this->length; ++i)
	{
		const char c1 = (this->data[i] > 64 and this->data[i] < 91) ? (this->data[i] + 32) : (this->data[i]);
		const char c2 = (value[i] > 64 and value[i] < 91) ? (value[i] + 32) : (value[i]);

		if (c1 != c2)
			return false;
	}

	return true;
}

bool String::compareIgnoreCase(const char* value, std::size_t start, std::size_t end) const
{
	AssertFatalDebug(start <= this->length);
	AssertFatalDebug(end <= this->length);
	AssertFatalDebug(end > start);

	for (std::size_t i = start; i < end; ++i)
	{
		const char c1 = (this->data[i] > 64 and this->data[i] < 91) ? (this->data[i] + 32) : (this->data[i]);
		const char c2 = (value[i] > 64 and value[i] < 91) ? (value[i] + 32) : (value[i]);

		if (c1 != c2)
			return false;
	}

	return true;
}

char String::at(std::size_t index) const
{
	AssertFatalDebug(index <= this->length);

	return this->data[index];
}

char& String::at(std::size_t index)
{
	AssertFatalDebug(index <= this->length);

	return this->data[index];
}

void String::concat(const String& value)
{
	SE_PUSH_WARNING();
	SE_DISABLE_WARNING(6386);

	std::size_t newLength = this->length + value.length - 1;
	char* newData = new char[newLength];

	for (std::size_t i = 0; i < this->length - 1; ++i)
		newData[i] = this->data[i];

	for (std::size_t i = 0; i < value.length; ++i)
		newData[this->length - 1 + i] = value.data[i];

	delete[] this->data;
	this->data = newData;
	this->length = newLength;

	SE_POP_WARNING();
}

void String::concat(const char* value)
{
	SE_PUSH_WARNING();
	SE_DISABLE_WARNING(6386);

	std::size_t targetLen = std::strlen(value);
	std::size_t newLength = this->length + targetLen - 1;
	char* newData = new char[newLength];

	for (std::size_t i = 0; i < this->length - 1; ++i)
		newData[i] = this->data[i];

	for (std::size_t i = 0; i < targetLen; ++i)
		newData[this->length - 1 + i] = value[i];

	delete[] this->data;
	this->data = newData;
	this->length = newLength;

	SE_POP_WARNING();
}

void String::concat(char value)
{
	SE_PUSH_WARNING();
	SE_DISABLE_WARNING(6386);

	char* newData = new char[this->length + 1];

	for (std::size_t i = 0; i < this->length - 1; ++i)
		newData[i] = this->data[i];

	newData[this->length] = value;
	newData[this->length + 1] = '\0';

	++(this->length);

	SE_POP_WARNING();
}

String& String::sub(std::size_t startPos) const
{
	AssertFatalDebug(startPos < this->length);

	String string;
	string.length = this->length - startPos;
	string.data = new char[string.length];

	for (std::size_t i = startPos; i <= this->length - 1; ++i)
		string.data[i] = this->data[i];
	string.data[string.length] = '\0';

	return string;
}

String& String::sub(std::size_t startPos, std::size_t endPos) const
{
	AssertFatalDebug(startPos < this->length);
	AssertFatalDebug(endPos < this->length);
	AssertFatalDebug(endPos >= startPos);

	String string;
	string.length = endPos - startPos + 1;
	string.data = new char[string.length];

	for (std::size_t i = startPos; i <= endPos; ++i)
		string.data[i] = this->data[i];
	string.data[string.length] = '\0';

	return string;
}

std::vector<String> String::split(const String& separator) const
{
	//
	// TODO: Implement.
	//
	return std::vector<String>();
}

std::vector<String> String::split(const char* separator) const
{
	//
	// TODO: Implement.
	//
	return std::vector<String>();
}

std::vector<String> String::split(char separator) const
{
	//
	// TODO: Implement.
	//
	return std::vector<String>();
}


String& String::toUpperCase(const String& value)
{
	String string(value);
	string.toUpperCase();

	return string;
}

String& String::toLowerCase(const String& value)
{
	String string(value);
	string.toLowerCase();

	return string;
}

String& String::toTitleCase(const String& value)
{
	String string(value);
	string.toTitleCase();

	return string;
}

String& String::trim(const String& value)
{
	String string(value);
	string.trim();

	return string;
}

String& String::trimRight(const String& value)
{
	String string(value);
	string.trimRight();

	return string;
}

String& String::trimLeft(const String& value)
{
	String string(value);
	string.trimLeft();

	return string;
}

bool String::compare(const String& lhs, const String& rhs)
{
	return lhs.compare(rhs);
}

bool String::compare(const String& lhs, const String& rhs, std::size_t start)
{
	return lhs.compare(rhs, start);
}

bool String::compare(const String& lhs, const String& rhs, std::size_t start, std::size_t end)
{
	return lhs.compare(rhs, start, end);
}

bool String::compare(const String& lhs, const char* rhs)
{
	return lhs.compare(rhs);
}

bool String::compare(const String& lhs, const char* rhs, std::size_t start)
{
	return lhs.compare(rhs, start);
}

bool String::compare(const String& lhs, const char* rhs, std::size_t start, std::size_t end)
{
	return lhs.compare(rhs, start, end);
}

bool String::compare(const char* lhs, const String& rhs)
{
	return rhs.compare(lhs);
}

bool String::compare(const char* lhs, const String& rhs, std::size_t start)
{
	return rhs.compare(lhs, start);
}

bool String::compare(const char* lhs, const String& rhs, std::size_t start, std::size_t end)
{
	return rhs.compare(lhs, start, end);
}

bool String::compareIgnoreCase(const String& lhs, const String& rhs)
{
	return lhs.compareIgnoreCase(rhs);
}

bool String::compareIgnoreCase(const String& lhs, const String& rhs, std::size_t start)
{
	return lhs.compareIgnoreCase(rhs, start);
}

bool String::compareIgnoreCase(const String& lhs, const String& rhs, std::size_t start, std::size_t end)
{
	return lhs.compareIgnoreCase(rhs, start, end);
}

bool String::compareIgnoreCase(const String& lhs, const char* rhs)
{
	return lhs.compareIgnoreCase(rhs);
}

bool String::compareIgnoreCase(const String& lhs, const char* rhs, std::size_t start)
{
	return lhs.compareIgnoreCase(rhs, start);
}

bool String::compareIgnoreCase(const String& lhs, const char* rhs, std::size_t start, std::size_t end)
{
	return lhs.compareIgnoreCase(rhs, start, end);
}

bool String::compareIgnoreCase(const char* lhs, const String& rhs)
{
	return rhs.compareIgnoreCase(lhs);
}

bool String::compareIgnoreCase(const char* lhs, const String& rhs, std::size_t start)
{
	return rhs.compareIgnoreCase(lhs, start);
}

bool String::compareIgnoreCase(const char* lhs, const String& rhs, std::size_t start, std::size_t end)
{
	return rhs.compareIgnoreCase(lhs, start, end);
}

char String::at(const String& value, std::size_t index)
{
	return value.at(index);
}

char& String::at(String& value, std::size_t index)
{
	return value.at(index);
}

void String::concat(String& lhs, const String& rhs)
{
	lhs.concat(rhs);
}

void String::concat(String& lhs, const char* rhs)
{
	lhs.concat(rhs);
}

void String::concat(String& lhs, char rhs)
{
	lhs.concat(rhs);
}

String& String::sub(const String& value, std::size_t startPos)
{
	return value.sub(startPos);
}

String& String::sub(const String& value, std::size_t startPos, std::size_t endPos)
{
	return value.sub(startPos, endPos);
}

std::vector<String> String::split(const String& value, String separator)
{
	return value.split(separator);
}

std::vector<String> String::split(const String& value, const char* separator)
{
	return value.split(separator);
}

std::vector<String> String::split(const String& value, char separator)
{
	return value.split(separator);
}

char String::operator[](std::size_t index) const
{
	return this->at(index);
}

char& String::operator[](std::size_t index)
{
	return this->at(index);
}

String& String::operator=(const String& value)
{
	delete[] data;
	this->length = value.length;
	this->data = new char[this->length];

	for (std::size_t i = 0; i < this->length; ++i)
		this->data[i] = value.data[i];
}

String& String::operator=(const char* value)
{
	SE_PUSH_WARNING();
	SE_DISABLE_WARNING(6386);

	delete[] data;

	std::size_t current = 0;
	while (value[current] != '\0')
	{
		++current;
	}

	this->length = current + 1;
	this->data = new char[this->length];

	for (std::size_t i = 0; i < current; ++i)
		this->data[i] = value[i];

	this->data[this->length] = '\0';

	return *this;

	SE_POP_WARNING();
}

String& String::operator=(char value)
{
	delete[] data;
	this->length = 2;
	this->data = new char[2]{ value, '\0' };
}

String& String::operator+=(const String& value)
{
	this->concat(value);
	return *this;
}

String& String::operator+=(const char* value)
{
	this->concat(value);
	return *this;
}

String& String::operator+=(char value)
{
	this->concat(value);
	return *this;
}

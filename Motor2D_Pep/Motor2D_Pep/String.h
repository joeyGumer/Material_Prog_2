#ifndef _STRING_H_
#define _STRING_H_

#include <string.h>//needed for the string functions as strcpy_s, strcmp, strcat_s
#include <stdio.h>//needed for the printf_s
#include <stdarg.h>//neded for the ,... at the format constructor
#include <assert.h>

#define TMP_STRING_SIZE	4096

class cString
{
private: 
	char* str;
	unsigned int size;

public:

	/*
	Constructors
	*/

	//void
	cString()
	{
		Alloc(1);
		Clear();
	}

	//with size
	cString(unsigned int newSize)
	{
		if (newSize > 0)
			Alloc(newSize);
		else
			Alloc(1);
		
		Clear();
	}

	//copy
	cString(cString& c)
	{
		Alloc(c.size);
		strcpy_s(str, size, c.str);//STRCPY secure version (destiny, size of what you want, origin)
	}

	//I'm not sure about this one
	cString(const char *format, ...)
	{
		size = 0;

		if (format != NULL)
		{
			static char tmp[4096];
			static va_list  ap;

			// Construct the string from variable arguments
			va_start(ap, format);
			int res = vsprintf_s(tmp, 4096, format, ap);
			va_end(ap);

			if (res > 0)
			{
				Alloc(res + 1);
				strcpy_s(str, size, tmp);
			}
		}

		if (size == 0)
		{
			Alloc(1);
			Clear();
		}
	}

	/*
	Destructor
	*/
	~cString()
	{
		if (str != NULL)
			delete[] str;
	}

	/*
	Operators
	*/

	//Compare (for cStrings and char arrays)

	bool operator == (const cString& c) const
	{
		return strcmp(c.str, str) == 0;
	}
	bool operator == (const char* c) const
	{
		if (c != NULL)
			return strcmp(c, str) == 0;
		return false;
	}
	
	bool operator != (const cString& c) const
	{
		return strcmp(c.str, str) != 0;
	}
	bool operator != (const char* c) const
	{
		if (c != NULL)
		{
			return strcmp(c, str) != 0;
		}
		return false;
	}

	//Assgiment
	
	const cString& operator = (const cString& c)
	{
		//the Length()+1 is because length give the legth of the chain, not the memory, the 1 includes the "/0"
		if (c.Length() + 1 > size)
		{
			delete[] str;
			Alloc(c.Length() + 1);
		}
		else
			Clear();

		strcpy_s(str, size, c.str);

		return(*this);
	}
	const cString& operator = (const char* c)
	{
		if (c != NULL)
		{
			if (strlen(c) + 1 > size)
			{
				delete[] str;
				Alloc(strlen(c) + 1);
			}
			else
				Clear();
			
			strcpy_s(str, size, c);
		}
		else
		{
			Clear();
		}

		return(*this);

	}

	//Plus
	const cString& operator += (const cString& c)
	{
		unsigned int newSize = Length() + c.Length() + 1;
		
		if (newSize > size)
		{
			char* tmp = str;
			Alloc(newSize);
			strcpy_s(str, size, tmp);
			delete[] tmp;
		}

		strcat_s(str, size, c.str);

		return(*this);
	}

	const cString& operator += (const char* c)
	{
		if (c != NULL)
		{
			unsigned int newSize = Length() + strlen(c) + 1;

			if (newSize > size)
			{
				char* tmp = str;
				Alloc(newSize);
				strcpy_s(str, size, tmp);
				delete[] tmp;
			}

			strcat_s(str, size, c);
		}

		return(*this);
	}

	/*
	Utils
	*/

	void Clear()
	{
		str[0] = '\0';
	}

	unsigned int Length() const
	{
		return strlen(str);
	}

	unsigned int GetCapacity() const
	{
		return size;
	}

	char* GetString() const
	{
		return str;
	}

private:

	//changes the string size
	void Alloc(unsigned int memSize)
	{
		size = memSize;
		str = new char[size];
	}

public:
	/*
	Methods for exercise 4
	*/
	const cString Prefix(const cString& c)
	{
		assert(Length() + c.Length() < TMP_STRING_SIZE);
		
		char tmp[TMP_STRING_SIZE];
			
		strcpy_s(tmp, TMP_STRING_SIZE, c.str);
		strcat_s(tmp, TMP_STRING_SIZE, str);
		unsigned int need_size = strlen(tmp) + 1;
			
		if (need_size > size)
		{
			delete[] str;
				Alloc(need_size);
		}
		strcpy_s(str, size, tmp);
		
		return(*this);
	}
	
	const cString Prefix(const char* c)
	{
			unsigned int newSize = Length() + strlen(c) + 1;
			
			char* tmp = str;
			Alloc(newSize);

			strcpy_s(str, strlen(c), c);
			strcat_s(str, size, tmp);

			delete[] tmp;
		
			return(*this);
	}
};

#endif //!_
#ifndef MY_STRING_H
#define MY_STRING_H

#include <cstring>

class MyString
{
private:
    char* m_string;
    int   m_length;
public:
    MyString(const char *pstr = "")
    {
        // Lenght of the string
        m_length = std::strlen(pstr) + 1;

        // allocate buffer
        m_string = new char[m_length];

        // copy into internal buffer
        std::strncpy(m_string, pstr, m_length);

        // explicity terminate string
        m_string[m_length - 1] = '\0';
    }

    ~MyString()
    {
        // deallocate buffer
        delete[] m_string;

        // set pointer to null just in case
        m_string = nullptr;
    }

    char* GetString() { return m_string; }
    int   GetLength() { return m_length; }
};

#endif

#ifndef STRING_H_
#define STRING_H_
#include <string>

class String
{
    public:
        String();
        String( const String& );
        String( const std::string& );
        operator const char*() const;
    private:
        std::string str_;
};

#endif

#ifndef DATE_H
#define DATE_H
#include <ostream>
#include <array>

class Date
{
    friend std::ostream &operator<<( std::ostream &, const Date & );
    public:
        Date( int month = 1, int day = 1, int year = 1900 );
        void  setDate( int month, int day, int year);
        Date& operator++();          // prefix operator
        Date  operator++( int );     // postfix operator
        Date& operator+=( int );     // additive assignment operator
        bool  leapYear( int ) const;
        bool  endOfMonth( int ) const;
    private:
        int _day;
        int _month;
        int _year;
        static const std::array<int, 13> days; // days per month
        void _increment(); // utility function
};

#endif

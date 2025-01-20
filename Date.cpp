#include "Date.h"

Side::Date::Date() : year(0), month(0), day(0)
{
}

Side::Date::Date(int y, int m, int d) : year(y), month(m), day(d)
{
}

int Side::Date::getYear() const
{
    return year;
}

void Side::Date::setYear(int y)
{
    year = y;
}

int Side::Date::getMonth() const
{
    return month;
}

void Side::Date::setMonth(int m)
{
    month = m;
}

int Side::Date::getDay() const
{
    return day;
}

void Side::Date::setDay(int d)
{
    day = d;
}

bool Side::Date::operator==(const Date& other) const
{
    return (year == other.year && month == other.month && day == other.day);
}

bool Side::Date::operator!=(const Date& other) const
{
    return !(*this == other);
}

bool Side::Date::operator<(const Date& other) const
{
    if (year != other.year) 
        return year < other.year;
    if (month != other.month) 
        return month < other.month; 
    return day < other.day;
}

bool Side::Date::operator>(const Date& other) const
{
    return other < *this;
}

bool Side::Date::operator<=(const Date& other) const
{
    return !(other < *this);
}

bool Side::Date::operator>=(const Date& other) const
{
    return !(*this < other);
}

ostream& Side::operator<<(ostream& os, const Date& dt)
{
    os << setw(4) << setfill('0') << dt.year << '-' 
        << setw(2) << setfill('0') << dt.month << '-' 
        << setw(2) << setfill('0') << dt.day; 
    return os;
}

istream& Side::operator>>(istream& is, Date& dt)
{
    char sep; 
    is >> dt.year >> sep >> dt.month >> sep >> dt.day; 
    return is;
}

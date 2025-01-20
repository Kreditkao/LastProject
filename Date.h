#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

namespace Side {

    
    class Date {
    private:
        int year;
        int month;
        int day;

    public:
        Date();
        Date(int y, int m, int d);

        int getYear() const;
        void setYear(int y);

        int getMonth() const;
        void setMonth(int m);

        int getDay() const;
        void setDay(int d);

        friend ostream& operator<<(ostream& os, const Date& dt);
        friend istream& operator>>(istream& is, Date& dt);

        bool operator==(const Date& other) const;
        bool operator!=(const Date& other) const;
        bool operator<(const Date& other) const;
        bool operator>(const Date& other) const;
        bool operator<=(const Date& other) const;
        bool operator>=(const Date& other) const;
    };

}

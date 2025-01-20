#include "ChildrenHealthVoucher.h"
using namespace Side;

Tourism::ChildrenHealthVoucher::ChildrenHealthVoucher() : Voucher(), childAge(0), birthCertificate(""), gender("")
{
}

Tourism::ChildrenHealthVoucher::ChildrenHealthVoucher
(int code, const string& surname, const string& resort, 
    int room, const string& type, const Date& checkIn, 
    const Date& checkOut, int persons, double cost, int age, 
    const string& certificate, const string& gender) : 
    Voucher(code, surname, resort, room, type, checkIn, 
        checkOut, persons, cost), childAge(age), 
    birthCertificate(certificate), gender(gender)
{
}

int Tourism::ChildrenHealthVoucher::getChildAge() const
{
    return childAge;
}

string Tourism::ChildrenHealthVoucher::getBirthCertificate() const
{
    return birthCertificate;
}

string Tourism::ChildrenHealthVoucher::getGender() const
{
    return gender;
}

void Tourism::ChildrenHealthVoucher::printDetails() const
{
    Voucher::printDetails(); // Виклик методу батьківського класу для виводу загальних деталей 
    // Вивід специфічних полів путівки для дітей 
    cout << "Child Age: " << childAge << 
        ", Birth Certificate: " << birthCertificate << 
        ", Gender: " << gender << endl;
}

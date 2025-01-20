#include "ForeignVoucher.h"
using namespace Side;

Tourism::ForeignVoucher::ForeignVoucher() : Voucher(), passportNumber(""), insurancePolicy("")
{
}

Tourism::ForeignVoucher::ForeignVoucher(int code, 
    const string& surname, const string& resort, 
    int room, const string& type, 
    const Date& checkIn, const Date& checkOut, 
    int persons, double cost, const string& passport, 
    const string& insurance) : 
    Voucher(code, surname, resort, room, type, checkIn, 
        checkOut, persons, cost), passportNumber(passport), 
    insurancePolicy(insurance)
{

}

string Tourism::ForeignVoucher::getPassportNumber() const
{
    return passportNumber;
}

string Tourism::ForeignVoucher::getInsurancePolicy() const
{
    return insurancePolicy;
}

void Tourism::ForeignVoucher::printDetails() const
{
    Voucher::printDetails(); 
    // Викликаємо базову реалізацію 
    cout << "Passport Number: " << passportNumber << 
        ", Insurance Policy: " << insurancePolicy << endl;
}

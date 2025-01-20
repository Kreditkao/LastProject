#include "SanatoriumVoucher.h"
using namespace Side;

Tourism::SanatoriumVoucher::SanatoriumVoucher()
{
}

Tourism::SanatoriumVoucher::SanatoriumVoucher
(int code, const string& surname, const string& resort, 
    int room, const string& type, const Date& checkIn, 
    const Date& checkOut, int persons, double cost, 
    const string& policy, const string& diagnosis, 
    const string& referral) : 
    Voucher(code, surname, resort, room, type, checkIn, checkOut, persons, cost), medicalPolicy(policy), diagnosis(diagnosis), referral(referral) 
{
}

string Tourism::SanatoriumVoucher::getMedicalPolicy() const
{
    return medicalPolicy;
}

string Tourism::SanatoriumVoucher::getDiagnosis() const
{
    return diagnosis;
}

string Tourism::SanatoriumVoucher::getReferral() const
{
    return referral;
}

void Tourism::SanatoriumVoucher::printDetails() const
{
    Voucher::printDetails(); // Виклик методу батьківського класу для виводу загальних деталей 
    // Вивід специфічних полів санаторної путівки 
    cout << "Medical Policy: " << medicalPolicy 
        << ", Diagnosis: " << diagnosis
        << ", Referral: " << referral << endl;
}

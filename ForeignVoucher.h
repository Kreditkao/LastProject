#pragma once
#include <iostream>
#include "Voucher.h"

using namespace std;

namespace Tourism {

    // Клас ForeignVoucher, що успадковує клас Voucher
    class ForeignVoucher : public Voucher {
    private:
        string passportNumber;
        string insurancePolicy;

    public:
        // Конструктор за замовчуванням
        ForeignVoucher();

        // Параметризований конструктор
        ForeignVoucher(int code, const string& surname, const string& resort, int room, const string& type,
            const Date& checkIn, const Date& checkOut, int persons, double cost,
            const string& passport, const string& insurance);

        // Геттери для отримання значень приватних членів
        string getPassportNumber() const;
        string getInsurancePolicy() const;

        // Перевизначення віртуальної функції для друку деталей путівки
        void printDetails() const override;
    };

}

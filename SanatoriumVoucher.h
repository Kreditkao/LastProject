#pragma once
#include <iostream>
#include "Voucher.h"

using namespace std;

namespace Tourism {

    // Клас SanatoriumVoucher, який успадковує батьківський клас Voucher
    class SanatoriumVoucher : public Voucher {
    private:
        string medicalPolicy;  // Медичний поліс
        string diagnosis;      // Діагноз
        string referral;       // Направлення

    public:
        // Конструктор за замовчуванням
        SanatoriumVoucher();

        // Параметризований конструктор
        SanatoriumVoucher(int code, const string& surname, const string& resort, int room, const string& type,
            const Date& checkIn, const Date& checkOut, int persons, double cost,
            const string& policy, const string& diagnosis, const string& referral);

        // Аксесори для доступу до приватних полів
        string getMedicalPolicy() const;
        string getDiagnosis() const;
        string getReferral() const;

        // Перевизначений метод для виводу деталей путівки
        void printDetails() const override;
    };

}

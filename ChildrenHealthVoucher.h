#pragma once
#include <iostream>
#include "Voucher.h"

using namespace std;

namespace Tourism {

    //ChildrenHealthVoucher успадковує Voucher
    class ChildrenHealthVoucher : public Voucher {
    private:
        int childAge;               // Вік дитини
        string birthCertificate;    // Свідоцтво про народження
        string gender;              // Стать дитини

    public:
        // Конструктор за замовчуванням
        ChildrenHealthVoucher();

        // Параметризований конструктор
        ChildrenHealthVoucher(int code, const string& surname, const string& resort, int room, const string& type,
            const Date& checkIn, const Date& checkOut, int persons, double cost,
            int age, const string& certificate, const string& gender);

        // Аксесори для доступу до приватних полів
        int getChildAge() const;
        string getBirthCertificate() const;
        string getGender() const;

        // Перевизначений метод для виводу деталей путівки
        void printDetails() const override;
    };

}

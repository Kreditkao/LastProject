#pragma once
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;
using namespace Side;

namespace Tourism {

    // Оголошуємо клас Voucher, який буде базовим для інших типів путівок
    class Voucher {
    protected:
        int voucherCode;            // Код путівки
        string clientSurname;       // Прізвище клієнта
        string resortName;          // Назва курорту
        int roomNumber;             // Номер кімнати
        string accommodationType;   // Тип проживання
        Date checkInDate;           // Дата заїзду
        Date checkOutDate;          // Дата виїзду
        int numberOfPersons;        // Кількість осіб
        double price;               // Вартість путівки

        static int totalVouchers;   // Статичне поле для зберігання загальної кількості путівок

    public:
        // Конструктор за замовчуванням
        Voucher();

        // Параметризований конструктор для ініціалізації всіх членів класу
        Voucher(int code, const string& surname, const string& resort, int room, const string& type,
            const Date& checkIn, const Date& checkOut, int persons, double cost);

        // Віртуальний деструктор для забезпечення правильного видалення об'єктів нащадків
        virtual ~Voucher();

        // Геттери для доступу до приватних та захищених членів класу
        int getVoucherCode() const;
        string getClientSurname() const;
        string getResortName() const;
        int getRoomNumber() const;
        string getAccommodationType() const;
        Date getCheckInDate() const;
        Date getCheckOutDate() const;
        int getNumberOfPersons() const;
        double getPrice() const;

        // Статичний метод для отримання загальної кількості путівок
        static int getTotalVouchers();

        // Віртуальний метод для виведення деталей путівки
        virtual void printDetails() const;
    };

}

#include "Voucher.h"
using namespace std;
using namespace Side;

// Ініціалізація статичного поля (по замовчуванню це нуль)
int Tourism::Voucher::totalVouchers;

Tourism::Voucher::Voucher() : voucherCode(0), clientSurname(""), resortName(""), roomNumber(0),
accommodationType(""), checkInDate(), checkOutDate(), numberOfPersons(0), price(0.0) {
    ++totalVouchers;  // Збільшуємо кількість путівок при створенні об'єкта
}

Tourism::Voucher::Voucher(int code, const string& surname, const string& resort, 
    int room, const string& type, const Date& checkIn, const Date& checkOut, 
    int persons, double cost) : voucherCode(code), clientSurname(surname), 
    resortName(resort), roomNumber(room), accommodationType(type), 
    checkInDate(checkIn), checkOutDate(checkOut), numberOfPersons(persons), 
    price(cost) 
{
    ++totalVouchers;  // Збільшуємо кількість путівок при створенні об'єкта
}

// Віртуальний деструктор для забезпечення правильного видалення об'єктів нащадків
Tourism::Voucher::~Voucher()
{
    --totalVouchers;  // Зменшуємо кількість путівок при видаленні об'єкта
}

int Tourism::Voucher::getVoucherCode() const
{
    return voucherCode;
}

string Tourism::Voucher::getClientSurname() const
{
    return clientSurname;
}

string Tourism::Voucher::getResortName() const
{
    return resortName;
}

int Tourism::Voucher::getRoomNumber() const
{
    return roomNumber;
}

string Tourism::Voucher::getAccommodationType() const
{
    return accommodationType;
}

Date Tourism::Voucher::getCheckInDate() const
{
    return checkInDate;
}

Date Tourism::Voucher::getCheckOutDate() const
{
    return checkOutDate;
}

int Tourism::Voucher::getNumberOfPersons() const
{
    return numberOfPersons;
}

double Tourism::Voucher::getPrice() const
{
    return price;
}

// Статичний метод для отримання загальної кількості путівок
int Tourism::Voucher::getTotalVouchers()
{
    return totalVouchers;
}

// Віртуальний метод для виведення деталей путівки
void Tourism::Voucher::printDetails() const
{
    cout << "Voucher Code: " << voucherCode  // Виведення коду путівки
        << ", Client Surname: " << clientSurname  // Виведення прізвища клієнта
        << ", Resort Name: " << resortName  // Виведення назви курорту
        << ", Room Number: " << roomNumber  // Виведення номера кімнати
        << ", Accommodation Type: " << accommodationType  // Виведення типу проживання
        << ", Check-in Date: " << checkInDate  // Виведення дати заїзду
        << ", Check-out Date: " << checkOutDate  // Виведення дати виїзду
        << ", Number of Persons: " << numberOfPersons  // Виведення кількості осіб
        << ", Price: $" << price << endl;  // Виведення вартості путівки
}

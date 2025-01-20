#include "TourManager.h"

using namespace std;
using namespace Side;
using namespace Tourism;

TourManager::~TourManager() {
    for (Voucher* voucher : vouchers) {
        delete voucher;  // Видалення кожної путівки
    }
}

// Метод для додавання нової путівки до списку
void TourManager::addVoucher(Voucher* voucher) {
    if (voucher == nullptr) {  // Перевірка на нульовий вказівник
        throw invalid_argument("Invalid voucher pointer.");
    }
    vouchers.push_back(voucher);  // Додавання путівки до вектора
    cout << "Voucher added: " << voucher->getVoucherCode() << endl;  // Повідомлення про додавання
}

// Метод для видалення путівки зі списку за кодом путівки
void TourManager::deleteVoucher(int voucherCode) {
    auto it = remove_if(vouchers.begin(), vouchers.end(), [&voucherCode](Voucher* voucher) {
        return voucher->getVoucherCode() == voucherCode;  // Пошук путівки за кодом
        });
    if (it != vouchers.end()) {  // Перевірка, чи знайдено путівку
        for (auto iter = it; iter != vouchers.end(); ++iter) {
            delete* iter;  // Видалення знайденої путівки
        }
        vouchers.erase(it, vouchers.end());  // Видалення путівки зі списку
        cout << "Voucher deleted: " << voucherCode << endl;  // Повідомлення про видалення
    }
    else {
        throw runtime_error("Voucher not found.");  // Викидання виключення, якщо путівку не знайдено
    }
}

// Метод для редагування путівки у списку за кодом путівки
void TourManager::editVoucher(int voucherCode, Voucher* newVoucher) {
    auto it = find_if(vouchers.begin(), vouchers.end(), [&voucherCode](Voucher* voucher) {
        return voucher->getVoucherCode() == voucherCode;  // Пошук путівки за кодом
        });
    if (it != vouchers.end()) {  // Перевірка, чи знайдено путівку
        delete* it;  // Видалення старої путівки
        *it = newVoucher;  // Заміна на нову путівку
        cout << "Voucher edited: " << voucherCode << endl;  // Повідомлення про редагування
    }
    else {
        throw runtime_error("Voucher not found.");  // Викидання виключення, якщо путівку не знайдено
    }
}

// Метод для пошуку путівки за кодом путівки
Voucher* TourManager::searchVoucherByCode(int voucherCode) const {
    auto it = find_if(vouchers.begin(), vouchers.end(), [&voucherCode](Voucher* voucher) {
        return voucher->getVoucherCode() == voucherCode;  // Пошук путівки за кодом
        });
    if (it != vouchers.end()) {  // Перевірка, чи знайдено путівку
        return *it;  // Повернення знайденої путівки
    }
    else {
        throw runtime_error("Voucher not found.");  // Викидання виключення, якщо путівку не знайдено
    }
}

// Метод для пошуку путівок за діапазоном цін
vector<Voucher*> TourManager::searchByPriceRange(double minPrice, double maxPrice) const {
    vector<Voucher*> results;  // Вектор для збереження результатів пошуку
    copy_if(vouchers.begin(), vouchers.end(), back_inserter(results), [minPrice, maxPrice](Voucher* voucher) {
        return voucher->getPrice() >= minPrice && voucher->getPrice() <= maxPrice;  // Умова для пошуку путівок
        });
    return results;  // Повернення вектора з результатами пошуку
}

// Метод для виведення всіх путівок на екран
void TourManager::printAllVouchers() const {
    if (vouchers.empty()) {  // Перевірка, чи є путівки у списку
        cout << "No vouchers available." << endl;  // Повідомлення, якщо путівок немає
        return;
    }

    vector<Voucher*> foreignVouchers;  // Вектор для збереження закордонних путівок
    vector<Voucher*> childrenVouchers;  // Вектор для збереження дитячих путівок
    vector<Voucher*> sanatoriumVouchers;  // Вектор для збереження санаторних путівок

    // Розподіл путівок за категоріями
    for (Voucher* voucher : vouchers) {
        if (dynamic_cast<ForeignVoucher*>(voucher)) {
            foreignVouchers.push_back(voucher);  // Додавання до закордонних путівок
        }
        else if (dynamic_cast<ChildrenHealthVoucher*>(voucher)) {
            childrenVouchers.push_back(voucher);  // Додавання до дитячих путівок
        }
        else if (dynamic_cast<SanatoriumVoucher*>(voucher)) {
            sanatoriumVouchers.push_back(voucher);  // Додавання до санаторних путівок
        }
    }

    // Виведення закордонних путівок
    cout << "\n========== Foreign Vouchers ==========" << endl;
    if (foreignVouchers.empty()) {  // Перевірка, чи є закордонні путівки у списку
        cout << "No foreign vouchers available." << endl;  // Повідомлення, якщо закордонних путівок немає
    }
    else {
        for (Voucher* voucher : foreignVouchers) {
            voucher->printDetails();  // Виведення деталей путівки
            cout << "---------------------------------" << endl;
        }
    }

    // Виведення дитячих путівок
    cout << "\n========== Children Health Vouchers ==========" << endl;
    if (childrenVouchers.empty()) {  // Перевірка, чи є дитячі путівки у списку
        cout << "No children health vouchers available." << endl;  // Повідомлення, якщо дитячих путівок немає
    }
    else {
        for (Voucher* voucher : childrenVouchers) {
            voucher->printDetails();  // Виведення деталей путівки
            cout << "---------------------------------" << endl;
        }
    }

    // Виведення санаторних путівок
    cout << "\n========== Sanatorium Vouchers ==========" << endl;
    if (sanatoriumVouchers.empty()) {  // Перевірка, чи є санаторні путівки у списку
        cout << "No sanatorium vouchers available." << endl;  // Повідомлення, якщо санаторних путівок немає
    }
    else {
        for (Voucher* voucher : sanatoriumVouchers) {
            voucher->printDetails();  // Виведення деталей путівки
            cout << "---------------------------------" << endl;
        }
    }
}

vector<Voucher*> TourManager::getAllVouchers() const {
    // Отримання всіх путівок
    return vouchers;
}

// Функція для автентифікації адміністратора
bool TourManager::authenticateAdmin() {
    string correctUsername = "log123";
    string correctPassword = "pass123";

    string inputUsername;
    string inputPassword;

    cout << "Enter username: ";
    cin >> inputUsername;

    cout << "Enter password: ";
    cin >> inputPassword;

    return (inputUsername == correctUsername && inputPassword == correctPassword);
}

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include "Voucher.h"
#include "ForeignVoucher.h"
#include "SanatoriumVoucher.h"
#include "ChildrenHealthVoucher.h"

using namespace std;
using namespace Tourism;
using namespace Side;


    // Оголошення класу TourManager для управління путівками
    class TourManager {
    private:
        vector<Voucher*> vouchers;  // Вектор вказівників на путівки

    public:
        // Деструктор, що видаляє всі путівки
        ~TourManager();

        // Метод для додавання нової путівки до списку
        void addVoucher(Voucher* voucher);

        // Метод для видалення путівки зі списку за кодом путівки
        void deleteVoucher(int voucherCode);

        // Метод для редагування путівки у списку за кодом путівки
        void editVoucher(int voucherCode, Voucher* newVoucher);

        // Метод для пошуку путівки за кодом путівки
        Voucher* searchVoucherByCode(int voucherCode) const;

        // Метод для пошуку путівок за діапазоном цін
        vector<Voucher*> searchByPriceRange(double minPrice, double maxPrice) const;

        // Метод для виведення всіх путівок на екран
        void printAllVouchers() const;

        // Отримання всіх путівок
        vector<Voucher*> getAllVouchers() const;

        // Функція для автентифікації адміністратора
        bool authenticateAdmin();
    };



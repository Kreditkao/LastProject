#include <iostream>
#include <vector>
#include "Date.h"
#include "Voucher.h"
#include "ForeignVoucher.h"
#include "SanatoriumVoucher.h"
#include "ChildrenHealthVoucher.h"
#include "TourManager.h"

using namespace std;
using namespace Tourism;
using namespace Side;

    /*-----------------------------------------------------------------------------------------------*/
    /*-----------------------------------------------------------------------------------------------*/

    //0 Функція для відображення меню
    void displayMenu() {
        cout << "\nMenu Options:\n";  // Виводимо варіанти меню на екран
        cout << "1. Add Voucher\n";  // Додати путівку
        cout << "2. Edit Voucher\n";  // Редагувати путівку
        cout << "3. Delete Voucher\n";  // Видалити путівку
        cout << "4. Search Voucher by Code\n";  // Пошук путівки за кодом
        cout << "5. Search Vouchers by Price Range\n";  // Пошук путівок за ціновим діапазоном
        cout << "6. Display All Vouchers\n";  // Показати всі путівки
        cout << "7. Save Vouchers to File\n";  // Зберегти путівки до файлу
        cout << "8. Load Vouchers from File\n";  // Завантажити путівки з файлу
        cout << "9. Exit\n";  // Вихід
        cout << "Select an option: ";  // Запит на вибір опції
    }

    //1 Функція для додавання путівки
    void addVoucher(TourManager& manager) {
        int type;
        cout << "Enter Voucher Type (1: Foreign, 2: Sanatorium, 3: Children Health): ";
        cin >> type;

        int code, room, persons, age;
        double price;
        string surname, resort, accommodation, passport, insurance, policy, diagnosis, referral, certificate, gender;
        Date checkIn, checkOut;

        // Введення інформації про путівку
        cout << "Enter Voucher Code: ";
        cin >> code;
        cout << "Enter Client Surname: ";
        cin >> surname;
        cout << "Enter Resort Name: ";
        cin >> resort;
        cout << "Enter Room Number: ";
        cin >> room;
        cout << "Enter Accommodation Type: ";
        cin >> accommodation;
        cout << "Enter Check-in Date (YYYY MM DD): ";
        cin >> checkIn;
        cout << "Enter Check-out Date (YYYY MM DD): ";
        cin >> checkOut;
        cout << "Enter Number of Persons: ";
        cin >> persons;
        cout << "Enter Price: ";
        cin >> price;

        try {
            // Додавання путівки відповідного типу
            switch (type) {
            case 1:
                cout << "Enter Passport Number: ";
                cin >> passport;
                cout << "Enter Insurance Policy: ";
                cin >> insurance;
                manager.addVoucher(new ForeignVoucher(code, surname, resort, room, accommodation, checkIn, checkOut, persons, price, passport, insurance));
                break;
            case 2:
                cout << "Enter Medical Policy: ";
                cin >> policy;
                cout << "Enter Diagnosis: ";
                cin >> diagnosis;
                cout << "Enter Referral: ";
                cin >> referral;
                manager.addVoucher(new SanatoriumVoucher(code, surname, resort, room, accommodation, checkIn, checkOut, persons, price, policy, diagnosis, referral));
                break;
            case 3:
                cout << "Enter Child Age: ";
                cin >> age;
                cout << "Enter Birth Certificate: ";
                cin >> certificate;
                cout << "Enter Gender: ";
                cin >> gender;
                manager.addVoucher(new ChildrenHealthVoucher(code, surname, resort, room, accommodation, checkIn, checkOut, persons, price, age, certificate, gender));
                break;
            default:
                cout << "Invalid voucher type." << endl;  // Невірний тип путівки
                return;
            }
            cout << "Voucher added successfully." << endl;  // Путівку успішно додано
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;  // Виведення повідомлення про помилку
        }
    }

    //2 Функція для редагування путівки
    void editVoucher(TourManager& manager) {
        int code;
        cout << "Enter Voucher Code to Edit: ";
        cin >> code;

        int type;
        cout << "Enter New Voucher Type (1: Foreign, 2: Sanatorium, 3: Children Health): ";
        cin >> type;

        int room, persons, age;
        double price;
        string surname, resort, accommodation, passport, insurance, policy, diagnosis, referral, certificate, gender;
        Date checkIn, checkOut;

        // Введення нової інформації про путівку
        cout << "Enter New Client Surname: ";
        cin >> surname;
        cout << "Enter New Resort Name: ";
        cin >> resort;
        cout << "Enter New Room Number: ";
        cin >> room;
        cout << "Enter New Accommodation Type: ";
        cin >> accommodation;
        cout << "Enter New Check-in Date (YYYY MM DD): ";
        cin >> checkIn;
        cout << "Enter New Check-out Date (YYYY MM DD): ";
        cin >> checkOut;
        cout << "Enter New Number of Persons: ";
        cin >> persons;
        cout << "Enter New Price: ";
        cin >> price;

        try {
            // Редагування путівки відповідного типу
            switch (type) {
            case 1:
                cout << "Enter New Passport Number: ";
                cin >> passport;
                cout << "Enter New Insurance Policy: ";
                cin >> insurance;
                manager.editVoucher(code, new ForeignVoucher(code, surname, resort, room, accommodation, checkIn, checkOut, persons, price, passport, insurance));
                break;
            case 2:
                cout << "Enter New Medical Policy: ";
                cin >> policy;
                cout << "Enter New Diagnosis: ";
                cin >> diagnosis;
                cout << "Enter New Referral: ";
                cin >> referral;
                manager.editVoucher(code, new SanatoriumVoucher(code, surname, resort, room, accommodation, checkIn, checkOut, persons, price, policy, diagnosis, referral));
                break;
            case 3:
                cout << "Enter New Child Age: ";
                cin >> age;
                cout << "Enter New Birth Certificate: ";
                cin >> certificate;
                cout << "Enter New Gender: ";
                cin >> gender;
                manager.editVoucher(code, new ChildrenHealthVoucher(code, surname, resort, room, accommodation, checkIn, checkOut, persons, price, age, certificate, gender));
                break;
            default:
                cout << "Invalid voucher type." << endl;  // Невірний тип путівки
                return;
            }
            cout << "Voucher edited successfully." << endl;  // Путівку успішно відредаговано
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;  // Виведення повідомлення про помилку
        }
    }

    //3 Функція для видалення путівки
    void deleteVoucher(TourManager& manager) {
        int code;
        cout << "Enter Voucher Code to Delete: ";
        cin >> code;

        try {
            manager.deleteVoucher(code);
            cout << "Voucher deleted successfully." << endl;  // Путівку успішно видалено
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;  // Виведення повідомлення про помилку
        }
    }

    //4 Функція для пошуку путівки за кодом
    void searchVoucherByCode(TourManager& manager) {
        int code;
        cout << "Enter Voucher Code to Search: ";
        cin >> code;

        try {
            Voucher* voucher = manager.searchVoucherByCode(code);
            cout << "Voucher found:" << endl;
            voucher->printDetails();
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;  // Виведення повідомлення про помилку
        }
    }

    //7 Функція для збереження путівок у файл
    void saveVouchersToFile(const TourManager& manager) {
        int type;
        cout << "Enter Voucher Type to Save (1: Foreign, 2: Sanatorium, 3: Children Health): ";
        cin >> type;

        string filename;
        switch (type) {
        case 1:
            filename = "foreign_vouchers.txt";
            break;
        case 2:
            filename = "sanatorium_vouchers.txt";
            break;
        case 3:
            filename = "children_vouchers.txt";
            break;
        default:
            cout << "Invalid voucher type." << endl;
            return;
        }

        ofstream file(filename);
        if (!file) {
            cout << "Failed to open file: " << filename << endl;
            return;
        }

        for (Voucher* voucher : manager.getAllVouchers()) {
            if ((type == 1 && dynamic_cast<ForeignVoucher*>(voucher)) ||
                (type == 2 && dynamic_cast<SanatoriumVoucher*>(voucher)) ||
                (type == 3 && dynamic_cast<ChildrenHealthVoucher*>(voucher))) {
                // Записуємо загальні дані путівки до файлу
                file << voucher->getVoucherCode() << " "
                    << voucher->getClientSurname() << " "
                    << voucher->getResortName() << " "
                    << voucher->getRoomNumber() << " "
                    << voucher->getAccommodationType() << " "
                    << voucher->getCheckInDate() << " "
                    << voucher->getCheckOutDate() << " "
                    << voucher->getNumberOfPersons() << " "
                    << voucher->getPrice();

                // Записуємо специфічні поля для кожного типу путівки
                if (auto foreignVoucher = dynamic_cast<ForeignVoucher*>(voucher)) {
                    file << " " << foreignVoucher->getPassportNumber() << " "
                        << foreignVoucher->getInsurancePolicy();
                }
                else if (auto sanatoriumVoucher = dynamic_cast<SanatoriumVoucher*>(voucher)) {
                    file << " " << sanatoriumVoucher->getMedicalPolicy() << " "
                        << sanatoriumVoucher->getDiagnosis() << " "
                        << sanatoriumVoucher->getReferral();
                }
                else if (auto childrenVoucher = dynamic_cast<ChildrenHealthVoucher*>(voucher)) {
                    file << " " << childrenVoucher->getChildAge() << " "
                        << childrenVoucher->getBirthCertificate() << " "
                        << childrenVoucher->getGender();
                }
                file << endl;
            }
        }
        file.close();
        cout << "Vouchers saved successfully to " << filename << endl;
    }

    //8 Функція для завантаження путівок з файлу
    void loadVouchersFromFile(TourManager& manager) {
        int type;
        cout << "Enter Voucher Type to Load (1: Foreign, 2: Sanatorium, 3: Children Health): ";
        cin >> type;

        string filename;
        switch (type) {
        case 1:
            filename = "foreign_vouchers.txt";
            break;
        case 2:
            filename = "sanatorium_vouchers.txt";
            break;
        case 3:
            filename = "children_vouchers.txt";
            break;
        default:
            cout << "Invalid voucher type." << endl;
            return;
        }

        ifstream file(filename);
        if (!file) {
            cout << "Failed to open file: " << filename << endl;
            return;
        }

        int code, room, persons, age;
        double price;
        string surname, resort, accommodation, passport, insurance, policy, diagnosis, referral, certificate, gender;
        Date checkIn, checkOut;

        while (file >> code >> surname >> resort >> room >> accommodation >> checkIn >> checkOut >> persons >> price) {
            if (type == 1) {
                file >> passport >> insurance;
                manager.addVoucher(new ForeignVoucher(code, surname, resort, room, accommodation, checkIn, checkOut, persons, price, passport, insurance));
                cout << "Foreign Voucher loaded: " << code << " " << surname << " " << resort << " " << room << " " << accommodation << " " << checkIn << " " << checkOut << " " << persons << " " << price << " " << passport << " " << insurance << endl;
            }
            else if (type == 2) {
                file >> policy >> diagnosis >> referral;
                manager.addVoucher(new SanatoriumVoucher(code, surname, resort, room, accommodation, checkIn, checkOut, persons, price, policy, diagnosis, referral));
                cout << "Sanatorium Voucher loaded: " << code << " " << surname << " " << resort << " " << room << " " << accommodation << " " << checkIn << " " << checkOut << " " << persons << " " << price << " " << policy << " " << diagnosis << " " << referral << endl;
            }
            else if (type == 3) {
                file >> age >> certificate >> gender;
                manager.addVoucher(new ChildrenHealthVoucher(code, surname, resort, room, accommodation, checkIn, checkOut, persons, price, age, certificate, gender));
                cout << "Children Health Voucher loaded: " << code << " " << surname << " " << resort << " " << room << " " << accommodation << " " << checkIn << " " << checkOut << " " << persons << " " << price << " " << age << " " << certificate << " " << gender << endl;
            }
        }
        file.close();
        cout << "Vouchers loaded successfully from " << filename << endl;
    }

    //5 Функція для пошуку путівок за діапазоном цін
    void searchVouchersByPriceRange(TourManager& manager) {
        double minPrice, maxPrice;
        cout << "Enter Min Price: ";
        cin >> minPrice;
        cout << "Enter Max Price: ";
        cin >> maxPrice;

        try {
            vector<Voucher*> results = manager.searchByPriceRange(minPrice, maxPrice);
            if (results.empty()) {
                cout << "No vouchers found in the given price range." << endl;
            }
            else {
                cout << "Vouchers found:" << endl;
                for (Voucher* voucher : results) {
                    voucher->printDetails();
                    cout << "---------------------------------" << endl;
                }
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    /*-----------------------------------------------------------------------------------------------*/
    /*-----------------------------------------------------------------------------------------------*/


    int main() {
        TourManager manager;  // Створюємо об'єкт менеджера турів

        cout << "Welcome to our Cruise Hotel!" << endl;
        cout << "This is an admin page only, please log in to continue.\n";
        cout << "\n";
        cout << "\n";
        if (!manager.authenticateAdmin()) {
            cout << "Authentication failed. Exiting program..." << endl;
            return 1; // Завершення програми з кодом помилки
        }

        cout << "\n";
        cout << "\n";
        cout << "Great! You are logged in.\n";
        cout << "Greetings admin 1!.\n";
        cout << "\n";
        cout << "Choose what you want to do today.\n";
        cout << "\n";
        cout << "\n";




        // Додавання демонстраційних путівок
        manager.addVoucher(new ForeignVoucher(1, "Ivanov", "Hilton", 101, "Suite", Date(2025, 6, 15), Date(2025, 6, 30), 2, 2000.0, "AB123456", "Yes"));
        manager.addVoucher(new SanatoriumVoucher(2, "Petrov", "Sanatorium Health", 202, "Standard", Date(2025, 7, 1), Date(2025, 7, 15), 1, 1500.0, "Policy123", "Flu", "Referral123"));
        manager.addVoucher(new ChildrenHealthVoucher(3, "Sidorov", "Children's Camp", 303, "Dorm", Date(2025, 8, 1), Date(2025, 8, 10), 3, 1200.0, 12, "BirthCert123", "Male"));
        manager.addVoucher(new ForeignVoucher(4, "Smith", "Ritz", 404, "Deluxe", Date(2025, 9, 1), Date(2025, 9, 15), 2, 3000.0, "CD789012", "Yes"));
        manager.addVoucher(new ForeignVoucher(5, "Johnson", "Marriott", 505, "Executive", Date(2025, 10, 1), Date(2025, 10, 10), 1, 2500.0, "EF456789", "Yes"));
        manager.addVoucher(new SanatoriumVoucher(6, "Brown", "Health Resort", 606, "Premium", Date(2025, 11, 1), Date(2025, 11, 15), 1, 1800.0, "Policy456", "Asthma", "Referral456"));
        manager.addVoucher(new ChildrenHealthVoucher(7, "Taylor", "Youth Camp", 707, "Cabin", Date(2025, 12, 1), Date(2025, 12, 10), 2, 1100.0, 10, "BirthCert456", "Female"));
        manager.addVoucher(new ForeignVoucher(8, "Anderson", "Four Seasons", 808, "Penthouse", Date(2025, 1, 1), Date(2025, 1, 15), 1, 5000.0, "GH012345", "Yes"));

        // Головний цикл меню
        int choice;
        do {
            displayMenu();
            cin >> choice;

            switch (choice) {
            case 1:
                addVoucher(manager);  // Додавання путівки
                break;
            case 2:
                editVoucher(manager);  // Редагування путівки
                break;
            case 3:
                deleteVoucher(manager);  // Видалення путівки
                break;
            case 4:
                searchVoucherByCode(manager);  // Пошук путівки за кодом
                break;
            case 5:
                searchVouchersByPriceRange(manager);  // Пошук путівок за діапазоном цін
                break;
            case 6:
                manager.printAllVouchers();  // Відображення всіх путівок
                break;
            case 7:
                saveVouchersToFile(manager);  // Збереження путівок до файлу
                break;
            case 8:
                loadVouchersFromFile(manager);  // Завантаження путівок з файлу
                break;
            case 9:
                cout << "Exiting program..." << endl;  // Вихід з програми
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;  // Невірний вибір опції
            }
        } while (choice != 9);  // Завершуємо цикл, якщо вибрано опцію виходу

        return 0;  // Завершення програми
    }



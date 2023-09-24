//
// Created by Roman Sherstiuk on 13/05/2023.
//

#ifndef INC_2223L_20C_S27185_PASSWORDMANAGER_H
#define INC_2223L_20C_S27185_PASSWORDMANAGER_H
#include "PasswordGenerator.h"
#include<string>
#include <vector>
#include <iostream>
#include <algorithm>
class PasswordManager {
public:
    struct Password {
        std::string name;
        std::string password;
        std::string category;
        std::string website;
        std::string login;

        friend std::ostream& operator<<(std::ostream& str, const Password pass){
            return str<< pass.name << "\t"<< pass.password << "\t" << pass.category << (pass.website.empty()?"":"\t") << (pass.website.empty()?"":pass.website) << (pass.login.empty()?"":"\t") << (pass.login.empty()?"":pass.login) << std::endl;
        }
    };

private:
    std::vector<Password> passwords;
    std::vector<std::string> categories;
    std::vector<Password> sortedpasswords;


public:

    /**
     * @brief Wyszukiwanie haseł
     * Wyszukiwanie haseł poprzez podanie słowa do poszukiwania i wybrania potrzebnego parametru
     */
    void searchPassword();

    /**
     * @brief Dodawanie nowego hasła
     */
    void setRecord();

    /**
     * @brief Metoda do zwracania hasła które zostało wygenerowane lub samodzielnie wprowadzone
     * @return Hasło do rekordu Password
     */
    std::string setPassword();

    /**
     * @brief Dodawanie nowej kategorii
     */
    void addCategory();

    /**
     * Wewnątrz konstruktora znajduje się kod, który sprawdza, czy wszystkie kategorie z wektora haseł
     * znajdują się w wektorze kategorii, a jeśli nie, to je dodaje
     * @param passwords
     */
    explicit PasswordManager(const std::vector<Password> &passwords);


    static bool sortByName(Password a, Password b);
    static bool sortByCategory(Password a, Password b);
    static bool sortByWebsite(Password a, Password b);
    static bool sortByLogin(Password a, Password b);

    /**
     * Duży switch służący do sortowania według 2 parametrów ustawionych przez użytkownika
     * @param sortOption1 Liczba wprowadzona z metody sortPasswords która określa według jakiego parametru sortować
     * @param sortOption2 Liczba wprowadzona z metody sortPasswords która określa według jakiego parametru sortować
     */
    void sortPasswordByParameters(int sortOption1, int sortOption2);

    /**
     * Metoda do wyboru parametrow do sortowania wektora
     */
    void sortPasswords();

    std::vector<Password> getPasswords() const;


    void printAllPasswords();
    void printAllSortedPassword();

    /**
     * Edytowania hasła poprzez zmianę pola password w strukturze Rekordu (Nie usuwanie całego rekordu!)
     */
    void editPassword();
    /**
     * Usuwanie całego rekordu
     */
    void deletePassword();

    /**
     * Usuwanie całej kategorii z hasłami
     */
    void deleteCategory();
};


#endif //INC_2223L_20C_S27185_PASSWORDMANAGER_H

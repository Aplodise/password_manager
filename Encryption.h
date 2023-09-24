//
// Created by Roman Sherstiuk on 13/05/2023.
//

#ifndef INC_2223L_20C_S27185_ENCRYPTION_H
#define INC_2223L_20C_S27185_ENCRYPTION_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include "PasswordManager.h"

class Encryption {
public:

    /**
     * @brief Metoda do szyfrowania pliku
     * @param filePath Plik, który ma zostać zaszyfrowany
     * @param password Hasło główne
     */
    static void encrypt(const std::string& filePath, const std::string& password);

    /**
     * @brief Metoda do szyfrowania pliku
     * @param filePath Plik, który ma zostac rozszyfrowany
     * @param password Hasło główne
     * @return Zwraca filePath
     */
    static std::string decrypt(const std::string& filePath, const std::string& password);

    /**
     * @brief Metoda do zapisania wektora w plik
     * @param filePath
     * @param data
     */
    static void writeVectorToFile(const std::string &filePath, std::vector<PasswordManager::Password> &data);

private:
    /**
     * @brief Metoda do otzymania godziny w formacie HH
     * @return Godzina w formacie HH
     */
    static std::string getCurrentHour();

    /**
     * @brief Metoda do otzymania minut w formacie MM
     * @return Minuty w formacie MM
     */
    static std::string getCurrentMinute();

    /**
     * @brief Metoda do otzymania sekund w formacie SS
     * @return Sekundy w formacie SS
     */
    static std::string getCurrentSecond();

    /**
     * @brief Metoda do zaszyfrowania charu wykorzystając XOR algorytm
     * @param c Char
     * @param key Klucz główny
     * @return zaszyfrowany char
     */
    static char encryptChar(char c, const std::string &key);

    /**
     * @biref Metoda do rozszyfrowania charu wykorzystając XOR algorytm
     * @param c Char
     * @param key Klucz główny
     * @return rozszyfrowany char
     */
    static char decryptChar(char c, const std::string &key);
    std::string timestamps;

};

#endif //INC_2223L_20C_S27185_ENCRYPTION_H

//
// Created by Roman Sherstiuk on 21/05/2023.
//

#ifndef INC_2223L_20C_S27185_DECRYPTTOVECTOR_H
#define INC_2223L_20C_S27185_DECRYPTTOVECTOR_H
#include "PasswordManager.h"
#include <vector>
#include <iostream>
#include <fstream>

#include <string>
class DecryptToVector {
public:
    /**
     * @brief Metoda do odczytania rozszyfrowanego pliku i zwracania wektora haseł
     * @param path
     * @return Wektor struktur Password
     */
    static std::vector<PasswordManager::Password> decryptToVector(std::string path);
};


#endif //INC_2223L_20C_S27185_DECRYPTTOVECTOR_H

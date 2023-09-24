//
// Created by Roman Sherstiuk on 21/05/2023.
//

#ifndef INC_2223L_20C_S27185_PASSWORDGENERATOR_H
#define INC_2223L_20C_S27185_PASSWORDGENERATOR_H
#include <iostream>
#include <string>
class PasswordGenerator {
public:
    /**
     * @brief Metoda do wyboru parametrów generowania hasła
     * @return Zgenerowane hasło
     */
    static std::string generatePassword();

    /**
     * Generator hasła
     * @param length Długość hasła
     * @param uppercase Duże litery
     * @param lowercase Małe litery
     * @param specialChars Znaki specjalne
     * @return Zgenerowane hasło
     */
    static std::string generator(int length, bool uppercase, bool lowercase, bool specialChars);
};


#endif //INC_2223L_20C_S27185_PASSWORDGENERATOR_H

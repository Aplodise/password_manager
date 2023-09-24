
//
// Created by Roman Sherstiuk on 21/05/2023.
//

#include "PasswordGenerator.h"

std::string PasswordGenerator::generatePassword() {
    int length;
    char choice;
    bool uppercase, lowercase, specialChars;

    std::cout << "Password length: ";
    std::cin >> length;
    std::cout << "Use uppercase letters? (Y/N) ";
    std::cin >> choice;
    uppercase = (choice == 'Y' || choice == 'y');
    std::cout << "Use lowercase letters? (Y/N) ";
    std::cin >> choice;
    lowercase = (choice == 'Y' || choice == 'y');
    std::cout << "With special characters? (Y/N) ";
    std::cin >> choice;
    specialChars = (choice == 'Y' || choice == 'y');
    return generator(length, uppercase, lowercase, specialChars);
}

std::string PasswordGenerator::generator(int length, bool uppercase, bool lowercase, bool specialChars) {
    std::string result = "";
    std::string chars ="0123456789";
    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasSpecialChar = false;

    std::srand(std::time(nullptr));
    if (uppercase) {
        chars += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    if (lowercase) {
        chars += "abcdefghijklmnopqrstuvwxyz";
    }
    if (specialChars) {
        chars += "!@#$%^&*()_+-={}[]|:;<>,.?/~\\";
    }
    for (int i = 0; i < length; i++) {
        int index = std::rand() % chars.length();
        char selectedChar = chars[index];
        result += selectedChar;

        if (uppercase && !hasUppercase && isupper(selectedChar)) {
            hasUppercase = true;
        }
        if (lowercase && !hasLowercase && islower(selectedChar)) {
            hasLowercase = true;
        }
        if (specialChars && !hasSpecialChar && !isalnum(selectedChar)) {
            hasSpecialChar = true;
        }
    }

    if (uppercase && !hasUppercase) {
        int uppercaseIndex = std::rand() % 26;
        char uppercaseChar = chars[10 + uppercaseIndex];
        result[std::rand() % length] = uppercaseChar;
    }
    if (lowercase && !hasLowercase) {
        int lowercaseIndex = std::rand() % 26;
        char lowercaseChar = chars[36 + lowercaseIndex];
        result[std::rand() % length] = lowercaseChar;
    }
    if (specialChars && !hasSpecialChar) {
        int specialCharIndex = std::rand() % 22;
        char specialChar = chars[62 + specialCharIndex];
        result[std::rand() % length] = specialChar;
    }

    return result;
}

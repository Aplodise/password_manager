//
// Created by Roman Sherstiuk on 21/05/2023.
//

#include "Menu.h"

void Menu::menu() {
    std::cout << "Hi welcome to Password Manager v1" << std::endl;
    std::cout<<std::endl;
    int dirOrSource;
    std::cout << "Do you want to open file chooser in current directory or provide path? Write a number to pick from menu" << std::endl;
    std::cout << std::endl;
    std::cout << "-> 0. Exit program" << std::endl;
    std::cout << "-> 1. Path" << std::endl;
    std::cout << "-> 2. Current Directory" << std::endl;
    std::cin >> dirOrSource;
    std::string path = DirectoryChooser::chooseBetweenTwo(dirOrSource);

    std::string masterpassword;
    std::cout << "Please provide a master-password for this file" << std::endl;
    std::cin >> masterpassword;
    std::string pathForVector = Encryption::decrypt(path, masterpassword);

    std::vector<PasswordManager::Password> passwords = DecryptToVector::decryptToVector(pathForVector);
    PasswordManager passwordManager(passwords);


    bool returnToMenu = false;
    do {
        std::cout << std::endl;
        std::cout << "Please select an action:" << std::endl;
        std::cout << "1. Add Password" << std::endl;
        std::cout << "2. Add Category" << std::endl;
        std::cout << "3. Sort passwords" << std::endl;
        std::cout << "4. Edit password" << std::endl;
        std::cout << "5. Delete password" << std::endl;
        std::cout << "6. Delete category" << std::endl;
        std::cout << "7. Show all passwords" << std::endl;
        std::cout << "8. Search Password" << std::endl;
        std::cout << "0. End program" << std::endl;
        int choice;
        std::cin >> choice;
        std::vector<PasswordManager::Password> vec;

        switch (choice) {
            case 1:
                passwordManager.setRecord();
                break;
            case 2:
                passwordManager.addCategory();
                break;
            case 3:
                passwordManager.sortPasswords();
                break;
            case 4:
                passwordManager.editPassword();
                break;
            case 5:
                passwordManager.deletePassword();
                break;
            case 6:
                passwordManager.deleteCategory();
                break;
            case 7:
                passwordManager.printAllPasswords();
                break;
            case 8:
                passwordManager.searchPassword();
                break;
            case 0:
                vec = passwordManager.getPasswords();
                Encryption::writeVectorToFile(pathForVector,vec);
                Encryption::encrypt(pathForVector,masterpassword);
                returnToMenu = true;
                break;
            default:
                std::cout << "Invalid choice. Your file would be encrypted." << std::endl;
                Encryption::writeVectorToFile(pathForVector,vec);
                Encryption::encrypt(pathForVector,masterpassword);
                break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!returnToMenu);

    std::cout << "----------------------------" << std::endl;
    std::vector<PasswordManager::Password> gettedPasswords = passwordManager.getPasswords();
    for (const auto &password: gettedPasswords) {
        std::cout << password << std::endl;
    }

}



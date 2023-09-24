//
// Created by Roman Sherstiuk on 13/05/2023.
//

#include "PasswordManager.h"


void PasswordManager::searchPassword() {
    std::string regex;
    std::cout << "Fine, please type your word to search for" << std::endl;
    std::cin >> regex;

    std::cout << "Choose by what parameter you like to search your password" << std::endl;
    std::cout << "1. Name" << std::endl;
    std::cout << "2. Password" << std::endl;
    std::cout << "3. Category" << std::endl;
    std::cout << "4. Website" << std::endl;
    std::cout << "5. Login" << std::endl;
    int parameter;
    std::cin >> parameter;
    int countNum = 0;
    switch(parameter){
        case 1:
            for (const auto &password: passwords) {
                if(password.name == regex){
                    std::cout << password << std::endl;
                    countNum++;
                }

            }
            break;
        case 2:
            for (const auto &password: passwords) {
                if(password.password == regex){
                    std::cout << password << std::endl;
                    countNum++;
                }

            }
            break;
        case 3:
            for (const auto &password: passwords) {
                if(password.category == regex){
                    std::cout << password << std::endl;
                    countNum++;
                }

            }
            break;
        case 4:
            for (const auto &password: passwords) {
                if(password.website == regex){
                    std::cout << password << std::endl;
                    countNum++;
                }

            }
            break;
        case 5:
            for (const auto &password: passwords) {
                if(password.login == regex) {
                    std::cout << password << std::endl;
                    countNum++;
                }

            }
            break;
        default:
            std::cout << "You chose a wrong number, try again" << std::endl;
            searchPassword();

    }
    if(countNum ==0)
        std::cout << "Nothing matching your word was found :(" << std::endl;
}
void PasswordManager::setRecord() {

    Password password;
    std::cout << "Enter name of the password record: " << std::endl;
    std::cin >> password.name;

    password.password = setPassword();



    if (categories.empty()) {
        std::cout << "No categories found. Please add a category first." << std::endl;
        addCategory();
        password.category = categories.at(0);

    } else {
        std::cout << "Choose a category from the following options or add a new one:" << std::endl;
        for (int i = 0; i < categories.size(); i++) {
            std::cout << i + 1 << ". " << categories[i] << std::endl;
        }
        std::cout << categories.size() + 1 << ". Add new category" << std::endl;

        int choose;
        std::cin >> choose;

        if (choose >= 1 && choose <= categories.size()) {
            password.category = categories[choose - 1];
        } else if (choose == categories.size() + 1) {
            addCategory();
            password.category = categories.back();
        } else {
            std::cout << "Invalid choice. Category not set." << std::endl;
        }
    }

    std::cout << "Do you want to add website?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;

    int choose;
    std::cin >> choose;
    switch(choose){
        case 1:
            std::cout << "Enter website: ";
            std::cin >> password.website;
            break;
        default:
            break;

    }

    std::cout << "Do you want to add login?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;

    int choose2;
    std::cin >> choose2;

    switch(choose2){
        case 1:
            std::cout << "Enter login: ";
            std::cin >> password.login;
            break;
        default: break;
    }

    passwords.push_back(password);
}



std::vector<PasswordManager::Password> PasswordManager::getPasswords() const {
    return passwords;
}


std::string PasswordManager::setPassword() {

    int num;
    std::cout << "Do you want to enter your own password or generate it by program?" << std::endl;
    std::cout << "1. Enter your own" << std::endl;
    std::cout << "2. Generate by program" << std::endl;
    std::cin >> num;
    std::string pass;
    bool isUsed;
    int chooser;
    switch(num){
        case 1:
            std::cout << "Enter your password" << std::endl;
            std::cin >> pass;

            for (const auto &password: passwords) {
                if(pass == password.password){
                    std::cout << "This password was used before" << std::endl;
                    isUsed = true;
                }
            }
            if(pass.length() < 8){
                std::cout << "Your password is short, this may affect on safety of your account! Please change it for another one!" << std::endl;
                setPassword();
            }


            if(isUsed){
                std::cout << "This password was used before, you want to remain it or maybe you want to change it or generate one by program? "<< std::endl;
                std::cout << "1. Keep it" << std::endl;
                std::cout << "2. Change it" << std::endl;
                std::cout << "3. Generate one" << std::endl;
                std::cin >> chooser;
                switch(chooser){
                    case 1: return pass;
                    case 2: return setPassword();
                    case 3: return PasswordGenerator::generatePassword();
                }
            }
            else{
                return pass;
            }
        case 2:
            return PasswordGenerator::generatePassword();
        default:
            return PasswordGenerator::generatePassword();

    }
}

PasswordManager::PasswordManager(const std::vector<Password> &passwords) : passwords(passwords) {
    for (size_t i = 0; i < passwords.size(); i++) {
        std::string uppercaseCategoryParsed;
        std::transform(passwords.at(i).category.begin(), passwords.at(i).category.end(), std::back_inserter(uppercaseCategoryParsed), ::toupper);

        bool categoryExists = false;
        for (size_t j = 0; j < categories.size(); j++) {
            std::string uppercaseCategory;
            std::transform(categories.at(j).begin(), categories.at(j).end(), std::back_inserter(uppercaseCategory), ::toupper);

            if (uppercaseCategoryParsed == uppercaseCategory) {
                categoryExists = true;
                break;
            }
        }

        if (!categoryExists) {
            categories.push_back(passwords.at(i).category);
        }
    }
}

void PasswordManager::addCategory() {
    std::string name;
    std::cout << "Please give a name for a category you would like to add" << std::endl;
    std::cin >> name;
    for (const auto &item: categories) {
        if(item == name){
            std::cout << "This category already exists, please add another" << std::endl;
            addCategory();
        }
    }
    categories.push_back(name);
}
bool PasswordManager::sortByName(Password a, Password b) {
    return a.name < b.name;
}

bool PasswordManager::sortByCategory(Password a, Password b) {
    return a.category < b.category;
}
bool PasswordManager::sortByWebsite(PasswordManager::Password a, PasswordManager::Password b) {
    return a.website < b.website;
}

bool PasswordManager::sortByLogin(PasswordManager::Password a, PasswordManager::Password b) {
    return a.login < b.login;
}

void PasswordManager::sortPasswordByParameters(int sortOption1, int sortOption2) {
    sortedpasswords= passwords;
    std::function<bool(const Password&, const Password&)> compareFunc;

    switch ((sortOption1 * 10) + sortOption2) {
        case 12:
            compareFunc = [](const Password& a, const Password& b) {
                return sortByName(a,b) || (a.name == b.name && sortByCategory(a,b));
            };
            break;
        case 13:
            compareFunc = [](const Password& a, const Password& b) {
                return sortByName(a,b) || (a.name == b.name && sortByWebsite(a,b));
            };
            break;
        case 14:
            compareFunc = [](const Password& a, const Password& b) {
                return sortByName(a,b) || (a.name == b.name && sortByLogin(a,b));
            };
            break;
        case 21:
            compareFunc = [](const Password& a, const Password& b) {
                return sortByCategory(a,b) || (a.category == b.category && sortByName(a,b));
            };
            break;
        case 23:
            compareFunc = [](const Password& a, const Password& b) {
                return sortByCategory(a,b) || (a.category == b.category && sortByWebsite(a,b));
            };
            break;
        case 24:
            compareFunc = [](const Password& a, const Password& b) {
                return sortByCategory(a,b) || (a.category == b.category && sortByLogin(a,b));
            };
            break;
        case 31:
            compareFunc = [](const Password& a, const Password& b) {
                return sortByWebsite(a,b) || (a.website == b.website && sortByName(a,b));
            };
            break;
        case 32:
            compareFunc = [](const Password& a, const Password& b) {
                return sortByWebsite(a,b) || (a.website == b.website && sortByCategory(a,b));
            };
            break;
        case 34:
            compareFunc = [](const Password& a, const Password& b) {
                return sortByWebsite(a,b) || (a.website == b.website && sortByLogin(a,b));
            };
            break;
        case 41:
            compareFunc = [](const Password& a, const Password& b) {
                return sortByLogin(a,b) || (a.login == b.login && sortByName(a,b));
            };
            break;
        case 42:
            compareFunc = [](const Password& a, const Password& b) {
                return sortByLogin(a,b) || (a.login == b.login && sortByCategory(a,b));
            };
            break;
        case 43:
            compareFunc = [](const Password& a, const Password& b) {
                return sortByLogin(a,b) || (a.login == b.login && sortByWebsite(a,b));
            };
            break;
        default:
            break;
    }

    std::sort(sortedpasswords.begin(), sortedpasswords.end(), compareFunc);
    printAllSortedPassword();
}


void PasswordManager::printAllPasswords() {
    std::cout << "-----------------------------------" << std::endl;
    for (const auto &password: passwords) {
        std::cout << password << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
}


void PasswordManager::sortPasswords() {
std::cout << "Please choose first and second parameter you want to sort with(enter space between each number)" << std::endl;
std::cout << "1. By name" << std::endl;
std::cout << "2. By category" << std::endl;
std::cout << "3. By website" << std::endl;
std::cout << "4. By login" << std::endl;
int choose1 =0 , choose2 = 0;
    std::cin >> choose1;
    std::cin >> choose2;
if((choose1 > 0 && choose1 < 5) && (choose2 > 0&& choose2 < 5)){
    sortPasswordByParameters(choose1,choose2);
}else{
    std::cerr << "You have entered wrong numbers, please try again" << std::endl;
    sortPasswords();
}

}

void PasswordManager::editPassword() {
    std::cout << "Select the password you want to edit:" << std::endl;
    for (size_t i = 0; i < passwords.size(); i++) {
        std::cout << i<< ". " << passwords[i].name << std::endl;
    }

    int choice;
    std::cin >> choice;
    if (choice >= 0 && choice <= passwords.size()-1) {

        std::cout << "Editing password: " << passwords[choice].name << std::endl;

        std::string newPass = setPassword();
        passwords[choice].password = newPass;

        std::cout << "Password \"" << passwords[choice].name << "\" successfully edited." << std::endl;
    } else {
        std::cout << "Invalid choice. No password selected for editing. Please try again" << std::endl;
        editPassword();
    }
}

void PasswordManager::deletePassword() {
    std::cout << "Select the password(s) you want to delete:" << std::endl;
    for (size_t i = 0; i < passwords.size(); i++) {
        std::cout << i << ". " << passwords[i].name << std::endl;
    }

    std::cout << "Enter the number(s) of the password(s) you want to delete (separated by spaces):" << std::endl;
    std::vector<int> choices;

    int choice;
    while (std::cin >> choice) {
        if (choice >= 0 && choice < passwords.size()) {
            choices.push_back(choice);
        } else {
            std::cout << "Invalid choice. Please enter a valid password number or any other key to finish deleting."
                      << std::endl;
            break;
        }

    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (!choices.empty()) {

        for (int i = choices.size() - 1; i >= 0; i--) {
            int index = choices[i];
            std::cout << "Confirm deletion of password: " << passwords[index].name << " (y/n): ";
            char confirmDelete;
            std::cin >> confirmDelete;
            if (confirmDelete == 'y' || confirmDelete == 'Y') {
                std::cout << "Deleted password: " << passwords[index].name << std::endl;
                passwords.erase(passwords.begin() + index);
            } else {
                std::cout << "Password \"" << passwords[index].name << "\" will not be deleted." << std::endl;
            }
        }


    }

    for (auto it = categories.begin(); it != categories.end(); ) {
        const std::string& category = *it;
        bool found = false;
        for (const auto& password : passwords) {
            if (password.category == category) {
                found = true;
                break;
            }
        }
        if (!found) {
            it = categories.erase(it);
        } else {
            ++it;
        }
    }
}


void PasswordManager::deleteCategory() {
    std::cout << "Select the category you want to delete:" << std::endl;
    for (size_t i = 0; i < categories.size(); i++) {
        std::cout << i << ". " << categories[i] << std::endl;
    }

    int choice;
    std::cin >> choice;
    if (choice >= 0 && choice < categories.size()) {
        std::string selectedCategory = categories[choice];
        std::cout << "Deleting category: " << selectedCategory << std::endl;

        std::vector<Password> updatedPasswords;
        for (const auto& password : passwords) {
            if (password.category != selectedCategory) {
                updatedPasswords.push_back(password);
            }
        }
        passwords = updatedPasswords;
        categories.erase(categories.begin() + choice);

        std::cout << "Category \"" << selectedCategory << "\" and associated passwords deleted." << std::endl;
    } else {
        std::cout << "Invalid choice. No category selected for deletion. Please try again" << std::endl;
        deleteCategory();
    }
}

void PasswordManager::printAllSortedPassword() {
    std::cout << "-----------------------------------" << std::endl;
    for (const auto &password: sortedpasswords) {
        std::cout << password << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
}








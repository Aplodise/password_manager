//
// Created by Roman Sherstiuk on 21/05/2023.
//

#include <sstream>
#include "DecryptToVector.h"



std::vector<PasswordManager::Password> DecryptToVector::decryptToVector(std::string path) {
    int lineCounter = 0;
    std::ifstream inputFile(path);
    std::string line;
    std::vector<PasswordManager::Password> vector;
    int lines = 0;
    while (std::getline(inputFile, line)){
        lines++;
    }

        inputFile.clear();
        inputFile.seekg(0, std::ios::beg);
        while (std::getline(inputFile, line)) {
            if (lineCounter == lines -1) {
                line = line.erase(line.length()-6);
            }

            std::stringstream ss(line);
            PasswordManager::Password password;
            int countPole = 0;
            std::string word;
            while (std::getline(ss, word, '\t')) {
                switch (countPole) {
                    case 0: password.name = word; break;
                    case 1: password.password = word; break;
                    case 2: password.category = word; break;
                    case 3: password.website = word; break;
                    case 4: password.login = word; break;
                }
                countPole++;
            }
            vector.push_back(password);
            lineCounter++;
        }



    return vector;
}


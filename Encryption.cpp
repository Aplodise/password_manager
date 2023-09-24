//
// Created by Roman Sherstiuk on 13/05/2023.
//

#include "Encryption.h"



void Encryption::encrypt(const std::string &filePath, const std::string &password) {
    std::ifstream inputFile(filePath);
    std::stringstream encryptedContent;
    std::string line;
    int lineCounter = 0;
    int lines = 0;
    while (std::getline(inputFile, line)){
        lines++;
    }


        inputFile.clear();
        inputFile.seekg(0, std::ios::beg);

        while (std::getline(inputFile, line)) {
            std::string encryptedLine;
            std::string times;
            if (lineCounter == lines - 1) {
                times  = line.substr(line.length() - 6);
                line = line.substr(0, line.length() - 6);
            }


            for (size_t i = 0; i < line.length(); i++) {
                char c = line[i];
                char untouched = line[i];
                if(!iswspace(c)){
                    c = encryptChar(c, password);

                }
                if(iswspace(c)){
                    c = untouched;
                }
                encryptedLine+=c;

            }
            if(lineCounter != lines -1){
                encryptedContent << encryptedLine << "\n";
            }
            else{
                encryptedContent << encryptedLine << times  << "\n";
            }
            lineCounter++;
        }



    inputFile.close();

    std::ofstream outputFile(filePath);
    outputFile << encryptedContent.str();
    outputFile.close();
}

std::string Encryption::decrypt(const std::string &filePath, const std::string &password) {
    std::ifstream inputFile(filePath);
    std::stringstream decryptedContent;
    std::string line;
    int lines = 0;
    int lineCounter = 0;

    std::string hh, mm, ss;
    while (std::getline(inputFile, line)){
        lines++;
    }

    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);

    while (std::getline(inputFile, line)){
        std::string decryptedLine;

        for (size_t i = 0; i < line.length(); i++) {
            char c = line[i];
            char untouched = line[i];
            if(!iswspace(c)){
                c = decryptChar(c, password);

            }
            if(iswspace(c)){
                c = untouched;
            }
            decryptedLine+=c;
        }

        if (lineCounter == lines - 1) {
            std::string currentTime = getCurrentHour() + getCurrentMinute() + getCurrentSecond();
            if (decryptedLine.length() >= 6) {
                decryptedLine = decryptedLine.substr(0, decryptedLine.length() - 6) + currentTime;
            } else {
                decryptedLine = currentTime;
            }
        }

        decryptedContent << decryptedLine << "\n";
        lineCounter++;
    }

    inputFile.close();

    std::ofstream outputFile(filePath);
    outputFile << decryptedContent.str();
    outputFile.close();
    return filePath;
}


std::string Encryption::getCurrentHour() {
    std::time_t currentTime = std::time(nullptr);

    std::tm* localTime = std::localtime(&currentTime);


    char hour[3];
    std::strftime(hour, sizeof(hour), "%H", localTime);


    return hour;
}

std::string Encryption::getCurrentMinute() {
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);

    char minutes[3];
    std::strftime(minutes, sizeof(minutes), "%M", localTime);

    return minutes;
}

std::string Encryption::getCurrentSecond() {
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);

    char seconds[3];
    std::strftime(seconds, sizeof(seconds), "%S", localTime);

    return seconds;
}

char Encryption::encryptChar(char c, const std::string &key) {
    char encryptedChar = c;

    for (char keyChar : key) {
        encryptedChar ^= keyChar;
    }

    return encryptedChar;
}

char Encryption::decryptChar(char c, const std::string &key) {
    char decryptedChar = c;

    for (char keyChar : key) {
        decryptedChar ^= keyChar;
    }

    return decryptedChar;
}

void Encryption::writeVectorToFile(const std::string &filePath, std::vector<PasswordManager::Password> &data) {
    std::ofstream outputFile(filePath);


    for (size_t i = 0; i < data.size(); i++) {
        PasswordManager::Password pass = data.at(i);
        std::string line = pass.name + "\t" + pass.password + "\t" + pass.category + (pass.website.empty()?"":"\t") + (pass.website.empty()?"":pass.website) +  (pass.login.empty()?"":"\t") + (pass.login.empty()?"":pass.login) ;

        if(i == data.size() -1){
            line += getCurrentHour() + getCurrentMinute() + getCurrentSecond();
        }
        outputFile << line << "\n";
    }

    outputFile.close();
}

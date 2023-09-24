//
// Created by Roman Sherstiuk on 11/05/2023.
//

#include "DirectoryChooser.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <map>
#include <regex>

std::string DirectoryChooser::fileChoose(std::map<int, std::string> map) {
    std::cout << "Choose file you want" << std::endl;
    int index;
    std::cin >> index;
    if(index < 0 || index > map.size()-1){
        std::cout << "Your index is invalid, choose another index" << std::endl;
        return fileChoose(map);
    }
        return map[index];
}

std::string DirectoryChooser::chooseDirectory(std::string source)  {

auto dirPath = source;
bool isDirExists = std::filesystem::is_directory(dirPath);
if(isDirExists) {

    auto dirIter = std::filesystem::directory_iterator(dirPath);
    static std::map<int,std::string> files;
    auto count = 0;
    std::regex pattern(".*\\.txt");

    for (const auto &item: dirIter) {
        auto pathCheck = item.path().string();
        if(item.is_regular_file() && std::regex_match(pathCheck,pattern)){
        files[count++] = item.path().string();
        }
    }
    if(files.empty()){
        std::cout << "You entered a directory which does not have .txt files please provide another directory" << std::endl;
        return chooseBetweenTwo(1);
    }
    for(int i =0; i <files.size(); i++){
        std::cout << i << ". " << files[i] << std::endl;
    }

    return fileChoose(files);

}else{
    std::cout << "Your directory does not exist. Please choose another" << std::endl;
   return chooseBetweenTwo(1);
}
}


std::string DirectoryChooser::chooseBetweenTwo(int dirOrSource) {
    std::string path;

    switch(dirOrSource){

        case 0:
            std::cout << "See you soon, bye" << std::endl;
            exit(0);
        case 1:
                std::cout << "Give your own directory path" << std::endl;
                std::cin >> path;
                return chooseDirectory(path);
        case 2:

                return chooseDirectory(".");
        default:
            std::cerr << "You wrote a wrong number, please try again" << std::endl;
            exit(1);
    }
}



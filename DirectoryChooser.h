//
// Created by Roman Sherstiuk on 11/05/2023.
//

#ifndef INC_2223L_20C_S27185_DIRECTORYCHOOSER_H
#define INC_2223L_20C_S27185_DIRECTORYCHOOSER_H
#include <string>
#include <map>
#include <filesystem>

class DirectoryChooser {
public:
    /**
     * Metoda która za pomocą regex poszukuje pliki z rozszerzeniem .txt i dodaje ich do mapy ścieżek
     * @param source
     * @return ścieżke
     */
    static std::string chooseDirectory(std::string source);

    /**
     * Metoda do wyboru katalogu, z którego mają być wyświetlane pliki
     * @param dirOrSource
     * @return ścieżke
     */
    static std::string chooseBetweenTwo(int dirOrSource);
private:
    /**
     * Metoda do wyboru pliku z mapy ścieżek plików
     * @param map
     * @return ścieżke
     */
    static std::string fileChoose(std::map<int, std::string> map);

};


#endif //INC_2223L_20C_S27185_DIRECTORYCHOOSER_H

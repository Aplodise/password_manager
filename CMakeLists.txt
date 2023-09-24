cmake_minimum_required(VERSION 3.24)
project(password_manager)

set(CMAKE_CXX_STANDARD 23)

add_executable(password_manager main.cpp DecryptToVector.cpp DirectoryChooser.cpp Encryption.cpp Menu.cpp PasswordGenerator.cpp PasswordManager.cpp)

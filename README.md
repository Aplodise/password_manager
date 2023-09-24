# Password Manager Project

## Overview
This is a Password Manager project written in C++ that allows users to securely store and manage their passwords. It offers a variety of features to make password management more convenient and secure.

## Features

### Directory Selection
- You can choose the directory where the password file is located or select the current directory for password storage.

### Password Decryption & Encryption
- Decrypt and encrypt password files using a master key to access stored passwords.

### Adding Passwords
- Add new passwords with the following information:
  - Password name
  - Password itself
  - Category
  - Website link (Not mandatory)
  - Login username (Not mandatory)

### Password Generation
- Generate strong passwords using built-in functionality, including:
  - Password length selection
  - Capital or lowercase letters
  - Special character inclusion

### Category Management
- Organize passwords by assigning them to specific categories for easier retrieval.

### Password Sorting
- Sort passwords based on two parameters of your choice for better organization.

### Password Modification
- Change and update existing passwords as needed.

### Password Deletion
- Delete passwords that are no longer needed.

### Category Deletion
- Remove entire categories, which will also delete all passwords within them.

### Password Listing
- Display a list of all stored passwords.

### Password Search
- Search for specific passwords by keyword.

## Getting Started
1. Clone the repository to your local machine:
   ```
   git clone <repository_url>
   ```
2. Compile the C++ code:
   ```
   g++ main.cpp -o password_manager
   ```
3. Run the program:
   ```
   ./password_manager
   ```

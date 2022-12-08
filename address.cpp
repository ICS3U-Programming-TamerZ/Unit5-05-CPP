// Copyright (c) 2022 Melody Berhane All rights reserved.
//
// Created by: Tamer
// Created on: Dec. 12, 2022
// This program asks the user for their address
// then re-prints it in proper format.

#include <iostream>
#include <string>
#include <cstring>


// properly formats an address following the Canadian post standard
std::string formatAddress(std::string name, std::string streetNum,
                          std::string streetName, std::string city,
                          std::string province, std::string postalCode,
                          std::string aptNum = "", std::string question = "") {
    // declaring variables
    std::string canPostAddress, CanPostAddress, userStringUpper;
    std::string userStringUpper1, userStringUpper2;
    std::string userStringUpper3, userStringUpper4, userStringUpper5;

    // gets length of string
    int nameLength = name.length();
    // declare char as length of string
    char char_array[nameLength + 1];
    strcpy(char_array, name.c_str());
    // converts each letter to uppercase
    for (int counter = 0; counter < nameLength; counter++) {
        userStringUpper += std::toupper(char_array[counter]);
    }

    // gets length of string
    int streetNameLength = streetName.length();
    // declare char as length of string
    char char_array1[streetNameLength + 1];
    strcpy(char_array1, streetName.c_str());

    // converts each letter to uppercase
    for (int counter = 0; counter < streetNameLength; counter++) {
        userStringUpper1 += std::toupper(char_array1[counter]);
    }

    // gets length of string
    int cityLength = city.length();
    // declare char as length of string
    char char_array2[cityLength + 1];
    strcpy(char_array2, city.c_str());

    // converts each letter to uppercase
    for (int counter = 0; counter < cityLength; counter++) {
        userStringUpper2 += std::toupper(char_array2[counter]);
    }

    // gets length of string
    int provinceLength = province.length();
    // declare char as length of string
    char char_array3[provinceLength + 1];
    strcpy(char_array3, province.c_str());

    // converts each letter to uppercase
    for (int counter = 0; counter < provinceLength; counter++) {
        userStringUpper3 += std::toupper(char_array3[counter]);
    }

    // gets length of string
    int postalCodeLength = postalCode.length();
    // declare char as length of string
    char char_array4[postalCodeLength + 1];
    strcpy(char_array4, postalCode.c_str());

    // converts each letter to uppercase
    for (int counter = 0; counter < postalCodeLength; counter++) {
        userStringUpper4 += std::toupper(char_array4[counter]);
    }

    if (question == "y") {
        // gets length of string
        int aptNumLength = aptNum.length();
        // declare char as length of string
        char char_array5[aptNumLength + 1];
        strcpy(char_array5, aptNum.c_str());

        // converts each letter to uppercase
        for (int counter = 0; counter < aptNumLength; counter++) {
            userStringUpper5 += std::toupper(char_array5[counter]);
        }

        CanPostAddress = userStringUpper + "\n";
        CanPostAddress += userStringUpper5 + "-" + \
                          streetNum + " " + userStringUpper1 + "\n";
        CanPostAddress += userStringUpper2 + " " + \
                          userStringUpper3 + " " + userStringUpper4;

        return CanPostAddress;
    }

    canPostAddress = userStringUpper + "\n";
    canPostAddress += streetNum + " " + userStringUpper1 + "\n";
    canPostAddress += userStringUpper2 + " " + \
                      userStringUpper3 + " " + userStringUpper4;

    return canPostAddress;
}


int main() {
    // displays opening message
    std::cout << "This program formulates an address to a ";
    std::cout << "Canadian mailing address!";
    std::cout << std::endl;
    std::cout << std::endl;

    // declaring variables
    std::string nameUser;
    std::string streetNumUser;
    std::string streetNameUser;
    std::string cityUser;
    std::string provinceUser;
    std::string postalCodeUser;
    std::string aptNumUser = "";
    std::string questionUser = "";
    std::string userAddress;

    // gets input from the user
    std::cout << "Enter your full name: ";
    getline(std::cin, nameUser);
    std::cout << "Do you live in an apartment? (y/n): ";
    getline(std::cin, questionUser);

    // checks if user lives in an apartment
    if (questionUser == "y") {
        std::cout << "Enter your apartment number: ";
        getline(std::cin, aptNumUser);
    }
    // gets input from the user
    std::cout << "Enter your street number: ";
    getline(std::cin, streetNumUser);
    std::cout << "Enter your street name and type ";
    std::cout << "(Main St., Flower Cres., etc.): ";
    getline(std::cin, streetNameUser);
    std::cout << "Enter your city: ";
    getline(std::cin, cityUser);
    std::cout << "Enter your province (as an abbreviation i.e ON, AB, etc.): ";
    getline(std::cin, provinceUser);
    std::cout << "Enter your postal code (i.e A1B 2C3): ";
    getline(std::cin, postalCodeUser);
    std::cout << std::endl;

    // assigns variable to function that formats the address
    if (aptNumUser != "") {
        userAddress = formatAddress(nameUser, streetNumUser,
                                    streetNameUser, cityUser, provinceUser,
                                    postalCodeUser, aptNumUser, questionUser);
        std::cout << userAddress;
    } else {
        userAddress = formatAddress(nameUser, streetNumUser,
                                    streetNameUser, cityUser, provinceUser,
                                    postalCodeUser);
        std::cout << userAddress;
    }
}
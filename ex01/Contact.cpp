#include <iostream>
#include "Contact.hpp"
#include <string>

// Setters

void Contact::setFirstName(std::string value){
    firstName = value;
}
void Contact::setLastName(std::string value){
    lastName = value;
}
void Contact::setNickName(std::string value){
    nickName = value;
}
void Contact::setPhoneNumber(std::string value){
    phoneNumber = value;
}
void Contact::setDarkestSecret(std::string value){
    darkestSecret = value;
}

// Getters

std::string Contact::getFirstName(){
    return firstName;
}
std::string Contact::getLastName(){
    return lastName;
}
std::string Contact::getNickName(){
    return nickName;
}
std::string Contact::getPhoneNumber(){
    return phoneNumber;
}
std::string Contact::getDarkestSecret(){
    return darkestSecret;
}

//  Diplay
void Contact::display(){
    std::cout << firstName << std::endl;
    std::cout << lastName << std::endl;
    std::cout << nickName << std::endl;
    std::cout << phoneNumber << std::endl;
    std::cout << darkestSecret << std::endl;
} 

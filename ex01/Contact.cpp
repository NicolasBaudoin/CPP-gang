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

void Contact::getFirstName(){
    return firstname;
}
void Contact::getLastName(){
    return lastName;
}
void Contact::getNickName(){
    return nickName;
}
void Contact::getPhoneNumber(){
    return phoneNumber;
}
void Contact::getDarkestSecret(){
    return darkestSecret;
}

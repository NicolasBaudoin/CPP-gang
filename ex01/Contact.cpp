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

char *Contact::getFirstName(){
    return firstName;
}
char *Contact::getLastName(){
    return lastName;
}
char *Contact::getNickName(){
    return nickName;
}
char *Contact::getPhoneNumber(){
    return phoneNumber;
}
char *Contact::getDarkestSecret(){
    return darkestSecret;
}

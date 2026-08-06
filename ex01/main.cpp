#include <iostream>
#include <string>
#include "PhoneBook.hpp"



int main()
{
    contact contact1;

    Contact::setFirstName("Nicolas");
    std::cout << Contact::getFirstName() << std::endl;
    
    return 0;
}

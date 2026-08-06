#include <iostream>
#include <string>
#include "PhoneBook.hpp"



int main()
{
    Contact contact1;

    contact1.setFirstName("Nicolas");
    std::cout << contact1.getFirstName();
    
    return 0;
}

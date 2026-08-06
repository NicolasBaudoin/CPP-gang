#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define LENGTH_PHONEBOOK 8

class PhoneBook {
    private :
      Contact contacts_list[LENGTH_PHONEBOOK];
      int head;
      int tail;
};

#endif

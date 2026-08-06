#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:

    // Setters
        void setFirstName(std::string value);
        void setLastName(std::string value);
        void setNickName(std::string value);
        void setPhoneNumber(std::string value);
        void setDarkestSecret(std::string value);
    
    // Getters
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
        
        void display();
};

#endif

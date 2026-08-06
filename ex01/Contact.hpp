#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
  public:

// Setters
      void setFirstName(std::string value);
      void setLastName(std::string value);
      void setNickName(std::string value);
      void setPhoneNumber(std::string value);
      void setDarkestSecret(std::string value);

// Getters
      void getFirstName();
      void getLastName();
      void getNickName();
      void getPhoneNumber();
      void getDarkestSecret();

  private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
};

#endif

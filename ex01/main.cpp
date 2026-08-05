#include <iostream>
#include <string>

// bool empty() const;

class phoneBook{
    private:
        contact[8];
};


class contact {
    public :
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        
    void secureEmptyDisplay(){
        firstName.empty() == true ? firstName = "VOID" : firstName;
        lastName.empty() == true ? lastName = "VOID" : lastName;
        nickName.empty() == true ? nickName = "VOID" : nickName;
        phoneNumber.empty() == true ? phoneNumber = "VOID" : phoneNumber;
    }

    void display(){
        secureEmptyDisplay();
        std::cout << "firstName : " << firstName << std::endl;
        std::cout << "lastName : " << lastName << std::endl;
        std::cout << "nickName : " << nickName << std::endl;
        std::cout << "phoneNumber : " << phoneNumber << std::endl;
    }

    private :
        std::string darkestSecret;
};

int main()
{
    contact contact1;

    contact1.firstName = "Nicolas";
    contact1.display();
    
    return 0;
}

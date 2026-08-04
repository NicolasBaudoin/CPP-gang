#include <fstream>
#include <string>


// #1 C++ Is an international standard
// ISO C++98 1998, C++03 2003

// #2 Deterministic Object Lifetime

void useString() {

	{
		std::string s("Ok ça marche ?"); //create s here
		std::string s2("Ok ça marche 2 ?"); //create s2 here
	}
	// destroy s2 here
	// destroy s here
	// s.size(); // ici ne marche pas car s est detruit avant car plus le même scope

	{
		std::ofstream file("output.txt");
		file << "data";
	} // file closed

}

// #2 AKA RAII

// #3 Destructors

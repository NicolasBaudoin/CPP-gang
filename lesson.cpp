#include <algorithm>
#include <fstream>
#include <memory>
#include <string>

// TUTO LINK https://www.youtube.com/watch?v=78Y_LRZPVRg


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

// FLAWED code (imparfait) to demosntrate what RAII is

struct MyType {
	MyType() : ptr(new int(5)) {}
	~MyType() { delete ptr; }

	int *ptr;
};

void myType() {

	MyType obj;

} // obj out of scope, destructor called

// Avoid destructors: Folow Rule of 0

// #4 Templates
// include STL, algo, containers etc


template<typename First, typename Second>
struct Pair {
	First i;
	Second j;
};

#include <vector>
#include <algorithm>

void usePair() {
	Pair<int, double> p;
	std::vector<int> vec;
	std::sort(vec.begin(), vec.end());
	std::vector<double> dvec;
	std::vector<Pair<int, double>> pvec;
}


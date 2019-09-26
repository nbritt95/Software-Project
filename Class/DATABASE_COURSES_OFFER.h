#include<iostream>
#include<string>
#include<vector>
using namespace std;

#ifndef DATABASE_COURSES_OFFER
#define DATABASE_COURSES_OFFER
enum key {
	null,
	COMPUTER,
	MATH
};
vector<string> category{
	"empty",
	"CS",
	"MATH"
};

vector<vector<string>> COURSE_NUMBER{
	{"0"},
	{ "1230","1240" }, // there are 2 classes in the computer science: Key COMPUTER
	{ "1010","1020" }  // there are 2 classes in Math major
};

vector<vector<string>> COURSE_NAME{
	{"0"},
	{ "C++1","C++2" },           // name of each courses we offer in computer science: Key COMPUTER
	{ "ALGEBRA","PRE-CALCULUS" } // name of each courses we offer in Math major 
};


const unsigned COURSE_NUMBER_LENGTH = 4;


// check if the input major is in our category or not
bool verify_couse_initial(string &major, const vector<string> category, unsigned size, key &first_key) {
	for (unsigned i{ 0 }; i < size; ++i) {
		if (major == category.at(i)) {
			first_key = static_cast<key>(i);
			return true;
		}
	}
	return false;
}

// if function "verify_couse_initial" return true, we check the Major's course number to see if the input number
// match with our number in the system
// Ex: we have input Major is CS --> "verify_couse_initial" return true
//     --> then the course belong to COMPUTER class
//     in the COMPUTER class, if the input number match any number in COMPUTER class, we will add its correponding to C_name also
//     then the fuction return true; 
bool verify_couse_number(string C_number, const vector<vector<string>> courseNumber,
						 key key_course, unsigned &second_key){
	unsigned iterations = courseNumber.at(key_course).size();
	for (unsigned i{ 0 }; i < iterations; ++i){
		if (C_number == courseNumber.at(key_course).at(i)){
			second_key = i;
			return true;
		}
	}
	return false;
};
#endif // DEBUG

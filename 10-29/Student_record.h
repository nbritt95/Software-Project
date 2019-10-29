// we need a function to get student name
// we need a function to get student ID
// we need a function to add course into the student record ( I think 4 courses is max per student)
//*****we need a function to manipulate information from takenCourses (line 17) to calculate GPA
// we need a function to display all the courses that a particular take in a semester
// we need a function to display all grades for a particular courses which student are taking or took
// more information will be added later ( I currently ran out of idea )
#ifndef STUDENT_RECORD
#define STUDENT_RECORD
#include<iostream>
#include<string>
#include<vector>
#include"CLASS_COURSES.h"
using namespace std;

class student: public courses{
private:
	string ID, name;
	vector<courses> takenCourses;

	//BN======================================================================================
	double semesterGPA;
	double totalCreditHours;
	double totalGPA;
	//BN======================================================================================
public:
	void add_course_to_std_record();
	
	void displayCourses() {
		for(unsigned i{ 0 }; i < takenCourses.size(); ++i) {
			takenCourses.at(i).display();
		}
	}
	void displayAll() {
		displayCourses();
	}

	//BN======================================================================================
	double get_totalCreditHours(); //get_totalCreditHours(vector<courses> takenCourses, double totalCreditHours)
	double get_totalGPA(); //get_totalGPA(vector<courses> takenCourses, double totalGPA)
	double get_semesterGPA(); //get_semesterGPA(double semesterGPA)

	/*
	//test functions
	string getName(string name);
	string getID(string input);
	void pseudo_studentdisplay(); //pseudo student display
	*/
	//BN======================================================================================
};
void student::add_course_to_std_record() {
	courses temp; // temporarily hold information of a particular course ( let assume it as a folder for specific course)
	temp.add_courses();
	temp.add_date();
	temp.add_time();
	temp.add_course_grade();
	takenCourses.push_back(temp); // add the folder into takenCourses in line 17
}

//BN=============================GPA CALCULATION===============================================
double student::get_totalCreditHours() //get total credit hours
{
	int size = takenCourses.size();
	int totalCreditHours = 0;

	if (size == 0)
	{
		return totalCreditHours;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			totalCreditHours += takenCourses[i].course_credit();
		}
	}


	return totalCreditHours;
}

double student::get_totalGPA() //get sum of GPA from courses
{
	int size = takenCourses.size();
	int totalGPA = 0;

	if (size == 0)
	{
		return totalGPA;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			totalGPA += (takenCourses[i].course_final_gpa() * takenCourses[i].course_credit());
		}
	}

	return totalGPA;
}

double student::get_semesterGPA() //Calculates student's gpa for the semester
{
	double gpa = get_totalGPA();
	double credits = get_totalCreditHours();
	
	semesterGPA = gpa / credits;

	return semesterGPA;
}
//BN=============================GPA CALCULATION===============================================

/*
//BN TEST FUNCTIONS.. used to create a student with name and ID and then added courses & grades to check for accurate GPA calculation
string student::getName(string input)
{

	return name = input;
}

string student::getID(string input)
{

	return ID = input;
}

void student::pseudo_studentdisplay()
{
	cout << name << endl;
	cout << ID << endl;
}

//copy of kwan's function to ignore add_time()/add_date() and add 4 grades to test GPA calculation
void student::add_course_to_std_record() {
	courses temp; // temporarily hold information of a particular course ( let assume it as a folder for specific course)
	temp.add_courses();
	//temp.add_date();
	//temp.add_time();
	for (int i{ 0 }; i < 4; i++)
	{
		temp.add_course_grade();
	}
	takenCourses.push_back(temp);
}
//BN===========================================================================================
*/


#endif // !STUDENT_RECORD
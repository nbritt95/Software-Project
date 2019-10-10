// we need a function to get student name
// we need a function to get student ID
// we need a function to add course into the student record ( I think 4 courses is max per student)
// we need a function to manipulate information from takenCourses (line 17) to calculate GPA  
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


//BN======================================================================================
double student::get_totalCreditHours() //get total credit hours
{
	int size = takenCourses.size();
	int totalCreditHours;

	for (int i = 0; i < size ; i++)
	{
		totalCreditHours += takenCourses[i].course_credit;
	}

	return totalCreditHours;
}

double student::get_totalGPA() //get sum of GPA from courses
{
	int size = takenCourses.size();

	for (int i = 0; i < size; i++)
	{
		totalGPA += takenCourses[i].course_final_gpa;
	}

	return totalGPA;
}

double student::get_semesterGPA()
{
	double gpa = get_totalGPA();
	double credits = get_totalCreditHours();
	
	semesterGPA = (gpa / credits);

	return semesterGPA;
}
//BN======================================================================================
#endif // !STUDENT_RECORD
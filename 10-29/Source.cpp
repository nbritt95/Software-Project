#include<iostream>
#include<string>
#include<vector>
#include"CLASS_COURSES.h"
#include"Student_record.h"

using namespace std;
int main() {

	//TEST CASE BY KWAN
	//input for my test case
	// cs
	//1230
	//1
	//2
	//3
	//4
	// the first display of my c1
	// 1(pick option 1) -> 9 ( change start date to 9)
	// 1(pick option 1) -> 8 ( change start time to 8)
	// 90 (set the 1 exam to 90)
	// the second display of my c1

	/*
	courses c1;      // create an object name c1 to test my functions
	c1.add_courses();// promt the admin to register course for student
	c1.add_date();   // promt the admin to add start date and final date of the course from previous statement ( line 10 )
	c1.add_time();   // promt the admin to add start time and end time of the course from line 10

	c1.display();    // display all the information of the course
	cout << "\n\n";
	c1.edit_date();  // test function edit_date to make change on start date, end date, or both of the course which is registered from line 10
	c1.edit_time();  // test function edit_time to make change on start time, end time, or both of the course which is registered from line 10
	c1.add_course_grade();// test function add_course_grade() to add grade for the exam of the course which is registered from line 10
	//c1.edit_grade() : still be in the process of implementation, dont use this function
	c1.display();    // display all information again to see if the changes from line 15 and 16 are save to the object c1
	*/
	

	/* TEST CASE BY BRENDAN;
	//made sure GPA calculation was correct. made a copy of kwan's add_course_to_std_record() to ignore adding class time/date. function can be found in BN test function section in student_record.h

	student joeMama;
	joeMama.getName("Joe Mama"); //testing studnet name and id
	joeMama.getID("101010");
	joeMama.pseudo_studentdisplay();
	joeMama.add_course_to_std_record(); //adding course and grades to test GPA calculator
	joeMama.add_course_to_std_record();
	joeMama.add_course_to_std_record();
	joeMama.add_course_to_std_record();

	cout << "total credit hours: ";
	cout << joeMama.get_totalCreditHours() << endl;
	cout << "total gpa: ";
	cout << joeMama.get_totalGPA() << endl;
	cout << "semester gpa: ";
	cout << joeMama.get_semesterGPA() << endl;
	*/
	
	

	system("pause");
	return 0;
}
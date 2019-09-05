#include"Student_record.h"
#include<iostream>
int main() {
	string ID, name, courseName, courseNumber;
	//double score, GPA;
	
	vector<course> c;
	c.push_back(addClasses());
	for (int i{ 0 }; i < 2; ++i) {
		c.at(0).getScore();
	}
	c.push_back(addClasses());
	for (int i{ 0 }; i < 2; ++i) {
		c.at(1).getScore();
	}
	cout << endl << endl;
	c.at(0).displayCourse();
	cout << endl << endl;
	c.at(1).displayCourse();








	/*
	vector<student>studentRecord;
	studentRecord.push_back(addStudent());
	studentRecord.at(0).display();
	studentRecord.at(0).classes.push_back(addClasses());
	cout << endl << endl;

	for (int i{ 0 }; i < 2; ++i) {
		studentRecord.at(0).classes.at(i).displayCourse();
	}*/


	
	system("pause");
	return 0;
}
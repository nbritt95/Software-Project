#include<iostream>
#include<string>
#include<vector>
using namespace std;

#ifndef CLASS_COURSE
#define CLASS_COURSE
const int DATE_CHARACTER = 9;
const int TIME_CHARACTER = 8;
const int START_END_DATE = 2;
class courses {
private:
	string C_Name{ "0" }, C_Number{ "0" };
	string Start_date{ "0" }, End_date{ "0" };  // start date and end date of particular course
	string Start_time{ "0" }, End_time{ "0" };  // start time and end time of particular course
	int Credit_per_hour{ 0 };
	char Letter_grade{ '0' };
	vector<double>Score;  
	bool noScore{ true };
public:
	void setName(string cname);
	void setNum( string cnum);
	void setScores(double score);
	void setDate(string StartDate="0000", string EndDate="0000");
	void setTime(string StarTime="00:00" , string EndTime ="00:00");
	
	void add_date();
	void edit_date(string &StartDate, string &EndDate); //to make any change to start or end date of a course
	void add_time();
	void edit_time(string &StartTime, string &EndTime);
	void add_courses();
	void add_course_grade();
	void edit_grade();
	int course_final_grade();
	int course_credit();
	void display();
};
#endif

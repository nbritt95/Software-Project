#include<iostream>
#include<string>
#include<vector>
#include"DATABASE_COURSES_OFFER.h"
using namespace std;

#ifndef CLASS_COURSE
#define CLASS_COURSE
const int DATE_CHARACTER = 9;
const int TIME_CHARACTER = 8;
const int START_END_DATE = 2;
class courses {
private:
	string C_Name{ "0" }, C_Number{ "0" };
	vector<string> Date{ "0", "0" };  // 1st index represent start date of the course, 2nd index represent final date of the course;
	vector<string> Time{ "0", "0" };  // 1st index represent the time course start, 2nd index represent the time course end
	int Credit_per_hour{ 0 };
	char Letter_grade{ '0' };
	vector<double>Score;  
	bool noScore{ true };
	
	//BN
	double courseGPA;
	//BN
public:
	void setName(string cname);
	void setNum(string major, string cnum);
	void setScores(double score);
	void setDate(string date="  ");
	void setTime(string time = "00:00");
	
	void add_date();
	void edit_date(); //to make any change to start or end date of a course

	void add_time();
	void edit_time();
	void add_courses();
	void add_course_grade();
	void edit_grade();
	char course_final_grade();
	int course_credit();
	void display();

	//BN
	double course_final_gpa();
	//BN
};

void courses::setName(string cname) {
	C_Name = cname;
}
	// need to look at this again
void courses::setNum(string major, string cnum) {
	// need to check major if major'value is not correct, 
	C_Number = major + " " + cnum;
} 
void courses::setScores(double score) {

	Score.push_back(score);

}
void courses::setDate(string date) {
	Date.push_back( date);
} 

	// the function add_date() (line 58) allow admin to add Start date and Final date of a particular course   
    // -->the result will be save into variable Date ( line 15)
	// the function edit_date() (line 79) allow admin to make changes on Start date and Final date or both of a particular course
	// -->the result will be save into variable Date ( line 15)
void courses::add_date () {
	vector<string> date_schedule;
	string start_date, end_date;        //0123456789
	cout << "Enter start date with format MM/DD/YYYY: ";
	cin >> start_date;
	date_schedule.push_back(start_date);

	cout << "Enter final date of class with format MM/DD/YYYY:";
	cin >> end_date;
	date_schedule.push_back(end_date);
	
	Date = date_schedule;
	while (Date.at(0).compare(Date.at(1)) == 0) {
			cout << "Start date and End date can not be the same:" << endl;
			edit_date();
			//start_date = date_schedule.at(0);
			//end_date = date_schedule.at(1);
	}

	Date=date_schedule;
}                                                                            
void courses::edit_date(){
	bool quit{ false };
	vector<string> date_schedule(2);
	date_schedule = Date;
	do {
		cout << "Edit START DATE press 1:" << endl;
		cout << "Edit FINAL DATE press 2:" << endl;
		cout << "Edit both START DATE and FINAL DATE press 3: " << endl;
		char option;
		cin >> option;
		if (option == '1') {
			cout << "Enter start date with format MM/DD/YYYY: ";
			cin >> date_schedule.at(0);
			quit = true; // exit program
		}
		else if (option == '2') {
			cout << "Enter final date of class with format MM/DD/YYY: ";
			cin >> date_schedule.at(1);
			quit = true; // exit program
		}
		else if (option == '3') {
			cout << "Enter start date with format MM/DD/YYYY: ";
			cin >> date_schedule.at(0);
			cout << "Enter final date of class with format MM/DD/YYY: ";
			cin >> date_schedule.at(1);
			quit = true; // exit program
		}
		else
			quit = false;
	} while (!quit);
	Date = date_schedule;
}  
//***********************************************************************************************************************************
    // the add_time() (line 116) allow admin to add Start time and End time of a particular course
	// -->the result will be save into varialbe Time( line 16)
	// the function edit_time() (line 138) allow amin to make changes on either Start time, End time, or both of a particular course
	// -->the result will be save into varialbe Time( line 16)
void courses::add_time() {
	//time_schedule: 1st index represent the time course start, 2nd index represent the time course end
	vector<string> time_schedule;
	string time_start, time_end;
	cout << "Enter time the class start: ";
	cin >> time_start;
	cout << "Enter time the class end: ";
	cin >> time_end;

	time_schedule.push_back(time_start);// add starting time of the course into 1st index of time_schedule
	time_schedule.push_back(time_end);  // add ending time of the course into 2nd index of time_schedule
	Time = time_schedule;
	// check if the start time and end time of the course are the same
	// if they are the same, the "while" will execute; 0 indicate start time and end time are the same 
	while (Time.at(0).compare(Time.at(1)) == 0) {
		cout << "course's start time and end time can not be the same: ";
		edit_time(); // call edit_time function to change either start time, end time, or both
		time_start = time_schedule.at(0);
		time_end = time_schedule.at(1);
	}
	Time = time_schedule;
}
void courses::edit_time() {
	bool quit{ false };
	vector<string> time_schedule(2);
	time_schedule = Time;
	do {
		cout << "Edit START TIME press 1:" << endl;
		cout << "Edit END TIME press 2:" << endl;
		cout << "Edit both START TIME and END TIME press 3: " << endl;
		char option;
		cin >> option;
		if (option == '1') {
			cout << "Enter START TIME with am or pm format: ";
			cin >> time_schedule.at(0);
			quit = true; // exit program
		}
		else if (option == '2') {
			cout << "Enter END TIME with am or pm formart: ";
			cin >> time_schedule.at(1);
			quit = true; // exit program
		}
		else if (option == '3') {
			cout << "Enter START TIME with am or pm format: ";
			cin >> time_schedule.at(0);
			cout << "Enter END TIME with am or pm formart: ";
			cin >> time_schedule.at(1);
			quit = true; // exit program
		}
		else
			quit = false;
	} while (!quit);
	Time = time_schedule;
}
//************************************************************************************************************************************


//************************************************************************************************************************************
    // the function add_course_grade() (line 173) allow admin to add grade into a particular course
	//--> the result will be saved into variable Score (line 17)
	// the function edit_grade() (line 182) allow admin to make changes of grade on particular exam of a specific course
	//--> the result will be saved into variable Score (line 17)
void courses::add_course_grade() {
	double grade;
	cout << "Enter score of the exam: ";
	cin >> grade;
	noScore = false;
	setScores(grade);
}
void courses::edit_grade() {

	if (noScore) {
		cout << "There is no grade for the exam in this course" << endl;
	}
	else {
		unsigned examNumber;
		cout << "What exam do you want to adjust the grade: ";
		cin >> examNumber;
		cout << "New grade for the exam " << examNumber+1 << " is: ";
		cin >> Score.at(examNumber);
	}
}
	// the edit_grade() still in the process of implementation; dont use this
//************************************************************************************************************************************


//************************************************************************************************************************************
// the function add_courses will promt the user to register for course
void courses::add_courses() {
	cout << boolalpha;
	bool quit{ false };
	string C_number;
	string C_name;
	string major;
	do {
		cout << "Enter major's initial: ";
		cin >> major;
		// convert characters in (major) into capital characters
		for (unsigned i{ 0 }; i < major.size(); ++i)
			major.at(i) = toupper(major.at(i));


		key first_key; // to hold the index of specific course which the input major belong to

		bool check;     // check if the input major is in our category or not
		check = verify_couse_initial(major, category, category.size(), first_key);

		if (check == true) {//check true, false of major
			// if check is true (the input major is match our offered course category)
			// execute "do while" loop to get course number
			do {
				cout << "enter course number: ";
				cin >> C_number;

				//vector COURSE_NAME AND vector COURSE_NUMBER using the same index because they bond together
				//Example: cs 1230 will be c++1, they are both at the index 1 of both vector.
				unsigned second_key{ 0 };
				check = verify_couse_number(C_number, COURSE_NUMBER, first_key, second_key);

				
				if (check == true) {
					// if the input course number match with our course number for specific course we offer
					// adding the name of the course corresponding to the course number
					C_name = COURSE_NAME.at(first_key).at(second_key);
					C_Name = C_name;
					C_Number = C_number;
					quit = true;
				}
				else {
					// if the input course number does not match with our course number for specific course we offer
					// asking the user to continous to register or stop the process
					char decision;
					cout << C_number << " not match our system number. Please enter again. Y or y for Yes ";
					cin >> decision;
					if (decision == 'Y' || decision == 'y') {
						quit = false;
					}
					else
						quit = true;
				}
			} while (!quit);
		}
		//if check is false (input major is not in our offer course category)
		//ask the user again to continous to register or stop the process
		else {
			char decision;
			cout << major << " not match our system catergory. Please enter again. Y or y for Yes ";
			cin >> decision;
			if (decision == 'Y' || decision == 'y') {
				quit = false;
			}
			else
				quit = true;
		}
	} while (!quit);

};
//************************************************************************************************************************************

//************************************************************************************************************************************
// the function display() will show all the information of the course in the following
// course name, course number, exams, start date, end date, start time, end time
int courses::course_credit() {
	Credit_per_hour = C_Number.at(1) - 48 ; // course's credit per hour is the second digit in the course number
	return Credit_per_hour;
}
char courses:: course_final_grade() {
	char letterGrade;
	if (Score.size() == 4) {
		double sum{ 0 };
		
		for (unsigned i{ 0 }; i < 4; ++i) {
			sum += Score.at(i);
		}
		
		if (sum >= 90) {
			letterGrade = 'A'; //4.0
		}
		else if (sum >= 80) {
			letterGrade = 'B'; //3.0
		}
		else if (sum >= 70) {
			letterGrade = 'C'; //2.0
		}
		else if (sum >= 60) {
			letterGrade = 'D'; //1.0
		}
		else
			letterGrade = 'F'; //0.0
	}
	else {
		cout << "Not enough 4 scores" << endl; // default is 4 scores for each class;
		letterGrade = 'N';                     // indicate not enough scores
	}
	return letterGrade;
}
void courses::display() {
	cout << "course name: " << C_Name << endl;
	cout << "course number: " << C_Number << endl;
	if (noScore == true) {

	}
	else {
		for (unsigned i{ 0 }; i < Score.size(); ++i) {
			cout << "Exam " << i + 1 << " score: ";
			cout << Score.at(i) << endl;
		}
	}
	cout << "Start date: " << Date.at(0) << endl;
	cout << "End date: " << Date.at(1) << endl;
	cout << "Class begin at: " << Time.at(0) << endl;
	cout << "Class end at: " << Time.at(1) << endl;
	//BN======================================================================================
	cout << "Course Credit Hour: " << Credit_per_hour << endl;
	//BN======================================================================================

}
//BN======================================================================================
double courses::course_final_gpa() {
	double courseGPA;
	if (Score.size() == 4) {
		double sum{ 0 };

		for (unsigned i{ 0 }; i < 4; ++i) {
			sum += Score.at(i);
		}

		if (sum >= 90) {
			courseGPA = 4.0; //4.0 A
		}
		else if (sum >= 80) {
			courseGPA = 3.0; //3.0 B
		}
		else if (sum >= 70) {
			courseGPA = 2.0; //2.0 C
		}
		else if (sum >= 60) {
			courseGPA = 1.0; //1.0 D
		}
		else
			courseGPA = 0.0; //0.0 F
 	}
	else {
		cout << "Not enough entries for scores (4 is needed)." << endl; // default is 4 scores for each class;
		courseGPA = 0;                     // indicate not enough scores
	}
	return courseGPA;
}
//BN======================================================================================

#endif // !CLASS_COURSE


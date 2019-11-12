#include"CLASS_COURSES.h"
#include"DATABASE_COURSES_OFFER.h"
bool DetermineCourse(string &major, bool &quit, key &first_key);
bool DetermineCourseNumber(string &C_number, key first_key, unsigned &second_key);
void courses::setName(string cname) {
	C_Name = cname;
}
// need to look at this again
void courses::setNum(string cnum) {
	// need to check major if major'value is not correct, 
	C_Number = cnum;
}
void courses::setScores(double score) {

	Score.push_back(score);

}
void courses::setDate(string StartDate, string EndDate){
	Start_date = StartDate;
	End_date = EndDate;
}
void courses::setTime(string StarTime, string EndTime) {
	Start_time = StarTime;
	End_time = EndTime;
}


// the function add_date() (line 58) allow admin to add Start date and Final date of a particular course   
// -->the result will be save into variable Date ( line 15)
// the function edit_date() (line 79) allow admin to make changes on Start date and Final date or both of a particular course
// -->the result will be save into variable Date ( line 15)
void courses::add_date() {
	string start_date, end_date;        //0123456789
	cout << "Enter start date with format MM/DD/YYYY: ";
	cin >> start_date;

	cout << "Enter final date of class with format MM/DD/YYYY:";
	cin >> end_date;
	
	while (start_date.compare(end_date) == 0) {
		cout << "Start date and End date can not be the same:" << endl;
		edit_date(start_date,end_date);
	}
}

void courses::edit_date(string &StartDate, string &EndDate) {
	bool quit{ false };
	do {
		cout << "Edit START DATE press 1:" << endl;
		cout << "Edit FINAL DATE press 2:" << endl;
		cout << "Edit both START DATE and FINAL DATE press 3: " << endl;
		char option;
		cin >> option;
		if (option == '1') {
			cout << "Enter start date with format MM/DD/YYYY: ";
			cin >> StartDate;
			quit = true; // exit program
		}
		else if (option == '2') {
			cout << "Enter final date of class with format MM/DD/YYY: ";
			cin >> EndDate;
			quit = true; // exit program
		}
		else if (option == '3') {
			cout << "Enter start date with format MM/DD/YYYY: ";
			cin >> StartDate;
			cout << "Enter final date of class with format MM/DD/YYY: ";
			cin >> EndDate;
			quit = true; // exit program
		}
		else
			quit = false;
	} while (!quit);

	setDate(StartDate, EndDate);
}


//***********************************************************************************************************************************
// the add_time() (line 116) allow admin to add Start time and End time of a particular course
// -->the result will be save into varialbe Time( line 16)
// the function edit_time() (line 138) allow amin to make changes on either Start time, End time, or both of a particular course
// -->the result will be save into varialbe Time( line 16)
void courses::add_time() {
	//time_schedule: 1st index represent the time course start, 2nd index represent the time course end
	string time_start, time_end;
	cout << "Enter time the class start: ";
	cin >> time_start;
	cout << "Enter time the class end: ";
	cin >> time_end;

	// check if the start time and end time of the course are the same
	// if they are the same, the "while" will execute; 0 indicate start time and end time are the same 
	while (time_start.compare(time_end) == 0) {
		cout << "course's start time and end time can not be the same: ";
		edit_time(time_start, time_end); // call edit_time function to change either start time, end time, or both
	}
}
void courses::edit_time(string &StartTime, string &EndTime) {
	bool quit{ false };
	do {
		cout << "Edit START TIME press 1:" << endl;
		cout << "Edit END TIME press 2:" << endl;
		cout << "Edit both START TIME and END TIME press 3: " << endl;
		char option;
		cin >> option;
		if (option == '1') {
			cout << "Enter START TIME with am or pm format: ";
			cin >> StartTime;
			quit = true; // exit program
		}
		else if (option == '2') {
			cout << "Enter END TIME with am or pm formart: ";
			cin >> EndTime;
			quit = true; // exit program
		}
		else if (option == '3') {
			cout << "Enter START TIME with am or pm format: ";
			cin >> StartTime;
			cout << "Enter END TIME with am or pm formart: ";
			cin >> EndTime;
			quit = true; // exit program
		}
		else
			quit = false;
	} while (!quit);
	
	setTime(StartTime, EndTime);
}
//************************************************************************************************************************************


//************************************************************************************************************************************
// the function add_course_grade() (line 173) allow admin to add grade into a particular course
//--> the result will be saved into variable Score (line 17)
// the function edit_grade() (line 182) allow admin to make changes of grade on particular exam of a specific course
//--> the result will be saved into variable Score (line 17)
void courses::add_course_grade() {
	double grade;
	cout << "Enter score of the exam "<<Score.size()+1<<" : ";
	cin >> grade;
	noScore = false;
	setScores(grade);
}
void courses::edit_grade() {
	if (noScore) {
		cout << "There is no grade for the exam in this course" << endl;
	}
	else {
		unsigned examNumber; // allow user to enter the exam which need to be modified
		for (unsigned i{ 0 }; i < Score.size(); ++i) {
			cout << "Exam " << i + 1 << " score: ";
			cout << Score.at(i) << endl;
		}
		bool quit = false;
		do {
			try {
				cout << "What exam do you want to adjust the grade: ";
				cin >> examNumber;
				if (examNumber > Score.size()) {
					throw examNumber; // if the exam number does not exist, throw it to line 165
				}
				cout << "New grade for the exam " << examNumber << " is: ";
				cin >> Score.at(examNumber - 1);
				quit = true;
			}
			catch (unsigned x) {
				cout << "The exam " << examNumber << " does not exist." << endl;
			}
		} while (!quit);	
	}
}
int courses::course_credit() {
	Credit_per_hour = C_Number.at(1) - 48; // course's credit per hour is the second digit in the course number
	return Credit_per_hour;
}
char courses::course_final_grade() {
	char letterGrade;
	if (Score.size() == 4) {
		double sum{ 0 };
		for (unsigned i{ 0 }; i < 4; ++i) {
			sum += Score.at(i);
		}
		sum /= 4;
		if (sum >= 90) {
			letterGrade = 'A';
		}
		else if (sum >= 80) {
			letterGrade = 'B';
		}
		else if (sum >= 70) {
			letterGrade = 'C';
		}
		else if (sum >= 60) {
			letterGrade = 'D';
		}
		else
			letterGrade = 'F';
	}
	else {
		cout << "Not enough 4 scores" << endl; // default is 4 scores for each class;
		letterGrade = 'N';                     // indicate not enough scores
	}
	return letterGrade;
}
//************************************************************************************************************************************


//************************************************************************************************************************************
// the function add_courses will promt the user to register for course
void courses::add_courses() {
	cout << boolalpha;
	bool quit{ false };
	string C_number;
	string C_name;
	string major;
	key first_key;  // to hold the index of specific course which the input major belong to
	unsigned second_key; // to hole the index of the specific course number
	bool check;

	check = DetermineCourse(major, quit, first_key); // check if the input course's initial letter is in our database or not
	if (check == true) {//check true, false of major
						// if check is true (the input major is match our offered course category)
						// execute "do while" loop to get course number
		check = DetermineCourseNumber(C_number, first_key, second_key);
		if (check == true) {
			// if the input course number match with our course number for specific course we offer
			// adding the name of the course corresponding to the course number
			setName(COURSE_NAME.at(first_key).at(second_key));
			setNum(C_number);
		}
	}
}
//************************************************************************************************************************************

//************************************************************************************************************************************
// the function display() will show all the information of the course in the following
// course name, course number, exams, start date, end date, start time, end time
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
	cout << "Start date: " << Start_date << endl;
	cout << "End date: " << End_date << endl;
	cout << "Class begin at: " << Start_time << endl;
	cout << " Class end at: " << End_time << endl;

}
bool DetermineCourse(string &major, bool &quit, key &first_key) {
	quit = false;
	bool check;     // check if the input major is in our category or not
	do {
		cout << "Enter major's initial: ";
		cin >> major;
		// convert characters in (major) into capital characters
		for (unsigned i{ 0 }; i < major.size(); ++i)
			major.at(i) = toupper(major.at(i));

		check = verify_couse_initial(major, category, category.size(), first_key);
		if (check == false) {
			char decision;
			cout << major << " not match our system catergory. Please enter again. Y or y for Yes ";
			cin >> decision;
			if (decision == 'Y' || decision == 'y') {
				quit = false;
			}
			else
				quit = true;
		}
		else
			quit = true;
	} while (!quit);
	return check;
}
bool DetermineCourseNumber(string &C_number,COURSE_NUMBER, key first_key, unsigned &second_key) {
	bool quit = false;
	bool check;  // check if the input course number is in the list of specific that we offer or not
	do {
		cout << "enter course number: ";
		cin >> C_number;
		//vector COURSE_NAME AND vector COURSE_NUMBER using the same index because they bond together
		//Example: cs 1230 will be c++1, they are both at the index 1 of both vector.
		check = verify_couse_number(C_number, first_key, second_key);
		if (check == false) {
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
		else
			quit = true;
	} while (!quit);
	return check;
}
	


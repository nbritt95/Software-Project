#ifndef STUDENT_RECORD
#define STUDENT_RECORD
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Let assume this is our database for courses that we offer in our school
//***********************************************
vector<string> COURSE_NAME  { "Computer","Math" };
vector<string> COURSE_NUMBER{ "cs1","m1" };
//***********************************************
class course {
	private:
	string courseName;
	vector<double> score;

	public:
	string getCourseName(){
		cout << "Course's name: ";
		cin >> courseName;
		return courseName;
	}
	vector<double> getScore()
	{
		double temporaryScore;
		cin >> temporaryScore;
		score.push_back(temporaryScore);
		return score;
	}
	void displayCourse() {
		cout << courseName << endl;
		for (unsigned i{ 0 }; i < score.size(); ++i) {
			cout << "Exam " << i + 1 << ": " << score.at(i) << endl;
		}
	}
	
};
course addScores()
{
	course tempClass;
	tempClass.getScore();
	return tempClass;
}
course addClasses() {
	course tempClass;
	tempClass.getCourseName();
	

	// will ask user to input the scores for each exam in a particular course that student earned so far
	// will 
	return tempClass;
}










class student {
	private:
		string ID;
		string Name;
	
		//vector<string> courseName;  //This vector will hold 
		//vector<string> courseNumber;
		double score, GPA;
	public:
		vector<course> classes;
		// This function allow the user to input student ID in the record
		string getId(){
			cout << "Enter Student ID: ";
			cin >> ID;
			return ID;
		}
		// This function allow the user to input student's name
		string getName() {
			string Fname, Lname;
			cout << "Student first name: " << endl;
			cin >> Fname;
			cout << "Student last name: " << endl;
			cin >> Lname;
		
			return Name = Fname + " " + Lname;
		}
		void display() {
			cout << "Student ID:" << ID << endl;
			cout << "Student courses: ";
			classes.at(0).displayCourse();
		}
};

 student addStudent() {
	 student temp;
	 temp.getId();
	 //=============================================================================
		 // adding courses to student's record
	 temp.classes.push_back(addClasses()); 
		 // will promt the user to determine how many classes need to be added in
	 //===============================================================================


	 //will have more information to be added
	 return temp;
	
 }
#endif // !STUDENT_RECORD


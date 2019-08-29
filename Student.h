#ifndef	STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string>

using namespace std;

class Student{

	private: //Should we use private?
		double gpa, examScore;
		string name, idNumber;
	
	public:
		void setName(string nm){
			name = nm;
		}
		void setID(string id){
			idNumber = id;
		}
		void setGPA(double grade){
			gpa = grade;
		}
		void setExamScore(double es){
			examScore = es;
		}
		string getName(){
			return name;
		}
		string getID(){
			return idNumber;
		}
		double getGPA(){
			return gpa;
		}
		double getExamScore(){
			return examScore;
		}

};

#endif

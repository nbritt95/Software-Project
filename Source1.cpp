#include <iostream>
#include <vector>

using namespace std;

float GPA()
{
	float grade_points[12] = { 4.00,3.70,3.33,3.00,2.70,2.30,2.00,1.70,1.30,1.00,0.70,0 };
	
	char letter_grade[12] = { 'A','A-','B+','B','B-','C+','C','C','D+','D','D-','F' };
	
	
	
	return 0;
}

void total_grade(vector <int>grades, vector<char> letter_grades)
{
	char letter_grade[12] = { 'A','A-','B+','B','B-','C+','C','C-','D+','D','F' };

	int total_grade = 0;

	for (int i = 0; i++; i < grades.size())
	{
		total_grade += grades[i];
	}

	int average = total_grade / grades.size();

	if (average >= 93)
		letter_grades.push_back(letter_grade[0]);
	else if (average >= 90 && average <=92)
		letter_grades.push_back(letter_grade[1]);
	else if (average >= 87 && average <= 89)
		letter_grades.push_back(letter_grade[2]);
	else if (average >= 83 && average <= 86)
		letter_grades.push_back(letter_grade[3]);
	else if (average >= 80 && average <= 82)
		letter_grades.push_back(letter_grade[4]);
	else if (average >= 77 && average <= 79)
		letter_grades.push_back(letter_grade[5]);
	else if (average >= 73 && average <= 76)
		letter_grades.push_back(letter_grade[6]);
	else if (average >= 70 && average <= 72)
		letter_grades.push_back(letter_grade[7]);
	else if (average >= 67 && average <= 69)
		letter_grades.push_back(letter_grade[8]);
	else if (average >= 65 && average <= 66)
		letter_grades.push_back(letter_grade[9]);
	else if (average < 65)
		letter_grades.push_back(letter_grade[10]);


}

void main()
{
	vector<int> grades;
	vector<string> letter_grades;


}
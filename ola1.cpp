//* ************************* Open Lab Assignment #1****************************
// FILE: ola1.cc
// AUTHOR: Norris, Joel R.
// Instructor: Dr. Dong
// COURSE:  CSCI 3110-00X
// DATE Due: 2017_01_30_0400
// DESCRIPTION: Search and display information on all students in the class
//				also input student info from data file
// OUTPUT: 1.  Student info
//         2.  Cumulative class info
// PURPOSE: Learn to work w/ arrays, structure, and I/O
//			Get familiar with Visual Studio Environment
//*****************************************************************************/

// preprocessor directives
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// variables
const int MAX_STUDENTS = 17;
const string FILENAME = "point.dat";
const int COLUMN_WIDTH = 7;

// data structures
struct Student {

	string c_number;
	int CLA;
	int OLA;
	int Quiz;
	int Homework;
	int Exam;
	int Bonus;
	int Total;
	int FinalGrade;

};

// function prototypes
// NOTE : HAVE TO PASS IN ARRAY SIZE TO FUNC ARGS
void readFile(string filename, Student *studentArray);

void printStudent(string cNumber, Student *studentArray);

void printAllStudents(Student *studentArray);

void printTableHeader();


// main program logic
int main() {

	//cout << "Hello World" << endl;

	// create array Roster
	Student Roster[MAX_STUDENTS];

	// read in data from file to array
	readFile(FILENAME, Roster);

	// prompt user for c#
	string cNumber;
	cout << "Please enter the student's c-number: ";
	cin >> cNumber;
	// display info of student w/ c#
	printStudent(cNumber, Roster);

	// display info of all students
	printAllStudents(Roster);

	// gtfo.
	return 0;

}

// Read file data into Roster Array
// Assign student data to each struct field accordingly
// PASS IN ARRAY SIZE!!!
void readFile(string filename, Student *studentArray) {

	ifstream inFile;

	inFile.open(filename);

	if ( !inFile ) {
		cout << "Error reading file" << endl;
		return;
	}

	//for (int i=0; i<MAX_STUDENTS; i++) {
	
	int i=0;
	string line;
	// skip the table header in the file
	getline( inFile, line);
	while( getline(inFile, line) ) {

		//cout << line << endl;

		stringstream ss(line);
		ss >> studentArray[i].c_number 
			>> int(studentArray[i].CLA)
			>> int(studentArray[i].OLA) 
			>> int(studentArray[i].Quiz) 
			>> int(studentArray[i].Homework) 
			>> int(studentArray[i].Exam) 
			>> int(studentArray[i].Bonus); 
			//>> studentArray[i].Total 
			//>> studentArray[i].FinalGrade;

		i++;

	}

	inFile.close();		


}

// print out Data for one student based on user input
void printStudent(string cNumber, Student *studentArray) {

	printTableHeader();

	for (int i=0; i<MAX_STUDENTS; i++) {
		
		// if the cNumbers match, print out student data.
		if (studentArray[i].c_number == cNumber) {
			cout << setw(COLUMN_WIDTH) <<
				studentArray[i].c_number << "\t" <<
				studentArray[i].CLA << "\t" <<
				studentArray[i].OLA << "\t" <<
				studentArray[i].Quiz << "\t" <<
				studentArray[i].Homework << "\t\t" <<
				studentArray[i].Exam << "\t" <<
				studentArray[i].Bonus << "\t" <<
				//studentArray[i].Total << "\t" <<
				//studentArray[i].FinalGrade << 
			endl;

		}

	}

}

// print out data of all students
void printAllStudents(Student *studentArray) {

	cout << "\nAll student information is given below:" << endl;

	printTableHeader();

	// loop through roster array and print out struct data for each student
	for (int i=0; i<MAX_STUDENTS; i++) {
		cout << setw(COLUMN_WIDTH) <<
			studentArray[i].c_number << "\t" <<
			studentArray[i].CLA << "\t" <<
			studentArray[i].OLA << "\t" <<
			studentArray[i].Quiz << "\t" <<
			studentArray[i].Homework << "\t\t" <<
			studentArray[i].Exam << "\t" <<
			studentArray[i].Bonus << "\t" <<
			//studentArray[i].Total << "\t" <<
			//studentArray[i].FinalGrade << 
		endl;
	}

}

// print table header
void printTableHeader() {

	cout << setw(COLUMN_WIDTH) << "\nID\tCLA\tOLA\tQuiz\tHomework\tExam\tBonus\tTotal\tFinalGrade\t" << endl;
	
}



#include <iostream>
#include <iomanip>
using namespace std;

const int NAME_LENGTH = 35;

struct Student{
	char name[NAME_LENGTH]; // Student's name
	int idNum;              // Student ID number
	int creditHours;        // Credit hours enrolled
	double gpa;             // Current GPA
};

int main(){

	char term;

	//prototype
	void getData(Student *);

	// structure identifier
	Student freshman;

	cout << "Enter the following student data:\n";

	getData(&freshman);    // Pass the address of freshman.

	cout << "\nThis is the information you have entered.\n";
	cout << setprecision(2);
	cout << "Name: " << freshman.name << endl;
	cout << "ID Number: " << freshman.idNum << endl;
	cout << "Credit Hours: " << freshman.creditHours << endl;
	cout << "GPA: " << freshman.gpa << endl << endl;

	cout << "Is this information correct? (Y,N): ";
	cin  >> term;

	if(term=='y' || term=='Y'){
		cout << "Confirmed. Have a nice day.\n\n";
	}
	else{
		cout << "Confirmed. Please run program again and re-enter information.\n\n";
	};

	// program termination
	cout << "***END OF PROGRAM***\n";
	cin.clear(); cin.ignore(); cin.get();

	return 0;
}


void getData(Student *s){
	cout << "Student name: ";
	cin.getline(s->name, NAME_LENGTH);

	cout << "Student ID Number: ";
	cin >> s->idNum;

	cout << "Credit Hours Enrolled: ";
	cin >> s->creditHours;

	cout << "Current GPA: ";
	cin >> s->gpa;
}

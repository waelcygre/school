#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//prototypes
void printHeading();
string enterPhoneNumber();
int isValid(string);
void displayResult(int, string);


int main()
{
	string number;
	int code;
	string choice;

	printHeading(); //infodump at beginning of program

	do{
		number = enterPhoneNumber(); 	//get number
		code = isValid(number);			//check if valid
		displayResult(code, number);	//display

		cout<<"Continue? (Y,N): "; cin>>choice;
		cout<<"\n\n";
	}while(choice=="y" || choice=="Y");

	cout<<"***END OF PROGRAM***\n";
    cin.clear(); cin.ignore(); cin.get(); //program wait

	return 0;
}

//General Functions

//get number
string enterPhoneNumber(){
	string num;
	cout << "Enter a phone number 8 or 11 digits in length: "; cin >> num;
	return num;
}

//check number
int isValid(string str){
	int code;
	string digits = "0123456789";

	if(str.length() != 8 && str.length() != 11){			//check length of number
		code=1;
	}
	else if(str.at(0) != '1'){							//check if it begins with 1
		code=2;
	}
	else if(str.find_last_not_of(digits) != string::npos){	//check string for only numbers
		code=3;
	}
	else{
		code=0;
	}
	return code;
}

//format for legibility
string formatNumber(string str){

	string format;

	if(str.length()==11){
		format = "1-(" + str.substr(1, 3) + ")-" + str.substr(4, 3) + "-" + str.substr(7);
	}
	else{
		format = "1-" + str.substr(1, 3) + "-" + str.substr(4);
	}
	return format;
}

//output number or error
void displayResult(int i, string phonenum)
{
	string formatted;
	if(i == 0)
	{
		formatted = formatNumber(phonenum);
		cout << "Formatted number is: " << formatted << "\n\n";
	}
	else
	{
		cout << "Invalid phone number: " << phonenum << "\n\n";
		cout << "Your call cannot be completed because:\n";

		if(i == 1){
			cout << "A phone number must have 8 or 11 characters.\n\n";
		}
		else if(i == 2){
			cout << "A phone number must begin with a 1.\n\n";
		}
		else{
			cout << "A phone number must contain only digits 0-9.\n\n";
		}
		cout << "Please try again." << endl;
	}
	return;
}

void printHeading(){
    cout << endl <<"Telephone Number Verification Program";
    cout << "\n\n";

    // program introduction and directions
    cout << "\nWelcome to the Telephone Number Verification program. ";
    cout << "\nWhen prompted, please enter either an 8 digit telephone number ";
    cout << "\nor an 11 digit telephone number. Valid telephone numbers ";
    cout << "\nwill always begin with 1, always have 8 digits or 11 digits, and ";
    cout << "\ncontain only the digits 0-9." ;
    cout << "\n\n";

    return;
}

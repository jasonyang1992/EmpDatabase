#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void enterData();
void searchData();
void editData();
void deleteData();
void displayData();

int main(){
	int choice;
	system("cls");
	system("title Database");
	cout << "Enter the number choice " << endl;
	cout << "1. Enter Data " << endl;
	cout << "2. Search Data " << endl;
	cout << "3. Edit Data " << endl;
	cout << "4. Delete Data " << endl;
	cout << "5. Display All Data " << endl;
	cout << "6. Exit " << endl;
	cout << endl;
	cin >> choice;

	switch (choice){
	case 1:
			   enterData();
			   break;
	
	case 2:
			   searchData();
			   break;
	
	case 3:
			   editData();
			   break;

	case 4:
				deleteData();
				break;

	case 5:
			   displayData();
			   break;
	
	case 6:
			   return 0;
	
	}
}

void enterData(){
	system("cls");
	int empID;
	string fName = "";
	string lName = "";
	string occupation = "";
	int age;
	int salary;

	cout << "Enter empID ";
	cin >> empID;

	cout << "Enter first name ";
	cin >> fName;

	cout << "Enter last name ";
	cin >> lName;

	cout << "Enter occupation ";
	cin >> occupation;

	cout << "Enter age ";
	cin >> age;

	cout << "Enter salary ";
	cin >> salary;

	// creates a text file with the emp ID name
	string empID2 = to_string(empID);
	empID2.append(".txt");

	// Create data
	ofstream newemployee(empID2);
	newemployee << empID << ' ' << fName << ' ' << lName << ' ' << occupation << ' ' << age << ' ' << salary << endl;
	newemployee.close(); 

	// create a text file with all the data to display all
	ofstream dir("directory.txt", ios::app);
	dir << empID << ' ' << fName << ' ' << lName << ' ' << occupation << ' ' << age << ' ' << salary << endl;
	dir.close();

	main();
	/*
		ofstream myfile;
		myfile.open("database.txt");
		myfile << "empID fName lName occupation age salary " << endl;
		myfile << empID << " " << fName << " " << lName << " " << occupation << " " << age << " " << salary << endl;
		myfile.close();
		main();
	*/
}

void searchData(){
	system("cls");
	int empID;
	string fName = "";
	string lName = "";
	string occupation = "";
	int age;
	int salary;

	cout << "Enter an employee ID number: ";
	cin >> empID;
	
	// Searching employee ID number
	string empID2 = to_string(empID);
	empID2.append(".txt");

	ifstream employee(empID2);
	while (employee >> empID >> fName >> lName >> occupation >> age >> salary){

		/*

		int fNameLength = fName.size();
		int lnameLength = lName.size();
		int lengthTotal = fNameLength + lnameLength;

			string answer;
			cout << "Is this the the employee you are searching for [y/n]" << endl;
			cout << fName << ' ' << lName << endl;
			cin >> answer;
		*/

		system("cls");

		cout << "EmpID:       " << empID << endl;
		cout << "First Name:  " << fName << endl;
		cout << "Last Name:   " << lName << endl;
		cout << "Age:         " << age << endl;
		cout << "Occupation:  " << occupation << endl;
		cout << "Salary:      " << salary << endl;

		/*
		if (answer == "y"){
			system("cls");
			cout << "Name";
			for (int y = 1; y < lengthTotal; y++){
				cout << " ";
			}
			cout << " age ";
			for (int z = 1; z < 2; z++){
				cout << " ";
			}
			cout << " salary ";
			cout << " ID# " << endl;
			for (int x = 1; x < lengthTotal + 30; x++){
				cout << "-";
				
			}
			cout << ' ' << endl;
			cout << fName << ' ' << lName << ' ' << age << ' ' << salary << ' ' << empID << endl;
		}
		*/

	}
	system("pause");
	main();
}

void editData(){
	system("cls");
	int empID;
	string fName = "";
	string lName = "";
	string occupation = "";
	int age;
	int salary;

	string newFName = "";
	string newLName = "";
	string newOccupation = "";
	int newAge;
	int newSalary;

	string choice;

	cout << "Enter an employee ID number to edit: ";
	cin >> empID;

	string empID2 = to_string(empID);
	empID2.append(".txt");

	ifstream employee(empID2);

	while (employee >> empID >> fName >> lName >> occupation >> age >> salary){

		cout << "-------Current Information-------" << endl;
		cout << endl;
		cout << "EmpID:       " << empID << endl;
		cout << "First Name:  " << fName << endl;
		cout << "Last Name:   " << lName << endl;
		cout << "Age:         " << age << endl;
		cout << "Occupation:  " << occupation << endl;
		cout << "Salary:      " << salary << endl;
		cout << endl;
		
		cout << "Is this the employee you wish to edit? [y/n] " << endl;
		cin >> choice;

		if (choice == "y"){
			cout << "Eneter new first name: ";
			cin >> newFName;
			cout << "Enter new last name: ";
			cin >> newLName;
			cout << "Enter new age: ";
			cin >> newAge;
			cout << "Enter new occupation: ";
			cin >> newOccupation;
			cout << "Enter new Salary: ";
			cin >> newSalary;

			ofstream employee2(empID2);
			employee2 << empID << ' ' << newFName << ' ' << newLName << ' ' << newOccupation << ' ' << newAge << ' ' << newSalary << endl;

			system("cls");

			cout << "-----Previous Information-----" << endl;
			cout << endl;
			cout << "EmpID:       " << empID << endl;
			cout << "First Name:  " << fName << endl;
			cout << "Last Name:   " << lName << endl;
			cout << "Age:         " << age << endl;
			cout << "Occupation:  " << occupation << endl;
			cout << "Salary:      " << salary << endl;

			cout << endl;
			cout << endl;

			cout << "-------New Information-------" << endl;
			cout << endl;
			cout << "EmpID:       " << empID << endl;
			cout << "First Name:  " << newFName << endl;
			cout << "Last Name:   " << newLName << endl;
			cout << "Age:         " << newAge << endl;
			cout << "Occupation:  " << newOccupation << endl;
			cout << "Salary:      " << newSalary << endl;
			cout << endl;
			system("pause");
			main();
		}
		else {
			cout << "Returning to menu" << endl;
			system("pause");
			system("cls");
			main();
		}
		
	}
}

void deleteData(){
	system("cls");
	int empID;

	cout << "Enter the EmpID you wish to delete" << endl;
	cin >> empID;

	string empID2 = to_string(empID);
	empID2.append(".txt"); // open file
	std::remove(empID2.c_str()); // deletes file

	cout << "The employee has been removed from the database" << endl;
	system("pause");
	main();
}

void displayData(){
	system("cls");
	int empID;
	string fName = "";
	string lName = "";
	string occupation = "";
	int age;
	int salary;
	cout << "------Complete Database Search------" << endl;
	cout << "------------------------------------" << endl;

	/*
	cout << "EmpID";
	for (int x = 1; x < 5; x++){
		cout << " ";
	}

	cout << "Name";
	for (int y = 1; y < 15; y++) {
		cout << " ";
	}
	cout << "Occupation";
	for (int c = 1; c < 10; c++){
		cout << " ";
	}
	cout << "Age";
	for (int v = 1; v < 4; v++){
		cout << " ";
	}
	cout << "Salary";
	cout << endl;
	*/

	ifstream dir("directory.txt");

	while (dir >> empID >> fName >> lName >> occupation >> age >> salary){

		cout << empID << " " << fName << " " << lName << " " << occupation << " " << age << " " << salary << endl;

	}
	system("pause");
	main();
	/*
	string data;
	ifstream myfile("directory.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, data))
		{
			cout << data << endl;
		}
		myfile.close();
	}

	else cout << "Unable to open file";
	system("pause");
	main();
	*/
}
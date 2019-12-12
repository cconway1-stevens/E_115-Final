#include<iostream>
#include<fstream>
#include<vector>
#include<ostream>
#include<sstream>
#include<string>
using namespace std;
class Date {
public:
	int month, day, year;
	Date() : month(0), day(0), year(0) {}

	void add() {
		int start = 1;
		//cout << endl;
		//cout << "========================== Date ==========================" << endl;

		while (start == 1) {
			int x;
			cout << endl;
			cout << "       Numerical Month: ";
			cin >> x;
			month = x;
			cout << endl;
			cout << "       Numerical Day: ";
			cin >> x;
			day = x;
			cout << endl;
			cout << "       Year: ";
			cin >> x;
			year = x;
			cout << endl;
			cout << "========================== Date CHECKER ==========================" << endl;
			cout << "The date entered is " << month << " /" << day << " /" << year << " " << endl;
			start = 0;
		}

	}
	void display_date() {
		cout << month << " / " << day << " / " << year << endl;

	}
	string display_date2() {
		return month + " / " + day + year;
	}
	void clear() {
		month = 00;
		day = 00;
		year = 0000;
	}
};
class Student {
private:
	int CWID, PO_Box;
	string first_Name, last_Name;
	Date date;

public:
	Student(string first_Name, string last_Name, int CWID, int PO_Box) :
		first_Name(first_Name), last_Name(last_Name), CWID(CWID), PO_Box(PO_Box), date() {}

	Student() {
		first_Name = "N/A", last_Name = "N/A";
		CWID = 0, PO_Box = 0;
	}
	vector <string> s_Fn;
	vector <string> s_Ln;
	vector <int> s_CWID;
	int list_order = 0;
	void add_data() {
		int start = 1;
		cout << "========================== ADDER ==========================" << endl;
		while (start == 1) {
			int x;
			int z;
			string y;
			cout << endl;
			cout << "First Name: ";
			cin >> y;
			first_Name = y;
			cout << endl;
			cout << "Last Name: ";
			cin >> y;
			last_Name = y;
			cout << endl;
			cout << "CWID: ";
			cin >> z;
			CWID = z;
			cout << endl;
			cout << "========================== ADDER CHECKER ==========================" << endl;
			cout << "Their First Name is " << first_Name << endl << "Their Last Name is " << last_Name << endl << "Their CWID is " << CWID << endl;
			cout << "If all information is correct please enter 1 if false enter 2" << endl;
			cin >> x;
			if (x == 1) {
				start = 0;
				vec_ZIP();
				add_file();
			}
			else {
				start = 1;
			}
		}
	}
	void show() {
		cout << first_Name << " " << last_Name << " " << CWID << " " << endl;
	}
	void add_file() {
		ofstream student_List;
		student_List.open("student_List.txt");
		student_List << first_Name << " " << last_Name << " " << CWID << " " << PO_Box << endl;
		student_List.close();
	}
	
	void fillVector() {
		ifstream readFile("student_List.txt");
		string curLine;
		Student temp;
		cin.ignore();
		while (!readFile.eof()) {
			getline(readFile, curLine);
			istringstream iss(curLine);
			iss >> temp.first_Name >> temp.last_Name >>temp. CWID >> temp.PO_Box;

		}
	}
	void vec_ZIP() {
		s_Fn.push_back(first_Name);
		s_Ln.push_back(last_Name);
		s_CWID.push_back(CWID);
	}

	// EDIT: added this
	friend ostream& operator << (ostream& s, Student x) {
		return s << x.first_Name << "\t" << x.last_Name << "\t" << x.CWID << "\t" << "PO: " << x.PO_Box << "\t";
	}
};


int main() {
	vector <Student> student_list;
	int str_prog = 1;
	while (str_prog == 1) {
		cout << "==================================================== Trax Pax ====================================================" << endl;
		cout << "Welcome to Trax Pax. What can I do for you ? \n \nType use the numbers to make selection" << endl;
		cout << "1). Add Student" << endl;
		cout << "2). Display Students" << endl;
		cout << "3). Recieved Postage" << endl;
		cout << "4). Release Postage" << endl;
		cout << "4). Display Postage" << endl;
		int a;
		cin >> a;
		switch (a) {
		case 1: {
			Student New;
			New.add_data();
			student_list.push_back(New);
			break;
		}

		case 2: {



			break;
		}


		}
		return(0);
	}
}


#include <iostream>
#include <string.h>
using namespace std;

class student_data;

class student {
    string name;
    int roll_number;
    string grade;
    char* division;
    string date_of_birth;
    char* blood_group;
    static int count;

public:
    student() { // Default Constructor
        name = " ";
        roll_number = 0;
        grade = " ";
        division = new char;
        date_of_birth = "dd/mm/yyyy";
        blood_group = new char[4];
    }

    ~student() { // Destructor
        delete division;
        delete[] blood_group;
    }

    static int getCount() {
        return count;
    }

    void getData(student_data*);
    void displayData(student_data*);
};

class student_data {
    string address;
    long int* telephone_number;
    long int* driving_license_number;
    friend class student;

public:
    student_data() { // Constructor
        address = " ";
        telephone_number = new long;
        driving_license_number = new long;
    }

    ~student_data() { // Destructor
        delete telephone_number;
        delete driving_license_number;
    }

    void getstudent_data() {
        cout << "Enter Contact Address : ";
        cin.get();
        getline(cin, address);
        cout << "Enter Telephone Number : ";
        cin >> *telephone_number;
        cout << "Enter Driving License Number : ";
        cin >> *driving_license_number;
    }

    void dispstudent_data() {
        cout << "Contact Address : " << address << endl;
        cout << "Telephone Number : " << *telephone_number << endl;
        cout << "Driving License Number : " << *driving_license_number << endl;
    }
};

inline void student::getData(student_data* st) {
    cout << "Enter Student Name : ";
    getline(cin, name);
    cout << "Enter Roll Number : ";
    cin >> roll_number;
    cout << "Enter Class : ";
    cin.get();
    getline(cin, grade);
    cout << "Enter Division : ";
    cin >> division;
    cout << "Enter Date of Birth : ";
    cin.get();
    getline(cin, date_of_birth);
    cout << "Enter Blood Group : ";
    cin >> blood_group;
    st->getstudent_data();
    count++;
}

inline void student::displayData(student_data* st1) {
    cout << "Student Name : " << name << endl;
    cout << "Roll Number : " << roll_number << endl;
    cout << "Class : " << grade << endl;
    cout << "Division : " << division << endl;
    cout << "Date of Birth : " << date_of_birth << endl;
    cout << "Blood Group : " << blood_group << endl;
    st1->dispstudent_data();
}

int student::count;

int main() {
    student* stud1[100];
    student_data* stud2[100];
    int n = 0;
    char ch;

    do {
        stud1[n] = new student;
        stud2[n] = new student_data;
        stud1[n]->getData(stud2[n]);
        n++;
        cout << "Do you want to add another student (y/n) : ";
        cin >> ch;
        cin.get();
    } while (ch == 'y' || ch == 'Y');

    for (int i = 0; i < n; i++) {
        cout << "---------------------------------------------------------------" << endl;
        stud1[i]->displayData(stud2[i]);
    }

    cout << "---------------------------------------------------------------" << endl;
    cout << "Total Students : " << student::getCount();
    cout << endl << "---------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        delete stud1[i];
        delete stud2[i];
    }

    return 0;
}


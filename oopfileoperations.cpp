#include<iostream>
#include<fstream>
using namespace std;

int main() {
    fstream file;

    // Creating file
    file.open("Assignment4.txt", ios::out);
    if (!file) {
        cout << "Error in creating file" << endl;
        return 0;
    }
    cout << "File created successfully" << endl;

    // Writing data to file
    cout << "Writing data in file" << endl;
    file << "This is an assignment to practice File Handling in C++" << endl;
    cout << "Closing file" << endl;
    file.close();

    // Opening file in read mode
    cout << "Opening file again in reading mode" << endl;
    file.open("Assignment4.txt", ios::in);
    if (!file) {
        cout << "Error in opening file" << endl;
        return 0;
    }

    // Reading data from file
    char ch;
    cout << "Reading data in file:" << endl;
    while (!file.eof()) {
        file >> ch;
        cout << ch;
    }
    cout << endl;
    file.close();

    // Appending data to file
    file.open("Assignment4.txt", ios::app);
    if (!file) {
        cout << "Error in opening file" << endl;
        return 0;
    }
    file << "Appending data using app mode" << endl;
    file.close();

    // Reading appended data
    file.open("Assignment4.txt", ios::in);
    if (!file) {
        cout << "Error in opening file" << endl;
        return 0;
    }
    char hr;
    while (!file.eof()) {
        file >> hr;
        cout << hr;
    }
    cout << endl;
    file.close();

    // Truncating file and writing new data
    file.open("Assignment4.txt", ios::out | ios::trunc);
    file << "Only this line should be visible" << endl;
    file.close();

    // Reading truncated data
    file.open("Assignment4.txt", ios::in);
    if (!file) {
        cout << "Error in opening file" << endl;
        return 0;
    }
    char hc;
    while (!file.eof()) {
        file >> hc;
        cout << hc;
    }
    cout << endl;
    file.close();

    return 0;
}


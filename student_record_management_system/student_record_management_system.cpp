#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> names;
vector<string> rollNos;
vector<string> courses;
vector<string> classes;
vector<string> contacts;

void enter() {
    int numStudents = 0;
    cout << "What number of students do you wish to enroll? " << endl;
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        cout << "\nEnter the student's data here:- " << i + 1 << endl << endl;
        string name, rollNo, course, classInfo, contact;

        cout << "Enter name: ";
        cin >> name;
        names.push_back(name);

        cout << "Enter Roll no: ";
        cin >> rollNo;
        rollNos.push_back(rollNo);

        cout << "Enter course: ";
        cin >> course;
        courses.push_back(course);

        cout << "Enter class: ";
        cin >> classInfo;
        classes.push_back(classInfo);

        cout << "Enter contact: ";
        cin >> contact;
        contacts.push_back(contact);
    }
}

void show() {
    if (names.empty()) {
        cout << "No data is entered" << endl;
    } else {
        for (int i = 0; i < names.size(); i++) {
            cout << "\nData of Student:- " << i + 1 << endl << endl;
            cout << "Name: " << names[i] << endl;
            cout << "Roll no: " << rollNos[i] << endl;
            cout << "Course: " << courses[i] << endl;
            cout << "Class: " << classes[i] << endl;
            cout << "Contact: " << contacts[i] << endl;
        }
    }
}

void search() {
    if (names.empty()) {
        cout << "No data is entered" << endl;
    } else {
        string rollNo;
        cout << "Enter the roll no of the student: ";
        cin >> rollNo;

        for (int i = 0; i < rollNos.size(); i++) {
            if (rollNo == rollNos[i]) {
                cout << "Name: " << names[i] << endl;
                cout << "Roll no: " << rollNos[i] << endl;
                cout << "Course: " << courses[i] << endl;
                cout << "Class: " << classes[i] << endl;
                cout << "Contact: " << contacts[i] << endl;
                return;
            }
        }

        cout << "No students were found matching the provided roll number." << endl;
    }
}

void update() {
    if (names.empty()) {
        cout << "No data is entered" << endl;
    } else {
        string rollNo;
        cout << "Enter the student's roll number whose information you want to update: ";
        cin >> rollNo;

        for (int i = 0; i < rollNos.size(); i++) {
            if (rollNo == rollNos[i]) {
                cout << "\nPrevious data" << endl << endl;
                cout << "Data of Student " << i + 1 << endl;
                cout << "Name: " << names[i] << endl;
                cout << "Roll no: " << rollNos[i] << endl;
                cout << "Course: " << courses[i] << endl;
                cout << "Class: " << classes[i] << endl;
                cout << "Contact: " << contacts[i] << endl;

                cout << "\nEnter new data" << endl << endl;
                cout << "Enter name: ";
                cin >> names[i];

                cout << "Enter Roll no: ";
                cin >> rollNos[i];

                cout << "Enter course: ";
                cin >> courses[i];

                cout << "Enter class: ";
                cin >> classes[i];

                cout << "Enter contact: ";
                cin >> contacts[i];

                cout << "Data updated successfully." << endl;
                return;
            }
        }

        cout << "No students were found using the provided roll number." << endl;
    }
}

void deleteRecord() {
    if (names.empty()) {
        cout << "No data is entered" << endl;
    } else {
        int choice;
        cout << "Press 1 to delete all records" << endl;
        cout << "Press 2 to delete a specific record" << endl;
        cin >> choice;

        if (choice == 1) {
            names.clear();
            rollNos.clear();
            courses.clear();
            classes.clear();
            contacts.clear();
            cout << "All records deleted successfully." << endl;
        } else if (choice == 2) {
            string rollNo;
            cout << "Enter the roll number of the student you want to erase: ";
            cin >> rollNo;

            for (int i = 0; i < rollNos.size(); i++) {
                if (rollNo == rollNos[i]) {
                    names.erase(names.begin() + i);
                    rollNos.erase(rollNos.begin() + i);
                    courses.erase(courses.begin() + i);
                    classes.erase(classes.begin() + i);
                    contacts.erase(contacts.begin() + i);
                    cout << "Record deleted successfully." << endl;
                    return;
                }
            }

            cout << "No students were found using the provided roll number.." << endl;
        } else {
            cout << "Invalid input." << endl;
        }
    }
}

int main() {
    int value;

    while (true) {
        cout << "\nPress 1 to enter data" << endl;
        cout << "Press 2 to show data" << endl;
        cout << "Press 3 to search data" << endl;
        cout << "Press 4 to update data" << endl;
        cout << "Press 5 to delete data" << endl;
        cout << "Press 6 to exit" << endl;
        cin >> value;

        switch (value) {
            case 1:
                enter();
                break;
            case 2:
                show();
                break;
            case 3:
                search();
                break;
            case 4:
                update();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                exit(0);
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }

    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct Student {

    Student(string other_firstname, string other_lastname, int other_day, int other_month, int other_year) {
        firstname = other_firstname;
        lastname = other_lastname;
        day = other_day;
        month = other_month;
        year = other_year;
    }

    string firstname = "";
    string lastname = "";
    int day = 0;
    int month = 0;
    int year = 0;
};

int main() {

    string firstname, lastname;
    int day, month, year;
    vector<Student> v;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> firstname >> lastname >> day >> month >> year;
        Student student{firstname, lastname, day, month, year};
        v.push_back(student);
    }

    int m;
    cin >> m;

    for (int j = 0; j < m; ++j) {
        string operation;
        int k;
        cin >> operation >> k;
        if (operation == "name" && k > 0 && k <= v.size()) {
            cout << v[k-1].firstname << " " << v[k-1].lastname << endl;
        } else if (operation == "date" && k > 0 && k <= v.size()) {
            cout << v[k-1].day << "." << v[k-1].month << "." << v[k-1].year << endl;
        } else {
            cout << "bad request" << endl;
        }
    }

    return 0;
}

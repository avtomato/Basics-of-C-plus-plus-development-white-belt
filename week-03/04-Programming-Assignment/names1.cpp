#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
        firstname[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        lastname[year] = last_name;
    }
    string GetFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year
        string first_name = GetFirstName(year, firstname);
        string last_name = GetLastName(year, lastname);
        string full_name = first_name + " " + last_name;
        if (first_name.size() == 0 && last_name.size() == 0) {
            full_name = "Incognito";
            return full_name;
        } else if (first_name.size() == 0) {
            full_name = last_name + " with unknown first name";
            return full_name;
        } else if (last_name.size() == 0) {
            full_name = first_name + " with unknown last name";
            return full_name;
        }
        return full_name;
    }
private:
    // приватные поля
    string GetFirstName(int year, map<int, string>& firstname) {
        while (firstname.count(year) == 0 && year > 0) {
            --year;
        }
        string first = firstname[year];
        return first;
    }
    string GetLastName(int year, map<int, string>& lastname) {
        while (lastname.count(year) == 0 && year > 0) {
            --year;
        }
        string last = lastname[year];
        return last;
    }

    map<int, string> firstname;
    map<int, string> lastname;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}

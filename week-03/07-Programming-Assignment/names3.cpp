#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


string FindNameByYear(int year, const map<int, string>& names) {
    string name;  // изначально имя неизвестно

    // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
    for (const auto& item : names) {
        // если очередной год не больше данного, обновляем имя
        if (item.first <= year) {
            name = item.second;
        } else {
            // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
            break;
        }
    }

    return name;
}

string GetHistory(int year, const map<int, string>& names) {
    vector<string> names_history;
    string current_name = "";

    for (const auto& item : names) {
        if (item.first <= year) {
            if (item.second != current_name) {
                vector<string> v = {item.second};
                names_history.insert(begin(names_history), begin(v), end(v));
                current_name = item.second;
            }
        } else {
            break;
        }
    }

    string history = "";
    
    for (int i = 1; i < names_history.size(); ++i) {
        if (history.size() == 0) {
            history += names_history[i];
        } else {
            history = history + ", " + names_history[i];
        }
    }

    return history;
}

class Person {
public:
    Person (const string& first_name, const string& last_name, int year) {
        year_of_birth = year;
        firstname[year] = first_name;
        lastname[year] = last_name;
    }
    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
        if (year < year_of_birth) {

        } else {
            firstname[year] = first_name;
        }
    }
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        if (year < year_of_birth) {

        } else {
            lastname[year] = last_name;
        }
    }
    string GetFullName(int year) const {
        // получить имя и фамилию по состоянию на конец года year
        if (year < year_of_birth) {
            return "No person";
        }
        const string first_name = FindNameByYear(year, firstname);
        const string last_name = FindNameByYear(year, lastname);
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
    string GetFullNameWithHistory(int year) const {
        if (year < year_of_birth) {
            return "No person";
        }
        // получить все имена и фамилии по состоянию на конец года year
        const string first_name = FindNameByYear(year, firstname);
        const string last_name = FindNameByYear(year, lastname);
        const string history_first_name = GetHistory(year, firstname);
        const string history_last_name = GetHistory(year, lastname);

        string full_name = first_name + " (" + history_first_name + ")" + " " + last_name + " (" + history_last_name + ")";

        if (first_name.size() == 0 && last_name.size() == 0) {
            full_name = "Incognito";
            return full_name;
        } else if (first_name.size() == 0) {
            if (history_last_name.size() == 0) {
                full_name = last_name + " with unknown first name";
                return full_name;
            } else {
                full_name = last_name + " (" + history_last_name + ")" + " with unknown first name";
                return full_name;
            }
        } else if (last_name.size() == 0) {
            if (history_first_name.size() == 0) {
                full_name = first_name + " with unknown last name";
                return full_name;
            } else {
                full_name = first_name + " (" + history_first_name + ")" + " with unknown last name";
                return full_name;
            }
        } else if (history_first_name.size() == 0 && history_last_name.size() == 0) {
            full_name = first_name + " " + last_name;
            return full_name;
        }else if (history_first_name.size() == 0) {
            full_name = first_name + " " + last_name + " (" + history_last_name + ")" ;
            return full_name;
        } else if (history_last_name.size() == 0) {
            full_name = first_name + " (" + history_first_name + ") " + last_name;
            return full_name;
        }
        return full_name;
    }

private:
    // приватные поля
    map<int, string> firstname;
    map<int, string> lastname;
    int year_of_birth;
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}

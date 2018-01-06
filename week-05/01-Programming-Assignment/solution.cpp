#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <map>
#include <set>

using namespace std;


// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:

    Date () {
        year = 0001;
        month = 01;
        day = 01;
    }

    Date (int new_year, int new_month, int new_day) {
        
        year = new_year;
        if (new_month  < 1 || new_month > 12) {
            string error = "Month value is invalid: " + to_string(new_month);
            throw invalid_argument(error);
        }
        
        month = new_month;
        if (new_day  < 1 || new_day > 31) {
            string error = "Day value is invalid: " + to_string(new_day);
            throw invalid_argument(error);
        }
        day = new_day;
    }

    int GetYear() const {
        return year;
    }
    
    int GetMonth() const {
        return month;
    }
    
    int GetDay() const {
        return day;
    }

private:
    int year;
    int month;
    int day;
};

bool operator < (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        if (db.count(date) > 0) {
            db[date].insert(event);
        } else {
            set<string> events;
            events.insert(event);
            db[date] = events;
        }
    }

    bool DeleteEvent(const Date& date, const string& event) {
        bool y;
        if (db[date].count(event) > 0) {
            db[date].erase(event);
            y = true;
        } else {
            y = false;
        }
        return y;
    }

    int  DeleteDate(const Date& date) {
        int n = 0;
        if (db.count(date) > 0) {
            n = db[date].size();
            db.erase(date);
        }
        return n;
    }

    // поиск событий
    void Find(const Date& date) const {
        try {
            set<string> s = db.at(date);
            for (const auto& item : s) {
                cout << item  << endl;
            }
        }
        catch (out_of_range&) {
            // нет событий
        }
    }

    // печать всех событий
    void Print() const {
        for (const auto& pair : db) {
            for (const auto& event : pair.second) {
                cout << setw(4) << setfill('0') << pair.first.GetYear() << '-';
                cout << setw(2) << setfill('0') << pair.first.GetMonth() << '-';
                cout << setw(2) << setfill('0') << pair.first.GetDay();
                cout << " " << event << endl;
            }
        }
    }

private:
    map<Date, set<string>> db;
};

ostream& operator << (ostream& out, const Date& date) {
    out << date.GetYear() << '-'  << date.GetMonth() << '-' << date.GetDay();
    return out;
}

void EnsureNextSymbolEndSkip(istream &stream) {
    if (stream.peek() != '-') {
        throw runtime_error("");
    }
    stream.ignore(1);
}

istream& operator >> (istream& in, Date& date) {
    string input;
    in >> input;
    stringstream stream(input);
    int y; int m; int d;

    try {
        stream >> y;
        EnsureNextSymbolEndSkip(stream);
        stream >> m;
        EnsureNextSymbolEndSkip(stream);
        stream >> d;
        if (stream.peek() != -1) {
            throw runtime_error("");
        }
    } catch (runtime_error& re) {
        throw runtime_error("Wrong date format: " + input);
    }
    date = Date(y, m, d);
    
    return in;
}

int main() {
    Database db;

    string command;
    while (getline(cin, command)) {
        // Считайте команды с потока ввода и обработайте каждую
        stringstream stream(command);
        string operation;
        stream >> operation;

        try {
            if (operation == "Add") {
                stream.ignore(1);
                Date date;
                try {
                    stream >> date;
                } catch (exception& ex) {
                    cout << ex.what() << endl;
                    break;
                }
                stream.ignore(1);
                string event;
                stream >> event;
                db.AddEvent(date, event);
            } else if (operation == "Del") {
                stream.ignore(1);
                Date date;
                try {
                    stream >> date;
                } catch (exception& ex) {
                    cout << ex.what() << endl;
                    break;
                }
                if (stream.peek() != -1) {
                    stream.ignore(1);
                    string event;
                    stream >> event;
                    if (db.DeleteEvent(date, event)) {
                        cout << "Deleted successfully" << endl;
                    } else {
                        cout << "Event not found" << endl;
                    }
                } else {
                    int n = 0;
                    n = db.DeleteDate(date);
                    cout << "Deleted " << n << " events" << endl;
                }
            } else if (operation == "Find") {
                stream.ignore(1);
                Date date;
                try {
                    stream >> date;
                } catch (exception& ex) {
                    cout << ex.what() << endl;
                    break;
                }
                db.Find(date);
            } else if (operation == "Print") {
                db.Print();
                break;
            } else if (operation == "") {

            } else {
                throw runtime_error("Unknown command: " + operation);
            }
        } catch (exception& ex) {
            cout << ex.what() << endl;
            break;
        }
    }

    return 0;
}

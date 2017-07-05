#include <algorithm>
#include <map>
#include <vector>

vector<string> FindNamesHistory(const map<int, string>& names_by_year,
                                int year) {
    vector<string> names;
    for (const auto& item : names_by_year) {
        if (item.first <= year && (names.empty() || names.back() != item.second)) {
            names.push_back(item.second);
        }
    }
    return names;
}

string BuildJoinedName(vector<string> names) {
    reverse(begin(names), end(names));
    string joined_name = names[0];
    for (int i = 1; i < names.size(); ++i) {
        if (i == 1) {
            joined_name += " (";
        } else {
            joined_name += ", ";
        }
        joined_name += names[i];
    }
    if (names.size() > 1) {
        joined_name += ")";
    }
    return joined_name;
}

class Person {
public:
    // конструктор
    Person(const string& first_name, const string& last_name,
           int new_birth_year) {
        birth_year = new_birth_year;
        first_names[birth_year] = first_name;
        last_names[birth_year] = last_name;
    }
    void ChangeFirstName(int year, const string& first_name) {
        // игнорируем запись, если год меньше года рождения
        if (year >= birth_year) {
            first_names[year] = first_name;
        }
    }
    void ChangeLastName(int year, const string& last_name) {
        if (year >= birth_year) {
            last_names[year] = last_name;
        }
    }
    string GetFullName(int year) const {
        // обрабатываем случай, когда год меньше года рождения
        if (year < birth_year) {
            return "No person";
        }
        const vector<string> first_names = FindFirstNamesHistory(year);
        const vector<string> last_names = FindLastNamesHistory(year);
        // объединяем имя и фамилию через пробел
        return first_names.back() + " " + last_names.back();
    }
    string GetFullNameWithHistory(int year) const {
        if (year < birth_year) {
            return "No person";
        }
        const string first_name = BuildJoinedName(FindFirstNamesHistory(year));
        const string last_name = BuildJoinedName(FindLastNamesHistory(year));
        return first_name + " " + last_name;
    }
private:
    vector<string> FindFirstNamesHistory(int year) const {
        return FindNamesHistory(first_names, year);
    }
    vector<string> FindLastNamesHistory(int year) const {
        return FindNamesHistory(last_names, year);
    }

    int birth_year;
    map<int, string> first_names;
    map<int, string> last_names;
};

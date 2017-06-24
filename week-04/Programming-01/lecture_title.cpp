#include <iostream>
#include <string>

using namespace std;


struct Specialization {
    string value;
    explicit Specialization(string other_value) {
        value = other_value;
    }
};

struct Course {
    string value;
    explicit Course(string other_value) {
        value = other_value;
    }
};

struct Week {
    string value;
    explicit Week(string other_value) {
        value = other_value;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(Specialization other_specialization, Course other_course, Week other_week) {
        specialization = other_specialization.value;
        course = other_course.value;
        week = other_week.value;
    }
};

int main() {

    LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
    );

    return 0;
}
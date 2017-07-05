#include <iostream>
#include <string>

using namespace std;

struct Specialization {
    explicit Specialization(const string& new_value) {
        value = new_value;
    }
    string value;
};

struct Course {
    explicit Course(const string& new_value) {
        value = new_value;
    }
    string value;
};

struct Week {
    explicit Week(const string& new_value) {
        value = new_value;
    }
    string value;
};

struct LectureTitle {
    LectureTitle(const Specialization& new_specialization,
                 const Course& new_course,
                 const Week& new_week) {
        specialization = new_specialization.value;
        course = new_course.value;
        week = new_week.value;
    }
    string specialization;
    string course;
    string week;
};

#include "CourseCatalog.h"
#include <map>
#include <string>

// oppgave 3 b

void CourseCatalog::addCourse(std::string CourseCode, std::string CourseName) {
  Courses.insert(std::make_pair(courseCode, courseName))
}

void CourseCatalog::removeCourse(std::string courseCode) {
  Courses.erase(courseCode);
}

std::string CourseCatalog::getCourse(std::string courseCode) {
  return Courses.at(courseCode));
}

// oppgave 3 c
std::ostream &operator<<(std::ostream &os, const CourseCatalog &c) {
  for (const auto &course : c.courses) {
    os << "Emnekode: " << course.first << ", Emnenavn: " << course.second
       << '\n';
  }
  return os;
}

// oppave 3 d
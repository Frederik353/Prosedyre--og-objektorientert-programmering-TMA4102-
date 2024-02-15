#include "CourseCatalog.h"
#include <map>
#include <string>

// oppgave 3 b

void CourseCatalog::addCourse(std::string CourseCode, std::string CourseName) {
  std::map<std::string, std::string> course =
      std::make_pair(courseCode, courseName);
  auto result = Courses.insert(course);
  if (!result.second) {
    Courses[courseCode] = courseName;
  }
  saveToFile(course)
}

void CourseCatalog::removeCourse(std::string courseCode) {
  Courses.erase(courseCode);
}

std::string CourseCatalog::getCourse(std::string courseCode) {
  return Courses.at(courseCode);
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
void CourseCatalog::saveToFile(std::pair<std::string, std::string> course,
                               std::string filename) {
  std::ofstream file;
  file.open(filename, std::ios::app);
  file << course.first << "," << course.second << '\n';
  file.close();
}

void CourseCatalog::loadFile(std::string filename) {
  std::ifstream inFile(filename);
  std::string line;
  while (std::getline(inFile, line)) {
    std::istringstream lineStream(line);
    std::string courseCode, courseName;
    std::getline(lineStream, courseCode, ','); // Use ',' as delimiter
    std::getline(lineStream, courseName);
    addCourse(courseCode, courseName);
  }
}

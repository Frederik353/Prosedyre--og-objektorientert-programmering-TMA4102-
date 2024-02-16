#include "courseCatalog.h"
#include <fstream>
#include <map>
#include <sstream>
#include <string>

CourseCatalog::CourseCatalog() { loadFile(); }

// oppgave 3 b

void CourseCatalog::addCourse(std::string courseCode, std::string courseName,
                              bool save) {
  std::pair<std::string, std::string> course =
      std::make_pair(courseCode, courseName);
  auto result = courses.insert(course);
  if (!result.second) {
    courses[courseCode] = courseName;
  }
  if (save)
    saveToFile(course);
}

void CourseCatalog::removeCourse(std::string courseCode) {
  courses.erase(courseCode);
}

std::string CourseCatalog::getCourse(std::string courseCode) {
  return courses.at(courseCode);
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
  file << course.second << "," << course.first << '\n';
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
    addCourse(courseCode, courseName, false);
  }
}

void CourseCatalog::clearCourses() { courses.clear(); }

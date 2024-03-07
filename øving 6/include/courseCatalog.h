#include <string>
#include <iostream>
#include <map>


// oppgave 3 a
class CourseCatalog {
    private:
        std::map<std::string, std::string>  courses;
    public:
      CourseCatalog();
      // does not remove duplicates from file but does not add duplicates to map
      // when loading file and the latest course defention is used has added
      // benefit of keeoing track of name changes
      void addCourse(std::string courseCode, std::string courseName,
                     bool saveToFile = true);
      void removeCourse(std::string courseCode);
      std::string getCourse(std::string courseCode);
      friend std::ostream &operator<<(std::ostream &os, const CourseCatalog &c);
      void saveToFile(std::pair<std::string, std::string> course,
                      std::string filename = "courses.csv");
      void loadFile(std::string filename = "courses.csv");

      void clearCourses();
};
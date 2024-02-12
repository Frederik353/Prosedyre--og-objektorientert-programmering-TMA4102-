#include <string>
#include <iostream>
#include <map>


// oppgave 3 a
class CourseCatalog {
    private:
        std::map<std::string, int>  courses;
    public:
        void addCourse(  std::string courseCode, std::string courseName);
        void removeCourse(std::string courseCode);
        std::string getCourse(std::string courseCode);
        friend std::ostream& operator<<(std::ostream& os, const CourseCatalog& c);
}
#include "courseCatalog.h"
#include <cstdio>
#include <gtest/gtest.h>

class CourseCatalogTest : public ::testing::Test {
protected:
  // Setup run before each test
  CourseCatalog catalog;
  void SetUp() override { catalog.clearCourses(); }

  // Teardown run after each test
  void TearDown() override {
    const char *filename = "courses.csv";

    if (remove(filename) != 0) {
      perror("Error deleting file");
    } else {
      puts("File successfully deleted");
    }
  }
};

TEST_F(CourseCatalogTest, AddAndGetCourse) {
  std::string courseName = "Prosedyre- og objektorientert programmering";
  std::string courseCode = "TDT4102";
  catalog.addCourse(courseCode, courseName);
  EXPECT_EQ(catalog.getCourse(courseCode), courseName);
}

TEST_F(CourseCatalogTest, RemoveCourse) {
  std::string courseName = "Matematikk 1";
  std::string courseCode = "TMA4100";
  catalog.addCourse(courseCode, courseName);
  catalog.removeCourse(courseCode);
  EXPECT_THROW(
      {
        try {
          catalog.getCourse(courseCode);
        } catch (const std::out_of_range &e) {
          // Forventet unntak ved forsøk på å hente et kurs som ikke finnes
          throw;
        }
      },
      std::out_of_range);
}

// oppave 3 d

TEST_F(CourseCatalogTest, PrintCatalog) {
  catalog.addCourse("TMA4100", "Matematikk 1");
  catalog.addCourse("TDT4109", "Informasjonsteknologi grunnkurs");
  catalog.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");

  std::stringstream output;
  output << catalog;

  std::string expected =
      "Emnekode: TDT4102, Emnenavn: Prosedyre- og objektorientert "
      "programmering\n"
      "Emnekode: TDT4109, Emnenavn: Informasjonsteknologi grunnkurs\n"
      "Emnekode: TMA4100, Emnenavn: Matematikk 1\n";

  EXPECT_EQ(output.str(), expected);

  //   change course name
  expected = "Emnekode: TDT4102, Emnenavn: c++\n"
             "Emnekode: TDT4109, Emnenavn: Informasjonsteknologi grunnkurs\n"
             "Emnekode: TMA4100, Emnenavn: Matematikk 1\n";

  output.str("");
  output.clear();
  catalog.addCourse("TDT4102", "c++");
  output << catalog;
  EXPECT_EQ(output.str(), expected);
}

// oppgave 3 e
/*
[] endrer verdien hvis den allerede eksisterer

insert() endrer ikke verdien hvis den allerede eksisterer og returnerer et pair
med en iterator til den eksisterende verdien og en bool som er false hvis den
allerede eksisterer

*/

#include "CourseCatalog.h"
#include <gtest/gtest.h>

TEST_F(CourseCatalogTest, AddAndGetCourse) {
  std::string courseName = "Prosedyre- og objektorientert programmering";
  std::string courseCode = "TDT4102";
  catalog.addCourse(courseName, courseCode);
  EXPECT_EQ(catalog.getCourse(courseName), courseCode);
}

TEST_F(CourseCatalogTest, RemoveCourse) {
  std::string courseName = "Matematikk 1";
  std::string courseCode = "TMA4100";
  catalog.addCourse(courseName, courseCode);
  catalog.removeCourse(courseName);
  EXPECT_THROW(
      {
        try {
          catalog.getCourse(courseName);
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
  catalog.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
  catalog.addCourse("TDT4109", "Informasjonsteknologi grunnkurs");

  std::stringstream output;
  output << catalog;

  std::string expected =
      "Emnekode: TDT4109, Emnenavn: Informasjonsteknologi grunnkurs\n"
      "Emnekode: TDT4102, Emnenavn: Prosedyre- og objektorientert "
      "programmering\n"
      "Emnekode: TMA4100, Emnenavn: Matematikk 1\n";

  EXPECT_EQ(output.str(), expected);
}

// oppgave 3 e
/*
[] endrer verdien hvis den allerede eksisterer

insert() endrer ikke verdien hvis den allerede eksisterer og returnerer et pair
med en iterator til den eksisterende verdien og en bool som er false hvis den
allerede eksisterer

*/

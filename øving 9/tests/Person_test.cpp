#include "Car.h"
#include "Person.h"
#include <gtest/gtest.h>
#include <memory>


class PersonTest : public ::testing::Test {
protected:
  void SetUp() override {
    // Setup code here, if necessary.
  }

  void TearDown() override {
    // Cleanup code here, if necessary.
  }
};

TEST_F(PersonTest, GetName) {
  Person person("John Doe", "johndoe@example.com");
  ASSERT_EQ(person.getName(), "John Doe");
}

TEST_F(PersonTest, GetEmail) {
  Person person("John Doe", "johndoe@example.com");
  ASSERT_EQ(person.getEmail(), "johndoe@example.com");
}

TEST_F(PersonTest, SetEmail) {
  Person person("John Doe", "johndoe@example.com");
  person.setEmail("newemail@example.com");
  ASSERT_EQ(person.getEmail(), "newemail@example.com");
}

TEST_F(PersonTest, HasAvailableSeatsNoCar) {
  Person person("John Doe", "johndoe@example.com");
  ASSERT_FALSE(person.hasAvailableSeats());
}

TEST_F(PersonTest, HasAvailableSeatsWithCar) {
  auto car = std::make_unique<Car>(
      3); // Assuming Car constructor takes the number of seats.
  Person person("John Doe", "johndoe@example.com", std::move(car));
  ASSERT_TRUE(person.hasAvailableSeats());
}

// Additional tests can be written for operator<<, but this would require
// mocking the ostream or capturing stdout.

// int main(int argc, char **argv)
// {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }

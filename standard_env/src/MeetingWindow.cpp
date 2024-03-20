#include "MeetingWindow.h"
#include "Car.h"
#include <string>

void MeetingWindow::cb_newPerson() {
  std::string name = person_name.getText();
  std::string email = person_email.getText();
  std::string seatText = person_seats.getText();
  std::unique_ptr<Car> car_ptr;

  if (name.empty() || name == "Name" || email.empty() || email == "Email") {
    std::cerr << "Invalid name or email." << std::endl;
    return;
  }

  try {
    if (seatText.empty() ||
        !std::all_of(seatText.begin(), seatText.end(), ::isdigit)) {
      throw std::invalid_argument(
          "Car seat count must be a non-negative integer.");
    }

    int car_seats = std::stoi(seatText);

    if (car_seats < 0) {
      throw std::out_of_range("Car seat count cannot be negative.");
    }

    car_ptr = std::make_unique<Car>(car_seats);
    std::cout << car_ptr->getFreeSeats() << std::endl;

    if (car_seats > 0) {
      car_ptr->reserveFreeSeat();
    }
  } catch (const std::invalid_argument &e) {
    std::cerr << "Invalid argument: " << e.what() << '\n';
    return;
  } catch (const std::out_of_range &e) {
    std::cerr << "Out of range: " << e.what() << '\n';
    return;
  }

  person_name.setText("Name");
  person_email.setText("Email");
  person_seats.setText("Car seats");

  people.emplace_back(
      std::make_shared<Person>(name, email, std::move(car_ptr)));

  show_people();
};

void MeetingWindow::show_people() {
  for (const auto &person_ptr : people) {
    std::cout << *person_ptr << std::endl;
  }
}

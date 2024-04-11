#include "Meeting.h"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const Campus &campus) {
  switch (campus) {
  case Campus::Trondheim:
    os << "Trondheim";
    break;
  case Campus::Alesund:
    os << "Ålesund";
    break;
  case Campus::Gjovik:
    os << "Gjøvik";
    break;
  default:
    os << "Ukjent Campus";
    break;
  }
  return os;
}

std::vector<std::string> Meeting::getParticipantList() const {
  std::vector<std::string> res;
  for (const auto &person : _participants) {
    res.push_back(person->getName());
  }
  return res;
}

std::ostream &operator<<(std::ostream &os, const Meeting &meeting) {
  os << "Subject: " << meeting.getSubject() << "\n";
  os << "Location: " << meeting.getLocation() << "\n";
  os << "Start Time: " << meeting.getStartTime() << "\n";
  os << "End Time: " << meeting.getEndTime() << "\n";
  os << "Meeting Leader: " << meeting.getLeader()->getName() << "\n";
  os << "Participants: ";
  auto participants = meeting.getParticipantList();
  for (size_t i = 0; i < participants.size(); ++i) {
    os << participants[i];
    if (i < participants.size() - 1) {
      os << ", ";
    }
  }
  os << "\n";
  return os;
}

std::vector<std::shared_ptr<Person>>
Meeting::findPotentialCoDriving(const Meeting other) const {
  std::vector<std::shared_ptr<Person>> potentialDrivers;
  if (this->_location != other._location || this->_day != other._day) {
    return potentialDrivers;
  }
  if (std::abs(this->_startTime - other._startTime) >= 60 ||
      std::abs(this->_endTime - other._endTime) >= 60) {
    return potentialDrivers;
  }
  for (const auto &person : other._participants) {
    if (person->hasAvailableSeat()) {
      potentialDrivers.push_back(person);
    }
  }
  return potentialDrivers;
}

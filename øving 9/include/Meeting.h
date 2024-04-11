#pragma once
#include "Person.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

enum class Campus { Trondheim, Alesund, Gjovik };

class Meeting {
private:
  int _day;
  int _startTime;
  int _endTime;
  Campus _location;
  std::string _subject;
  const std::shared_ptr<Person> _leader;
  std::vector<std::shared_ptr<Person>> _participants;

public:
  int getDay() const { return _day; };
  int getStartTime() const { return _startTime; };
  int getEndTime() const { return _endTime; };
  Campus getLocation() const { return _location; };
  std::string getSubject() const { return _subject; };
  std::shared_ptr<Person> getLeader() const { return _leader; };
  void addParticipant(std::shared_ptr<Person> person) {
    _participants.push_back(person);
  };
  Meeting(int day, int startTime, int endTime, Campus location,
          std::string subject, const std::shared_ptr<Person> leader)
      : _day{day}, _startTime{startTime}, _endTime{endTime},
        _location{location}, _subject{subject}, _leader{leader} {
    addParticipant(leader);
  };
  std::vector<std::string> getParticipantList() const;

  std::vector<std::shared_ptr<Person>>
  findPotentialCoDriving(const Meeting other) const;
};

// oppgave 3 e
/*
enkle tyepr som int vil bli fjernet nå Meeting går ut av scope
shared_ptr vil redusere referansetelleren, når denne blir null vil objektet
figjøres stoppes programmet blir automatisk alt minnne brukt av programmet
frigjort av operativsystemet
*/

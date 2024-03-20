#pragma once
#include "AnimationWindow.h"
#include "Person.h"
#include "std_lib_facilities.h"
#include "widgets/Button.h"
#include "widgets/TextInput.h"
#include <memory>
#include <string>
#include <vector>

class MeetingWindow : public AnimationWindow {
private:
  static constexpr int _pad{30};
  static constexpr int _btnW{200};
  static constexpr int _btnH{30};
  static constexpr int _fieldW{300};
  static constexpr int _fieldH{40};
  std::vector<std::shared_ptr<Person>> people;

  // Declare widgets as member variables
  TDT4102::Button quit_btn;
  TDT4102::Button add_person_btn;
  TDT4102::TextInput person_name;
  TDT4102::TextInput person_email;
  TDT4102::TextInput person_seats;

public:
  MeetingWindow(int x, int y, int w, int h, const std::string &title)
      : AnimationWindow(x, y, w, h, title),
        quit_btn{TDT4102::Point{w - _btnW, 0}, _btnW, _btnH, "Quit"},
        add_person_btn{TDT4102::Point{_pad, 0}, _btnW, _btnH, "Add person"},
        person_name{TDT4102::Point{_pad, _fieldH + _pad}, _fieldW, _fieldH,
                    "Name"},
        person_email{TDT4102::Point{_pad, _fieldH * 2 + _pad * 2}, _fieldW,
                     _fieldH, "Email"},
        person_seats{TDT4102::Point{_pad, _fieldH * 3 + _pad * 3}, _fieldW,
                     _fieldH, "Car seats"} {
    add(quit_btn);
    add(person_name);
    add(person_email);
    add(person_seats);
    add(add_person_btn);
    quit_btn.setCallback(std::bind(&MeetingWindow::cb_quit, this));
    add_person_btn.setCallback(std::bind(&MeetingWindow::cb_newPerson, this));
  };

  void cb_quit() { close(); };

  void cb_newPerson();
  void show_people();
};

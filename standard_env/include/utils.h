

int incrementByValueNumTimes(int startValue, int increment, int numTimes);

int incrementByValueNumTimesRef(int &startValue, int increment, int numTimes);

void swap(int &a, int &b);

// oppgave 2 a

struct student {
  std::string name;
  std::string studyProgram;
  int age;
};

void printStudent(student s);

std::string randomizeString(int length, char lower, char upper);

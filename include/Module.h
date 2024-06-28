#include <map>

class UnitTest {
  virtual void unitTest() = 0;
};

class CircleTest {
  virtual void circleTest() = 0;
};

class Module {

public:
  virtual void test() = 0;

  std::map<std::string, std::string> parameters;
};

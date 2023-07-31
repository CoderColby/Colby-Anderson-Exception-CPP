#include <iostream>
using namespace std;

class invalidCharacterException {
  private:
    char invalidChar;
  public:
    invalidCharacterException(char c) {
      invalidChar = c;
    }
    char getChar() {
      return invalidChar;
    }
};

class invalidRangeException {
  private:
    int invalidRange;
  public:
    invalidRangeException(int i) {
      invalidRange = i;
    }
    int getRange() {
      return invalidRange;
    }
};


char character(char start, int offset);


int main() {
  std::cout << "Hello World!\n";
}


char character(char start, int offset) {

  if (!isalpha(start))
    throw invalidCharacterException(start);

  start += offset;

  if (!isalpha(start) || (start - 91) * (start + offset - 91) < 0)
    throw invalidRangeException(offset);

  return start;
}
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
    char invalidChar;
    int invalidRange;
  public:
    invalidRangeException(char c, int i) {
      invalidChar = c;
      invalidRange = i;
    }
    char getChar() {
      return invalidChar;
    }
    int getRange() {
      return invalidRange;
    }
};


char character(char start, int offset);


int main() {
  char start = 'A';
  int offset = 32;

  try {
    cout << start << "+" << offset << "=" << character(start, offset);
  } catch (invalidCharacterException e) {
    cout << "ERROR: The character " << e.getChar() << " is not a letter.";
  } catch (invalidRangeException e) {
    cout << "ERROR: The range " << e.getRange() << " is not valid with character " << e.getChar() << ".";
  }
}


char character(char start, int offset) {

  if (!isalpha(start))
    throw invalidCharacterException(start);

  char end = start + offset;

  if (!isalpha(end) || (start - 91) * (end - 91) < 0)
    throw invalidRangeException(start, offset);

  return end;
}
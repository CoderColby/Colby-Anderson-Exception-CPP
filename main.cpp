/*
Colby Anderson
CIS 1202 800
July 30 2023
*/


#include <iostream>
using namespace std;

// Thrown if starting character is not a letter
class invalidCharacterException {
  private:
    char invalidChar; // Character that caused the exception
  public:
    invalidCharacterException(char c) { // Accepts the conditions that caused the exception
      invalidChar = c;
    }
    char getChar() {
      return invalidChar;
    }
};

// Thrown if ending character is not a letter or if the case changed
class invalidRangeException {
  private:
    char invalidChar; // Starting character
    int invalidRange; // Range that caused the exception
  public:
    invalidRangeException(char c, int i) { // Accepts the conditions that caused the exception
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


// Given from instructions
char character(char start, int offset);


int main() {
  // Starting conditions
  char start = 'A'; // Change me
  int offset = 32; // Change me

  // Try to call character function and catch exceptions if unsuccessful
  try {
    cout << start << "+" << offset << "=" << character(start, offset);
  } catch (invalidCharacterException e) { // Starting character was not alphabetic
    cout << "ERROR: The character " << e.getChar() << " is not a letter.";
  } catch (invalidRangeException e) { // Ending character was not alphabetic or the range changed the case of the character
    cout << "ERROR: The range " << e.getRange() << " is not valid with character " << e.getChar() << ".";
  }
}


// Moves the starting character by the distance in offset and throws an exception if 'start' or 'end' is not valid
char character(char start, int offset) {

  if (!isalpha(start)) // If 'start' is not a letter
    throw invalidCharacterException(start);

  char end = start + offset; // Change character according to ASCII values

  if (!isalpha(end) || (start - 91) * (end - 91) < 0) // If 'end' is not a letter or the character '[' (91 in ASCII) is between 'start' and 'end' which signifies that the character has changed case 
    throw invalidRangeException(start, offset);

  // Return character if no exceptions occurred
  return end;
}
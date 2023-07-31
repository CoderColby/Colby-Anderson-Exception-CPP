#include <iostream>
using namespace std;

char character(char start, int offset);

int main() {
  std::cout << "Hello World!\n";
}


char character(char start, int offset) {
  string charException = "ERROR: Invalid character\n";
  string rangeException = "ERROR: Invalid range\n";

  if (!isalpha(start))
    throw charException;
}
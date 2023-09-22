#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countSpaces(string s) {
  int count = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') {
      count++;
    } else {
      break;
    }
  }

  return count;
}

string strip(string s) {
  string stripped = "";
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != ' ') {
      stripped += s.substr(i);
      break;
    }
  }

  return stripped;
}

int main(int argc, char *argv[]) {
}

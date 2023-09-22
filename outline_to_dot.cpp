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
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <filename>" << endl;
    return 1;
  }

  string filename = argv[1];

  vector<string> stack;
  stack.push_back("root");

  ifstream file(filename.c_str());

  if (file.is_open()) {
    cout << "digraph G {" << endl;
    cout << "  rankdir=\"LR\";" << endl;

    string line;
    while (getline(file, line)) {
    }
    cout << "}" << endl;
    file.close();
  } else {
    cout << "Unable to open file: " << filename << endl;
  }
}

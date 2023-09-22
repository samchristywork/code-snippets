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
      if (line.length() == 0) {
        continue;
      }

      int depth = countSpaces(line) / 2 + 2;
      string label = strip(line);

      if (depth == stack.size() + 1) {
        stack.push_back(label);
      } else if (depth == stack.size()) {
        stack.pop_back();
        stack.push_back(label);
      } else if (depth < stack.size() + 1) {
        while (depth < stack.size()) {
          stack.pop_back();
        }
        stack.pop_back();
        stack.push_back(label);
      }

      string parent = stack[stack.size() - 2];
      cout << "  \"" << parent << "\"->\"" << label << "\"" << endl;
    }
    cout << "}" << endl;
    file.close();
  } else {
    cout << "Unable to open file: " << filename << endl;
  }
}

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

//Code is ok for 2.1 and output is 1598415

int parse_line_and_sum(string line) {
  
  string parsed = "";
  int numbers[3];
  int entry = 0;

  for (int i = 0; line[i]; i++) {
    if (line[i] == 'x' and line[i + 1] != '\0') {
      numbers[entry++] = stoi(parsed);
      parsed = "";
    }
    else if (line[i + 1] == '\0') {
      parsed += line[i];
      numbers[entry] = stoi(parsed);
      break;
    }
    else {
      parsed += line[i];
    }
  }

  int lw = numbers[0] * numbers[1];
  int wh = numbers[0] * numbers[2];
  int hl = numbers[1] * numbers[2];

  int small_side;
  // here we need to take into acount that sides could be equal or smaller
  if (lw <= wh and lw <= hl) {
    small_side = lw;
  }
  else if (wh <= lw and wh <= hl)
  {
    small_side = wh;
  }
  else {
    small_side = hl;
  }
  
  return (2 * lw ) + (2 * wh) + (2 * hl) + small_side;
}

int main() {
  // dimensions are length x width x height
  // the formula for the surface 2*l*w + 2*w*h + 2*h*l
  // also need to add the smallest area of the package

  // from https://www.geeksforgeeks.org/read-a-file-line-by-line-in-cpp/
  ifstream file("input.txt");
  string line;
  int sum = 0;

  if (file.is_open()) {
    while (getline(file, line)) {
      sum += parse_line_and_sum(line);
    }
    file.close();
  }
  cout << "The sum is : " << sum;
  return 0;
}
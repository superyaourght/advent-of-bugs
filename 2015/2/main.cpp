#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

//Code is ok for 2.1 and output is 1598415
/*
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
*/

/*
  For the second part i need to :
    - calculate the volume of the gift
    - find the smallest side
    - find the second smallest side
      - make the operation smallest side * 2 + second smallest * 2
    => finally volume + operation result
*/
// works for 2.2 and output is 3812909
int parse_path_volume(string line) {
  
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

  // i know i don't really need to do it but makes more sens for me after
  int side1 = numbers[0];
  int side2 = numbers[1];
  int side3 = numbers[2];

  int smallest_side;
  if (side1 <= side2 and side1 <= side3) {
    smallest_side = side1;
  }
  else if (side2 <= side1 and side2 <= side3) {
    smallest_side = side2;
  }
  else if (side3 <= side1 and side3 <= side2) {
    smallest_side = side3;
  }

  // brute force and not optimised should be a prettier way but osef and works
  int second_smallest;
  if ((side1 <= side2 and side1 >= side3) or (side1 <= side3 and side1 >= side2)) {
    second_smallest = side1;
  }
  else if ((side2 <= side1 and side2 >= side3) or (side2 <= side3 and side2 >= side1)) {
    second_smallest = side2;
  }
  else if ((side3 <= side1 and side3 >= side2) or (side3 <= side2 and side3 >= side1)) {
    second_smallest = side3;
  }

  int length = 2 * smallest_side + 2 * second_smallest;
  int volume = side1 * side2 * side3;

  cout << side1 << "x" << side2 << "x" << side3 << endl;
  cout << "smallest is " << smallest_side << endl;
  cout << "second is " << second_smallest << endl << endl;
  
  return length + volume;
}

int main() {
  ifstream file("input.txt");
  string line;
  int sum = 0;

  if (file.is_open()) {
    while (getline(file, line)) {
      sum += parse_path_volume(line);
    }
    file.close();
  }
  cout << "The sum is : " << sum;
  return 0;
}
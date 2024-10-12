#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

void task1(double kids[], string names[], int n) {
  string swap;
  int j = 0;
  while (kids[0] < kids[1] || kids[1] < kids[2] || kids[2] < kids[3] ||
         kids[3] < kids[4] || kids[4] < kids[5] || kids[5] < kids[6] ||
         kids[6] < kids[7] || kids[7] < kids[8] || kids[8] < kids[9]) {
    for (j = 0; j < n; j += 1) {
      if (kids[j] < kids[j + 1]) {
        kids[j] += kids[j + 1];
        kids[j + 1] = kids[j] - kids[j + 1];
        kids[j] = kids[j] - kids[j + 1];
        names[j].swap(names[j + 1]);
      }
    }
    for (j = 9; j > 0; j -= 1) {
      if (kids[j] > kids[j - 1]) {
        kids[j] += kids[j - 1];
        kids[j - 1] = kids[j] - kids[j - 1];
        kids[j] = kids[j] - kids[j - 1];
        names[j].swap(names[j - 1]);
      }
    }
  }
  cout << setw(24) << right << "----SCORES----" << endl;
  for (j = 0; j < n; j += 1) {
    cout << ""
         << " (" <<setw(2)<<right<< j + 1 << setw(6) << left << ")" << setw(4) << right
         << kids[j] << setw(15) << right << " " << names[j] << endl;
  }
}
void task2(double kids[], int n) {
  int j;
  double average = 0;
  for (j = 0; j < n; j += 1) {
    average += kids[j];
  }
  average = average / 10;
  cout << "\n\nAverage before drop: " << average << endl;
  average = 0;
  for (j = 9; j > -1; j--) {
    average += kids[j];
  }
  average = average / 9;
  cout << "Average after drop: " << average << endl;
}
int main() {
  int j = 0, n = 10;
  double kids[n];
  string names[n];
  for (j = 0; j < n; j += 1) {
    cout << "Enter the grade for kid " << j + 1 << ": ";
    cin >> kids[j] >> names[j];
    if (kids[j] > 100 || kids[j] < 0) {
      cout << "Invalid input, try again" << endl;
      cin >> kids[j] >> names[j];
    }
  }
  task1(kids, names, n);
  task2(kids, n);
  return 0;
}
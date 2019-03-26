#include <iostream>
#include <vector>

using namespace std;

// Sort array in-place in ascending order
void bubbleSort(vector<int>& array) {
  int arraySize = array.size();
  bool sorted = false;

  while (!sorted) {
    sorted = true;

    for (int i = 0; i < arraySize - 1; ++i) {
      if (array[i] > array[i + 1]) {
        swap(array[i], array[i + 1]);
        sorted = false;
      }
    }
  }
}

ostream& operator<<(ostream& out, const vector<int>& array) {
  for (auto it = array.begin(); it != array.end(); ++it) {
    if (it != array.begin()) out << ", ";
    out << *it;
  }

  return out;
}

int main() {
  vector<int> a1;
  cout << "a1: " << a1 << endl;

  bubbleSort(a1);
  cout << "a1 (sorted): " << a1 << endl;

  vector<int> a2 = { 123 };
  cout << "a2: " << a2 << endl;

  bubbleSort(a2);
  cout << "a2 (sorted): " << a2 << endl;

  vector<int> a3 = { -213, 1032, 1, 2, 0, 0, 1, -2313 };
  cout << "a3: " << a3 << endl;

  bubbleSort(a3);
  cout << "a3 (sorted): " << a3 << endl;
}

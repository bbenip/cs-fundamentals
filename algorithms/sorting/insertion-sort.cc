#include <iostream>
#include <vector>

using namespace std;

// Sort array in-place in ascending order
void insertionSort(vector<int>& array) {
  int arraySize = array.size();

  for (int i = 1; i < arraySize; ++i) {
    int key = array[i];

    // Insert array[i] into the sorted subarray a[0..i-1]
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      --j;
    }

    array[j + 1] = key;
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

  insertionSort(a1);
  cout << "a1 (sorted): " << a1 << endl;

  vector<int> a2 = { 123 };
  cout << "a2: " << a2 << endl;

  insertionSort(a2);
  cout << "a2 (sorted): " << a2 << endl;

  vector<int> a3 = { -213, 1032, 1, 2, 0, 0, 1, -2313 };
  cout << "a3: " << a3 << endl;

  insertionSort(a3);
  cout << "a3 (sorted): " << a3 << endl;
}

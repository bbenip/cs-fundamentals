#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/**
 * Apply Selection Sort to an array
 *
 * Stable: No
 * Time Complexity: Θ(n^2)
 * Space Complexity: O(1)
 *
 * @param array
 *   An unsorted vector of integers
 */
void selectionSort(vector<int>& array) {
  int arraySize = array.size();

  // Store the smallest elements in the lowest indices
  for (int i = 0; i < arraySize - 1; ++i) {
    int minIndex = i;

    for (int j = i + 1; j < arraySize; ++j) {
      if (array[j] < array[minIndex]) minIndex = j;
    }

    swap(array[i], array[minIndex]);
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

  selectionSort(a1);
  cout << "a1 (sorted): " << a1 << endl;

  vector<int> a2 = { 123 };
  cout << "a2: " << a2 << endl;

  selectionSort(a2);
  cout << "a2 (sorted): " << a2 << endl;

  vector<int> a3 = { -213, 1032, 1, 2, 0, 0, 1, -2313 };
  cout << "a3: " << a3 << endl;

  selectionSort(a3);
  cout << "a3 (sorted): " << a3 << endl;
}

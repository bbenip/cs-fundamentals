#include <iostream>
#include <vector>

using namespace std;

/**
 * Search for key in array
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * @param array
 *   An vector of integers
 * @param key
 *   An integer which we are searching for
 * @return
 *   A boolean indicating whether key is in array 
 */
bool linearSearch(vector<int>& array, int key) {
  int arraySize = array.size();

  for (int i = 0; i < arraySize; ++i) {
    if (array[i] == key) {
      return true;
    }
  }

  return false;
}

ostream& operator<<(ostream& out, const vector<int>& array) {
  for (auto it = array.begin(); it != array.end(); ++it) {
    if (it != array.begin()) out << ", ";
    out << *it;
  }

  return out;
}

int main() {
  cout << boolalpha;

  vector<int> a1;
  int key1 = 0;

  cout << "a1: " << a1 << endl;
  cout << "key1: " << key1 << endl;
  cout << "linearSearch(a1, key1): " << linearSearch(a1, key1) << endl;
  cout << endl;

  vector<int> a2 = { 0 };
  int key2 = 0;

  cout << "a2: " << a2 << endl;
  cout << "key2: " << key2 << endl;
  cout << "linearSearch(a2, key2): " << linearSearch(a2, key2) << endl;
  cout << endl;

  vector<int> a3 = { 0, 1, 2 };
  int key3 = 3;

  cout << "a3: " << a3 << endl;
  cout << "key3: " << key3 << endl;
  cout << "linearSearch(a3, key3): " << linearSearch(a3, key3) << endl;
  cout << endl;

  vector<int> a4 = { 0, 1, 2, 3 };
  int key4 = 3;

  cout << "a4: " << a4 << endl;
  cout << "key4: " << key4 << endl;
  cout << "linearSearch(a4, key4): " << linearSearch(a4, key4) << endl;
  cout << endl;
}

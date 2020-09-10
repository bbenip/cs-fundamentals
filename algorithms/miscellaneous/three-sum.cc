#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Check if 3 distinct elements in array sum to 0
 *
 * Time Complexity: Ω(nlogn), O(n^2)
 * Space Complexity: O(1)
 *
 * @param array
 *   An unsorted vector of integers
 * @return
 *   A boolean indicating whether 3 distinct elements in array sum to 0
 */
bool threeSum(vector<int>& array) {
  sort(array.begin(), array.end());

  const int size = array.size();
  for (int i = 0; i < size - 2; ++i) {
    int j = i + 1;
    int k = size - 1;

    while (j < k) {
      const int sum = array[i] + array[j] + array[k];

      if (sum > 0) {
        --k;
      } else if (sum < 0) {
        ++j;
      } else {
        return true;
      }
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
  cout << "a1: " << a1 << endl;
  cout << "a1 (threeSum): " << threeSum(a1) << "\n\n";

  vector<int> a2 = { 123 };
  cout << "a2: " << a2 << endl;
  cout << "a2 (threeSum): " << threeSum(a2) << "\n\n";

  vector<int> a3 = { -1, 1 };
  cout << "a3: " << a3 << endl;
  cout << "a3 (threeSum): " << threeSum(a3) << "\n\n";

  vector<int> a4 = { 1, 0, -1 };
  cout << "a4: " << a4 << endl;
  cout << "a4 (threeSum): " << threeSum(a4) << "\n\n";

  vector<int> a5 = { 0, -1, 2 };
  cout << "a5: " << a5 << endl;
  cout << "a5 (threeSum): " << threeSum(a5) << "\n\n";

  vector<int> a6 = { 100, 1000, -344, 313, -656 };
  cout << "a6: " << a6 << endl;
  cout << "a6 (threeSum): " << threeSum(a6) << "\n\n";
}

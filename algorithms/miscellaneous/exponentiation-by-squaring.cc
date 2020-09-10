#include <iostream>

using namespace std;

/**
 * Calculate repeated multiplication of a base
 *
 * Time Complexity: O(logn)
 * Space Complexity: O(1)
 *
 * @param base
 *   An integer representing the base to be multiplied
 * @param exponent
 *   An integer representing the number of repeated multiplications
 * @return
 *   The value given by the base raised to the power of exponent
 */
int exponentiationBySquaring(int base, unsigned int exponent) {
  int result = 1;

  while (exponent > 0) {
    if (exponent & 1) {
      result *= base;
    }

    exponent >>= 1;
    base *= base;
  }

  return result;
}

int main() {
  const int base1 = 2;
  const unsigned int exponent1 = 0;

  cout << base1 << "^" << exponent1 << " = "
    << exponentiationBySquaring(base1, exponent1) << "\n\n";

  const int base2 = 4;
  const unsigned int exponent2 = 15;

  cout << base2 << "^" << exponent2 << " = "
    << exponentiationBySquaring(base2, exponent2) << "\n\n";

  const int base3 = 11;
  const unsigned int exponent3 = 7;

  cout << base3 << "^" << exponent3 << " = "
    << exponentiationBySquaring(base3, exponent3) << "\n\n";
}

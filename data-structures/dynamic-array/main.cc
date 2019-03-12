#include <iostream>
#include "dynamic-array.h"

using namespace std;

int main() {
  DynamicArray a1;

  cout << "a1 size: " << a1.getSize() << endl;

  a1 << 1 << 2 << 3;
  cout << "a1 size: " << a1.getSize() << endl;
  cout << a1 << endl;

  DynamicArray a2;
  a2.addRange(1, 10);
  cout << "a2 size: " << a2.getSize() << endl;
  cout << a2 << endl;
}

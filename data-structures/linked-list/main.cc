#include <iostream>
#include "linked-list.h"

using namespace std;

int main() {
  LinkedList l1;
  l1.insertAtFront(2);
  l1.insertAtBack(3);
  l1.insertAtFront(1);

  cout << "l1 size: " << l1.getSize() << endl;
  cout << l1 << endl;

  l1.reverseIterative();
  cout << "l1 reversed (iterative): " << l1 << endl;

  LinkedList l2;
  l2.insertAtBack(3);
  l2.insertAtFront(2);
  l2.insertAt(0, 1);
  l2.insertAt(3, 5);
  l2.insertAt(3, 4);
  l2.addRange(6, 10);

  cout << "l2 size: " << l2.getSize() << endl;
  cout << l2 << endl;

  l2.reverseRecursive();
  cout << "l2 reversed (recursive): " << l2 << endl;
}

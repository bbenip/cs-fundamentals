#include <ostream>

class LinkedList {
public:
  ~LinkedList();

  void insertAtFront(int value);
  void insertAtBack(int value);
  void insertAt(int index, int value);

  int getSize();

  void addRange(int begin, int end);

  friend std::ostream& operator<<(std::ostream& out, const LinkedList& ll);

private:
  struct Node;

  Node* head = nullptr;
  Node* tail = nullptr;
  int size = 0;
};

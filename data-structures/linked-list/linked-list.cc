#include <exception>
#include <string>
#include <utility>
#include "linked-list.h"

struct LinkedList::Node {
  int value;
  Node* next = nullptr;

  Node(int value, Node* next = nullptr);
  ~Node();
};

LinkedList::Node::Node(int value, LinkedList::Node* next) :
  value { value }, next { next } {}

LinkedList::Node::~Node() { delete next; }

LinkedList::~LinkedList() { delete head; }

void LinkedList::insertAtFront(int value) {
  Node* newNode = new Node(value, head);
  head = newNode;

  if (size == 0) tail = newNode;
  ++size;
}

void LinkedList::insertAtBack(int value) {
  Node* newNode = new Node(value);
  if (size == 0) {
    head = newNode;
  } else {
    tail->next = newNode;
  }

  tail = newNode;
  ++size;
}

void LinkedList::insertAt(int index, int value) {
  if (index < 0 || index > size) {
    throw std::out_of_range("ERROR: Index " +
        std::to_string(index) +
        " is invalid!");
  } else if (index == 0) {
    insertAtFront(value);
    return;
  } else if (index == size) {
    insertAtBack(value);
    return;
  }

  Node* previousNode = head;

  while (index > 1) {
    previousNode = previousNode->next;
    --index;
  }

  Node* newNode = new Node(value, previousNode->next);
  previousNode->next = newNode;

  ++size;
}

int LinkedList::getSize() { return size; }

void LinkedList::addRange(int begin, int end) {
  for (int i = begin; i < end; ++i) {
    insertAtBack(i);
  }
}

void LinkedList::reverseIterative() {
  if (size <= 1) return;

  Node* prevNode = nullptr;
  Node* curNode = head;
  Node* tmpNode;

  while (curNode->next != nullptr) {
    tmpNode = curNode->next;
    curNode->next = prevNode;
    prevNode = curNode;
    curNode = tmpNode;
  }

  curNode->next = prevNode;

  std::swap(tail, head);
}

std::ostream& operator<<(std::ostream& out, const LinkedList& ll) {
  LinkedList::Node* curNode = ll.head;

  while (curNode != nullptr) {
    if (curNode != ll.head) { out << " -> "; }
    out << curNode->value;
    curNode = curNode->next;
  }

  return out;
}

void LinkedList::reverseRecursive() {
  if (size <= 1) return;

  reverseRecursiveNode(head, nullptr);
  std::swap(head, tail);
}

void LinkedList::reverseRecursiveNode(Node* curNode, Node* prevNode) {
  if (curNode->next != nullptr) reverseRecursiveNode(curNode->next, curNode);
  curNode->next = prevNode;
}

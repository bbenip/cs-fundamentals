#include "dynamic-array.h"

DynamicArray::DynamicArray() {
  array = new int[capacity];
}

DynamicArray::~DynamicArray() {
  delete[] array;
}

int& DynamicArray::operator[](int index) const {
  return array[index];
}

DynamicArray& DynamicArray::operator<<(int value) {
  if (size == capacity) resizeArray();

  array[size] = value;
  ++size;

  return *this;
}

int DynamicArray::getSize() const { return size; }

void DynamicArray::addRange(int begin, int end) {
  for (int i = begin; i < end; ++i) {
    (*this) << i;
  }
}

void DynamicArray::resizeArray() {
  int newCapacity = capacity * 2;
  int* newArray = new int[newCapacity];

  for (int i = 0; i < capacity; ++i) {
    newArray[i] = array[i];
  }

  delete[] array;

  array = newArray;
  capacity = newCapacity;
}

std::ostream& operator<<(std::ostream& oss, const DynamicArray& array) {
  int size = array.getSize();

  for (int i = 0; i < size; ++i) {
    if (i != 0) oss << " ";
    oss << array[i];
  }

  return oss;
}

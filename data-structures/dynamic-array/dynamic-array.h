#include <ostream>

class DynamicArray {
public:
  DynamicArray();
  ~DynamicArray();

  int& operator[](int index) const;
  DynamicArray& operator<<(int value);

  int getSize() const;

  void addRange(int begin, int end);

private:
  int* array;
  int size = 0;
  int capacity = 1;

  void resizeArray();
};

std::ostream& operator<<(std::ostream& oss, const DynamicArray& array);

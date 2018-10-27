#ifndef TYPE_SAFE_IDENTIFIER_H
#define TYPE_SAFE_IDENTIFIER_H
#include <ostream>

template <typename T>
class TypeSafeIdentifier {
 public:
  explicit TypeSafeIdentifier(int id) : id_(id) {}

  int value() { return id_; }

  bool operator<(TypeSafeIdentifier<T> rhs) const { return id_ < rhs.id_; }
  bool operator==(TypeSafeIdentifier<T> rhs) const { return id_ == rhs.id_; }
  bool operator!=(TypeSafeIdentifier<T> rhs) const { return id_ != rhs.id_; }

 private:
  int id_;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, TypeSafeIdentifier<T> identifier) {
  return os << identifier.value();
}

#endif  // TYPE_SAFE_IDENTIFIER_H

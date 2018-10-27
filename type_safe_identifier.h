#ifndef TYPE_SAFE_IDENTIFIER_H
#define TYPE_SAFE_IDENTIFIER_H
#include <ostream>

template <typename T, typename IntegralT = int>
class TypeSafeIdentifier {
 public:
  explicit TypeSafeIdentifier(IntegralT id) : id_(id) {}

  /// Get the identifier value as an int
  int value() { return id_; }

  bool operator<(TypeSafeIdentifier<T> rhs) const { return id_ < rhs.id_; }
  bool operator==(TypeSafeIdentifier<T> rhs) const { return id_ == rhs.id_; }
  bool operator!=(TypeSafeIdentifier<T> rhs) const { return id_ != rhs.id_; }

 private:
  IntegralT id_;
};

template <typename T, typename IntegralT>
std::ostream &operator<<(std::ostream &os, TypeSafeIdentifier<T, IntegralT> identifier) {
  return os << identifier.value();
}

#endif  // TYPE_SAFE_IDENTIFIER_H

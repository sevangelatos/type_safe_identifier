#ifndef TYPE_SAFE_IDENTIFIER_H
#define TYPE_SAFE_IDENTIFIER_H
#include <ostream>

/**
 * A type-safe identifier class that wraps
 * a primitive id type to create a type safe one.
 */
template <typename T, typename RawIdT = int>
class TypeSafeIdentifier {
 public:
  explicit TypeSafeIdentifier(RawIdT id) : id_(id) {}

  /// Get the identifier value as an int
  RawIdT value() { return id_; }

  bool operator<(TypeSafeIdentifier<T, RawIdT> rhs) const {
    return id_ < rhs.id_;
  }

  bool operator==(TypeSafeIdentifier<T, RawIdT> rhs) const {
    return id_ == rhs.id_;
  }

  bool operator!=(TypeSafeIdentifier<T, RawIdT> rhs) const {
    return id_ != rhs.id_;
  }

 private:
  RawIdT id_;
};

template <typename T, typename RawIdT>
std::ostream &operator<<(std::ostream &os,
                         TypeSafeIdentifier<T, RawIdT> identifier) {
  return os << identifier.value();
}

#endif  // TYPE_SAFE_IDENTIFIER_H

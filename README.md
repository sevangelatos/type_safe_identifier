# Type Safe Identifier for C++
A C++ template class for type-safe identifiers replacing integer ids

Example usage:
```cpp
#include "type_safe_identifier.h"
#include <iostream>

class Cat;
using CatId = TypeSafeIdentifier<Cat>;

class Dog;
using DogId = TypeSafeIdentifier<Dog>;

void Feed(DogId dog) { std::cout << "Feeding dogfood to dog " << dog << '\n'; }
void Feed(CatId cat) { std::cout << "Feeding catfood to cat " << cat << '\n'; }
void GiveBath(DogId dog) { std::cout << "Doggie " << dog  << " takes a bath\n"; }
int main() {
  CatId minty(1);
  DogId spot(1);
  
  // These will feed the right kind of food.
  Feed(minty);
  Feed(spot);
  
  // Doggies are ok with taking a bath
  GiveBath(spot);
  
  // Cats don't like taking a bath and the compiler will protect you
  // by producing an error if you try to do so 
  // GiveBath(minty);
  return 0;
}

```

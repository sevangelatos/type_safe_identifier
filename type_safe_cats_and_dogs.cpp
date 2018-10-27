#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include "type_safe_identifier.h"

class Cat;
using CatId = TypeSafeIdentifier<Cat>;

class Dog;
using DogId = TypeSafeIdentifier<Dog>;

void Feed(DogId dog) { std::cout << "Feeding dog" << dog << std::endl; }

void Feed(CatId cat) { std::cout << "Feeding cat" << cat << std::endl; }

void DeclareParent(DogId parent, DogId child) {
  assert(child != parent);
  std::cout << "Dog " << parent << " is the parent of dog " << child
            << std::endl;
}

int main() {
  CatId minty(1);
  DogId lassy(1);
  DogId spot(2);

  // These will do the right thing
  Feed(minty);
  Feed(spot);
  Feed(lassy);

  DeclareParent(lassy, spot);

  // But this would cause an error because a cat cannot ever give birth to
  // a dog.
  // DeclareParent(minty, lassy);

  std::map<DogId, std::string> dog_names = {{lassy, "Lassy"}, {spot, "Spot"}};

  // As this will also cause a compilation error because you can't
  // look up a cat among a collection of dogs.
  // std::cout << dog_names[minty];

  for (auto it : dog_names) {
    std::cout << it.second << "'s DogId is " << it.first << std::endl;
  }
}

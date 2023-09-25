#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

bool sortByAge = false;

struct Person {
  char name[50];
  int age;
  bool operator<(const Person &p) const {
    if (sortByAge) {
      if (age != p.age)
        return age < p.age;
    }
    return strcmp(name, p.name) < 0;
  }
};
ostream &operator<<(ostream &os, const Person &p) {
  return os << "{" << p.name << ", " << p.age << "}";
}

vector<double> numbers{645.41, 37.59, 76.41,  5.31,    -34.23, 1.11,
                       1.10,   23.46, 635.47, -876.32, 467.83, 62.25};
vector<Person> people = {
    Person{"Hal", 20},
    Person{"Susann", 31},
    Person{"Dwight", 19},
    Person{"Kassandra", 21},
    Person{"Lawrence", 25},
    Person{"Cindy", 22},
    Person{"Cory", 27},
    Person{"Mac", 19},
    Person{"Romana", 27},
    Person{"Doretha", 32},
    Person{"Danna", 20},
    Person{"Zara", 23},
    Person{"Rosalyn", 26},
    Person{"Risa", 24},
    Person{"Benny", 28},
    Person{"Juan", 33},
    Person{"Natalie", 25}
};

template <class T> void printVector(vector<T> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i != v.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

int main() {

  cout << "Before:\nnumbers = ";
  printVector(numbers);

  sort(numbers.begin(), numbers.end());

  cout << "\nAfter:\nnumbers = ";
  printVector(numbers);

  cout << "\nBefore:\npeople = ";
  printVector(people);

  // Sort people vector by custom comparison function
  sort(people.begin(), people.end());

  cout << "\nAfter:\npeople = ";
  printVector(people);

  sortByAge = true;

  cout << "\nBefore:\npeople = ";
  printVector(people);

  // Sort people vector again with updated comparison function
  sort(people.begin(), people.end());

  cout << "\nAfter:\npeople = ";
  printVector(people);

  return 0;
}

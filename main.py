numbers = [
  645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32,
  467.83, 62.25
]

people = [{
  "name": "Hal",
  "age": 20
}, {
  "name": "Susann",
  "age": 31
}, {
  "name": "Dwight",
  "age": 19
}, {
  "name": "Kassandra",
  "age": 21
}, {
  "name": "Lawrence",
  "age": 25
}, {
  "name": "Cindy",
  "age": 22
}, {
  "name": "Cory",
  "age": 27
}, {
  "name": "Mac",
  "age": 19
}, {
  "name": "Romana",
  "age": 27
}, {
  "name": "Doretha",
  "age": 32
}, {
  "name": "Danna",
  "age": 20
}, {
  "name": "Zara",
  "age": 23
}, {
  "name": "Rosalyn",
  "age": 26
}, {
  "name": "Risa",
  "age": 24
}, {
  "name": "Benny",
  "age": 28
}, {
  "name": "Juan",
  "age": 33
}, {
  "name": "Natalie",
  "age": 25
}]

numbers.sort()
print(numbers)
print()
people.sort(key = lambda x: x.get("name"))
print(people)
print()
people.sort(key=lambda x: x.get("age"), reverse=True)
print(people)

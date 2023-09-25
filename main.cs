using System;
using System.Collections.Generic;
using System.Linq;

public struct Person
{
    public Person(string n, int a) { name = n; age = a; }
    public string name { get; set; }
    public int age { get; set; }
    public override string ToString() { return "{" + name + ", " + age + "}"; }
}

class Program
{
    public static void printList<T>(List<T> l)
    {
        Console.Write("[");
        for (var i = 0; i < l.Count; i++)
        {
            Console.Write(l[i]);
            if (i != l.Count - 1) Console.Write(", ");
        }
        Console.WriteLine("]");
    }

    public static void Main(string[] args)
    {
        var numbers = new List<double> { 645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25 };
        var people = new List<Person>{
      new Person() {name = "Hal", age = 20},
      new Person() {name = "Susann", age = 31},
      new Person() {name = "Dwight", age = 19},
      new Person() {name = "Kassandra", age = 21},
      new Person() {name = "Lawrence", age = 25},
      new Person() {name = "Cindy", age = 22},
      new Person() {name = "Cory", age = 27},
      new Person() {name = "Mac", age = 19},
      new Person() {name = "Romana", age = 27},
      new Person() {name = "Doretha", age = 32},
      new Person() {name = "Danna", age = 20},
      new Person() {name = "Zara", age = 23},
      new Person() {name = "Rosalyn", age = 26},
      new Person() {name = "Risa", age = 24},
      new Person() {name = "Benny", age = 28},
      new Person() {name = "Juan", age = 33},
      new Person() {name = "Natalie", age = 25}
    };
        Console.Write("Before:\nnumbers = ");
        printList(numbers);
        numbers.Sort();
        Console.Write("\nAfter:\nnumbers = ");
        printList(numbers);

        Console.Write("\nBefore:\npeople = ");
        printList(people);
        people = people.OrderBy(a => a.name).ToList();
        Console.Write("\nAfter:\npeople = ");
        printList(people);

        Console.Write("\nBefore:\npeople = ");
        printList(people);
        people = people.OrderByDescending(a => a.age).ToList();
        Console.Write("\nAfter:\npeople = ");
        printList(people);
    }
}
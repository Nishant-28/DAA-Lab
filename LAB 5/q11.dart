import 'dart:io';

class Person {
  int id;
  String name;
  int age;
  int height;
  int weight;

  Person(this.id, this.name, this.age, this.height, this.weight);
}

List<Person> heap = [];
int size = 0;
int capacity = 0;

void insert(Person p) {
  if (size == capacity) {
    print("Heap is full");
    return;
  }
  size++;
  int i = size - 1;
  heap.add(p);
  while (i != 0 && heap[parent(i)].age > heap[i].age) {
    swap(i, parent(i));
    i = parent(i);
  }
}

void delete() {
  if (size == 0) {
    print("Heap is empty");
    return;
  }
  if (size == 1) {
    size--;
    return;
  }
  heap[0] = heap[size - 1];
  size--;
  heapify(0);
}

void heapify(int i) {
  int l = left(i);
  int r = right(i);
  int smallest = i;
  if (l < size && heap[l].age < heap[i].age) smallest = l;
  if (r < size && heap[r].age < heap[smallest].age) smallest = r;
  if (smallest != i) {
    swap(i, smallest);
    heapify(smallest);
  }
}

void swap(int i, int j) {
  Person temp = heap[i];
  heap[i] = heap[j];
  heap[j] = temp;
}

int parent(int i) {
  return (i - 1) ~/ 2;
}

int left(int i) {
  return 2 * i + 1;
}

int right(int i) {
  return 2 * i + 2;
}

void display() {
  for (int i = 0; i < size; i++) {
    print(
        "${heap[i].id} ${heap[i].name} ${heap[i].age} ${heap[i].height} ${heap[i].weight}");
  }
}

void displayWeight() {
  print("Weight of youngest student: ${heap[0].weight} kg");
}

void main() {
  print("MAIN MENU (HEAP)");
  print("1. Read Data");
  print("2. Create a Min-heap based on the age");
  print("3. Create a Max-heap based on the weight");
  print("4. Display weight of the youngest person");
  print("5. Insert a new person into the Min-heap");
  print("6. Delete the oldest person");
  print("7. Exit");

  late int ch;
  stdout.write("Enter option: ");
  ch = int.parse(stdin.readLineSync()!);

  while (ch != 7) {
    switch (ch) {
      case 1:
        {
          stdout.write("Enter the number of students: ");
          int n = int.parse(stdin.readLineSync()!);

          capacity = n;

          for (int i = 0; i < n; i++) {
            stdout.write("Enter id: ");
            int id = int.parse(stdin.readLineSync()!);

            stdout.write("Enter name: ");
            String name = stdin.readLineSync()!;

            stdout.write("Enter age: ");
            int age = int.parse(stdin.readLineSync()!);

            stdout.write("Enter height: ");
            int height = int.parse(stdin.readLineSync()!);

            stdout.write("Enter weight: ");
            int weight = int.parse(stdin.readLineSync()!);

            Person p = Person(id, name, age, height, weight);

            insert(p);
          }
          break;
        }
      case 2:
        {
          print("Min-heap based on age:");
          display();
          break;
        }
      case 3:
        {
          print("Max-heap based on weight:");
          for (int i = 0; i < size; i++) {
            heap[i].age = -heap[i].age;
          }
          for (int i = 0; i < size; i++) {
            heap[i].age = -heap[i].age;
          }
          display();
          break;
        }
      case 4:
        {
          displayWeight();
          break;
        }
      case 5:
        {
          stdout.write("Enter id: ");
          int id = int.parse(stdin.readLineSync()!);

          stdout.write("Enter name: ");
          String name = stdin.readLineSync()!;

          stdout.write("Enter age: ");
          int age = int.parse(stdin.readLineSync()!);

          stdout.write("Enter height: ");
          int height = int.parse(stdin.readLineSync()!);

          stdout.write("Enter weight: ");
          int weight = int.parse(stdin.readLineSync()!);

          Person p = Person(id, name, age, height, weight);

          insert(p);
          break;
        }
      case 6:
        {
          delete();
          break;
        }
      default:
        {
          print("Invalid choice");
          break;
        }
    }
    stdout.write("Enter option: ");
    ch = int.parse(stdin.readLineSync()!);
  }
}

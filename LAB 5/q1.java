/*5.1 Aim of the program:
Define a struct person as follows:
struct person
{
int id;
char *name;
int age;
int height;
int weight;
};
Write a menu driven program to read the data of ‘n’ students from a file and store them in a
dynamically allocated array of struct person. Implement the min-heap or max-heap and its
operations based on the menu options.
Sample Input/Output:
MAIN MENU (HEAP)
1. Read Data
2. Create a Min-heap based on the age
3. Create a Max-heap based on the weight
4. Display weight of the youngest person
5. Insert a new person into the Min-heap
6. Delete the oldest person
7. Exit
Enter option: 1
Id Name Age Height Weight(pound)
0 Adarsh Hota 39 77 231
1 Levi Maier 56 77 129
2 Priya Kumari 63 78 240
3 Dorothy Helton 47 72 229
4 Florence Smith 24 75 171
5 Erica Anyan 38 73 102
6 Norma Webster 23 75 145
Enter option: 4
Weight of youngest student: 65.77 kg */

import java.util.*;
import java.io.*;
class person
{
    int id;
    String name;
    int age;
    int height;
    int weight;
    person(int id,String name,int age,int height,int weight)
    {
        this.id=id;
        this.name=name;
        this.age=age;
        this.height=height;
        this.weight=weight;
    }
}
class q1
{
    static person[] heap;
    static int size;
    static int capacity;
    static void insert(person p)
    {
        if(size==capacity)
        {
            System.out.println("Heap is full");
            return;
        }
        size++;
        int i=size-1;
        heap[i]=p;
        while(i!=0 && heap[parent(i)].age>heap[i].age)
        {
            swap(i,parent(i));
            i=parent(i);
        }
    }
    static void delete()
    {
        if(size==0)
        {
            System.out.println("Heap is empty");
            return;
        }
        if(size==1)
        {
            size--;
            return;
        }
        heap[0]=heap[size-1];
        size--;
        heapify(0);
    }
    static void heapify(int i)
    {
        int l=left(i);
        int r=right(i);
        int smallest=i;
        if(l<size && heap[l].age<heap[i].age)
            smallest=l;
        if(r<size && heap[r].age<heap[smallest].age)
            smallest=r;
        if(smallest!=i)
        {
            swap(i,smallest);
            heapify(smallest);
        }
    }
    static void swap(int i,int j)
    {
        person temp=heap[i];
        heap[i]=heap[j];
        heap[j]=temp;
    }
    static int parent(int i)
    {
        return (i-1)/2;
    }
    static int left(int i)
    {
        return 2*i+1;
    }
    static int right(int i)
    {
        return 2*i+2;
    }
    static void display()
    {
        for(int i=0;i<size;i++)
            System.out.println(heap[i].id+" "+heap[i].name+" "+heap[i].age+" "+heap[i].height+" "+heap[i].weight);
    }
    static void displayWeight()
    {
        System.out.println("Weight of youngest student: "+heap[0].weight+" kg");
    }
    public static void main(String args[])throws IOException
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("MAIN MENU (HEAP)");
        System.out.println("1. Read Data");
        System.out.println("2. Create a Min-heap based on the age");
        System.out.println("3. Create a Max-heap based on the weight");
        System.out.println("4. Display weight of the youngest person");
        System.out.println("5. Insert a new person into the Min-heap");
        System.out.println("6. Delete the oldest person");
        System.out.println("7. Exit");
        System.out.print("Enter option: ");
        int ch=sc.nextInt();
        while(ch!=7)
        {
            switch(ch)
            {
                case 1:
                {
                    System.out.print("Enter the number of students: ");
                    int n=sc.nextInt();
                    capacity=n;
                    heap=new person[capacity];
                    for(int i=0;i<n;i++)
                    {
                        System.out.print("Enter id: ");
                        int id=sc.nextInt();
                        System.out.print("Enter name: ");
                        String name=sc.next();
                        System.out.print("Enter age: ");
                        int age=sc.nextInt();
                        System.out.print("Enter height: ");
                        int height=sc.nextInt();
                        System.out.print("Enter weight: ");
                        int weight=sc.nextInt();
                        person p=new person(id,name,age,height,weight);
                        insert(p);
                    }
                    break;
                }
                case 2:
                {
                    System.out.println("Min-heap based on age:");
                    display();
                    break;
                }
                case 3:
                {
                    System.out.println("Max-heap based on weight:");
                    for(int i=0;i<size;i++)
                        heap[i].age=-heap[i].age;
                    Arrays.sort(heap,0,size,new Comparator<person>(){
                        public int compare(person p1,person p2)
                        {
                            return p1.age-p2.age;
                        }
                    });
                    for(int i=0;i<size;i++)
                        heap[i].age=-heap[i].age;
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
                    System.out.print("Enter id: ");
                    int id=sc.nextInt();
                    System.out.print("Enter name: ");
                    String name=sc.next();
                    System.out.print("Enter age: ");
                    int age=sc.nextInt();
                    System.out.print("Enter height: ");
                    int height=sc.nextInt();
                    System.out.print("Enter weight: ");
                    int weight=sc.nextInt();
                    person p=new person(id,name,age,height,weight);
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
                    System.out.println("Invalid choice");
                    break;
                }
            }
            System.out.print("Enter option: ");
            ch=sc.nextInt();
        }
    }
}

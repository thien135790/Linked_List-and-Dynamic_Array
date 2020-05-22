#include <chrono>
#include <ctime>
#include <iostream>
#include <ratio>
using namespace std;
using namespace std::chrono;
//      Struct + Khai bao
struct Array {
  int capacity;
  int n;
  int *arr;
};
struct Node {
  int value;
  Node *next;
};
struct List {
  Node *head, *tail;
};
void init_array(Array &arr) {
  arr.arr = NULL;
  arr.n = arr.capacity = 0;
}
void init_list(List &l) { l.head = l.tail = NULL; }
///////////////////////////////////
//      Dynamic_array      //
// #Add code here
void Input_Array(Array& a, int x) { //them phan tu vao cuoi mang
    if (a.n == 0) {
        a.arr = new int[2];
        a.arr[0] = x;
        a.n = 1; a.capacity = 2;
    }
    else if (a.n < a.capacity) {
        a.arr[a.n] = x;
        a.n++;
    }
    else if (a.n >= a.capacity) {
        auto b = new int[a.capacity * 2];
        for (int i = 0; i < a.n; i++) { b[i] = a.arr[i]; }
        b[a.n] = x;
        delete a.arr;
        a.arr = b;
        a.n++;
        a.capacity *= 2;
    }
}
void Add_into_any_position(Array& a, int x, int pos) {
    if (a.n < a.capacity) {
        if (pos == a.n) {
            a.arr[a.n] = x;
            a.n++;
        }
        else if (pos == 0) {
            for (int i = a.n; i > 0; i--) {
                a.arr[i] = a.arr[i - 1];
            }
            a.arr[0] = x;
            a.n++;
        }
        else if (pos != 0 && pos != a.n) {
            for (int i = a.n; i > pos; i--) {
                a.arr[i] = a.arr[i - 1];
            }
            a.arr[pos] = x;
            a.n++;
        }
    }
}
///////////////////////////////////

//////////////////////////////////
//      Linked_List            //
// #Add code here
//////////////////////////////////

int main() {
  // Khai bao
  int number = ;  // cho so vao day
  high_resolution_clock::time_point t1, t2;
  duration<double> time_span;
  List l;
  init_list(l);
  Array a;
  init_array(a);
  // So sanh
  /* Recycle key_word
   t1 = high_resolution_clock::now();
   t2 = high_resolution_clock::now();
   time_span = duration_cast<duration<double>>(t2 - t1);
   cout << " " << time_span.count() << " seconds.\n";*/
  // thao tac 1

  // thao tac 2

  //

  return 0;
}

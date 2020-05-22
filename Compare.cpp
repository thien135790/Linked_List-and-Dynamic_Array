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
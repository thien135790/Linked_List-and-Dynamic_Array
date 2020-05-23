#include <chrono>
#include <ctime>
#include <iostream>
#include <map>
#include <ratio>
#include <tuple>
#include <utility>
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
void Input_Array(Array &a, int x) {  // them phan tu vao cuoi mang
  if (a.n == 0) {
    a.arr = new int[2];
    a.arr[0] = x;
    a.n = 1;
    a.capacity = 2;
  } else if (a.n < a.capacity) {
    a.arr[a.n] = x;
    a.n++;
  } else if (a.n >= a.capacity) {
    auto b = new int[a.capacity * 2];
    for (int i = 0; i < a.n; i++) {
      b[i] = a.arr[i];
    }
    b[a.n] = x;
    delete a.arr;
    a.arr = b;
    a.n++;
    a.capacity *= 2;
  }
}
void Add_into_any_position(Array &a, int x, int pos) {
  if (a.n < a.capacity) {
    if (pos == a.n) {
      a.arr[a.n] = x;
      a.n++;
    } else if (pos == 0) {
      for (int i = a.n; i > 0; i--) {
        a.arr[i] = a.arr[i - 1];
      }
      a.arr[0] = x;
      a.n++;
    } else if (pos != 0 && pos != a.n) {
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
Node *CreateNode(int value) {
  Node *pNode = new Node;
  if (pNode == nullptr) {
    return 0;
  }
  pNode->value = value;
  pNode->next = nullptr;
  return pNode;
}
// cac thao tac them vao danh sach
void Add_Head(List &l, int value) {
  Node *pNode = CreateNode(value);
  if (l.head == nullptr) {
    l.head = pNode;
    l.tail = l.head;
  } else {
    pNode->next = l.head;
    l.head = pNode;
  }
}
void Add_Tail(List &l, int value) {
  Node *pNode = CreateNode(value);
  if (l.head == nullptr) {
    l.head = pNode;
    l.tail = l.head;
  } else {
    l.tail->next = pNode;
    l.tail = pNode;
    pNode->next = nullptr;
  }
}
void Insert(List &l, int index, int value) {
  Node *pNode = l.head;
  while (pNode != nullptr) {
    if (pNode->value == index) {
      break;
    }
    pNode = pNode->next;
  }
  if (pNode == nullptr) {
    return;
  } else {
    Node *ptemp = new Node;
    ptemp->value = value;
    ptemp->next = pNode->next;
    pNode->next = ptemp;
  }
}
// cac thao tac duyet mang
Node *Find_Node(List &l, int value) {
  if (l.head == nullptr) {
    return nullptr;
  } else {
    Node *pNode = l.head;
    while (pNode != l.tail && pNode->next->value != value) {
      pNode = pNode->next;
    }
    if (pNode == l.tail) {
      return nullptr;
    } else if (pNode->next->value == value) {
      return pNode;
    }
  }
  return nullptr;
}
int Find_Value_at_Index(List &l, int index) {
  int count = 0;
  Node *p = l.head;
  while (p != nullptr) {
    p = p->next;
    if (count == index) {
      return p->value;
    }
    ++count;
  }
  return -1;
}
int Find_Value(List &l, int value) {
  Node *p = l.head;
  while (p->next != nullptr) {
    if (p->value == value) {
      return p->value;
    }
    p = p->next;
  }
  return -1;
}
int getLength(List &l) {
  if (l.head == 0) {
    return 0;
  }
  int count = 0;
  Node *p = l.head;
  while (p != nullptr) {
    ++count;
    p = p->next;
  }
  return count;
}
void OutPut(List &l) {
  if (l.head == 0) {
    cout << "emty!";
  } else {
    Node *p = l.head;
    while (p != nullptr) {
      cout << p->value << " ";
      p = p->next;
    }
  }
}

// cac thao tac xoa
void Del_Head(List &l) {
  if (l.head == nullptr) {
    return;
  } else if (l.head == l.tail) {
    delete l.head;
    l.head = l.tail = nullptr;
  } else {
    Node *p = l.head;
    l.head = l.head->next;
    delete p;
  }
}
void Del_tail(List &l) {
  if (l.head == nullptr) {
    return;
  }
  Node *pNode = l.head;
  while (pNode->next->next != nullptr) {
    pNode = pNode->next;
  }
  Node *q = pNode->next;
  l.tail = pNode;
  pNode->next = nullptr;
  delete q;
}
void DelNode(List &l, Node *q) {
  if (q->next == l.tail) {
    delete l.tail;
    q->next = nullptr;
    l.tail = q;
  } else if (q == l.tail) {
    return;
  } else {
    Node *pNode = q->next;
    q->next = pNode->next;
    delete pNode;
  }
}
// cac thao tac khac
void Change(List &l, int index, int value) {
  Node *p = l.head;
  int count = 0;
  while (p != nullptr) {
    if (count == index) {
      p->value = value;
      return;
    }
    p = p->next;
    ++count;
  }
}
void Copy(List &l, List &l2) {
  Node *pNode1 = l.head;
  Node *pNode2;
  init_list(l2);
  while (pNode1 != nullptr) {
    pNode2 = pNode1;
    Add_Tail(l2, pNode2->value);
    pNode1 = pNode1->next;
  }
}
// cac thao tac kiem tra
void Dao_Nguoc(List &l) {
  Node *next, *temp, *pNode;
  temp = l.head;
  pNode = NULL;
  while (temp != NULL) {
    next = temp->next;
    temp->next = pNode;
    pNode = temp;
    temp = next;
  }
  l.head = pNode;
}
bool isDoiXung(List &l) {
  Node *p1 = l.head;
  Node *p2 = l.head;
  while (p2 != NULL && p2->next != NULL) {
    p2 = p2->next->next;
    p1 = p1->next;
  }
  Node *pNode;
  Node *next;
  pNode = NULL;
  while (p1 != NULL) {
    next = p1->next;
    p1->next = pNode;
    pNode = p1;
    p1 = next;
  }
  p1 = pNode;
  p2 = l.head;
  while (p1 != NULL) {
    if (p1->value != p2->value) {
      return false;
    }
    p1 = p1->next;
    p2 = p2->next;
  }
  return true;
}
void print_longest_increasing_sub_list(List &l) {
  Node *p = l.head;
  int count = 0, temp = 0;
  while (p->next != NULL) {
    if (p->next->value >= p->value) {
      ++count;
    }
    if (p->next->value < p->value) {
      count = 0;
    }
    if (count > temp) {
      temp = count;
    }
    p = p->next;
  }
  cout << temp + 1;
}
bool is_subsequence(List l1, List l2) {
  int l1_count = 0;
  int l2_count = 0;
  int l1_length = getLength(l1);
  int l2_length = getLength(l2);
  Node *p1 = l1.head;
  Node *p2 = l2.head;
  while (l1_count < l1_length && l2_count < l2_length) {
    if (p1->value == p2->value) {
      ++l1_count;
      p1 = p1->next;
    }
    ++l2_count;
    p2 = p2->next;
  }
  if (l1_count == l1_length) {
    return true;
  }
  return false;
}
// sap xep danh sach tang dan
void SelectionSort(List &l) {
  int j = 0;
  int temp = 0;
  for (Node *p = l.head; p->next != nullptr; p = p->next) {
    int min = p->value;
    int index = 0;
    ++j;
    int i = 0;
    i += j;
    for (Node *q = p->next; q != nullptr; q = q->next, ++i) {
      if (q->value < min) {
        min = q->value;
        index = i;
      }
    }
    if (index == 0) {
    } else {
      temp = p->value;
      p->value = min;
      Change(l, index, temp);
    }
  }
}
// chia danh sach
tuple<List, List, List> partition(List &l, int x) {
  List l2, l3;
  Node *node = l.head;
  Node *p = NULL;
  Node *p2 = NULL;
  Node *q = NULL;
  Node *q2 = NULL;
  init_list(l2);
  init_list(l3);
  while (node != NULL) {
    if (node->value < x) {
      if (p == NULL) {
        p = p2 = node;
      } else {
        p2->next = node;
        p2 = node;
      }
    } else if (node->value == x) {
      Add_Head(l2, node->value);
    } else {
      if (q == NULL) {
        q = q2 = node;
      } else {
        q2->next = node;
        q2 = node;
      }
    }
    node = node->next;
  }
  delete node;
  init_list(l);
  p2->next = NULL;
  q2->next = NULL;
  l3.head = q;
  l3.tail = q2;
  l.head = p;
  l.tail = p2;
  return std::make_tuple(l, l2, l3);
}
void join(List &l, List &l2) {
  if (l.head == NULL) {
    l.head = l2.head;
    l.tail = l2.tail;
  } else if (l2.head == NULL)
    return;
  else if (l.head->value == l2.head->value)
    return;
  else {
    Node *p = l.tail;
    p->next = l2.head;
    l.tail = l2.tail;
  }
}
// tach danh sach
inline pair<List, List> split(List &l) {
  int i = 0;
  Node *head1 = l.head;
  Node *head2 = NULL;
  Node *temp = head1;
  head2 = temp->next;
  Node *holder1 = head1;
  Node *holder2 = head2;
  while (temp != NULL) {
    ++i;
    if (i % 2 == 1 && i != 1) {
      holder1->next = temp;
      holder1 = holder1->next;
    }
    if (i % 2 == 0 && i != 2) {
      holder2->next = temp;
      holder2 = holder2->next;
    }
    temp = temp->next;
  }
  holder1->next = NULL;
  holder2->next = NULL;
  pair<List, List> gan;
  gan.first.head = head1;
  gan.second.head = head2;
  return gan;
}
// tron 2 mang
List merge_2_sorted_lists(List &l1, List &l2) {
  Node *p1 = l1.head;
  Node *p2 = l2.head;
  if (p1 == NULL) {
    return l2;
  }
  if (p2 == NULL) {
    return l1;
  }
  if (p2->value < p1->value) {
    Node *temp = p2;
    p2 = p1;
    p1 = temp;
  }
  Node *pNode1 = p1;
  Node *pNode2 = p2;
  while (pNode1 != NULL && pNode2 != NULL) {
    if (pNode2->value >= pNode1->value &&
        ((pNode1->next == NULL) || (pNode2->value < pNode1->next->value))) {
      Node *t1 = pNode1->next;
      Node *t2 = pNode2->next;
      pNode1->next = pNode2;
      pNode2->next = t1;
      pNode2 = t2;
    } else {
      pNode1 = pNode1->next;
    }
  }
  if (l1.head->value <= l2.head->value) {
    return l1;
  } else {
    return l2;
  }
}

//////////////////////////////////

int main() {
  // Khai bao
  int number = 100000;  // cho so vao day
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
  srand(time(NULL));
  for (int i = 0; i < 5; i++) {
    Add_Tail(l, rand());
  }
  OutPut(l);
  cout << "\n";
  
  SelectionSort(l);
  OutPut(l);

  // thao tac 2

  //

  return 0;
}

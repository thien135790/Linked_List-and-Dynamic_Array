#include <algorithm>
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
// them phan tu vao cuoi mang
void Input_Array(Array &a, int x) {
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
// them vao bat ky vi tri nao
void Add_into_any_position(Array& a, int x, int pos) {
    if (a.capacity > a.n) {
        for (int i = a.n; i > pos; i--) {
            a.arr[i] = a.arr[i - 1];
        }
        a.arr[pos] = x;
        ++a.n;
    }
    else {
        a.capacity = a.n;
        ++a.capacity;
        int* b = new int[++a.capacity];
        for (int i = 0; i < pos; i++) {
            b[i] = a.arr[i];
        }
        b[pos] = x;
        for (int i = pos + 1; i <= a.n; i++) {
            b[i] = a.arr[i - 1];
        }
        delete a.arr;
        a.arr = b;
        ++a.n;
    }
}
// xoa vi tri bat ky
void Delete_any_position(Array& a, int pos) {
    if (pos == a.n - 1) {
        int* b = new int[a.n - 1];
        for (int i = 0; i < a.n - 1; i++) {
            b[i] = a.arr[i];
        }
        delete a.arr;
        a.arr = b;
        a.n -= 1;
        return;
    }
    if (a.n == 0);
    else {
        if (pos < a.n) {
            for (int i = pos; i < a.n - 1; i++) {
                a.arr[i] = a.arr[i + 1];
            }
            a.n--;
        }
    }
}
// tra ve so luong phan tu cua mang
int DemSoLuongPhanTu(Array a) { return a.n; }
// xuat mang
void Ouput_Array(Array a) {
  for (int i = 0; i < a.n; i++) {
    cout << a.arr[i] << " ";
  }
  cout << endl;
}
// tim kiem tuyen tinh
int search(Array a, int x) {
  for (int i = 0; i < a.n; i++) {
    if (a.arr[i] == x) return i;
  }
  return -1;
}
// sap xep mang
void SelectionSort_arr(Array &a) {
  int i, j, min_idx;

  for (i = 0; i < a.n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < a.n; j++)
      if (a.arr[j] < a.arr[min_idx]) min_idx = j;

    // Swap the found minimum element with the first element
    swap(a.arr[min_idx], a.arr[i]);
  }
}
void sort(int *&a, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j]) swap(a[i], a[j]);
    }
  }
}
int Bin(int *a, int l, int r, int x) {
  if (l <= r) {
    if (a[l] == x) return l;
    if (a[r] == x) return r;
    int m = (l + r) / 2;
    if (a[m] == x) return m;
    if (a[m] < x) return Bin(a, m + 1, r, x);
    if (a[m] > x) return Bin(a, l, m - 1, x);
  }
  return -1;
}
// tim kiem nhi phan
int Binasearch(Array &a, int x) {
  sort(a.arr, a.n);
  int l = 0, r = a.n - 1;
  return Bin(a.arr, l, r, x);
}
// thay doi vi tri bat ky
void Change_the_value_of_any_position(Array &a, int x, int pos) {
  if (pos >= a.n)
    ;
  else {
    a.arr[pos] = x;
  }
}
// sao chep mang A sang B
void Copy(Array a, Array &b) {
  init_array(b);
  b.n = a.n;
  b.capacity = a.capacity;
  for (int i = 0; i < b.n; i++) {
    b.arr[i] = a.arr[i];
  }
}
// dao mang
void Dao_mang(Array &a) {
  for (int i = 0; i < a.n / 2; i++) {
    swap(a.arr[i], a.arr[a.n - 1 - i]);
  }
}
// kiem tra doi xung
bool Doi_Xung(Array a) {
  for (int i = 0; i < a.n; i++) {
    if (a.arr[i] != a.arr[a.n - i - 1]) return false;
  }
  return true;
}
// dem mang con tang
int DemMangTang(Array a) {
  int count = 0;
  for (int i = 0; i < a.n - 1; i++) {
    if (a.arr[i] < a.arr[i + 1]) {
      ++count;
      while (a.arr[i] <= a.arr[i + 1]) {
        ++i;
      }
    }
  }
  return count;
}
// kiem tra mang con

bool is_MangCon(Array a, Array b) {
  int l1_count = 0, l2_count = 0;
  int i = 0, j = 0;
  while (l1_count < a.n && l2_count < b.n) {
    if (a.arr[i] == b.arr[j]) {
      ++l1_count;
      ++i;
    }
    ++l2_count;
    ++j;
  }
  if (l1_count == a.n) {
    return true;
  }
  return false;
}
tuple<Array, Array, Array> PhanHoach(Array a, int x) {
  Array m, n, p;
  init_array(m);
  init_array(n);
  init_array(p);
  if (a.n == 0) return make_tuple(m, n, p);
  for (int i = 0; i < a.n; i++) {
    if (a.arr[i] < x) {
      Input_Array(m, a.arr[i]);
    } else if (a.arr[i] == x) {
      Input_Array(n, a.arr[i]);
    } else if (a.arr[i] > x) {
      Input_Array(p, a.arr[i]);
    }
  }
  return make_tuple(m, n, p);
}
void insertion_sort(int *a, int n) {
  int i, j, x;
  for (i = 1; i < n; i++) {
    x = a[i];
    j = i;
    while (j > 0 && a[j - 1] > x) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = x;
  }
}
Array TronTangDan(Array a, Array b) {
  Array c;
  init_array(c);
  c.n = a.n + b.n;
  c.arr = new int[c.n];
  c.capacity = a.capacity + b.capacity;
  for (int i = 0; i < c.n; i++) {
    if (i < a.n) {
      c.arr[i] = a.arr[i];
    } else
      c.arr[i] = b.arr[i - a.n];
  }
  return c;
}
pair<Array, Array> TachMang(Array a) {
  pair<Array, Array> A;
  init_array(A.first);
  init_array(A.second);
  if (a.n % 2 == 0) {
    A.first.n = a.n % 2;
    A.second.n = a.n % 2;
  } else {
    A.first.n = a.n % 2;
    A.second.n = (a.n % 2) + 1;
  }
  for (int i = 0; i < a.n; i++) {
    if (i % 2 == 0) {
      Input_Array(A.first, a.arr[i]);
    } else
      Input_Array(A.second, a.arr[i]);
  }
  return A;
}
int Sub_arr_arr(Array a) {
  int temp = 0, count = 0;
  for (int i = 0; i < a.n - 1; i++) {
    if (a.arr[i + 1] >= a.arr[i]) {
      ++count;
    }
    if (a.arr[i + 1] < a.arr[i]) {
      count = 0;
    }
    if (count > temp) {
      temp = count;
    }
  }
  return temp + 1;
}
Array Link_array(Array a, Array b) {
  Array c;
  init_array(c);
  c.n = a.n + b.n;
  c.arr = new int[c.n];
  c.capacity = a.capacity + b.capacity;
  for (int i = 0; i < c.n; i++) {
    if (i < a.n) {
      c.arr[i] = a.arr[i];
    } else
      c.arr[i] = b.arr[i - a.n];
  }
  return c;
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
Node* Findnode2(List& l, int pos) {
    if (l.head == nullptr) {
        return NULL;
    }
    int m = 0;
    for (Node* i = l.head; i != NULL; i = i->next) {
        m += 1;
        if (m == pos) return i;
    }
    return NULL;
}
int Find_Value_at_Index(List &l, int index) {
  int count = 0;
  Node *p = l.head;
  while (p != nullptr) {
    if (count == index) {
      return p->value;
    }
    ++count;
    p = p->next;
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
void OutPut_list(List &l) {
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
void Insert_list(List &l, int index, int value) {
  Node *pNode = l.head;
  int i = Find_Value_at_Index(l, index);
  if (l.head->value == i) {
    Node *temp = CreateNode(value);
    temp->next = l.head->next;
    l.head->next = temp;
    return;
  }
  while (pNode != NULL) {
    if (pNode->value == i) {
      break;
    }
    pNode = pNode->next;
  }
  if (pNode == nullptr) {
    Add_Head(l, value);
  } else {
    Node *p = new Node;
    p->value = value;
    p->next = pNode->next;
    pNode->next = p;
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
int Sub_arr_List(List l) {
  int count = 0;
  for (Node *p = l.head; p != nullptr; p = p->next) {
    if (p->value < p->next->value) {
      ++count;
      while (p->value <= p->next->value) {
        p = p->next;
      }
    }
  }
  return count;
}
//////////////////////////////////

int main() {
  // Khai bao
  int number = 10;  // cho so vao day
  high_resolution_clock::time_point t1, t2;
  duration<double> time_span;
  List l;
  init_list(l);
  Array a;
  init_array(a);
  srand(time(NULL));
  for (int i = 0; i < number; i++) {
    int x = rand();
    Input_Array(a, x);
    Add_Tail(l, x);
  }
  // So sanh mang dong

  t1 = high_resolution_clock::now();

  t2 = high_resolution_clock::now();
  time_span = duration_cast<duration<double>>(t2 - t1);
  cout << "Dynamic Array " << time_span.count() << " seconds.\n";

  // so sanh danh sach lien ket
  t1 = high_resolution_clock::now();

  t2 = high_resolution_clock::now();
  time_span = duration_cast<duration<double>>(t2 - t1);
  cout << "Linked List " << time_span.count() << " seconds.\n";
  //

  return 0;
}

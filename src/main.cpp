#include  <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node {
  char letter;
  struct node *next;
  struct node *prev;
};

void traversal(node*, node*, char);

// Testing malloc/new syntax differences and uses
char alphabet[5];

int main() {
  int i = 0;
  int j = 0;
  int len = 26;
  char letter = 'a';
  char search;
  // malloc() taken from stdlib.h, typically C-style of allocating memory
  char *malloc_alphabet = (char*) malloc(sizeof(alphabet) * sizeof(char));
  // new is cC++ memory allocation technique
  char *new_alphabet = new char[sizeof(alphabet)];

  // can current and orevious be turned into standard int pointers?
  //struct node *current;
  //struct node *previous;
  node *head;
  node *current;
  node *previous;
  node *tmp; 

  struct node *list;
  //list->letter = letter;
  //list->next = NULL;
  //list->prev = NULL;
  //head = list;

  //current = list;
  //previous = list;

  //char conversion and increment
  int int_data = letter;
  cout << "Letter to be searched for: ";
  cin >> search;

  for(i = 1; i <= len; i++) {
    // set previous to point to current node for it to become the previous node
    struct node *new_node = new node;
    if (i == 1) { 
      list = new_node;
      head = list;
    }
    new_node->next = NULL;
    new_node->prev = NULL;
    current = list;
    if (i != 1) {
      // list is the first node of the list, no need to have two "first" nodes
      int_data += 1;
    } //end if
    new_node->letter = (char) int_data;
    previous = list;
    list->next = new_node;
    new_node->prev = list;
    list = list->next;
    current = list;
    cout << "Value of node #" << i << ": " << list->letter << endl;  
  }

  // debugging traversal
//  tmp = head;  
//  while (tmp != NULL) {
//    cout << tmp->letter << endl;
//    tmp = tmp->next;
//  }

  traversal(head, list, search);
  cout << "Size of malloc_alphabet: " << sizeof(malloc_alphabet) << endl;
  cout << "Size of new_alphabet: " << sizeof(malloc_alphabet) << endl;
  cout << "Address of malloc_alphabet: " << &malloc_alphabet << endl;
  cout << "Address of new_alphabet: " << &new_alphabet << endl; 
  return 0;
}

void traversal(node* head, node* tail, char search) {
  struct node* current = head;
  struct node* end = tail;
  int forward = 1;
  int reverse = 1;
  
  //testing out standard traversal, head->tail
  while (current != NULL) {
    //cout << "I found " << current->letter << " here!" << endl;
    if (current->letter == search){
      cout << "Forward search: " << search << " found at memory location " << &current 
        << " after " << forward << " jumps!" << endl;
      break;
    } else {
      forward += 1;
      current = current->next;
    }
  }

  while(end != NULL) {
    if (end->letter == search) {
      cout << "Reverse search: " << search << "found at " << &current << " after " << reverse << " jumps!" <<endl;
      break;
    } else {
      reverse += 1;
      end = end->prev;
    }
  }
}

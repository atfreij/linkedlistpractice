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

  struct node *list = new node;
  list->letter = letter;
  list->next = NULL;
  list->prev = NULL;
  head = list;

  current = list;
  previous = list;

  //char conversion and increment
  int int_data = letter;
  cout << "Letter to be searched for: ";
  cin >> search;

  for(i = 0; i < len; i++) {
    // set previous to point to current node for it to become the previous node
    struct node *new_node = new node;
    new_node->next = NULL;
    new_node->prev = NULL;
    current = new_node;
    if (i != 0) {
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
    //}
    //int_a += 1;
    //new_node->letter = (char) int_a;
    //new_node->next = NULL;
    //new_node->prev = NULL;
    //current = new_node;
    //current->prev 
  }
 // cout << "Hello world!\n";

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
  
  //testing out standard traversal, head->tail
  while (current->next != NULL) {
    cout << "I found " << current->letter << " here!" << endl;
    if (current->letter == search){
      cout << search << " found at memory location " << &(current->letter) << endl;
      break;
    } else {
      current = current->next;
    }
  }


  // test reverse traversal, tail->head, to see if prev fields have been filled in correctly
}

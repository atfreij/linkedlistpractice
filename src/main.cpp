#include  <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node {
  char letter;
  struct node *next;
  struct node *prev;
};

char alphabet[5];

int main() {
  int i = 0;
  int j = 0;
  char alphabet[5] = {'a','b','c','d','e'};
  // malloc() taken from stdlib.h, typically C-style of allocating memory
  char *malloc_alphabet = (char*) malloc(sizeof(alphabet) * sizeof(char));
  // new is cC++ memory allocation technique
  char *new_alphabet = new char[sizeof(alphabet)];

  struct node *current;
  struct node *previous;
  //int length = 26;

  struct node *start = new node;
  start->letter = alphabet[0];
  start->next = NULL;
  start->prev = NULL;

  current = start;
  previous = NULL;

  for(i=0; i < sizeof(alphabet); i++) {
    
  }
 // cout << "Hello world!\n";
  cout << "Size of malloc_alphabet: " << sizeof(*malloc_alphabet) << endl;
  cout << "Size of new_alphabet: " << sizeof(*malloc_alphabet) << endl; 
  return 0;
}

//main();

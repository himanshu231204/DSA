#include <bits/stdc++.h>
using namespace std;



// a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

class Solution {
    public:
      void deleteAllOccurOfX(struct Node** head_ref, int x) {
      Node* temp = *head_ref;
      while (temp != NULL) {
          if (temp->data == x) {
              if (temp == *head_ref) {
                  *head_ref = temp->next;
              }
              Node* nextNode = temp->next;
              Node* prevNode = temp->prev;
              if (nextNode) {
                  nextNode->prev = prevNode;
              }
              if (prevNode) {
                  prevNode->next = nextNode;
              }
              free(temp);
              temp = nextNode;
          } else {
              temp = temp->next;
          }
      }
  }
  };
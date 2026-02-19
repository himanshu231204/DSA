#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};


// Approach (using reverse LL)
class Solution

{
public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;

        while (curr)
        {
            Node *nextNode = curr->next; // save next
            curr->next = prev;           // reverse link
            prev = curr;                 // move prev
            curr = nextNode;             // move curr
        }
        return prev;
    }

    Node *addOne(Node *head)
    {

        head = reverse(head);

        Node *temp = head;
        int car = 1; // caary

        while (temp != NULL)
        {
            temp->data = temp->data + car;

            if (temp->data < 10)
            {
                car = 0;

                break;
            }

            else
            {
                temp->data = 0;
                car = 1;
            }
            temp = temp->next;
        }

        if (car == 1)
        {
            Node *newNode = new Node(1); // create a new node with value 1
            head = reverse(head);        // reverse the existing list
            newNode->next = head;        // attach reversed list to the new node
            return newNode;              // newNode becomes the new head
        }

        head = reverse(head);
        return head;
    }
};

// using recurssion


class Solution {
    public:
    
    int addhelper(Node* temp){
        
        if(temp==NULL){
            return 1;
        }
        
        int car=addhelper(temp->next);
        temp->data+=car;
        
        if(temp->data<10) return 0;
        temp->data=0;
        return 1;
        
    }
      Node* addOne(Node* head) {
         
       int car=addhelper(head);
       
       if(car==1){
           Node* newNode= new Node(1);
           newNode->next=head;
           head=newNode;
       }
       return head;
      }
  };
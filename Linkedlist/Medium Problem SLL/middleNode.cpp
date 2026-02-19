#include <iostream>
#include <bits/stdc++.h>
using namespace std;



class Node {
    public:
    int data; 
    Node* next; 
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Brute force

Node *findMiddle(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;

    }

    int mid=cnt/2+1;
    temp=head;

    while(temp!=NULL){
        mid=mid-1;
        if(mid==0) break;
        temp=temp->next;

    }
    return temp;
}

// Optimal solutions(Using two slow and fast pointer)
// slow=+1 step and fast=+2 step

Node *OptimalfindMiddle(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL ){
        slow=slow->next; // move 1 step
        fast=fast->next->next; // move 2 step
    }
    return slow;
}

int main() {
    // Creating a sample linked list: 
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Find the middle node
   // Node* middleNode = findMiddle(head);

    Node* middleNode = OptimalfindMiddle(head);


    // Display the value of the middle node
    cout << "The middle node value is: " << middleNode->data << endl;

    return 0;
}
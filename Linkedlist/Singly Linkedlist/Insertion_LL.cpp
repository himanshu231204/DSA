#include <bits/stdc++.h>
using namespace std;

class Node
{ // use class in place of struct
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

/// convert  Array to linkedlist

Node *convertArr2ll(vector<int> &arr)
{

    Node *head = new Node(arr[0]);

    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Print the linked list
void printLL(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}



// inesrtion at head of LL

Node* insertHead(Node*head,int val){

    Node* temp= new Node(val,head);
    return temp;
}

// insertion at tail/last of LL
Node* insertLast(Node*head,int val){

    if(head==NULL){
        return new Node(val);
    }

    Node* temp=head;
    while(temp->next!=nullptr){

       temp= temp->next;
     }

     Node* newNode= new Node(val);
     temp->next=newNode;
    return head;
}


Node* insertatK(Node* head,int el,int k){

    if(head==NULL){
        if(k==1) return new Node(el);
        else return NULL;
    }
    // if k==1 insert before head
    if(k==1){
        Node*temp= new Node(el,head);
        return temp;
    }

    int cnt=0;
    Node*temp= head;
    while(temp!=NULL){
        cnt++;

        if(cnt==k-1){
            Node* x= new Node(el);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}


Node* insert_el_befor_val(Node* head,int el,int val){

    if(head==NULL){
       return NULL;
    }

    if(head->data==val){
        return new Node(el,head);
        
    }

    Node*temp= head;
    while(temp->next!=NULL){
      
        if(temp->next->data == val){
            Node* x= new Node(el,temp->next);
            
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main()
{

    vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArr2ll(arr);


    head=insert_el_befor_val(head,100,8);
    printLL(head);
    return 0;
}
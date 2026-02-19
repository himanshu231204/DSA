#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node* convertArr2Dll(vector<int> &arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << "  ";
        head = head->next;
    }
}
//---------------------------------------------------------------------------------------

// insert new node befor head

Node* insertbeforhead(Node* head,int val){

    Node* newhead= new Node(val,head,nullptr);
    head->back=newhead;
    return newhead;
}

//--------------------------------------------------

// insert new node befor tail

Node* insertBeforeTail(Node*head,int val){
    if (head->next==NULL){ // single elements
       return insertbeforhead(head,val);
    }
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;

    }
    Node* prev=tail->back;

    Node* newNode= new Node(val,tail,prev);

    prev->next=newNode;
    tail->back=newNode;
    newNode->back=prev;
    newNode->next=tail;
    return head;


}

// insert befor kth elements

Node* insertBeforeKthElm(Node*head,int k,int val){

    if(k==1) {
        return insertbeforhead(head,val);
}

Node*temp=head;
int cnt=0;
while(temp!=NULL){
    cnt++;
    if(cnt==k) break;
    temp=temp->next;

}

Node* prev=temp->back;

Node* newNode= new Node(val,temp,prev);

prev->next=newNode;
temp->back=newNode;

newNode->back=prev;
newNode->next=temp;
return head;
}

// insert before a given node

void insertBeforeGivenNode(Node* node,int val ){

    Node* prev= node->back;
    Node* newNode= new Node(val,node,prev);

    prev-> next=newNode;
    node->back=newNode;

}
//---------------------------------------
int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2Dll(arr);
   // head=insertbeforhead(head,100);
  // head=insertBeforeTail(head,200);
  // head=insertBeforeKthElm(head,3,200);
  insertBeforeGivenNode(head->next,300);
    print(head);
    return 0;
}
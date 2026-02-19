#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;    // data store in node
    Node* next;   // pointer to the next node (forward directions)
    Node* back;  // pointer to the previous/back node(backward directions)

    // Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
    Node(int data1, Node*next1,Node*back1){
        data=data1;
        next=next1; // Similar to a singly linked list, but now with a 'back' pointer.
        back=back1; // Addition of 'back' pointer for the doubly linked list.
    }

    
// Constructor for a Node with data, and no references to the next and previous nodes (end of the list)
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }

};


// convert array to DLL

Node*  convertArr2Dll(vector<int> &arr){
    if (arr.empty()) return nullptr;

    Node* head= new Node(arr[0]);
    Node* prev= head;

    for(int i=1; i<arr.size();i++){

        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp; // move the prev
    }
    return head;


}

// print the Dll

void print(Node*head) {
    while(head!=NULL){

        cout<<head->data<<"  ";
        head=head->next;

    }

}


//-----------------------------------
int main(){

    vector<int> arr={12,5,8,7};
    Node* head=convertArr2Dll(arr);
    print(head);

    return 0;
}
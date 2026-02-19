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

// reversi the linklist 

// eXtream brute force ( using stack ds (LIFO))

Node* reverse(Node*head){

    if(head==NULL || head->next == NULL){
        return head;
    }
    Node* temp=head;
    
    stack<int> st;

    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;

    }
     temp=head;
    while(temp!= NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}


// Optimal solutions( reversing the link in single traversal)

Node* reverseOptimal(Node*head){
    if(head==NULL || head->next == NULL){
        return head;
    }

    Node* Last=nullptr;
    Node* current=head;

    while(current!=NULL){

        Last=current->back;
        current->back=current->next;

        current->next=Last;

        current=current->back;
    }
    return Last->back; // new head

}



int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2Dll(arr);
    cout << endl << "Doubly Linked List Initially:  " << endl;
    print(head);
    cout << endl << "Doubly Linked List After Reversing " << endl;
    
     // Insert a node with value 10 at the end
   // head = reverse(head);
   head=reverseOptimal(head);
    print(head);
}
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
//--------------------------------------------------------------------------------------------------------------

// Deletion Of "HEAD" in Dll

Node* deleteHead(Node* head){

    // edge case: DLL is empty or having 1 element

    if(head==NULL || head->next==NULL) {
        return NULL;
    }

    Node*prev=head;
    head=head->next; // move head
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;
}

//------------------------------------------------------

// Deletion Of "Tail" in Dll


Node* deleteTail(Node* head){

    // edge case: DLL is empty or having 1 element

    if(head==NULL || head->next==NULL) {
        return NULL;
    }

    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;

    }

    Node* prev=tail->back;
    tail->back=nullptr;
    prev->next=nullptr;
    delete tail;
    return head;
}

//-------------------------------------------------------------

// Delete the kth elements of the DLL

 Node* deleteKthElm(Node* head,int k){

    if(head==NULL){
        return NULL;
    }

    int cnt=0;

    Node* kNode=head;

    while(kNode!=NULL){

        cnt++;
        if(cnt==k) break;
        kNode=kNode->next;

    }

    Node* prev=kNode->back;
    Node* front=kNode->next;
    // k=1 or single element
    if(prev==NULL && front==NULL){
        delete kNode;
        return NULL;
    }
    else if(prev==NULL){ // head
       return deleteHead(head);
        
    }
    else if(front==NULL){ //its tail
       return deleteTail(head);
    }
// breaking the link of kNode to remove it
    prev->next=front;
    front->back=prev;

    kNode->next=nullptr;
    kNode->back=nullptr;
    delete kNode;
    return head;

 }


 // deleting the given node in dll

void deleteNode(Node* temp){

    Node* prev=temp->back;
    Node* front=temp->next;

    if(front==NULL){
        prev->next=nullptr;
        temp->back=nullptr;
        delete temp;
        return;

    }
    temp->next=temp->back=nullptr;
    prev->next=front;
    front->back=prev;
    delete temp;
}









//-----------------------------------------------------------------
int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2Dll(arr);

   // head=deleteHead(head);
  // head=deleteTail(head);
 head=deleteKthElm(head,2);
 deleteNode(head->next);
   print(head);
 
    return 0;
}

#include <bits/stdc++.h>
using namespace std;



class Node{ // use class in place of struct
     public:
    int data;
    Node*next;

    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }



};
/// convert  Array to linkedlist

Node* convertArr2ll(vector<int> &arr){

    Node* head= new Node(arr[0]);

    Node* mover= head;

    for(int i=1; i<arr.size();i++){
        Node* temp=new Node(arr[i]) ;
         mover->next=temp;
         mover=temp;

    }
    return head;
}

// Print the linked list
void printLL(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}


// removing the head

Node* removeHead(Node* head){

    if( head== nullptr) return head;/// if linkedlist is empty


    Node*temp= head;
    head=temp->next;
    free(temp);
    return head;
}

// deleting the last elements /tails

Node* deleteTail(Node* head){

    if(head==nullptr || head->next==nullptr) return nullptr;

    Node* temp= head;

    while( temp->next->next!= nullptr){
        // move temp
        temp= temp->next;
    }
    delete temp->next;// last element deleted

    // now temp->next will null
    temp->next=nullptr;

    return head;
}


// deleting the kth elements

Node* deleteK(Node* head,int k){

    if(head==NULL) return head;

    if(k==1){
        Node*temp=head;
        head=head->next;
        delete temp;
        return head;

    }

    int cnt=0; 
    Node*temp=head;
    Node*prev=NULL;

    while(temp!=NULL){
        cnt++;

        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            break;

        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}


// deleting the value/element in linklist


Node* deleteValue(Node* head,int el){

    if(head==NULL) return head;

    if(head->data==el){
        Node*temp=head;
        head=head->next;
        delete temp;
        return head;

    }

    
    Node*temp=head;
    Node*prev=NULL;

    while(temp!=NULL){
       

        if(temp->data==el){
            prev->next=prev->next->next;
            delete temp;
            break;

        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}


int main(){

    vector<int> arr={12,5,8,7};
    Node* head=convertArr2ll(arr);

   // head= removeHead(head);

  head= deleteValue(head,5);
    printLL(head);

    
  

    return 0;

}
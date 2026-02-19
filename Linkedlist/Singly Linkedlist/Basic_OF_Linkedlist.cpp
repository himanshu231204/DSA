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


// lenght of ll

int lengthofll(Node* head){
    int cnt=0;
    Node* temp=head;
while(temp!=nullptr){
 // cout<<  temp->data<<" ";
  temp=temp->next;
  cnt++;

}
return cnt;

}



// search in linkedlist

int searchLL(Node* head, int target){

    Node* temp=head;
    while(temp!=nullptr){
      if(temp->data == target) return 1; // target found

      temp=temp->next;
}
return 0; // if target not found
}



int main(){

vector<int> arr={2,5,8,7};

//Node* y=new Node(arr[0],nullptr); 
//cout << y->data;

Node* head=convertArr2ll(arr);
//cout<< head->data;
 //cout<<endl;
// travesing the ll

/* traversal of ll
Node* temp=head;
while(temp!=nullptr){
  cout<<  temp->data<<" ";
  temp=temp->next;

}
cout<<endl;
*/
//cout<< " Length Of LL: "<< lengthofll(head) <<endl;

cout << searchLL(head,7);
return 0;
}
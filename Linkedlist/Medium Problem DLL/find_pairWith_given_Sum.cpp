#include <bits/stdc++.h>
using namespace std;



class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// Brute Force (this will give TLE)
class Solution {
    public:
      vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
          
          
          Node* temp1=head;
          
          vector<pair<int,int>>arr;
          
          while(temp1!=NULL){
              
              Node* temp2=temp1->next;
          
          
          while(temp2!=NULL && temp1->data+temp2->data <= target){
              
              if(temp1->data+temp2->data == target){
                  
                  arr.push_back({temp1->data,temp2->data});
                  
              }
              temp2=temp2->next;
              
          }
       
          temp1=temp1->next;
          }
          return arr;
      }
  };


  // Optimal solutions(using two pointer approach)

  class Solution {
    public:
    
    Node* findtail(Node* head){
        
        Node * tail=head;
        while(tail->next!=NULL) tail=tail->next;
        return tail;
    }
      vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
          
          vector<pair<int, int>>arr;
          
          Node* left= head;
          Node* right=findtail(head);
          
          
          while(left->data < right->data){
              
              if(left->data + right->data == target){
                  
                  arr.push_back({left->data,right->data});
                  left=left->next;
                  right=right->prev;
              }
              
              else if(left->data + right->data < target){
                  left=left->next;
              }
              else  right=right->prev;
                  
              
          }
          return arr;
      }
  };
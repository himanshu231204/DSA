
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute Force(Using hash table)
        ListNode *detectCycle(ListNode *head) {
            
            ListNode* temp=head;
            unordered_map<ListNode*,int>mpp;
    
            while(temp!=nullptr){
                if(mpp.count(temp)!=0){
                    return temp;
                }
    
                mpp[temp]=1;
                temp=temp->next;
    
            }
            return nullptr;
    
        }
    


// // Optimal solutions (Tortoise and Hare approach)

ListNode *startNode(ListNode *head) {

    ListNode* slow=head;
     ListNode* fast=head;

     while(fast!=NULL && fast->next!=NULL){

        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            // finding starting node;
             ListNode* slow=head;

             while(slow!=fast){
                slow=slow->next;
                fast=fast->next;

             }
             return slow;
        }
     }

     return NULL;

    
}
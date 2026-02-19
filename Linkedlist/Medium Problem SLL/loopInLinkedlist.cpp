#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute Force (using hash table)

//TC= O(N * 2 * log(N) )
//SC=O(N)

bool detectLoop(ListNode*head){

    ListNode*temp=head;

    unordered_map<ListNode*,int> mpp;

    while(temp!=nullptr){

        if(mpp.find(temp)!= mpp.end()){ // If the node is already in the
                                        // map, there is a loop
            return true;
        }
        mpp[temp]=1;
        temp=temp->next;
    }
     return false;
}


// Optimal solutions (Tortoise and Hare approach)

//TC=O(N) , SC=O(N)

bool hasCycle(ListNode *head) {

    ListNode *slow=head;
    ListNode *fast=head;

    while(fast!=NULL &&  fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        // loop found
        if(slow==fast) return true;

    }
    return false;
}
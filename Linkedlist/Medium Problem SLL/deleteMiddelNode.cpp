#include <bits/stdc++.h>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 // Optimal solutions
class Solution {
    public:
        ListNode* deleteMiddle(ListNode* head) {
    
            // edge case: if 0 or 1 node, return NULL
            if (head == NULL || head->next == NULL)
                return NULL;
    
            ListNode* slow = head;
            ListNode* fast = head;
    
            // Move fast two steps ahead initially
            fast = fast->next->next;
    
            // Move slow by 1 and fast by 2 until fast reaches end
            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }
    
            // Delete the middle node
            ListNode* mid = slow->next;
            slow->next = slow->next->next;
            delete mid;
    
            return head;
        }
    };
    

//  brute force 
ListNode *deleteMiddle(ListNode *head) {
    // Initialize a temporary node
    // to traverse the linked list
    ListNode* temp = head;
    
    // Variable to hold the number
    // of nodes in the linked list
    int n = 0;
    
    // Loop to count the number of
    // nodes in the linked list
    while(temp!=NULL){
        n++;
        temp = temp->next;
    }
    
    // Calculate the index of the middle node
    int res = n/2;
    
    // Reset the temporary node to
    // the beginning of the linked list
    temp = head;
    
    // Loop to find the
    // middle node to delete
    while(temp!=NULL){
        
        res --;
        
        // If the middle node is found
        if(res==0){
            
            // Create a pointer
            // to the middle node
            ListNode* middle = temp->next;
            
            // Adjust pointers to
            // skip the middle node
            temp->next = temp->next->next;
            
            // Free the memory allocated
            // to the middle node
            free(middle);
            
            // Exit the loop after
            // deleting the middle node
            break;
        }
        // Move to the next node
        // in the linked list
        temp = temp->next;
    }
    // Return the head of the
    // modified linked list
    return head;
}
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

  // brute force(using array)
  class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            ListNode* temp= head;
    
            vector<int>arr;
    
            while(temp!=NULL){
                arr.push_back(temp->val);
                temp=temp->next;
    
            }
    
            sort(arr.begin(),arr.end());
    
            int i=0;
            temp=head;
    
            while(temp!=NULL){
                temp->val=arr[i];
                i++;
                temp=temp->next;
            }
            return head;
            
        }
    };


    // optimal(using merge sort)

    class Solution {
        public:
            ListNode* findMiddle(ListNode* head) {
                if (head == NULL || head->next == NULL) {
                    return head;
                }
        
                ListNode* slow = head;
                ListNode* fast = head->next;
        
                while (fast != NULL && fast->next != NULL) {
                    slow = slow->next;       // move 1 step
                    fast = fast->next->next; // move 2 step
                }
                return slow;
            }
        
            ListNode* MergeTwoList(ListNode* list1, ListNode* list2) {
        
                ListNode* dummyNode = new ListNode(-1);
                ListNode* temp = dummyNode;
                // Traverse both lists simultaneously
                while (list1 != nullptr && list2 != nullptr) {
                    // Compare elements of both lists and
                    // link the smaller node to the merged list
                    if (list1->val <= list2->val) {
                        temp->next = list1;
                        list1 = list1->next;
                    } else {
                        temp->next = list2;
                        list2 = list2->next;
                    }
                    // Move the temporary pointer
                    // to the next node
                    temp = temp->next;
                }
        
                // If any list still has remaining
                // elements, append them to the merged list
                if (list1 != nullptr) {
                    temp->next = list1;
                } else {
                    temp->next = list2;
                }
                // Return the merged list starting
                // from the next of the dummy node
                return dummyNode->next;
            }
        
            ListNode* sortList(ListNode* head) {
        
                if (head == NULL || head->next == NULL)
                    return head;
        
                ListNode* mid = findMiddle(head);
        
                ListNode* right = mid->next;
                mid->next = nullptr;
                ListNode* left = head;
        
                // Recursively sort the left and right halves
                left = sortList(left);
                right = sortList(right);
        
                return MergeTwoList(left, right);
            }
        };
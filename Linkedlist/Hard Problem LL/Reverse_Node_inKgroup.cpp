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
 
class Solution {
public:

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next; 
            curr->next = prev;               
            prev = curr;                     
            curr = nextNode;                 
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1; 
        while (temp != NULL && k > 0) {
            k--; 
            temp = temp->next; 
        }
        return temp; 
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while (temp != NULL) {
            ListNode* kthNode = getKthNode(temp, k);

            if (kthNode == NULL) {
                if (prevNode) {
                    prevNode->next = temp; 
                }
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            ListNode* reversedHead = reverse(temp);

            if (temp == head) {
                head = reversedHead;
            } else {
                prevNode->next = reversedHead;
            }

            prevNode = temp;   // old head becomes tail
            temp = nextNode;   // move to next group
        }

        return head;
    }
};

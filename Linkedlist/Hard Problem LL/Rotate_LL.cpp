#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  class Solution {
public:
    ListNode* findlastNode(ListNode* temp, int k) {
        int cnt = 1;
        while (temp != NULL) {
            if (cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) return head;  // ✅ fix

        // Step 1: Find length and tail
        int len = 1;
        ListNode* tail = head;
        while (tail->next != NULL) {
            len++;
            tail = tail->next;
        }

        // Step 2: Adjust k
        k = k % len;
        if (k == 0) return head;  // No rotation needed

        // Step 3: Make list circular
        tail->next = head;

        // Step 4: Find new tail
        ListNode* newLastNode = findlastNode(head, len - k);

        // Step 5: Break circle and return new head
        head = newLastNode->next;
        newLastNode->next = NULL;

        return head;
    }
};

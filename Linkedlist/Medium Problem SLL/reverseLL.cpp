#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// =============================================
// 1️⃣ Brute Force Approach (Using Stack)
// =============================================
ListNode* reverseWithStack(ListNode* head) {
    if (!head || !head->next) return head;

    stack<ListNode*> st;
    ListNode* curr = head;

    while (curr) {
        st.push(curr);
        curr = curr->next;
    }

    ListNode* newHead = st.top();
    st.pop();
    ListNode* tail = newHead;

    while (!st.empty()) {
        tail->next = st.top();
        st.pop();
        tail = tail->next;
    }
    tail->next = NULL;
    return newHead;
}

// =============================================
// 2️⃣ Optimal Iterative Approach (Pointer Swapping)
// Analogy: swap(a, b) but here swap(curr->next, prev)
// =============================================
ListNode* reverseIterative(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr) {
        ListNode* nextNode = curr->next; // save next
        curr->next = prev;               // reverse link
        prev = curr;                     // move prev
        curr = nextNode;                  // move curr
    }
    return prev;
}

// =============================================
// 3️⃣ Recursive Approach
// =============================================
ListNode* reverseRecursive(ListNode* head) {
    if (!head || !head->next) return head; // base case

    ListNode* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

// =============================================
// Helper function to print linked list
// =============================================
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// =============================================
// Main Function
// =============================================
int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original List: ";
    printList(head);

    // Call Brute Force
    head = reverseWithStack(head);
    cout << "Reversed with Stack: ";
    printList(head);

    // Reverse back using Iterative
    head = reverseIterative(head);
    cout << "Reversed Iteratively: ";
    printList(head);

    // Reverse back using Recursive
    head = reverseRecursive(head);
    cout << "Reversed Recursively: ";
    printList(head);

    return 0;
}

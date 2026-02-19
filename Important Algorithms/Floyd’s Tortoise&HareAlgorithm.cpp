/*
===============================================
🔄 Floyd’s Tortoise & Hare Algorithm Revision
===============================================
✅ Purpose:
 - Detect if a linked list has a cycle.
 - If cycle exists, find the starting node of the loop.

✅ Intuition:
 - Two pointers move at different speeds (slow=1 step, fast=2 steps).
 - If there’s a loop, they must meet inside the cycle.
 - To find the loop start: reset one pointer to head, move both 1 step at a time; where they meet is the start of the loop.

===============================================
✅ Typical Problems where it’s used:
 - 🌀 Detect cycle in linked list (LeetCode 141)
 - 🎯 Find starting node of cycle in linked list (LeetCode 142)
 - 🔍 Find middle of linked list (by stopping before checking cycle)
 - 🔄 Detect repetition/cycle in pseudo-random number sequences
 - 🛑 Detect infinite loops in algorithms relying on repeated states
 - 🌐 Detect cycles in state transitions in games or automata

===============================================
📝 Pseudocode for Finding Start of Loop:
===============================================
function detectCycle(head):
    slow = head
    fast = head
    
    // Phase 1: Check if cycle exists
    while fast != NULL and fast.next != NULL:
        slow = slow.next
        fast = fast.next.next
        
        if slow == fast:
            // Cycle detected
            break
    
    if fast == NULL or fast.next == NULL:
        return NULL // No cycle
    
    // Phase 2: Find start of cycle
    slow = head
    while slow != fast:
        slow = slow.next
        fast = fast.next
    
    return slow // Start of cycle node

===============================================
💡 Key Insight:
When slow and fast meet inside the loop, the distance from head to loop start
is the same as the distance from meeting point to loop start inside the cycle.
This is why resetting one pointer to head and moving both one step each
finds the exact loop start.
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int data) {
        val = data;
        next = NULL;
    }
};

// Function to detect the starting node of the cycle
ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Phase 1: Detect if cycle exists
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle found
            break;
        }
    }

    // If no cycle
    if (fast == NULL || fast->next == NULL)
        return NULL;

    // Phase 2: Find the start of the cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // Starting node of cycle
}

// Utility function to print linked list (for debugging purpose)
void printList(ListNode* head, ListNode* loopNode) {
    ListNode* temp = head;
    int count = 0;
    while (temp != NULL && count < 15) {  // Print limit for cyclic list
        cout << temp->val << " -> ";
        if (temp == loopNode) count++; // Avoid infinite loop in print
        temp = temp->next;
    }
    cout << "...\n";
}

int main() {
    // Creating a sample linked list with loop:
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6
    //           ↑         ↓
    //           ← ← ← ← ←
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    // Creating a loop: node 6 -> node 3
    head->next->next->next->next->next->next = head->next->next;

    ListNode* loopStart = detectCycle(head);
    if (loopStart) {
        cout << "🔁 Cycle detected! Starting at node with value: " << loopStart->val << endl;
    } else {
        cout << "✅ No cycle detected.\n";
    }

    // Optional: Uncomment to see partial list print
    // printList(head, loopStart);

    return 0;
}

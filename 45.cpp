#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        // Traverse the list
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                // Skip duplicate node
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from vector
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Main function
int main() {
    // Input
    vector<int> arr = {1, 1, 2, 3, 3};
    
    // Create linked list
    ListNode* head = createList(arr);

    // Solve
    Solution sol;
    head = sol.deleteDuplicates(head);

    // Output
    cout << "After removing duplicates: ";
    printList(head);

    return 0;
}

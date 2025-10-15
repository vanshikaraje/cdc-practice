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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

// Helper to create linked list from vector
ListNode* createList(vector<int> arr) {
    if(arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for(int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper to print linked list
void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    vector<int> v = {4,5,1,9};
    ListNode* head = createList(v);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    // Suppose we want to delete node with value 5 (second node)
    ListNode* nodeToDelete = head->next;
    sol.deleteNode(nodeToDelete);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            int sum = val1 + val2 + carry;

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;

            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }

        return dummyHead->next;
    }
};

// Helper to create linked list from vector
ListNode* createList(vector<int> arr) {
    if(arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for(int i=1; i<arr.size(); i++) {
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
    vector<int> v1 = {2,4,3}; // represents 342
    vector<int> v2 = {5,6,4}; // represents 465

    ListNode* l1 = createList(v1);
    ListNode* l2 = createList(v2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Sum List: ";
    printList(result); // Output should be 7->0->8 representing 807

    return 0;
}

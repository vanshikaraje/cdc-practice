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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp != nullptr) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
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
    vector<int> v = {1,2,3,4,5}; // Example list
    ListNode* head = createList(v);

    Solution sol;
    ListNode* reversed = sol.reverseList(head);

    cout << "Reversed List: ";
    printList(reversed);

    return 0;
}

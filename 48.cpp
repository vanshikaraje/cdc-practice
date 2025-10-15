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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node to simplify merging
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        // Append remaining nodes
        if(list1 != nullptr) curr->next = list1;
        if(list2 != nullptr) curr->next = list2;

        return dummy->next;
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
    vector<int> v1 = {1,2,4};
    vector<int> v2 = {1,3,4};

    ListNode* l1 = createList(v1);
    ListNode* l2 = createList(v2);

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(l1, l2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}

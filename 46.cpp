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
    // Helper to find the k-th node
    ListNode* findNthNode(ListNode* temp, int k){
        int cnt = 1;
        while(temp != NULL){
            if(cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;

        // Find length and tail
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }

        // If rotation is multiple of len, return same head
        if(k % len == 0) return head;

        k = k % len;

        // Make list circular
        tail->next = head;

        // Find new last node (len - k th node)
        ListNode* newLastNode = findNthNode(head, len - k);

        // New head is next of new last node
        head = newLastNode->next;
        newLastNode->next = NULL;

        return head;
    }
};

// Helper to create linked list from vector
ListNode* createList(vector<int> arr) {
    if(arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for(int i=1; i<arr.size(); i++){
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper to print linked list
void printList(ListNode* head) {
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 2;

    ListNode* head = createList(arr);

    Solution sol;
    head = sol.rotateRight(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}

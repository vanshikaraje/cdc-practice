#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Solution class
class Solution {
public:
    int getCount(Node* head) {
        int count = 0;
        Node* temp = head;
        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

// Helper to create linked list from vector
Node* createList(vector<int> arr) {
    if(arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for(int i=1; i<arr.size(); i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Main function
int main() {
    vector<int> v = {1,2,3,4,5}; // Example list
    Node* head = createList(v);

    Solution sol;
    int length = sol.getCount(head);

    cout << "Length of linked list: " << length << endl; // Output: 5

    return 0;
}

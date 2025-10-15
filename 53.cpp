#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// MyLinkedList class
class MyLinkedList {
private:
    ListNode* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        ListNode* curr = head;
        for(int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if(!head) {
            head = newNode;
        } else {
            ListNode* curr = head;
            while(curr->next) curr = curr->next;
            curr->next = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;
        if(index == 0) return addAtHead(val);
        if(index == size) return addAtTail(val);

        ListNode* newNode = new ListNode(val);
        ListNode* curr = head;
        for(int i = 0; i < index-1; i++) curr = curr->next;
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        if(index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        } else {
            ListNode* curr = head;
            for(int i = 0; i < index-1; i++) curr = curr->next;
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        size--;
    }
};

// Helper to print list (for VS Code testing)
void printList(MyLinkedList& list, int n) {
    for(int i=0; i<n; i++) {
        cout << list.get(i) << " ";
    }
    cout << endl;
}

// Main function for testing in VS Code
int main() {
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1,2); // List: 1->2->3
    printList(myLinkedList, 3);

    cout << myLinkedList.get(1) << endl; // Output: 2
    myLinkedList.deleteAtIndex(1);       // List: 1->3
    printList(myLinkedList, 2);
    cout << myLinkedList.get(1) << endl; // Output: 3

    return 0;
}

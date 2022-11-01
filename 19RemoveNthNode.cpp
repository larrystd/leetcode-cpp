#include <bits/stdc++.h>
/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* prev = dummy;
        ListNode* current = head;
        ListNode* base = current;
        for (int i = 1; i < n; i++) {
            base = base->next;
        }        
        while(base != nullptr) {
            base = base->next;
            prev = prev->next;
            current = current->next;
        }
        prev->next = current->next;
        delete current;
        head = dummy->next;
        delete dummy;
        return head;
    }
};
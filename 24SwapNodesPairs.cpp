#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* dumpy = new ListNode(-1, head);
        ListNode* prev = dumpy;
        ListNode* p = head, *q = head->next;
        while (p && q) {
            ListNode* temp = q->next;
            prev->next = q;
            q->next = p;
            p->next =temp;
            prev = p;
            p = temp;
            if (p == nullptr) {
                break;
            }
            q = p->next;
        }
        head = dumpy->next;
        delete dumpy;
        return head;
    }
};
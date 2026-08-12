/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        int stepsToMove = length - n;
        for (int i = 0; i < stepsToMove; i++) {
            cur = cur->next;
        }
        
        if (cur->next != nullptr) {
            cur->next = cur->next->next;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
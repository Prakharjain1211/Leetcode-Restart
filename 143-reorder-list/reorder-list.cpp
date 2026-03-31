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
    void reorderList(ListNode* head) {
        ListNode* slowptr=head;
        ListNode* fastptr=head;
        while(fastptr->next && fastptr->next->next)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        } 

        ListNode* prev = NULL;
        ListNode* curr = slowptr->next;
        slowptr->next = NULL;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode* first = head;
        ListNode* second = prev;

         while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
        
    }
};
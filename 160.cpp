/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp = headA;
        ListNode *temp2 = headB;

        int m = 0, n = 0;

        while(temp != nullptr) { temp = temp->next; ++m; }
        while(temp2 != nullptr) { temp2 = temp2->next; ++n; }
        temp = headA; temp2 = headB;

        int proceed = m > n ? m - n : n - m;

        if ( m < n ) {
            while ( proceed != 0 && temp2 != nullptr ) {
                temp2 = temp2->next;
                --proceed;
            }
        } else {
            while ( proceed != 0 && temp != nullptr ) {
                temp = temp->next;
                --proceed;
            }
        }

        while (temp != nullptr && temp2 != nullptr && temp != temp2) {
            temp = temp->next;
            temp2 = temp2->next;
        }

        return temp;
    }
};
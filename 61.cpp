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
    ListNode* rotateRight(ListNode* head, int k) {
        if ( head == nullptr || k == 0 || head->next == nullptr ) return head;
        ListNode* oldHead = head;
        ListNode* temp = head;
        int size = 0;
        while (temp != nullptr) {
            temp = temp->next;
            ++size;
        }
        //--size;
        //cout << "size = " << size;
        if ( k >= size ) {
            k = k % size;
            if ( k == 0 ) return head;
        }
        int newHeadPosition = size - k; // se aglay wala
        temp = head;
        int p = 1;
        while ( p < newHeadPosition ) {
            temp = temp->next;
            ++p;
        }
        head = temp->next;
        temp->next = nullptr;
        temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = oldHead;

        return head;
    }
};
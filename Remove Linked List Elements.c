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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ptr=head;
        ListNode* prev=NULL;
        while(ptr != NULL){
            if(ptr->val == val) {
                if(prev == NULL){ //its head pointer
                    head=head->next;
                    ptr=head;
                }
                else{
                    prev->next=ptr->next;
                    ptr=ptr->next;
                }
            }
            else{
                prev=ptr;
                ptr=ptr->next;
            }
        }
        return head;
    }
};

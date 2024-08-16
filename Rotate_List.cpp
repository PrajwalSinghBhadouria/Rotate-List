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
        if(head==NULL || head->next == NULL){
            return head;
        }
        int count=0;
        ListNode *temp1 = head;
        while(temp1!=NULL){
            count++;
            temp1= temp1->next;
        }
        
        
        for(int i=0; i<k%count; i++){
        ListNode *temp=head;
        ListNode *pre = NULL;
        while(temp->next != NULL){
            pre = temp;
            temp = temp->next;
        }
        ListNode *newnode = new ListNode(temp->val);
        pre->next = NULL;
        newnode->next = head;
        head = newnode;
        }
        return head;
    }
};

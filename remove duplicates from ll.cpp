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
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode *temp=head;
//         if(temp==NULL)
//             return NULL;
//         while(temp && temp->next!=NULL){
//             int value=temp->val;
//             while(temp && temp->next && temp->val==temp->next->val){
//                 ListNode *del=temp->next;
//                 temp->next=del->next;
               
//                 delete del;
//             }
//              if(temp)
//                 temp=temp->next;
            
//         }
//         return head;
//     }
// };
/////////////////////////////
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        
        ListNode *prev=NULL;
        ListNode *hd=head;
        while(head){
            if(prev && head->val==prev->val){
                ListNode *tmp=head->next;
                prev->next=tmp;
                delete head;
                head=tmp;
                continue;
            }
            prev=head;
            head=head->next;
        }
        return hd;
    }
};
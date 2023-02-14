/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void printlst(Node *head){
        while(head){
            cout<<(head->val)<<" | ";
            head=head->next;
        }
        cout<<endl;
    }    
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node *temp=head;
        while(temp){
            Node *copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=copy->next;
        }
        ////////////
        //printlst(head);
        //assign random pointers
        temp=head;
        while(temp && temp->next){
            temp->next->random=temp->random ? temp->random->next : NULL;
            temp=temp->next->next;
        }
        //take out copy and restore original list
        temp=head;
        Node *copylst=NULL;
        Node *cur=NULL;
        while(temp){
            if(!copylst){
                copylst=temp->next;
                cur=copylst;
            }
            else{
                cur->next=temp->next;
                cur=cur->next;  
            }
            temp->next=cur->next;
            temp=temp->next;
        }
        return copylst;
    }
};
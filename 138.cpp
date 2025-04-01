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
    public:
         Node*randomlist( Node*head){
            if(head==0) return 0;
             Node*it =head;
             while(it){
              Node*newnode= new Node(it->val);
              newnode->next=it->next;
              it->next=newnode;
              it=it->next->next;
              }
              it=head;
              while(it){
                it->next->random=it->random?it->random->next:0;
                it=it->next->next;
                ;}
              
              it=head;
               Node*newhead=it->next;
               while(it){
                 Node*newnode=it->next;
                 it->next=it->next->next;
                 if(newnode->next){
                    newnode->next=newnode->next->next;
                 }
                 it=it->next;
               }
               return newhead;
         }
        Node* copyRandomList(Node* head) {
           return randomlist(head);
    
            
        }
    };
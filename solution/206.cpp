//Use iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        while(head!=NULL){
            ListNode* next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
};
//Recursive
class Solution {
public:
    ListNode* reverse(ListNode* next,ListNode* head){
        ListNode* p;
        ListNode* prev;
        if(head!=NULL){
            p=head->next;
            prev=head;
            head->next=next;    
        }
        else return next;
        return reverse(prev,p);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(NULL,head);
    }
};
//Other people recursive solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
             return head;
        }
        auto ans = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
       	return ans;
    }
};
//Use stack
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return head;
        stack<int>pos;
        ListNode* p=head;   
        while(p!=NULL){
            pos.push(p->val);
            p=p->next;
        }
        p=head;
        while(p!=NULL){
            p->val=pos.top();
            pos.pop();
            p=p->next;
        }
        return head;
    }
};
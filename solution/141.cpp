//Use Two Pointers
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)return false;
        ListNode *fast=head;;
        ListNode *slow=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)return true;
        }
        return false;
    }
};
//Use Hash Table
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *,int>count;
        while(head!=NULL){
            if(++count[head]==2)return true;
            head=head->next;
        }
        return false;
    }
};
//Use Set
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *>count;
        while(head!=NULL){
            if(count.count(head)==1)return true;
            else count.insert(head);
            head=head->next;
        }
        return false;
    }
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=1;i<=n;++i)fast=fast->next;
        if(!fast)return head->next;
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }    
        slow->next=slow->next->next;
        return head;
    }
};
//Use single traverse to record all the element,then find the nth node fron the end to delete.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {    
        vector<ListNode*>pos;
        ListNode* h=head;
        while(h){
            pos.push_back(h);
            h=h->next;
        }
        pos.erase(pos.begin()+(pos.size()-1-(n-1)));
        if(pos.size()>0){
            int i;
            for(i=0;i<pos.size()-1;i++){
                pos[i]->next=pos[i+1];
            }
            pos[i]->next=NULL;
            return pos[0];
        }   
        else return NULL;
    }
};
//first version
 class Solution {
    public:
        ListNode* reverse(ListNode* head) {
            if(!head || !(head->next))return head;
            auto ans = reverse(head -> next);
            head -> next -> next = head;
            head -> next =NULL;
            return ans;
        }
        void reorderList(ListNode* head) {
            ListNode *slow = head, *fast = head, *ans = head;
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode *mid = slow->next;
            slow->next = NULL;
            ListNode *reverse_mid = reverse(mid);
            while(head && reverse_mid){
                ListNode *temp = head->next;
                head->next = reverse_mid;
                reverse_mid = reverse_mid->next;
                head->next->next = temp;
                head = temp;
            }
     
        }
    };
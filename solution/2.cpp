class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dump = new ListNode();
            ListNode* res = dump;
            int carry = 0;
            while(l1 || l2){
                int val1 = l1 ? l1 -> val : 0;
                int val2 = l2 ? l2 -> val : 0;
                dump -> next = new ListNode((val1 + val2 + carry) % 10);
                carry = (val1 + val2 + carry) / 10;
                dump = dump -> next;
                if(l1) l1 = l1 -> next;
                if(l2) l2 = l2 -> next;
            }
            if(carry) dump -> next = new ListNode(carry);
            return res -> next;
        }
    };
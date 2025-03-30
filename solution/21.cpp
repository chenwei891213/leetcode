class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if(list1 == NULL && list2 == NULL)return list1;
            if(list1 == NULL || list2 == NULL)return list1==NULL?list2:list1;
            ListNode *temp = new ListNode();
            ListNode* ans = temp;
            while(list1 != NULL && list2 != NULL){
                if(list1->val <= list2->val){
                    temp->next = list1;
                    list1 = list1->next;
                }
                else{
                    temp->next = list2;
                    list2 = list2->next;
                }
                temp = temp -> next;
            }
            if(list1)temp->next = list1;
            else if(list2)temp->next = list2;
            return ans->next;
        }
    };
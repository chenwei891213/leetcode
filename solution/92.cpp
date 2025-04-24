//first version
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
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            ListNode* dump = new ListNode();
            ListNode* temp = head;
            ListNode* ans = dump;
            for(int i = 1; i < left; ++i){
                dump -> next = head;
                head = head -> next;
                dump = dump -> next;     
            } 
            ListNode* prev = NULL;
            ListNode* next = NULL;
            for(int i = 0; i < (right-left+1); ++i){
                next = head -> next;
                head -> next = prev;
                prev = head;
                head = next;
            }
            if(dump -> next){
                dump -> next -> next = next;
                dump -> next = prev;
            }
            else{
                dump -> next = prev;
                temp -> next = next;
            }
            return ans -> next;
        }
    };


class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            ListNode* dummy = new ListNode();
            dummy -> next = head;
            ListNode* prev = dummy;
            for(int i = 0; i < (left-1); ++i) prev = prev -> next;
            ListNode* cur = prev -> next;
            for(int i = 0; i < (right-left); ++i){
                ListNode* temp = cur -> next;
                cur -> next = temp -> next;
                temp -> next = prev -> next;
                prev -> next = temp;
            }
            return dummy -> next;
    
        }
    };
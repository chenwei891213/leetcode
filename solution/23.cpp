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
        ListNode* merge(ListNode* l1, ListNode* l2){
            ListNode* dump = new ListNode();
            ListNode* ans = dump;
            while(l1 && l2){
                if(l1 -> val < l2 -> val){
                    dump -> next = l1;
                    l1 = l1 -> next;
                }
                else{
                    dump -> next = l2;
                    l2 = l2 -> next;
                }
                dump = dump -> next;
            }
            dump -> next = l1 ? l1 : l2;
    
            return ans -> next;
        }
        
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            ListNode* dump = NULL;
            for(int i = 0; i < lists.size(); ++i){
                dump = merge(dump, lists[i]);
            }
            return dump;
        }
    };
    


//Divide and Conquer solution
class Solution {
    public:
        ListNode* merge(ListNode* l1, ListNode* l2){
            ListNode* dump = new ListNode();
            ListNode* ans = dump;
            while(l1 && l2){
                if(l1 -> val < l2 -> val){
                    dump -> next = l1;
                    l1 = l1 -> next;
                }
                else{
                    dump -> next = l2;
                    l2 = l2 -> next;
                }
                dump = dump -> next;
            }
            dump -> next = l1 ? l1 : l2;
    
            return ans -> next;
        }
        
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if(lists.empty()) return NULL;
            int n = lists.size();
            while(n > 1){
                int k = (n+1)/2;
                for(int i = 0; i < n/2; ++i){
                    lists[i] = merge(lists[i], lists[i + k]);
                }
                n = k;
            }
            return lists[0];
        }
    };

//Heap solution
class Solution {
    public:
        
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            ListNode* dump = new ListNode();
            ListNode* ans = dump;
            auto cmp = [](ListNode*& a, ListNode*& b) {
                return a->val > b->val;
            };
    
            std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> minHeap(cmp);
            for(int i = 0; i < lists.size(); ++i){
                if(lists[i]) minHeap.push(lists[i]);
            }
    
            while(!minHeap.empty()){
                ListNode* q = minHeap.top(); minHeap.pop();
                dump -> next = q;
                if(q -> next) minHeap.push(q -> next);
                dump = dump -> next;
            }
            return ans -> next;
        }
    
    };
    
    
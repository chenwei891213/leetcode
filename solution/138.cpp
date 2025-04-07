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
        Node* copyRandomList(Node* head) {
            if(!head)return NULL;
            Node *ans = new Node(head -> val);
            Node *temp = ans, *tempHead = head -> next;
            unordered_map<Node*, Node*> table;
            table[head] = ans;
            while(tempHead){
                Node* t = new Node(tempHead -> val);
                temp -> next = t;
                table[tempHead] = t;
                temp = temp -> next;
                tempHead = tempHead -> next;
            }
            temp = ans, tempHead = head;
            while(tempHead){
                temp -> random = table[tempHead -> random];
                temp = temp -> next;
                tempHead = tempHead -> next;
            }
            return ans;
        }
    };



class Solution {
    public:
        Node* copyRandomList(Node* head) {
            unordered_map<Node*, Node*> m;
            return helper(head, m);
        }
        Node* helper(Node* node, unordered_map<Node*, Node*>& m) {
            if (!node) return nullptr;
            if (m.count(node)) return m[node];
            Node *res = new Node(node->val, nullptr, nullptr);
            m[node] = res;
            res->next = helper(node->next, m);
            res->random = helper(node->random, m);
            return res;
        }
    };
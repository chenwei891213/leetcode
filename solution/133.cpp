class Solution {
    public:
        Node* cloneGraph(Node* node) {
            unordered_map<Node*, Node*> table;
            return clone(node, table);
        }
        Node* clone(Node* node, unordered_map<Node*, Node*> &table){
            if(!node) return NULL;
            if(table.count(node))return table[node];
            Node* res = new Node(node -> val);
            table[node] = res;
    
            for(Node* neighbor : node -> neighbors){
                res -> neighbors.push_back(clone(neighbor, table));
            }
    
            return res;
        }
    };


class Solution {
    public:
        Node* cloneGraph(Node* node) {
            if(!node)return NULL;
            unordered_map<Node*, Node*> table;
            queue<Node*> q;
            q.push(node);
            table[node] = new Node(node -> val);
            while(!q.empty()){
                Node* cur = q.front(); q.pop();
                for(Node *neighbor : cur -> neighbors){
                    if(!table.count(neighbor)){
                        table[neighbor] = new Node(neighbor -> val);
                        q.push(neighbor);
                    }
                    table[cur] -> neighbors.push_back(table[neighbor]);
                }
            }
            return table[node];
        }
    };
    
    
class Node{
 
    public:
        bool isWord;
        Node* table[26];
        Node(){
            isWord = false;
            for(int i = 0; i < 26; ++i) table[i] = NULL;
        }
};
class WordDictionary {
    private:
        Node* root;
    public:

        WordDictionary() {
            root = new Node();
        }
        
        void addWord(string word) {
            Node* cur = root;
            for(char s : word){
                int index = s - 'a';
                if(!cur -> table[index]) cur -> table[index] = new Node();
                cur = cur -> table[index];
            }
            cur -> isWord = true;
        }

        bool searchWord(int index, string word, Node* node){
            Node* cur = node;
            for(int i = index; i < word.length(); ++i){
                if(word[i] == '.'){
                    for(auto s : cur -> table){
                        if(s && searchWord(i+1, word, s)) return true;
                    }
                    return false;
                }
                int s = word[i] - 'a';
                if(!cur -> table[s]) return false;
                cur = cur -> table[s];
            }
            return cur -> isWord;
        }
        
        bool search(string word) {
            return searchWord(0, word, root);
        }
};
// Another solution
class Node{
 
    public:
        bool isWord;
        Node* table[26];
        Node(){
            isWord = false;
            for(int i = 0; i < 26; ++i) table[i] = NULL;
        }
};
class WordDictionary {
    private:
        Node* root;
    public:

        WordDictionary() {
            root = new Node();
        }
        
        void addWord(string word) {
            Node* cur = root;
            for(char s : word){
                int index = s - 'a';
                if(!cur -> table[index]) cur -> table[index] = new Node();
                cur = cur -> table[index];
            }
            cur -> isWord = true;
        }

        bool searchWord(int i, string word, Node* node){
            if(i == word.length()) return node -> isWord;
            Node* cur = node;
            if(word[i] == '.'){
                for(auto s : cur -> table){
                    if(s && searchWord(i+1, word, s)) return true;
                }
                return false;
            } else{
                int index = word[i] - 'a';
                return cur -> table[index] && searchWord(i+1, word, cur -> table[index]);
            }
        }
        
        bool search(string word) {
            return searchWord(0, word, root);
        }
};

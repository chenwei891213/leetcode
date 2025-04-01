class Trie {

    bool isWord;
    Trie* charList[26];

public:
    Trie() {
        isWord = false;
        for (int i = 0; i < 26; i++) charList[i] = nullptr;
    }
    
    void insert(string word) {
        Trie* ptr = this;
        for(auto c : word){
            auto index = c - 'a';
            if(ptr -> charList[index] == nullptr) ptr -> charList[index] = new Trie();
            ptr = ptr -> charList[index];
        }
        ptr -> isWord = true;
    }
    
    bool search(string word) {
        Trie* ptr = this;
        for(auto c : word){
            auto index = c - 'a';
            if(ptr -> charList[index] == nullptr) return false;
            ptr = ptr -> charList[index];
        }
        return ptr -> isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* ptr = this;
        for(auto c : prefix){
            auto index = c - 'a';
            if(ptr -> charList[index] == nullptr) return false;
            ptr = ptr -> charList[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
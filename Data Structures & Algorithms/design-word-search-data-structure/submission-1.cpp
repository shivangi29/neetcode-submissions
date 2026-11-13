class WordDictionary {
public:
    class TrieNode {
        public:
        TrieNode* child[26];
        bool end;
        TrieNode() {
            for(int i = 0 ; i < 26; i++)
                child[i] = nullptr;
            end = false;
        }
    };
    TrieNode *root = nullptr;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr = root;
        for(char ch : word) {
            int i = ch - 'a';
            if(curr->child[i] == nullptr) {
                curr->child[i] = new TrieNode();
            }
            curr = curr->child[i];
        }
        curr->end = true;
    }
    bool searchFrom(TrieNode* curr, string word) {
        //cout<<word<<endl;
        for(int i = 0 ; i < word.size() ; i++) {
            if(word[i] != '.') {
                int idx = word[i] - 'a';
                if(curr->child[idx] == nullptr)
                    return false;
                curr = curr->child[idx];
            } else {
                for(int j = 0 ; j < 26 ; j++) {
                    if(curr->child[j]) {
                        if(searchFrom(curr->child[j], word.substr(i+1)))
                            return true;
                    }
                }
                return false;
            }
        }
        return curr->end;
    }
    bool search(string word) {
        TrieNode *curr = root;
        for(int i = 0 ; i < word.size() ; i++) {
            if(word[i] != '.') {
                int idx = word[i] - 'a';
                if(curr->child[idx] == nullptr)
                    return false;
                curr = curr->child[idx];
            } else {
                for(int j = 0 ; j < 26 ; j++) {
                    if(curr->child[j]) {
                        if(searchFrom(curr->child[j], word.substr(i+1)))
                            return true;
                    }
                }
                return false;
            }
        }
        return curr->end;
    }
};

class PrefixTree {
public:
    struct trie {
        trie* child[26];
        bool end;
        trie(){
            for(int i = 0 ; i < 26; i++) 
                child[i] = nullptr;
            end = false;
        }
    };
    trie *root;
    PrefixTree() {
        root = new trie();  
    }
    
    void insert(string word) {
        trie *curr = root;
        int i = 0;
        while(i < word.size() && curr->child[word[i]-'a']) {
            curr = curr->child[word[i]-'a']; 
            i++;
        }
        while(i < word.size()) {
            curr->child[word[i]-'a'] = new trie();
            curr = curr->child[word[i]-'a'];
            i++;
        }
        curr->end = true;
    }
    
    bool search(string word) {
        trie* curr = root;
        for(auto ch : word) {
            if(!curr->child[ch-'a'])
                return false;
            curr = curr->child[ch-'a'];
        }
        return curr && curr->end;
    }
    
    bool startsWith(string prefix) {
        trie* curr = root;
        int i = 0;
        while(i < prefix.size()) {
            char ch = prefix[i] - 'a';
            if(!curr->child[ch])
                return false;
            curr = curr->child[ch];
            i++;
        }
        return i == prefix.size();
    }
};

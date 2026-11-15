class Solution {
public:
    class TrieNode {
    public:
        TrieNode* child[26] = {nullptr};
        string word = ""; // Stores the complete word at the end node
    };

    void insert(TrieNode* root, const string& str) {
        TrieNode* curr = root;
        for (char ch : str) {
            int idx = ch - 'a';
            if (curr->child[idx] == nullptr) {
                curr->child[idx] = new TrieNode();
            }
            curr = curr->child[idx];
        }
        curr->word = str;
    }

    void dfs(vector<vector<char>>& board, TrieNode* curr, int row, int col, vector<string>& ans) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return;

        char ch = board[row][col];
        if (ch == '#' || curr->child[ch - 'a'] == nullptr)
            return;

        curr = curr->child[ch - 'a'];
        
        // Found a valid word
        if (!curr->word.empty()) {
            ans.push_back(curr->word);
            curr->word = ""; // Clear to prevent duplicate entries in ans
        }

        board[row][col] = '#'; // Mark visited in-place

        dfs(board, curr, row + 1, col, ans);
        dfs(board, curr, row - 1, col, ans);
        dfs(board, curr, row, col + 1, ans);
        dfs(board, curr, row, col - 1, ans);

        board[row][col] = ch; // Backtrack: restore original character
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& str : words) {
            insert(root, str);
        }

        vector<string> ans;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, root, i, j, ans);
            }
        }
        return ans;
    }
};

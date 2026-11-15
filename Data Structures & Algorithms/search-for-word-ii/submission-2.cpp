class Solution {
public:
    class TrieNode {
    public:
        TrieNode* child[26] = {nullptr};
        bool end;
        TrieNode():end(false) {}
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
        curr->end = true;
    }

    void dfs(vector<vector<char>>& board, TrieNode* curr, int row, int col, vector<string>& ans, string tmp)    {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return;

        char ch = board[row][col];
        if (ch == '#' || curr->child[ch - 'a'] == nullptr)
            return;

        curr = curr->child[ch - 'a'];
        tmp.push_back(ch);
        // Found a valid word
        if (curr->end) {
            ans.push_back(tmp);
            curr->end = false;
        }

        board[row][col] = '#'; // Mark visited in-place

        dfs(board, curr, row + 1, col, ans, tmp);
        dfs(board, curr, row - 1, col, ans, tmp);
        dfs(board, curr, row, col + 1, ans, tmp);
        dfs(board, curr, row, col - 1, ans, tmp);

        board[row][col] = ch; // Backtrack: restore original character
        tmp.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& str : words) {
            insert(root, str);
        }

        vector<string> ans;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, root, i, j, ans, "");
            }
        }
        return ans;
    }
};

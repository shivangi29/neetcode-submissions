#include <vector>

using namespace std;

class DSU {
    vector<int> Parent, Size;

public:
    DSU(int n) {
        Parent.resize(n + 1);
        Size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            Parent[i] = i;
            Size[i] = 1;
        }
    }

    int find(int node) {
        if (Parent[node] != node) {
            Parent[node] = find(Parent[node]);
        }
        return Parent[node];
    }

    bool unionNodes(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (Size[pu] >= Size[pv]) {
            Size[pu] += Size[pv];
            Parent[pv] = pu;
        } else {
            Size[pv] += Size[pu];
            Parent[pu] = pv;
        }
        return true;
    }

    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        if (ROWS == 0) return;
        int COLS = board[0].size();
        
        // Dummy node index represents connection to the board borders
        int dummyNode = ROWS * COLS;
        DSU dsu(dummyNode);
        
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] != 'O') continue;
                
                int currentIdx = r * COLS + c;

                // Rule 1: Connect border 'O' cells directly to the dummyNode
                if (r == 0 || c == 0 || r == ROWS - 1 || c == COLS - 1) {
                    dsu.unionNodes(dummyNode, currentIdx);
                }
                
                // Rule 2: Check all 4 neighbor directions regardless of cell position.
                // This ensures border 'O's correctly spread their safety to adjacent internal 'O's.
                for (auto& dir : directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    
                    // Validate boundary conditions before accessing neighbor matrix properties
                    if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && board[nr][nc] == 'O') {
                        int neighborIdx = nr * COLS + nc;
                        dsu.unionNodes(currentIdx, neighborIdx);
                    }
                }
            }
        }

        // Flip all un-connected inner components
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'O' && !dsu.connected(dummyNode, r * COLS + c)) {
                    board[r][c] = 'X';
                }
            }
        }
    }
};

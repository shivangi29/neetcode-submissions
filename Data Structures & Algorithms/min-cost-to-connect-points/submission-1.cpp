class DSU {
    public:
        DSU(int n) {
            par.resize(n+1);
            rank.resize(n+1,1);
            for(int i = 0;  i<=n; i++ ) {
                par[i] = i;
            }
        }
        int find(int i) {
            if(i == par[i]) return i;
            return par[i] = find(par[i]);
        }
        int Union(int i, int j) {
            int pari = find(i),  parj = find(j);
            if(pari == parj) {
                return false;
            }
            if(rank[pari] < rank[parj]) {
                rank[parj] += rank[pari];
                par[pari] = parj;
            } else {
                rank[pari] += rank[parj];
                par[parj] = pari;
            }
            return true;
        }
        vector<int> par, rank;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        using vec = vector<int>;
        int n = points.size();
        vector<vector<int>> all_dis;
        for(int i = 0 ; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            for(int j =i+1;j<n;j++) {
                int x1 = points[j][0], y1 = points[j][1];
                int dis = abs(x-x1) + abs(y-y1);
                all_dis.push_back({dis,i,j});
            }   
        }
        sort(all_dis.begin(), all_dis.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[0]<b[0];
        });

        DSU dsu(n);
        int ans = 0, count;
        for(int i = 0 ; i < all_dis.size(); i++) {
            auto edge = all_dis[i];
            bool flag = dsu.Union(edge[1], edge[2]);
            if(flag) {
                ans+=edge[0];
                count++;
                if(count==n-1)break;
            }
        }
        return ans;
    }
};

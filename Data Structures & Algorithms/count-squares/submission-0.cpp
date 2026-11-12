class CountSquares {
public:
    map<pair<int,int>, int> hash;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        hash[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int new_x = point[0], new_y = point[1];
        int cnt = 0;
        for(auto itr : hash) {
            int x1 = itr.first.first, y1 = itr.first.second;
            if( x1 != new_x && y1 != new_y && abs(x1-new_x)==abs(y1-new_y)) {
                int a = hash[{x1,y1}];
                int b = hash[{new_x,y1}];
                int c = hash[{x1,new_y}];
                cnt += a*b*c;
            }
        }
        return cnt;
    }
};

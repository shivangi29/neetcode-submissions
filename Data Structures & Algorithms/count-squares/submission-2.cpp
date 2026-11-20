class CountSquares {
public:
    unordered_map<long, int> hash;
    CountSquares() {
        
    }
    long getKey(long x, long y) {
        return y << 32 | x;
    }
    void add(vector<int> point) {
        long key = getKey(point[0], point[1]);
        hash[key]++;
    }
    int count(vector<int> point) {
        long new_x = (long)point[0], new_y = (long)point[1];
        int cnt = 0;
        for(auto itr : hash) {
            long x1 = (itr.first << 32)>>32, y1 = itr.first >> 32;
            if( x1 != new_x && y1 != new_y && abs(x1-new_x)==abs(y1-new_y)) {
                int a=0,b=0,c=0;
                if(hash.contains(getKey(x1,y1)))
                    a = hash[getKey(x1,y1)];
                if(hash.contains(getKey(new_x,y1)))
                    b = hash[getKey(new_x, y1)];
                if(hash.contains(getKey(x1,new_y)))
                    c = hash[getKey(x1,new_y)];
                cnt += a*b*c;
            }
        }
        return cnt;
    }
};

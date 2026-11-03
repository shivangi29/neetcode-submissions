class Twitter {
public:
    unordered_map<int, unordered_set<int>> follower_list;
    unordered_map<int, vector<pair<int,int>>> post_list;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        post_list[userId].push_back( {time, tweetId});
        time++;
    }
    
    struct comp {
        bool operator() (pair<int,int>& a, pair<int,int>& b) {
            return a.first > b.first;
        }
    };
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> top10;
        for(auto post : post_list[userId]) {
            top10.push(post);
            if(top10.size() > 10)
                top10.pop();
        }  
        for(auto userid : follower_list[userId]){
            for(auto post : post_list[userid]) {
                top10.push(post);
                if(top10.size() > 10)
                    top10.pop();
            }       
        }
        vector<int> ans;
        while(!top10.empty()) {
            ans.push_back(top10.top().second);
            top10.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follower_list[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower_list[followerId].erase(followeeId);
    }
};

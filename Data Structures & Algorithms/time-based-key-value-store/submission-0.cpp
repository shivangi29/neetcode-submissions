class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> ds;
    TimeMap() {
    }
    
    string bs(vector<pair<int, string>>& arr, int target) {
        if(arr[0].first > target)
            return "";
        int low = 0, high = arr.size()-1;
        while(low<=high) {
            int mid = (low+high)>>1;
            if(arr[mid].first == target)
                return arr[mid].second;
            if(arr[mid].first > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return arr[high].second;
    }
    void set(string key, string value, int timestamp) {
        ds[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!ds.contains(key))
            return "";
        return bs(ds[key], timestamp);
    }
};

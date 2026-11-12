class RandomizedSet {
private:
    unordered_map<int, int> numMap;
    vector<int> nums;

public:
    RandomizedSet(){}

    bool insert(int val) {
        if (numMap.count(val)) return false;
        numMap[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!numMap.count(val)) return false;
        int idx = numMap[val];
        int last = nums[nums.size()-1];
        nums[idx] = last;
        numMap[last] = idx;
        numMap.erase(val);
        nums.pop_back();
        return true;
    }

    int getRandom() {
        int idx = rand() % nums.size();
        return nums[idx];
    }
};
class RandomizedSet {
private:
    unordered_map<int, int> numMap;
    int size;

public:
    RandomizedSet() : size(0) {}

    bool insert(int val) {
        if (numMap.count(val)) return false;
        numMap[val] = 1;
        size++;
        return true;
    }

    bool remove(int val) {
        if (!numMap.count(val)) return false;
        numMap.erase(val);
        size--;
        return true;
    }

    int getRandom() {
        int idx = rand() % size;
        auto it = numMap.begin();
        advance(it, idx);
        return it->first;
    }
};
#include <unordered_map>
#include <vector>

class FreqStack {
private:
    // Maps a frequency to a stack (vector) of elements with that frequency
    std::unordered_map<int, std::vector<int>> freq_map;
    
    // Maps an element to its current frequency count
    std::unordered_map<int, int> count_map;
    
    // Tracks the current maximum frequency in the system
    int max_freq = 0;

public:
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        // 1. Increment the frequency of the element
        int current_freq = ++count_map[val];
        
        // 2. Update max_freq if we reached a higher frequency threshold
        if (current_freq > max_freq) {
            max_freq = current_freq;
        }
        
        // 3. Add the element to the stack corresponding to its current frequency tier
        freq_map[current_freq].push_back(val);
    }
    
    int pop() {
        // 1. Get the most recently added element at the highest frequency
        int val = freq_map[max_freq].back();
        freq_map[max_freq].pop_back();
        
        // 2. Decrement its overall frequency representation
        count_map[val]--;
        
        // 3. Clean up: if no elements left at the maximum frequency, move down a tier
        if (freq_map[max_freq].empty()) {
            freq_map.erase(max_freq); // Optional optimization to save space
            max_freq--;
        }
        
        return val;
    }
};

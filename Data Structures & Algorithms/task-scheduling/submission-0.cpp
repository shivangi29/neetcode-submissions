class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26] = {0};
        for (char task : tasks) {
            count[task - 'A']++;
        }
        priority_queue<int> max_heap;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                max_heap.push(count[i]);
            }
        }
        queue<pair<int, int>> cooldown_queue;
        int time = 0;
        while (!max_heap.empty() || !cooldown_queue.empty()) {
            time++;
            if (!cooldown_queue.empty() && cooldown_queue.front().second == time) {
                max_heap.push(cooldown_queue.front().first);
                cooldown_queue.pop();
            }
            if (!max_heap.empty()) {
                int remaining_tasks = max_heap.top() - 1;
                max_heap.pop();
                if (remaining_tasks > 0) {
                    cooldown_queue.push({remaining_tasks, time + n + 1});
                }
            }
        }
        return time;
    }
};

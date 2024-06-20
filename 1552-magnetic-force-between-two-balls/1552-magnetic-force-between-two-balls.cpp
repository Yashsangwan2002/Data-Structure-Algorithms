class Solution {
public:
    bool check(vector<int>& position, int m, int x) {
        int prev = position[0];
        int placed = 1;
        for (int i = 1; i < position.size() && placed < m; i++) {
            if (position[i] - prev >= x) {
                placed++;
                prev = position[i];
            }
        }
        return placed == m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1;
        int right = position[position.size() - 1] - position[0];
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(position, m, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
};

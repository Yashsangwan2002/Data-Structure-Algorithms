class Solution {
public:
    int find(int ind, vector<vector<int>>& books, int n, vector<int>& dp) {
        if (ind == books.size()) return 0;
        if (dp[ind] != -1) return dp[ind];
        int width = 0;
        int height = 0;
        int minHeight = INT_MAX;
        for (int i = ind; i < books.size(); i++) {
            if (width + books[i][0] > n) break;
            width += books[i][0];
            height = max(height, books[i][1]);
            minHeight = min(minHeight, height + find(i + 1, books, n, dp));
        }
        return dp[ind] = minHeight;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> dp(books.size(), -1);
        return find(0, books, shelfWidth, dp);
    }
};
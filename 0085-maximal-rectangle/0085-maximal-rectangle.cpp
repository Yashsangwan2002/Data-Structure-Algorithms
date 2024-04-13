class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    
    int maxArea = 0;
    vector<int> height(matrix[0].size(), 0);
    
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            height[j] = (matrix[i][j] == '1' ? height[j] + 1 : 0);
        }
        stack<int> st;
        for (int j = 0; j <= height.size(); ++j) {
            int curHeight = (j == height.size() ? 0 : height[j]);
            while (!st.empty() && height[st.top()] > curHeight) {
                int h = height[st.top()];
                st.pop();
                int w = st.empty() ? j : j - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(j);
        }
    }
    
    return maxArea;
    }
};
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

 
    auto cmp = [](pair<double, pair<int, int>>& a, pair<double, pair<int, int>>& b) {
            return a.first > b.first;
        };
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, decltype(cmp)> pq(cmp);

        int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double frac = static_cast<double>(arr[i]) / arr[j];
            pq.push({frac, {arr[i], arr[j]}});
        }
    }
    for (int i = 0; i < k - 1; ++i) {
        pq.pop();
    }
    auto result = pq.top().second;
    return {result.first, result.second};
    }
};
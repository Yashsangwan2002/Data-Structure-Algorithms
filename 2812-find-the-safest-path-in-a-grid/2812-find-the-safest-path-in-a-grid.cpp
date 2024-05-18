class Solution {
public:
    int n;
    vector<vector<int>> safeness;

    bool isSafe(int mid, vector<vector<int>>& grid) {
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int, int>> q;

        if (safeness[0][0] >= mid) {
            q.push({0, 0});
            vis[0][0] = 1;
        }

        int row[] = {0, 1, 0, -1};
        int col[] = {1, 0, -1, 0};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == n - 1 && y == n - 1) return true;

            for (int i = 0; i < 4; i++) {
                int nx = x + row[i];
                int ny = y + col[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny] && safeness[nx][ny] >= mid) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }

    void calculateSafeness(vector<vector<int>>& grid) {
        safeness = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    safeness[i][j] = 0;
                }
            }
        }

        int row[] = {0, 1, 0, -1};
        int col[] = {1, 0, -1, 0};
        int dis = 0;

        while (!q.empty()) {
            int q_size = q.size();
            dis++;
            for (int i = 0; i < q_size; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int nx = x + row[j];
                    int ny = y + col[j];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && safeness[nx][ny] > dis) {
                        safeness[nx][ny] = dis;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        calculateSafeness(grid);

        int left = 0, right = n * n, result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isSafe(mid, grid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};
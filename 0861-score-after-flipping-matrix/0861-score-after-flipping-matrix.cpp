class Solution {
public:
    void rowflip(int y, int m, std::vector<std::vector<int>>& grid) {
        for (int i = 0; i < m; i++) {
            if (grid[y][i] == 1)
                grid[y][i] = 0;
            else
                grid[y][i] = 1;
        }
    }
    void colflip(int x, int n, std::vector<std::vector<int>>& grid) {
        for (int i = 0; i < n; i++) {
            if (grid[i][x] == 1)
                grid[i][x] = 0;
            else
                grid[i][x] = 1;
        }
    }
    int matrixScore(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0)
                rowflip(i, n, grid);
        }
        for (int j = 1; j < n; j++) {
            int countOnes = 0;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 1)
                    countOnes++;
            }
            if (countOnes <= m / 2) {
                colflip(j, m, grid);
            }
        }
        int score = 0;
        for (int i = 0; i < m; i++) {
            int rowValue = 0;
            for (int j = 0; j < n; j++) {
                rowValue = (rowValue << 1) | grid[i][j];
            }
            score += rowValue;
        }

        return score;
    }
};
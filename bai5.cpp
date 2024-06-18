#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        const int m = grid.size();
        const int n = grid[0].size();
        int ans = 0;
        int countFresh = 0;
        queue<pair<int, int>> q;

        // Initialize
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++countFresh;
                } else if (grid[i][j] == 2) {
                    q.emplace(i, j); // Add rotten oranges to the queue
                }
            }
        }

        if (countFresh == 0) {
            return 0;
        }

        // BFS
        while (!q.empty()) {
            ++ans;
            int sz = q.size();
            for (int k = 0; k < sz; ++k) {
                auto [i, j] = q.front();
                q.pop();
                for (const auto& dir : dirs) {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) {
                        continue;
                    }
                    grid[x][y] = 2; // Mark as rotten
                    q.emplace(x, y); // Add to queue
                    --countFresh; // Decrease count of fresh oranges
                }
            }
        }

        //If it is impossible to rot all oranges
        return countFresh == 0 ? ans - 1 : -1;
    }
};


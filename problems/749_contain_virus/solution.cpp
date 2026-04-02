#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    int containVirus(vector<vector<int>>& isInfected) {
        int m = isInfected.size(), n = isInfected[0].size(), walls = 0;
        while (true) {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            vector<set<int>> regions, frontiers;
            vector<int> perimeters;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (isInfected[i][j] == 1 && !visited[i][j]) {
                        set<int> region, frontier;
                        int perim = 0;
                        queue<pair<int,int>> q;
                        q.push({i,j}); visited[i][j] = true;
                        while (!q.empty()) {
                            auto [r,c] = q.front(); q.pop();
                            region.insert(r*n+c);
                            for (auto [dr,dc] : vector<pair<int,int>>{{0,1},{0,-1},{1,0},{-1,0}}) {
                                int nr=r+dr, nc=c+dc;
                                if (nr>=0&&nr<m&&nc>=0&&nc<n) {
                                    if (isInfected[nr][nc]==0) { frontier.insert(nr*n+nc); perim++; }
                                    else if (isInfected[nr][nc]==1&&!visited[nr][nc]) { visited[nr][nc]=true; q.push({nr,nc}); }
                                }
                            }
                        }
                        regions.push_back(region); frontiers.push_back(frontier); perimeters.push_back(perim);
                    }
                }
            }
            if (regions.empty()) break;
            int idx = 0;
            for (int i = 1; i < (int)frontiers.size(); i++)
                if (frontiers[i].size() > frontiers[idx].size()) idx = i;
            walls += perimeters[idx];
            for (int code : regions[idx]) isInfected[code/n][code%n] = -1;
            bool any = false;
            for (int i = 0; i < (int)regions.size(); i++) {
                if (i == idx) continue;
                for (int code : frontiers[i]) { isInfected[code/n][code%n] = 1; any = true; }
            }
            if (!any) break;
        }
        return walls;
    }
};

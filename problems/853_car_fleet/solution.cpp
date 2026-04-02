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
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars(n);
        for (int i = 0; i < n; i++) cars[i] = {position[i], speed[i]};
        sort(cars.begin(), cars.end(), greater<>());
        int fleets = 0;
        double lastTime = 0;
        for (auto& [pos, spd] : cars) {
            double time = (double)(target - pos) / spd;
            if (time > lastTime) { fleets++; lastTime = time; }
        }
        return fleets;
    }
};

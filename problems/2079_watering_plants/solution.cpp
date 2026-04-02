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
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0, water = capacity;
        for (int i = 0; i < (int)plants.size(); i++) {
            if (water >= plants[i]) {
                steps++;
                water -= plants[i];
            } else {
                steps += 2 * i + 1;
                water = capacity - plants[i];
            }
        }
        return steps;
    }
};

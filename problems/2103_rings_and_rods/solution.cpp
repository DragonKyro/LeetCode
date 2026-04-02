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
    int countPoints(string rings) {
        unordered_set<char> rods[10];
        for (int i = 0; i < (int)rings.size(); i += 2) {
            rods[rings[i + 1] - '0'].insert(rings[i]);
        }
        int count = 0;
        for (int i = 0; i < 10; i++) if (rods[i].size() == 3) count++;
        return count;
    }
};

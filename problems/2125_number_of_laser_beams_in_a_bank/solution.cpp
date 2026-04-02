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
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, total = 0;
        for (const string& row : bank) {
            int count = std::count(row.begin(), row.end(), '1');
            if (count > 0) {
                total += prev * count;
                prev = count;
            }
        }
        return total;
    }
};

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
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](auto& a, auto& b) {
            return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
        });
        int count = 0, maxDef = 0;
        for (auto& p : properties) {
            if (p[1] < maxDef) count++;
            else maxDef = p[1];
        }
        return count;
    }
};

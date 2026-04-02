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
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result, current;
        for (int x : arr) {
            unordered_set<int> next = {x};
            for (int y : current) next.insert(x | y);
            result.insert(next.begin(), next.end());
            current = next;
        }
        return result.size();
    }
};

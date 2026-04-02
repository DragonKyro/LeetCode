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
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int len = to_string(low).size(); len <= (int)to_string(high).size(); len++) {
            for (int start = 1; start <= 9 - len + 1; start++) {
                int num = 0;
                for (int i = 0; i < len; i++) num = num * 10 + start + i;
                if (num >= low && num <= high) res.push_back(num);
            }
        }
        return res;
    }
};

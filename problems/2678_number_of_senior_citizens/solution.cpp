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
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for (auto& d : details) if (stoi(d.substr(11, 2)) > 60) cnt++;
        return cnt;
    }
};

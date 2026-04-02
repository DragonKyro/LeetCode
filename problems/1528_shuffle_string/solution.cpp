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
    string restoreString(string s, vector<int>& indices) {
        string res(s.size(), ' ');
        for (int i = 0; i < (int)s.size(); i++) res[indices[i]] = s[i];
        return res;
    }
};

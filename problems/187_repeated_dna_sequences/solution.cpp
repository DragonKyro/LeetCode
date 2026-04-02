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
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> seen;
        vector<string> res;
        for (int i = 0; i + 10 <= (int)s.size(); i++) {
            string seq = s.substr(i, 10);
            if (++seen[seq] == 2) res.push_back(seq);
        }
        return res;
    }
};

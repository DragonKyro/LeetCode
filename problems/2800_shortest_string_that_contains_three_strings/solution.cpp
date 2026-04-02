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
    string minimumString(string a, string b, string c) {
        auto merge = [](string s1, string s2) {
            if (s1.find(s2) != string::npos) return s1;
            for (int i = 0; i < (int)s1.size(); i++)
                if (s2.substr(0, s1.size()-i) == s1.substr(i)) return s1.substr(0,i) + s2;
            return s1 + s2;
        };
        vector<string> v = {a, b, c};
        int p[] = {0,1,2};
        string best;
        do {
            string res = merge(merge(v[p[0]], v[p[1]]), v[p[2]]);
            if (best.empty() || res.size() < best.size() || (res.size() == best.size() && res < best))
                best = res;
        } while (next_permutation(p, p+3));
        return best;
    }
};

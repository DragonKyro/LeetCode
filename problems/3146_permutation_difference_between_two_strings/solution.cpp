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
    int findPermutationDifference(string s, string t) {
        int ps[26]={}, pt[26]={};
        for (int i = 0; i < s.size(); i++) { ps[s[i]-'a']=i; pt[t[i]-'a']=i; }
        int res = 0;
        for (int i = 0; i < 26; i++) res += abs(ps[i]-pt[i]);
        return res;
    }
};

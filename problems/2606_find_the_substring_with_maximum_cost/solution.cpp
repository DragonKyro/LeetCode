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
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int cost[26]; for (int i=0;i<26;i++) cost[i]=i+1;
        for (int i=0;i<chars.size();i++) cost[chars[i]-'a']=vals[i];
        int ans=0, cur=0;
        for (char c:s) { cur+=cost[c-'a']; if(cur<0)cur=0; ans=max(ans,cur); }
        return ans;
    }
};

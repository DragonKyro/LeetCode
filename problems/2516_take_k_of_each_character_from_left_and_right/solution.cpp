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
    int takeCharacters(string s, int k) {
        int cnt[3]={}, n=s.size(), ans=n, j=0, w[3]={};
        for (char c:s) cnt[c-'a']++;
        if (cnt[0]<k||cnt[1]<k||cnt[2]<k) return -1;
        for (int i=0;i<n;i++) {
            w[s[i]-'a']++;
            while (cnt[0]-w[0]<k||cnt[1]-w[1]<k||cnt[2]-w[2]<k) w[s[j++]-'a']--;
            ans = min(ans, n-(i-j+1));
        }
        return ans;
    }
};

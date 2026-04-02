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
    string clearStars(string s) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        set<int> removed;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                removed.insert(i);
                auto [c, ni] = pq.top(); pq.pop();
                removed.insert(-ni);
            } else {
                pq.push({s[i]-'a', -i});
            }
        }
        string res;
        for (int i = 0; i < s.size(); i++)
            if (!removed.count(i)) res += s[i];
        return res;
    }
};

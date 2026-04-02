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
    unordered_map<string, string> mp;
    int counter = 0;
public:
    string encode(string longUrl) {
        string key = to_string(++counter);
        mp[key] = longUrl;
        return "http://tinyurl.com/" + key;
    }
    string decode(string shortUrl) {
        string key = shortUrl.substr(shortUrl.rfind('/') + 1);
        return mp[key];
    }
};

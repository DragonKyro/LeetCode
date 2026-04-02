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
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<int> st;
        int prevTime = 0;
        for (auto& log : logs) {
            int i1 = log.find(':');
            int i2 = log.find(':', i1 + 1);
            int fid = stoi(log.substr(0, i1));
            string type = log.substr(i1 + 1, i2 - i1 - 1);
            int time = stoi(log.substr(i2 + 1));
            if (type == "start") {
                if (!st.empty()) result[st.top()] += time - prevTime;
                st.push(fid);
                prevTime = time;
            } else {
                result[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }
        return result;
    }
};

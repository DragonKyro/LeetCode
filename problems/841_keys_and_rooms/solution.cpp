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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        stack<int> st;
        st.push(0);
        while (!st.empty()) {
            int room = st.top(); st.pop();
            if (!visited.insert(room).second) continue;
            for (int key : rooms[room]) if (!visited.count(key)) st.push(key);
        }
        return visited.size() == rooms.size();
    }
};

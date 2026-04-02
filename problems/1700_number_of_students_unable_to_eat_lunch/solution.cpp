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
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0};
        for (int s : students) count[s]++;
        for (int i = 0; i < sandwiches.size(); i++) {
            if (count[sandwiches[i]] > 0) count[sandwiches[i]]--;
            else return sandwiches.size() - i;
        }
        return 0;
    }
};

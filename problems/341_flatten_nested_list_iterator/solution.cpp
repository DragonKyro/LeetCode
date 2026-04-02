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

class NestedIterator {
    vector<int> list;
    int idx = 0;
    void flatten(vector<NestedInteger>& nestedList) {
        for (auto& ni : nestedList) {
            if (ni.isInteger()) list.push_back(ni.getInteger());
            else flatten(ni.getList());
        }
    }
public:
    NestedIterator(vector<NestedInteger>& nestedList) { flatten(nestedList); }
    int next() { return list[idx++]; }
    bool hasNext() { return idx < list.size(); }
};

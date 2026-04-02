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

class SnapshotArray {
public:
    vector<vector<pair<int, int>>> snaps;
    int snapId = 0;

    SnapshotArray(int length) {
        snaps.resize(length);
        for (int i = 0; i < length; i++) {
            snaps[i].push_back({0, 0});
        }
    }

    void set(int index, int val) {
        if (snaps[index].back().first == snapId) {
            snaps[index].back().second = val;
        } else {
            snaps[index].push_back({snapId, val});
        }
    }

    int snap() {
        return snapId++;
    }

    int get(int index, int snap_id) {
        auto it = upper_bound(snaps[index].begin(), snaps[index].end(), make_pair(snap_id, INT_MAX));
        --it;
        return it->second;
    }
};

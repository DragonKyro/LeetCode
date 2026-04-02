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
    Node* intersect(Node* q1, Node* q2) {
        if (q1->isLeaf) return q1->val ? q1 : q2;
        if (q2->isLeaf) return q2->val ? q2 : q1;
        auto tl = intersect(q1->topLeft, q2->topLeft);
        auto tr = intersect(q1->topRight, q2->topRight);
        auto bl = intersect(q1->bottomLeft, q2->bottomLeft);
        auto br = intersect(q1->bottomRight, q2->bottomRight);
        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && tl->val == tr->val && tr->val == bl->val && bl->val == br->val)
            return new Node(tl->val, true);
        return new Node(false, false, tl, tr, bl, br);
    }
};

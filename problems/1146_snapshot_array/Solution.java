import java.util.*;

class SnapshotArray {
    List<int[]>[] snaps;
    int snapId = 0;

    public SnapshotArray(int length) {
        snaps = new List[length];
        for (int i = 0; i < length; i++) {
            snaps[i] = new ArrayList<>();
            snaps[i].add(new int[]{0, 0});
        }
    }

    public void set(int index, int val) {
        List<int[]> list = snaps[index];
        if (list.get(list.size() - 1)[0] == snapId) {
            list.get(list.size() - 1)[1] = val;
        } else {
            list.add(new int[]{snapId, val});
        }
    }

    public int snap() {
        return snapId++;
    }

    public int get(int index, int snap_id) {
        List<int[]> list = snaps[index];
        int lo = 0, hi = list.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (list.get(mid)[0] <= snap_id) lo = mid;
            else hi = mid - 1;
        }
        return list.get(lo)[1];
    }
}

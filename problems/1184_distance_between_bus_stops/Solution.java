class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int total = 0, clockwise = 0;
        for (int d : distance) total += d;
        if (start > destination) { int t = start; start = destination; destination = t; }
        for (int i = start; i < destination; i++) clockwise += distance[i];
        return Math.min(clockwise, total - clockwise);
    }
}

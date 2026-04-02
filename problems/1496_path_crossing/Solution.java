import java.util.*;

class Solution {
    public boolean isPathCrossing(String path) {
        Set<String> visited = new HashSet<>();
        int x = 0, y = 0;
        visited.add("0,0");
        for (char d : path.toCharArray()) {
            if (d == 'N') y++;
            else if (d == 'S') y--;
            else if (d == 'E') x++;
            else x--;
            if (!visited.add(x + "," + y)) return true;
        }
        return false;
    }
}

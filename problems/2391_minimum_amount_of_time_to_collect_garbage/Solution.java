class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        int result = 0;
        int[] last = new int[3];
        for (int i = 0; i < garbage.length; i++) {
            result += garbage[i].length();
            for (char c : garbage[i].toCharArray()) {
                if (c == 'M') last[0] = i;
                else if (c == 'P') last[1] = i;
                else last[2] = i;
            }
        }
        int[] prefix = new int[travel.length + 1];
        for (int i = 0; i < travel.length; i++) prefix[i+1] = prefix[i] + travel[i];
        for (int l : last) result += prefix[l];
        return result;
    }
}

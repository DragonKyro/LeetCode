class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int[] count = new int[2];
        for (int s : students) count[s]++;
        for (int i = 0; i < sandwiches.length; i++) {
            if (count[sandwiches[i]] > 0) count[sandwiches[i]]--;
            else return sandwiches.length - i;
        }
        return 0;
    }
}

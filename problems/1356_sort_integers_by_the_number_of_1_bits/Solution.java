import java.util.*;

class Solution {
    public int[] sortByBits(int[] arr) {
        Integer[] boxed = new Integer[arr.length];
        for (int i = 0; i < arr.length; i++) boxed[i] = arr[i];
        Arrays.sort(boxed, (a, b) -> Integer.bitCount(a) != Integer.bitCount(b) ? Integer.bitCount(a) - Integer.bitCount(b) : a - b);
        for (int i = 0; i < arr.length; i++) arr[i] = boxed[i];
        return arr;
    }
}

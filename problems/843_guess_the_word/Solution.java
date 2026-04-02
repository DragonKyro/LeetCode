import java.util.*;

class Solution {
    public void findSecretWord(String[] words, Master master) {
        Random rand = new Random();
        List<String> candidates = new ArrayList<>(Arrays.asList(words));
        for (int i = 0; i < 10; i++) {
            String guess = candidates.get(rand.nextInt(candidates.size()));
            int m = master.guess(guess);
            if (m == 6) return;
            List<String> next = new ArrayList<>();
            for (String w : candidates) if (matches(w, guess) == m) next.add(w);
            candidates = next;
        }
    }
    int matches(String a, String b) {
        int c = 0;
        for (int i = 0; i < a.length(); i++) if (a.charAt(i) == b.charAt(i)) c++;
        return c;
    }
}

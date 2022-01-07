import java.util.*;
import java.lang.*;
class Solution {
    public int solution(String word) {
        int answer = 0;
        Map<Character, Integer> m = new HashMap<>();
        m.put('A', 1);
        m.put('E', 2);
        m.put('I', 3);
        m.put('O', 4);
        m.put('U', 5);
        for (int i = 0; i < word.length(); ++i) {
            int c = m.get(word.charAt(i));
            int num = 5 - i;
            if (c == 1) answer += 1;
            else {
                for (int j = num - 1; j > 0; j--) {
                    answer += (int)Math.pow(5.0, j) * (c - 1);
                }
                answer += (c);
            }
        }
        return answer;
    }
}
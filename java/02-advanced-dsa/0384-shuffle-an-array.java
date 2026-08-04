import java.util.*;

class Solution {
    int[] original;
    Random rand = new Random();
    public Solution(int[] nums) {
        original = nums.clone();
    }
    public int[] reset() {
        return original.clone();
    }
    public int[] shuffle() {
        int[] shuffled = original.clone();
        for (int i = 0; i < shuffled.length; i++) {
            int j = i + rand.nextInt(shuffled.length - i);
            int temp = shuffled[i];
            shuffled[i] = shuffled[j];
            shuffled[j] = temp;
        }
        return shuffled;
    }
}

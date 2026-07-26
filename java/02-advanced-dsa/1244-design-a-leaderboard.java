import java.util.*;

class Leaderboard {
    Map<Integer, Integer> scores = new HashMap<>();
    public Leaderboard() {}
    public void addScore(int playerId, int score) {
        scores.put(playerId, scores.getOrDefault(playerId, 0) + score);
    }
    public int top(int K) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(K);
        for (int score : scores.values()) {
            pq.offer(score);
            if (pq.size() > K) pq.poll();
        }
        int sum = 0;
        while (!pq.isEmpty()) sum += pq.poll();
        return sum;
    }
    public void reset(int playerId) {
        scores.remove(playerId);
    }
}

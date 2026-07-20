import java.util.*;

class UndergroundSystem {
    Map<Integer, Pair<String, Integer>> checkIns = new HashMap<>();
    Map<String, int[]> travelTimes = new HashMap<>(); // stationPair -> [totalTime, count]
    public UndergroundSystem() {}
    public void checkIn(int id, String stationName, int t) {
        checkIns.put(id, new Pair<>(stationName, t));
    }
    public void checkOut(int id, String stationName, int t) {
        Pair<String, Integer> start = checkIns.remove(id);
        String key = start.getKey() + "->" + stationName;
        int time = t - start.getValue();
        travelTimes.putIfAbsent(key, new int[2]);
        travelTimes.get(key)[0] += time;
        travelTimes.get(key)[1]++;
    }
    public double getAverageTime(String startStation, String endStation) {
        String key = startStation + "->" + endStation;
        int[] data = travelTimes.get(key);
        return (double) data[0] / data[1];
    }
}

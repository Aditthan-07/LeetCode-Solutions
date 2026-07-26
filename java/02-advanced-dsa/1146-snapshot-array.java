import java.util.*;

class SnapshotArray {
    List<TreeMap<Integer, Integer>> array;
    int snapId = 0;
    public SnapshotArray(int length) {
        array = new ArrayList<>(length);
        for (int i = 0; i < length; i++) {
            TreeMap<Integer, Integer> tm = new TreeMap<>();
            tm.put(0, 0);
            array.add(tm);
        }
    }
    public void set(int index, int val) {
        array.get(index).put(snapId, val);
    }
    public int snap() {
        return snapId++;
    }
    public int get(int index, int snap_id) {
        return array.get(index).floorEntry(snap_id).getValue();
    }
}

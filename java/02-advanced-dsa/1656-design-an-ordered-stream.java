import java.util.*;

class OrderedStream {
    String[] stream;
    int ptr = 0;
    public OrderedStream(int n) {
        stream = new String[n];
    }
    public List<String> insert(int idKey, String value) {
        stream[idKey - 1] = value;
        List<String> res = new ArrayList<>();
        while (ptr < stream.length && stream[ptr] != null) {
            res.add(stream[ptr++]);
        }
        return res;
    }
}

import java.util.*;

public class Codec {
    Map<Integer, String> map = new HashMap<>();
    int id = 0;
    public String encode(String longUrl) {
        map.put(id, longUrl);
        return "http://tinyurl.com/" + id++;
    }
    public String decode(String shortUrl) {
        int key = Integer.parseInt(shortUrl.replace("http://tinyurl.com/", ""));
        return map.get(key);
    }
}

import java.util.*;

class Logger {
    Map<String, Integer> msgMap = new HashMap<>();
    public Logger() {}
    public boolean shouldPrintMessage(int timestamp, String message) {
        if (!msgMap.containsKey(message) || timestamp - msgMap.get(message) >= 10) {
            msgMap.put(message, timestamp);
            return true;
        }
        return false;
    }
}

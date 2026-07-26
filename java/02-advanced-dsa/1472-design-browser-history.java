import java.util.*;

class BrowserHistory {
    List<String> history = new ArrayList<>();
    int curr = 0;
    public BrowserHistory(String homepage) {
        history.add(homepage);
    }
    public void visit(String url) {
        while (history.size() > curr + 1) history.remove(history.size() - 1);
        history.add(url);
        curr++;
    }
    public String back(int steps) {
        curr = Math.max(0, curr - steps);
        return history.get(curr);
    }
    public String forward(int steps) {
        curr = Math.min(history.size() - 1, curr + steps);
        return history.get(curr);
    }
}

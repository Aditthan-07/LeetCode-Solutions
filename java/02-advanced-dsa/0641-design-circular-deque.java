class MyCircularDeque {
    int[] deque;
    int head = 0, count = 0, cap;
    public MyCircularDeque(int k) {
        cap = k;
        deque = new int[k];
    }
    public boolean insertFront(int value) {
        if (isFull()) return false;
        head = (head - 1 + cap) % cap;
        deque[head] = value;
        count++;
        return true;
    }
    public boolean insertLast(int value) {
        if (isFull()) return false;
        deque[(head + count) % cap] = value;
        count++;
        return true;
    }
    public boolean deleteFront() {
        if (isEmpty()) return false;
        head = (head + 1) % cap;
        count--;
        return true;
    }
    public boolean deleteLast() {
        if (isEmpty()) return false;
        count--;
        return true;
    }
    public int getFront() {
        return isEmpty() ? -1 : deque[head];
    }
    public int getRear() {
        return isEmpty() ? -1 : deque[(head + count - 1) % cap];
    }
    public boolean isEmpty() {
        return count == 0;
    }
    public boolean isFull() {
        return count == cap;
    }
}

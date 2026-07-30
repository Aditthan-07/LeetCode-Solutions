class MyCircularQueue {
    int[] queue;
    int head = 0, count = 0, cap;
    public MyCircularQueue(int k) {
        cap = k;
        queue = new int[k];
    }
    public boolean enQueue(int value) {
        if (isFull()) return false;
        queue[(head + count) % cap] = value;
        count++;
        return true;
    }
    public boolean deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % cap;
        count--;
        return true;
    }
    public int Front() {
        return isEmpty() ? -1 : queue[head];
    }
    public int Rear() {
        return isEmpty() ? -1 : queue[(head + count - 1) % cap];
    }
    public boolean isEmpty() {
        return count == 0;
    }
    public boolean isFull() {
        return count == cap;
    }
}

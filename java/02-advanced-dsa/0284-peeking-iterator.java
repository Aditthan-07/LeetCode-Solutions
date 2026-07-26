import java.util.Iterator;

class PeekingIterator implements Iterator<Integer> {
    Iterator<Integer> it;
    Integer nextVal = null;
    public PeekingIterator(Iterator<Integer> iterator) {
        it = iterator;
        if (it.hasNext()) nextVal = it.next();
    }
    public Integer peek() {
        return nextVal;
    }
    @Override
    public Integer next() {
        Integer res = nextVal;
        nextVal = it.hasNext() ? it.next() : null;
        return res;
    }
    @Override
    public boolean hasNext() {
        return nextVal != null;
    }
}

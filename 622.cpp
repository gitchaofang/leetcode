class MyCircularQueue {
public:
    /*empty head == tail, full head + 1 = tail*/
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k): head(0), tail(0), cap(k) {
        q.resize(k + 1);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        q[head++] = value;
        head %= (cap + 1);
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        tail = (tail + 1) % (cap + 1);
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return q[tail];    
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return q[(head + cap) % (cap + 1)];    
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == tail;    
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (head + 1) % (cap + 1) == tail;    
    }
private:
    std::vector<int> q;
    int head;
    int tail;
    int cap;
};

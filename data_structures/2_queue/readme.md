# In cque.c 

## Issue may be : [cque.c](./cque.c)

**deque function edit**
int deque() {
    int x = -999;  // Default value for underflow case
    if (!underflow()) {  
        x = cq.c[cq.front];  // Store dequeued element
        if (cq.front == cq.rear) {  // Only one element in queue
            cq.front = -1;
            cq.rear = -1;
        } else {
            cq.front = (cq.front + 1) % cq.size;  // Move front forward
        }
    }
    return x;
}

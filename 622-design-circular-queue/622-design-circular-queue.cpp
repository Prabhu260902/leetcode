class MyCircularQueue {
    queue<int>q;
    int kk;
public:
    MyCircularQueue(int k) {
        kk=k;
    }
    
    bool enQueue(int value) {
        if(q.size()==kk) return false;
        q.push(value);
        return true;
    }
    
    bool deQueue() {
        if(q.empty()) return false;
        q.pop();
        return true;
    }
    
    int Front() {
        if(q.empty()) return -1;
        return q.front();
    }
    
    int Rear() {
        if(q.empty()) return -1;
        int n=q.size();
        for(int i=1;i<n;i++)
        {
            q.push(q.front());
            q.pop();
        }
        int pp=q.front();
        q.push(q.front());
        q.pop();
        return pp;
    }
    
    bool isEmpty() {
        if(q.empty()) return true;
        return false;
    }
    
    bool isFull() {
        if(q.size()==kk) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
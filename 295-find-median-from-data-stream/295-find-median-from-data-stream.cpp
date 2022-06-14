class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>minheap;
    priority_queue<int>maxheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minheap.empty()||maxheap.top()>num)
        {
            maxheap.push(num);
        }
        else
        {
            minheap.push(num);
        }
        if(maxheap.size()>minheap.size()+1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size()>maxheap.size()+1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        double avg;
        if(minheap.size()==maxheap.size())
        {
            if(maxheap.empty())
            {
                return 0;
            }
            else
            {
                avg = (minheap.top() + maxheap.top())/2.0;
                return avg;
            }
        }
        else
        {
            if(maxheap.size()>minheap.size())
            {
                return maxheap.top();
            }
        }
        return minheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
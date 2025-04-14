class MedianFinder {
    public:
        priority_queue<int> small, big;
        MedianFinder() {
            
        }
    
        void addNum(int num) {
            if(small.empty() || small.top() > num){
                small.push(num);
            }
            else big.push(-num);
            if(small.size() > big.size() + 1){
                big.push(-small.top());
                small.pop();
            }
            else if(small.size() < big.size()){
                small.push(-big.top());
                big.pop();
            }
        }
        
        double findMedian() {
            return small.size() == big.size() ? 0.5 * (small.top() - big.top()) : small.top();
        }
    };



class MedianFinder {
    public:
        priority_queue<int> small, big;
        MedianFinder() {     
        }
    
        void addNum(int num) {
            small.push(num);
            big.push(-small.top());
            small.pop();
            if(small.size() < big.size()){
                small.push(-big.top());
                big.pop();
            }
        }
        
        double findMedian() {
            return small.size() == big.size() ? 0.5 * (small.top() - big.top()) : small.top();
        }
    };
    

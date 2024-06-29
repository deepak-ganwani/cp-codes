struct monotonic_dequeue{
    deque<int> min_q, max_q;
    void insert(int x){
        while(min_q.size() && min_q.back() > x) min_q.pop_back();
        while(max_q.size() && max_q.back() < x) max_q.pop_back();
        min_q.push_back(x);
        max_q.push_back(x);
    }
    void erase(int x){
        if(!min_q.empty() && min_q.front() == x) min_q.pop_front();
        if(!max_q.empty() && max_q.front() == x) max_q.pop_front();
    }
    int getMin(){
        return min_q.front();
    }
    int getMax(){
        return max_q.front();
    }
    bool isMin(){
        return !min_q.empty();
    }
    bool isMax(){
        return !max_q.empty();
    }
};
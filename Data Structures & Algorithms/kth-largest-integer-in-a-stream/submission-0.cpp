class KthLargest {
public:

    priority_queue<int,vector<int>,greater<int>>pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto&i:nums){
            this->pq.push(i);
            while(this->pq.size()>k){
                this->pq.pop();
            }
        }
        
    }
    
    int add(int val) {
        
        this->pq.push(val);
        while(this->pq.size()>this->k){
                this->pq.pop();
            }
        return this->pq.top();
    }
};

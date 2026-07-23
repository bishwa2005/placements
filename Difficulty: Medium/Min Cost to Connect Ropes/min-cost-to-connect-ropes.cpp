class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int ans=0;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i : arr){
            pq.push(i);
            
        }
        
        while(pq.size()){
            if(pq.size()==1){
                // ans+=pq.top();
                break;
            }
            else{
                int t1=pq.top();
                pq.pop();
                int t2=pq.top();
                pq.pop();
                
                ans+=(t1+t2);
                pq.push(t1+t2);
            }
        }
        
        return ans;
    }
};
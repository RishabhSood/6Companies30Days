class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
      
        int lp = 0;
        int rp = 0;
      
        while(rp < n)
        {
            if(rp - lp + 1 < k)
            {
                pq.push({arr[rp], rp});
                rp++;
            } else {
                pq.push({arr[rp], rp});
                rp++;
                ans.push_back(pq.top().first);
                lp++;
                while(!pq.empty()){
                    if(pq.top().second < lp)
                        pq.pop();
                    else
                        break;
                }
            }
        }
        return ans;
    }
};

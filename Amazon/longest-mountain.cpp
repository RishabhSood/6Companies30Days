class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int iter = 0;
        int ans = 0;
        
        while(iter < arr.size())
        {
            int base = iter;
            while(iter + 1 < arr.size() && arr[iter] < arr[iter + 1])
                iter++;
            if(iter == base)
            {
                iter++;
                continue;
            }
            int peak = iter;
            while(iter + 1 < arr.size() && arr[iter] > arr[iter + 1])
                iter++;
            if(iter != peak)
                ans = max(ans, iter - base + 1);
        }
        
        return ans;
    }
};

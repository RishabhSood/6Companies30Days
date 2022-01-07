class Solution{
    map<string, pair<int, string>> dp; // l-r mapped to lowest ops and op rep
public:
    string matrixChainOrder(int A[], int n) {
        return matrixChainOrderUtil(A, 0, n - 1).second; 
    }
    
    pair<int, string> matrixChainOrderUtil(int A[], int l, int r)
    {
        if(l + 1 == r) // base case, arrived at single matrix
            return {0, "" + string(1, l + 'A')};
        
        string lr = to_string(l) + ":" + to_string(r);
        
        if(dp.find(lr) != dp.end())
            return dp[lr];
        
        else
        {
            int min_cost = INT_MAX;
            string ops;
            for(int k = l + 1; k < r; k++)   
            {
                auto lt = matrixChainOrderUtil(A, l, k), rt = matrixChainOrderUtil(A, k, r);
                if(lt.first + rt.first + A[l]*A[k]*A[r] < min_cost)
                {
                    min_cost = lt.first + rt.first + A[l]*A[k]*A[r];
                    ops = lt.second + rt.second;
                }
            }
            return dp[lr] = {min_cost, "(" + ops + ")"};
        }
    }
};

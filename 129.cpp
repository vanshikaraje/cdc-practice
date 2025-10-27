class Solution {
public:
    int climbStairs(int n) 
    { 
        // Base case: 1 stair → 1 way
        if(n == 1)  
        { 
            return 1; 
        } 

        // Base case: 2 stairs → 2 ways (1+1, or 2)
        if(n == 2)  
        { 
            return 2; 
        } 

        // Recursive relation: f(n) = f(n-1) + f(n-2)
        int ans = climbStairs(n-1) + climbStairs(n-2);  

        return ans; 
    } 
};

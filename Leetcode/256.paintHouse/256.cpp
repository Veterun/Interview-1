There are a row of n houses, each house can be painted with one of the three colors:
red, blue or green. The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color.
The cost of painting each house with a certain color is represented by a n x 3 cost matrix.
For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green,
and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

************************************************
int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int n = costs.size(), r = 0, g = 0, b = 0;
        for (int i = 0; i < n; i++) {
            int rr = r, bb = b, gg = g; 
            r = costs[i][0] + min(bb, gg);
            b = costs[i][1] + min(rr, gg);
            g = costs[i][2] + min(rr, bb);
        }
        return min(r, min(b, g));
    } 
    
    int minCost(vector<vector<int>>& costs) {
     int n = costs.size();
     vector< vector<int> > minprice(n + 1, vector<int>(3, 0));
     for (int i = 1; i <= n; ++i)
     {
     	minprice[i][0] = min (minprice[i - 1][1], minprice[i - 1][2]) + costs[i][0];
     	minprice[i][1] = min (minprice[i - 1][0], minprice[i - 1][2]) + costs[i][1];
     	minprice[i][2] = min (minprice[i - 1][0], minprice[i - 1][1]) + costs[i][2];
     }
     return min(minprice[n][0], min(minprice[n][1], minprice[n][2]));
    }

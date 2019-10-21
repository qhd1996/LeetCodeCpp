//Two Pouinters
//Time Complexity O(n)
//Space Complexity O(1)

class Solution
{
public:
    int maxArea(vector<int> &height){
        int i = 0, j = height.size() - 1, water = 0;
        while (i < j)
        {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j)
                i++;
            while (height[j] <= h && i < j)
                j--;
        }
        return water;
    }
};

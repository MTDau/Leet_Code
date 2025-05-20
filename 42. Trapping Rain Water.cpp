#include <vector>
#include <algorithm>

class Solution
{
public:
    int trap(std::vector<int> &height)
    {
        int size = height.size();
        if (size == 0 || size == 1)
            return 0;
        int pil_l{}, pil_r{}, left{}, right{size - 1};
        int vol{};
        while (left < right)
        {
            pil_l = std::max(pil_l, height[left]);
            pil_r = std::max(pil_r, height[right]);
            if (pil_l < pil_r){
                vol = vol + pil_l - height[left];
                left++;
            }
            else{
                vol = vol + pil_r - height[right];
                right--;
            }
        }
        return vol;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area{0};
        int leftptr = 0;
        int rightptr = height.size() - 1;
        while (leftptr < rightptr) {
            int width = rightptr - leftptr;
            int side = min(height[leftptr], height[rightptr]);
            max_area =
                max(max_area, width * side);
            if (height[leftptr] > height[rightptr]) {
                rightptr--;
            } else {
                leftptr++;
            }
        }
        return max_area;
    }
};

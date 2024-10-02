class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size3 = size1 + size2;
        std::vector<int> nums3(size3);
        int i{}, j{}, k{};
        // Find the smaller numbers and put it to the front.
        while (i < size1 && j < size2) {
            if (nums1.at(i) < nums2.at(j)) {
                nums3.at(k++) = nums1.at(i++);
            } else {
                nums3.at(k++) = nums2.at(j++);
            }
        }
        // In case of there are numbers left in the two vectors.
        while (i < size1) {
            nums3.at(k++) = nums1.at(i++);
        }
        while (j < size2) {
            nums3.at(k++) = nums2.at(j++);
        }

        if (size3 % 2 == 0) {
            double sum = nums3.at(size3 / 2) + nums3.at(size3 / 2 - 1);
            return sum / 2;
        } else
            return static_cast<double>(nums3.at(size3 / 2));
    }
};


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>

class Solution
{
public:
	std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
	{
		std::sort(nums.begin(), nums.end());
		std::vector<std::vector<int>> ans{};

		int size = nums.size();

		for (int i{}; i < size - 3; i++)
		{ // first pointer and leave 3 element for the next 3.
			for (int j{i + 1}; j < size - 2; j++)
			{						 // second pointer and leave 2 element for the next 2.
				int left{j + 1};	 // third pointer.
				int right{size - 1}; // fourth pointer.
				while (left < right)
				{
					std::int64_t sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];
					if (sum == target)
					{
						ans.push_back({nums[i], nums[j], nums[left], nums[right]});

						// Check for duplicate
						// Left pointer
						while ((left + 1) < right && nums[left] == nums[left + 1])
						{
							left++;
						}
						left++; // Move right after no duplicate
						// Right pointer
						while (right - 1 > j && nums[right] == nums[right - 1])
						{
							right--;
						}
						right--; // Move left after no duplicate
					}
					else if (sum < target)
					{
						left++;
					}
					else if (sum > target)
					{
						right--;
					}
				}
				// Check for duplicate second pointer.
				while (j + 1 < size && nums[j] == nums[j + 1])
				{
					j++;
				}
			}
			// Check for duplicate of first pointer.
			while (i + 1 < size && nums[i] == nums[i + 1])
			{
				i++;
			}
		}
		return ans;
	}
};

int main()
{
	Solution a;
	std::vector<int> nums{1, 0, -1, 0, -2, 2};
	int target = 0;
	std::vector<std::vector<int>> answer = a.fourSum(nums, target);
	for (const auto &row : answer)
	{
		for (const auto &elem : row)
		{
			std::cout << elem << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

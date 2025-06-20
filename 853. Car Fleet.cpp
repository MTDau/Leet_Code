#include <vector>
#include <stack>
#include <algorithm>

class Solution
{
public:
    int carFleet(int target, std::vector<int> &position, std::vector<int> &speed)
    {
        std::vector<std::vector<int>> cars; // {position, speed}
        for (int i = 0; i < position.size(); i++)
        {
            cars.push_back({position[i], speed[i]});
        }
        std::sort(cars.rbegin(), cars.rend()); // Sort in descending position.
        std::vector<double> times;
        for (auto &car : cars)
        {
            times.push_back(static_cast<double>(target - car[0]) / car[1]);
            // Only need to check the next 2 car that further away.
            if (times.size() > 1 && times[times.size() - 1] <= times[times.size() - 2])
            {
                // Two car become one fleet so pop the one that have sorter time complete.
                times.pop_back();
            }
        }
        return times.size();
    }
};

std::vector<std::vector<int>> cars; // {position, speed}
        for (int i = 0; i < position.size(); i++)
        {
            cars.push_back({position[i], speed[i]});
        }
        std::sort(cars.rbegin(), cars.rend()); // Sort in descending position.
        int fleets{};
        double prev_time{};
        for (auto &car : cars)
        {
            double curr_time = (double)(target - car[0]) / car[1];
            if (curr_time > prev_time)
            {
                fleets++;
                prev_time = curr_time;
            }
        }
        return fleets;

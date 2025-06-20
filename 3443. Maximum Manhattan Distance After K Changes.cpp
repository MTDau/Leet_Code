class Solution
{
public:
    int maxDistance(std::string s, int k)
    {
        int n{}, w{}, e{}, so{};
        int move{1}, ans{};
        for (auto &c : s)
        {
            switch (c)
            {
            case 'N':
                n++;
                break;
            case 'W':
                w++;
                break;
            case 'E':
                e++;
                break;
            case 'S':
                so++;
                break;
            default:
                break;
            }
            int x{abs(n - so)};
            int y{abs(w - e)};
            int dis = x + y;
            int curr_max = dis + std::min(2*k, move - dis);
            ans = std::max(curr_max,ans);
            move++;
        }
        return ans;
    }
};

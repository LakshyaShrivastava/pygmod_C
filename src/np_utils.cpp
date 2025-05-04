#include <np_utils.hpp>

std::vector<int> unravel_index(int index, const std::vector<int>& shape)
{
    std::vector<int> result;
    for (auto it = shape.rbegin(); it != shape.rend(); it++)
    {
        result.insert(result.begin(),  index % *it);
        index /= *it;
    }
    return result;
}

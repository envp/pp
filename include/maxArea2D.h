#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers");
#else

#include <vector>

namespace p011 {
class Solution {
public:
  int maxArea(std::vector<int> &height) {
    if (height.empty()) {
      return 0;
    }

    int i = 0, j = height.size();
    int maximum = -1;
    while (i < j) {
      maximum = std::max(maximum, std::min(height[j], height[i]) * (j - i));
      if (height[i] < height[j]) {
        ++i;
      } else {
        --j;
      }
    }
    return maximum;
  }
};
}

#endif

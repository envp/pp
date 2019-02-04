#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers together!")
#endif // INCLUDED_SOLUTION_HEADER

#if !defined(INCLUDED_SOLUTION_HEADER)
#define INCLUDED_SOLUTION_HEADER "003"

#include <map>
#include <string>

class Solution {
private:
  int max(int a, int b) { return a > b ? a : b; }

public:
  int lengthOfLongestSubstring(std::string s) {
    if (s.size() < 2) {
      return s.size();
    }
    int maxLen = 0;
    std::map<char, int> lastIdx;

    for (int i = 0, j = 0; j < s.size(); ++j) {
      if (lastIdx.find(s[j]) != std::end(lastIdx)) {
        // Ensure `i` can only move forwards
        i = max(i, lastIdx[s[j]] + 1);
      }
      lastIdx[s[j]] = j;
      maxLen = max(j - i + 1, maxLen);
    }

    return maxLen;
  }
};

#endif // INCLUDED_SOLUTION_HEADER
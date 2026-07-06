class Solution {
public:
    // Using a member variable is fine for performance, 
    // but ensure it's large enough (e.g., 1001 if stone weights go up to 1000)
    std::vector<int> freq;

    Solution() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(0);
    }

    int lastStoneWeight(vector<int>& stones) {
        // Reset the frequency vector to 0s each time
        freq.assign(1001, 0); 
        
        int maxStone = 0;
        for (int i : stones) {
            freq[i]++;
            if (i > maxStone) maxStone = i;
        }

        int first = maxStone;
        int second = maxStone;

        while (first > 0) {
            if (freq[first] % 2 == 0) {
                first--;
                continue;
            }

            int j = min(second, first - 1);
            while (j > 0 && freq[j] == 0) j--;
            
            if (j == 0) return first;
            
            second = j;
            freq[first]--;
            freq[second]--;
            freq[first - second]++;
            
            // Optimization: update first to be the maximum of the remaining 
            // or the newly created stone weight
            first = max(first - second, second);
        }
        return 0;
    }
};
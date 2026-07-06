class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // cout.tie(0);
    }
    int lastStoneWeight(vector<int>& stones) {
        vector<int>freq(101,0);

        for(auto&i:stones){
            freq[i]++;
        }
        int first=*max_element(stones.begin(),stones.end());
        int second=first;
        while(first>0){
            if(freq[first]%2==0){
                first--;
                continue;
            }
            int j=min(second,first-1);
            while(j>0&&freq[j]==0)j--;
            if(j==0)return first;
            second=j;
            freq[first]--;
            freq[second]--;
            freq[first-second]++;
            first=max(second,first-second);

        }
        return first;




    }
};

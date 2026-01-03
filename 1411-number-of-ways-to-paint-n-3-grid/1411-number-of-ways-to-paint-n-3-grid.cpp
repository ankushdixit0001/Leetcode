class Solution {
public:
    int numOfWays(int n)
    {
        //time complexity: O(n)
        //space complexity: O(1)

        const int MOD=1e9+7;

        //same: ways where a row has 2 colors same + 1 different (ABA)
        long long same=6;
        //diff: ways where all 3 colors are different (ABC)
        long long diff=6;

        for(int i=2;i<=n;i++)
        {
            //transition from previous row
            long long newSame= (same*3 + diff*2) % MOD;
            long long newDiff= (same*2 + diff*2) % MOD;

            //updating 'same' and 'diff'
            same=newSame;
            diff=newDiff;
        }

        //returning total ways for 'n' rows
        int ans=(same+diff) % MOD;
        return ans;
    }
};
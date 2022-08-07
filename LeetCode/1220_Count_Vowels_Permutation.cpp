class Solution 
{
public:
    
    static constexpr int MOD = 1e9 + 7;
    
    int countVowelPermutation(int n) 
    {
        // a -> e
        // e -> a, i
        // i -> a, e, o, u
        // o -> i, u
        // u -> a
        
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        
        while (--n)
        {
            int ta = (e + i + u) % MOD, te = (a + i) % MOD, ti = (e + o) % MOD, to = (i) % MOD, tu = (i + o) % MOD;
            a = ta;
            e = te;
            i = ti;
            o = to;
            u = tu;
        }
        
        return (a + e + i + o + u) % MOD;
    }
};
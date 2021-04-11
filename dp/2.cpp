/*
addition = a+b = a%mod +b%mod %mod;
subtraztion =   a%mod - b%mod = c if < 0 -> c+m % m ;
muti - >  a%mod * b%mod %mod;

dividion -> m - m/i * inv[m%i] % m; 
*/

int nCr(int n, int r)
{
    if (r > n)
        return 0;

    -vector<long long int> fact(n + 1);

    fact[0] = 1;
    fact[1] = 1;

    long long int ans = 1;

    for (int i = n; i >= n - r + 1; i--)
    {
        ans = (ans * i) % mod;
    }

    vector<long long int> inv(r + 1);

    inv[1] = 1;

    for (int i = 2; i <= r; i++)
    {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }

    for (int i = 2; i <= r; i++)
    {
        ans = ((ans % mod) * (inv[i] % mod)) % mod;
    }
    return ans;

    // here the main concept was the modular inversion
    /**/
    /*
 a/b == a%mod * inv[b]%mod %mod
*/
}

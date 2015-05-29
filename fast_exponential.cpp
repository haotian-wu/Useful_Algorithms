/* returns (base**exp) % mod. */
int exp_mod(int base, int exp, int mod)
{
    /* Returns 1 if base == 0 && exp == 0*/
    long long ans = 1;
    int a = base;
    while (exp)
    {
        if (exp & 0x1) ans = ans * a % mod;
        a = (long long) a * a % mod;
        exp >>= 1;
    }
    return (int) ans;
}

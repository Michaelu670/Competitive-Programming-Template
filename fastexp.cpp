long long fastexp (long long x, long long e) {
    if (!e) return 1;
    long long ret = fastexp(x, e / 2);
    ret = ret * ret % MOD;
    if (e % 2) ret = ret * x % MOD;
    return ret;
}
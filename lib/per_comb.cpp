struct PCMod {
    vector<ll> fact, inv, finv;

    PCMod(int n) : fact(n + 1), inv(n + 1), finv(n + 1) {
      fact[0] = 1;
      fact[1] = 1;
      inv[0] = 1;
      inv[1] = 1;
      finv[0] = 1;
      finv[1] = 1;

      FOR(i, 2, n + 1) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
      }
    }

    ll P(int m, int n) {
      if (m < n) return 0;
      return fact[m] * finv[m - n] % MOD;
    }

    ll C(int m, int n) {
      if (m < n) return 0;
      return fact[m] * (finv[n] * finv[m - n] % MOD) % MOD;
    }

};

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n) {
      REP(i, n) par[i] = i;
    }

    int root(int x) {
      return par[x] == x ? x : par[x] = root(par[x]);
    }

    bool same(int x, int y) {
      return root(x) == root(y);
    }

    void unite(int x, int y) {
      x = root(x);
      y = root(y);

      if (x == y) return;

      par[x] = y;
    }
};

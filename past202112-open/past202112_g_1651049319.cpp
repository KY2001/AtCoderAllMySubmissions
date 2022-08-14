// clang-format off
#include <bits/stdc++.h>
//#pragma GCC optimize ("-Ofast")
//#pragma GCC optimize ("unroll-loops")
#define int long long
#define endl '\n'
//#define double __float80
using namespace std;
#define fi first
#define se second
#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; i++)
#define rep2(i, a, b) for (int i = (int)(a), i##_len=(b); i < i##_len; i++)
#define rep3(i, a, b) for (int i = (int)(a), i##_len=(b); i >= i##_len; i--)
#define rfor(i, a) for (auto &i: a)
#define all(obj) begin(obj), end(obj)
#define _max(x) *max_element(all(x))
#define _min(x) *min_element(all(x))
#define _sum(x) accumulate(all(x), 0LL)

const int MOD   = 1000000007;
// const int MOD    = 998244353;
// const int INF    = 1e18;
// const int INF    = 1e13 + 7;
// const int INF    = LLONG_MAX; // 9.2e18
const double EPS = 1e-20;
const double PI  = 3.14159265358979;
template <class T> using V = vector<T>;
template <class T> using VV = vector<vector<T>>;
template <class T> using VVV = vector<vector<vector<T>>>;
template <class T, class S>  using P = pair<T, S>;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return true;}return false;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return true;}return false;}
int _ceil(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); }
template<class T> T chmod(T &a, T mod=MOD) {a =  a >= 0 ? a % mod : a - (mod * _ceil(a, mod)); return a;};
int _mod(int a, int mod=MOD) {return a >= 0 ? a % mod : a - (mod * _ceil(a, mod));}
double _mod(double a, int mod = MOD) { return fmod(a, mod) >= 0 ? fmod(a, mod) : fmod(a, mod) + mod; }
int _pow(int a, int b, int mod=MOD) {int res = 1;for (a %= mod; b; a = a * a % mod, b >>= 1)if (b & 1) res = res * a % mod;return res;}
vector<int> iota(int n){vector<int> ret(n); iota(begin(ret), end(ret), 0); return ret;}
struct mint {long long x;mint(long long x = 0): x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) {(x *= a.x) %= MOD;return *this;}mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; }mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long n) const {mint ret(1), mul(x);while (n > 0) {if (n & 1) ret *= mul;mul *= mul;n >>= 1;}return ret;}mint inv() const {int a = x, b = MOD, u = 1, v = 0, t;while (b > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);}return mint(u);}mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }bool operator==(const mint a) const { return x == a.x; }bool operator!=(const mint a) const { return x != a.x; }friend istream &operator>>(istream &is, mint &a) { return is >> a.x; }friend ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }};
// clang-format on

template<typename T>
class dynamic_connectivity {
    class euler_tour_tree {
      public:
        struct node;
        using np   = node *;
        using lint = long long;
        struct node {
            np ch[2] = {nullptr, nullptr};
            np p     = nullptr;
            int l, r, sz;
            T val = et, sum = et;
            bool exact;
            bool child_exact;
            bool edge_connected       = 0;
            bool child_edge_connected = 0;
            node() {}
            node(int l, int r): l(l), r(r), sz(l == r), exact(l < r), child_exact(l < r) {}
            bool is_root() {
                return !p;
            }
        };
        vector<unordered_map<int, np>> ptr;
        np get_node(int l, int r) {
            if (ptr[l].find(r) == ptr[l].end()) ptr[l][r] = new node(l, r);
            return ptr[l][r];
        }
        np root(np t) {
            if (!t) return t;
            while (t->p) t = t->p;
            return t;
        }
        bool same(np s, np t) {
            if (s) splay(s);
            if (t) splay(t);
            return root(s) == root(t);
        }
        np reroot(np t) {
            auto s = split(t);
            return merge(s.second, s.first);
        }
        pair<np, np> split(np s) {
            splay(s);
            np t = s->ch[0];
            if (t) t->p = nullptr;
            s->ch[0] = nullptr;
            return {t, update(s)};
        }
        pair<np, np> split2(np s) {
            splay(s);
            np t = s->ch[0];
            np u = s->ch[1];
            if (t) t->p = nullptr;
            s->ch[0] = nullptr;
            if (u) u->p = nullptr;
            s->ch[1] = nullptr;
            return {t, u};
        }
        tuple<np, np, np> split(np s, np t) {
            auto u = split2(s);
            if (same(u.first, t)) {
                auto r = split2(t);
                return make_tuple(r.first, r.second, u.second);
            } else {
                auto r = split2(t);
                return make_tuple(u.first, r.first, r.second);
            }
        }
        template<typename First, typename... Rest>
        np merge(First s, Rest... t) {
            return merge(s, merge(t...));
        }
        np merge(np s, np t) {
            if (!s) return t;
            if (!t) return s;
            while (s->ch[1]) s = s->ch[1];
            splay(s);
            s->ch[1] = t;
            if (t) t->p = s;
            return update(s);
        }
        int size(np t) { return t ? t->sz : 0; }
        np update(np t) {
            t->sum = et;
            if (t->ch[0]) t->sum = fn(t->sum, t->ch[0]->sum);
            if (t->l == t->r) t->sum = fn(t->sum, t->val);
            if (t->ch[1]) t->sum = fn(t->sum, t->ch[1]->sum);
            t->sz                   = size(t->ch[0]) + (t->l == t->r) + size(t->ch[1]);
            t->child_edge_connected = (t->ch[0] ? t->ch[0]->child_edge_connected : 0) | (t->edge_connected) | (t->ch[1] ? t->ch[1]->child_edge_connected : 0);
            t->child_exact          = (t->ch[0] ? t->ch[0]->child_exact : 0) | (t->exact) | (t->ch[1] ? t->ch[1]->child_exact : 0);
            return t;
        }
        void push(np t) {
            //遅延評価予定
        }
        void rot(np t, bool b) {
            np x = t->p, y = x->p;
            if ((x->ch[1 - b] = t->ch[b])) t->ch[b]->p = x;
            t->ch[b] = x, x->p = t;
            update(x);
            update(t);
            if ((t->p = y)) {
                if (y->ch[0] == x) y->ch[0] = t;
                if (y->ch[1] == x) y->ch[1] = t;
                update(y);
            }
        }
        void splay(np t) {
            push(t);
            while (!t->is_root()) {
                np q = t->p;
                if (q->is_root()) {
                    push(q), push(t);
                    rot(t, q->ch[0] == t);
                } else {
                    np r = q->p;
                    push(r), push(q), push(t);
                    bool b = r->ch[0] == q;
                    if (q->ch[1 - b] == t)
                        rot(q, b), rot(t, b);
                    else
                        rot(t, 1 - b), rot(t, b);
                }
            }
        }
        void debug(np t) {
            if (!t) return;
            debug(t->ch[0]);
            cerr << t->l << "-" << t->r << " ";
            debug(t->ch[1]);
        }

      public:
        euler_tour_tree() {}
        euler_tour_tree(int sz) {
            ptr.resize(sz);
            for (int i = 0; i < sz; i++) ptr[i][i] = new node(i, i);
        }
        int size(int s) {
            np t = get_node(s, s);
            splay(t);
            return t->sz;
        }
        bool same(int s, int t) {
            return same(get_node(s, s), get_node(t, t));
        }
        void set_size(int sz) {
            ptr.resize(sz);
            for (int i = 0; i < sz; i++) ptr[i][i] = new node(i, i);
        }
        void update(int s, T x) {
            np t = get_node(s, s);
            splay(t);
            t->val = fn(t->val, x);
            update(t);
        }
        void edge_update(int s, auto g) {
            np t = get_node(s, s);
            splay(t);
            function<void(np)> dfs = [&](np t) {
                assert(t);
                if (t->l < t->r && t->exact) {
                    splay(t);
                    t->exact = 0;
                    update(t);
                    g(t->l, t->r);
                    return;
                }
                if (t->ch[0] && t->ch[0]->child_exact)
                    dfs(t->ch[0]);
                else
                    dfs(t->ch[1]);
            };
            while (t && t->child_exact) {
                dfs(t);
                splay(t);
            }
        }
        bool try_reconnect(int s, auto f) {
            np t = get_node(s, s);
            splay(t);
            function<bool(np)> dfs = [&](np t) -> bool {
                assert(t);
                if (t->edge_connected) {
                    splay(t);
                    return f(t->l);
                }
                if (t->ch[0] && t->ch[0]->child_edge_connected)
                    return dfs(t->ch[0]);
                else
                    return dfs(t->ch[1]);
            };
            while (t->child_edge_connected) {
                if (dfs(t)) return 1;
                splay(t);
            }
            return 0;
        }
        void edge_connected_update(int s, bool b) {
            np t = get_node(s, s);
            splay(t);
            t->edge_connected = b;
            update(t);
        }
        bool link(int l, int r) {
            if (same(l, r)) return 0;
            merge(reroot(get_node(l, l)), get_node(l, r), reroot(get_node(r, r)), get_node(r, l));
            return 1;
        }
        bool cut(int l, int r) {
            if (ptr[l].find(r) == ptr[l].end()) return 0;
            np s, t, u;
            tie(s, t, u) = split(get_node(l, r), get_node(r, l));
            merge(s, u);
            np p = ptr[l][r];
            np q = ptr[r][l];
            ptr[l].erase(r);
            ptr[r].erase(l);
            delete p;
            delete q;
            return 1;
        }
        T get_sum(int p, int v) {
            cut(p, v);
            np t = get_node(v, v);
            splay(t);
            T res = t->sum;
            link(p, v);
            return res;
        }
        T get_sum(int s) {
            np t = get_node(s, s);
            splay(t);
            return t->sum;
        }
    };
    int dep = 1;
    vector<euler_tour_tree> ett;
    vector<vector<unordered_set<int>>> edges;
    int sz;

  public:
    dynamic_connectivity(int sz): sz(sz) {
        ett.emplace_back(sz);
        edges.emplace_back(sz);
    }
    bool link(int s, int t) {
        if (s == t) return 0;
        if (ett[0].link(s, t)) return 1;
        edges[0][s].insert(t);
        edges[0][t].insert(s);
        if (edges[0][s].size() == 1) ett[0].edge_connected_update(s, 1);
        if (edges[0][t].size() == 1) ett[0].edge_connected_update(t, 1);
        return 0;
    }
    bool same(int s, int t) {
        return ett[0].same(s, t);
    }
    int size(int s) {
        return ett[0].size(s);
    }
    vector<int> get_vertex(int s) {
        return ett[0].vertex_list(s);
    }
    void update(int s, T x) {
        ett[0].update(s, x);
    }
    T get_sum(int s) {
        return ett[0].get_sum(s);
    }
    bool cut(int s, int t) {
        if (s == t) return 0;
        for (int i = 0; i < dep; i++) {
            edges[i][s].erase(t);
            edges[i][t].erase(s);
            if (edges[i][s].size() == 0) ett[i].edge_connected_update(s, 0);
            if (edges[i][t].size() == 0) ett[i].edge_connected_update(t, 0);
        }
        for (int i = dep - 1; i >= 0; i--) {
            if (ett[i].cut(s, t)) {
                if (dep - 1 == i) {
                    dep++;
                    ett.emplace_back(sz);
                    edges.emplace_back(sz);
                }
                return !try_reconnect(s, t, i);
            }
        }
        return 0;
    }
    bool try_reconnect(int s, int t, int k) {
        for (int i = 0; i < k; i++) {
            ett[i].cut(s, t);
        }
        for (int i = k; i >= 0; i--) {
            if (ett[i].size(s) > ett[i].size(t)) swap(s, t);
            auto g = [&](int s, int t) { ett[i + 1].link(s, t); };
            ett[i].edge_update(s, g);
            auto f = [&](int x) -> bool {
                for (auto itr = edges[i][x].begin(); itr != edges[i][x].end();) {
                    auto y = *itr;
                    itr    = edges[i][x].erase(itr);
                    edges[i][y].erase(x);
                    if (edges[i][x].size() == 0) ett[i].edge_connected_update(x, 0);
                    if (edges[i][y].size() == 0) ett[i].edge_connected_update(y, 0);
                    if (ett[i].same(x, y)) {
                        edges[i + 1][x].insert(y);
                        edges[i + 1][y].insert(x);
                        if (edges[i + 1][x].size() == 1) ett[i + 1].edge_connected_update(x, 1);
                        if (edges[i + 1][y].size() == 1) ett[i + 1].edge_connected_update(y, 1);
                    } else {
                        for (int j = 0; j <= i; j++) {
                            ett[j].link(x, y);
                        }
                        return 1;
                    }
                }
                return 0;
            };
            if (ett[i].try_reconnect(s, f)) return 1;
        }
        return 0;
    }
    constexpr static T et = T();
    constexpr static T fn(T s, T t) {
        return s + t;
    }
};

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N, Q, q, u, v;
    cin >> N >> Q;
    dynamic_connectivity<int> uf(N);
    VV<bool> connect(N, V<bool>(N));
    rep(i, Q) {
        cin >> q >> u >> v;
        u--, v--;
        if (q == 1) {
            if (connect[u][v]) {
                connect[u][v] = false;
                connect[v][u] = false;
                uf.cut(u, v);
            } else {
                connect[u][v] = true;
                connect[v][u] = true;
                uf.link(u, v);
            }
        } else {
            if (uf.same(u, v)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}
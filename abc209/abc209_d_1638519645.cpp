#include <bits/stdc++.h>
#define int long long
#define endl '\n'
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

struct tree {            // 重み付き木構造
    struct SegmentTree { // LCA用のセグ木
        int n            = 1;
        vector<int> init = {(int)1e18, (int)1e18};
        vector<vector<int>> data;
        void construct(vector<vector<int>> &v) {
            while (n < v.size()) n *= 2;
            data.assign(2 * n - 1, init);
            for (int i = 0; i < v.size(); i++) data[i + n - 1] = v[i];
            for (int i = n - 2; i >= 0; i--) data[i] = min(data[2 * i + 1], data[2 * i + 2]);
        }
        vector<int> get_min(int L, int R, int k = 0, int l = 0, int r = -1) { //[L, R)
            if (r < 0) r = n;
            if (r <= L || R <= l) return init;
            if (L <= l and r <= R) return data[k];
            return min(get_min(L, R, 2 * k + 1, l, (l + r) / 2), get_min(L, R, 2 * k + 2, (l + r) / 2, r));
        }
    };
    template<class T> struct BIT { // ノード間距離算出用のBIT
        vector<T> data;
        int n;
        int s = 1;
        void construct(int N) {
            n = N;
            data.assign(n, 0);
            while (s * 2 <= n) { s *= 2; };
        }
        T sum(int R) { // return sum of [0, R);
            T ret = 0;
            for (--R; R >= 0; R = (R & (R + 1)) - 1) ret += data[R];
            return ret;
        }
        T sum(int L, int R) { return sum(R) - sum(L); } //return sum of [L, R);
        void add(int ind, T val) {
            for (; ind < n; ind |= ind + 1) data[ind] += val;
        }
    };
    vector<vector<vector<int>>> graph; // 木の隣接リスト
    vector<int> visit;                 // DFSで順に訪れた頂点
    vector<int> e_cost1;               // 初めて通った辺のコスト or 0
    vector<int> e_cost2;               // 初めて通った辺のコスト or -戻るときの辺のコスト
    vector<int> depth;                 // その頂点の深さ
    vector<int> in;                    // 頂点iに最初に着いた時刻
    vector<int> out;                   // 頂点iに最後に着いた時刻
    SegmentTree seg;                   // LCA用のRMQセグ木
    vector<vector<int>> depth_index;   // LCA用の{depth, index}
    BIT<int> bit1;
    BIT<int> bit2;

  private:
    void recursion(int now, int d, int dis) { // オイラーツアー構築用の再帰関数
        visit.emplace_back(now);
        if (in[now] == -1) {
            in[now] = visit.size() - 1;
            e_cost1.emplace_back(dis);
            e_cost2.emplace_back(dis);
        }
        depth.emplace_back(d);
        for (auto &i: graph[now]) {
            if (in[i[0]] != -1) continue;
            recursion(i[0], d + 1, i[1]);
            visit.emplace_back(now);
            e_cost1.emplace_back(0);
            e_cost2.emplace_back(-i[1]);
            depth.emplace_back(d);
        }
        out[now] = visit.size();
    }
    void Euler_Tour() { // オイラーツアーを構築
        in.assign(graph.size(), -1);
        out.assign(graph.size(), 0);
        recursion(0, 0, 0);
    }
    void LCA_init() { // LCA用
        depth_index.assign(visit.size(), vector<int>(2));
        for (int i = 0; i < visit.size(); i++) depth_index[i] = {depth[i], visit[i]};
        seg.construct(depth_index);
    }
    void dis_init() { // ノード間距離算出用
        bit1.construct(visit.size());
        for (int i = 0; i < e_cost2.size(); i++) bit1.add(i, e_cost2[i]);
    }
    void subtree_init() { // 部分木の辺の重みの総和算出用
        bit2.construct(visit.size());
        for (int i = 0; i < e_cost1.size(); i++) bit2.add(i, e_cost1[i]);
    }

  public:
    tree(vector<vector<vector<int>>> &graph): graph(graph) {
        Euler_Tour();   // 使わない場合削除
        LCA_init();     //使わない場合削除
        dis_init();     //使わない場合削除
        subtree_init(); //使わない場合削除
    }
    int LCA(int a, int b) { // 頂点aとbのLCAを計算(前計算にEuler_Tour(), LCA_init()) O(logN)
        return seg.get_min(min(in[a], in[b]), max(out[a], out[b]))[1];
    }
    int distance_from_root(int a) { // 根(0)からaへの距離(前計算にEuler_Tour(), dis_init()) O(logN)
        return bit1.sum(in[a] + 1);
    }
    int distance_of_nodes(int a, int b) { // ノードa, b間の距離(前計算にEuler_Tour(), dis_init()) O(logN)
        return distance_from_root(a) + distance_from_root(b) - 2 * distance_from_root(LCA(a, b));
    }
    int total_weight_of_subtree(int a) { // ノードaを根とする部分木の辺の重みの総和
        return bit2.sum(in[a] + 1, out[a]);
    }
};
class DCollision {
  public:
    static void solve(istream &cin, ostream &cout) {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
        int N, Q, a, b, c, d;
        cin >> N >> Q;
        VVV<int> graph(N);
        rep(i, N - 1) {
            cin >> a >> b;
            graph[a - 1].push_back({b - 1, 1});
            graph[b - 1].push_back({a - 1, 1});
        }
        tree Tree(graph);
        rep(i, Q) {
            cin >> c >> d;
            if (Tree.distance_of_nodes(c - 1, d - 1) % 2) {
                cout << "Road" << endl;
            } else {
                cout << "Town" << endl;
            }
        }
    }
};


signed main() {
  DCollision solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}

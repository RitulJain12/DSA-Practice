class Dsu {
public:
    vector<int> p, s;

    Dsu(int n) {
        p.resize(n + 1);
        s.resize(n + 1, 1);

        for (int i = 1; i <= n; i++)
            p[i] = i;
    }

    int find(int a) {
        if (p[a] == a) return a;
        return p[a] = find(p[a]);
    }

    bool uni(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (s[a] < s[b])
            swap(a, b);

        p[b] = a;
        s[a] += s[b];

        return true;
    }

    int getmax() {
        int ans = 0;
        for (int i = 1; i < s.size(); i++)
            ans = max(ans, s[i]);
        return ans;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        Dsu type1(n), type2(n);

        // Type 3 edges first
        sort(edges.begin(), edges.end(), greater<vector<int>>());

        int used = 0;

        for (auto &e : edges) {

            int type = e[0];
            int u = e[1];
            int v = e[2];

            if (type == 3) {

                bool a = type1.uni(u, v);
                bool b = type2.uni(u, v);

                if (a || b)
                    used++;
            }
            else if (type == 1) {

                if (type1.uni(u, v))
                    used++;
            }
            else {

                if (type2.uni(u, v))
                    used++;
            }
        }

        if (type1.getmax() != n || type2.getmax() != n)
            return -1;

        return edges.size() - used;
    }
};
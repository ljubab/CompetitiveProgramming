class Dsu {
private:
    vector<int> par, vel;       
    int n;
public:
    Dsu(int n2) {
        n = n2;
        vel.assign(n, 1);
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }

    int find_set(int a) {
        if(par[a] == a)
            return a;
        return par[a] = find_set(par[par[a]]);
    }

    bool unite(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if(a == b) {
            return 0;
        }

        if(vel[a] > vel[b]) {
            swap(a, b);
        }

        vel[b] += vel[a];
        par[a] = b;
        return 1;
    }
};

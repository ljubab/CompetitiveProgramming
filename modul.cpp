#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

//mislim da ipak necu koristiti ovaj kod, izgleda previse komplikovano o_O

struct Modular
{
    int value;

    Modular(long long v = 0){value = v % MOD; if(value < 0) value += MOD;}
    Modular(long long a, long long b) : value(0) {*this += a; *this /= b;}

    Modular& operator+=(Modular const &b) {value += b.value; if(value >= MOD) value -= MOD; return *this;}
    Modular& operator-=(Modular const &b) {value -= b.value; if(value < 0) value += MOD; return *this;}
    Modular& operator*=(Modular const &b) {value = value * 1LL * b.value % MOD; return *this;}

    friend Modular modPow(Modular a, long long b)
    {
        Modular res = 1;
        while(b)
        {
            if(b & 1)
                res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }

    //ovo radi samo kada je MOD prost.
    //PROVERI DA LI JE MOD PROST!!!!!!!
    friend Modular inverse(Modular a) {return modPow(a, MOD-2);}

    Modular& operator/=(Modular const &b) {return *this *= inverse(b);}
    friend Modular operator+(Modular a, Modular const b) {return a += b;}
    friend Modular operator-(Modular a, Modular const b) {return a -= b;}
    friend Modular operator-(Modular a){return 0 - a;}
    friend Modular operator*(Modular a, Modular const b) {return a *= b;}
    friend Modular operator/(Modular a, Modular const b) {return a /= b;}

    friend std::ostream& operator<<(std::ostream& os, Modular const &a) {return os << a.value;}

    friend bool operator==(Modular const &a, Modular const &b){return a.value == b.value;}
    friend bool operator!=(Modular const &a, Modular const &b){return a.value != b.value;}
};

int main()
{
    Modular a(MOD-1), b = (2);
    cout << a + b << endl;
}

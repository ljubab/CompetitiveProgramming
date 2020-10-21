#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

struct Determinanta
{
    int n;
    vector<vector<double>> a;

    Determinanta(int vel, vector<vector<double>> v) : n(vel), a(v)
    {

    }

    Determinanta(vector<vector<double>> v) : Determinanta((int)v.size(), v)
    {

    }

    void print()
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(j > 0)
                {
                    cout << " ";
                }
                cout << a[i][j];
            }
            cout << endl;
        }
    }

    double operator()()
    {
        if(n == 1)
        {
            return a[0][0];
        }

        double ans = 0;

        for(int i = 0; i < n; ++i)
        {
            double tren = ((i%2 == 0) ? 1 : -1);
            tren *= a[0][i];

            vector<vector<double>> temp;

            for(int j = 1; j < n; ++j)
            {
                vector<double> temp2;
                for(int k = 0; k < n; ++k)
                {
                    if(k == i)
                        continue;
                    temp2.push_back(a[j][k]);
                }
                temp.push_back(temp2);
            }

            Determinanta deter(temp);
            double vrednost = deter();
            ans += vrednost * tren;
        }
        return ans;
    }
};

struct Matrica
{
    int n, m;
    vector<vector<double>> a;
    //predpostavljam da ce korisnik pravilno da koristi program
    Matrica(int sirina, int duzina, vector<vector<double>> v) : n(sirina), m(duzina), a(v)
    {

    }

    Matrica(vector<vector<double>> v) : a(v)
    {
        //predpostavljam da matrica nije prazna
        n = v.size();
        m = v[0].size();
    }

    void print()
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(j > 0)
                {
                    cout << " ";
                }
                cout << a[i][j];
            }
            cout << endl;
        }
    }

    Matrica operator*(double broj)
    {
        vector<vector<double>> temp = a;

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                temp[i][j] *= broj;
            }
        }

        return Matrica(temp);
    }

    void operator*=(int broj)
    {
        *this = *this * broj;
    }

    Matrica operator*(Matrica &b)
    {
        vector<vector<double>> temp(n, vector<double>(b.m, 0));

        for(int i = 0; i < temp.size(); ++i)
        {
            for(int j = 0; j < temp[i].size(); ++j)
            {
                for(int k = 0; k < m; ++k)
                {
                    temp[i][j] += a[i][k] * b.a[k][j];
                }
            }
        }

        return Matrica(temp);
    }

    void operator*=(Matrica &b)
    {
        *this = *this * b;
    }

    Matrica operator+(Matrica &b)
    {
        vector<vector<double>> temp = a;

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                temp[i][j] += b.a[i][j];
            }
        }

        return Matrica(temp);
    }

    void operator+=(Matrica &b)
    {
        *this = *this + b;
    }

    Matrica operator-(Matrica &b)
    {
        Matrica c = b * -1;
        return *this + c;
    }

    void operator-=(Matrica &b)
    {
        *this = *this - b;
    }

    void transponuj()
    {
        //napravicu da radi samo za kvadratnu
        //mrzi me za sve slucajeve

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(i <= j)
                    continue;
                swap(a[i][j], a[j][i]);
            }
        }
    }

    Matrica operator()()
    {
        Determinanta det(a);
        if(det() == 0)
        {
            cerr << "GRESKA\n";
            exit(0);
        }
        Matrica adjungovana(a);

        //izracunaj kofaktore

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                double tren = ((i+j)%2 == 0 ? 1 : -1);
                vector<vector<double>> temp;

                for(int k = 0; k < n; ++k)
                {
                    vector<double> temp2;
                    if(k == i)
                        continue;
                    for(int k2 = 0; k2 < m; ++k2)
                    {
                        if(k2 == j)
                            continue;
                        temp2.push_back(a[k][k2]);
                    }

                    if(!temp2.empty())
                    {
                        temp.push_back(temp2);
                    }
                }

                Determinanta deti(temp);
                tren *= deti();
                adjungovana.a[i][j] = tren;
            }
        }

        adjungovana.transponuj();

        return adjungovana * (1.00/det());
    }
};

int main()
{
    Matrica m(3, 3, {{1, -1, 1}, {2, 1, 1}, {1, 1, 2}});
    Matrica m2 = m();
    m2.print();
}

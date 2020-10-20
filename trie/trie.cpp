struct Trie
{
    static const int mxN = 1e5;
    int a[mxN+1][26];
    bool kraj[mxN+1];
    int ima = 0;

    //trie u kome se koriste pokazivaci izgleda fuj

    void init()
    {
        for(int i = 0; i <= mxN; ++i)
        {
            for(int j = 0; j < 26; ++j)
            {
                a[i][j] = -1;
            }
            kraj[i] = 0;
        }
    }

    void insert(string s)
    {
        int tren = 0;
        for(int i = 0; i < (int)s.size(); ++i)
        {
            if(a[tren][s[i]-'a'] == -1)
            {
                a[tren][s[i]-'a'] = ++ima;
            }
            tren = a[tren][s[i]-'a'];
        }
    }

    bool search(string s)
    {
        int tren = 0;
        for(int i = 0; i < (int)s.size(); ++i)
        {
            if(a[tren][s[i]-'a'] == -1)
            {
                return false;
            }

            tren = a[tren][s[i]-'a'];
        }

        return true;
    }
};

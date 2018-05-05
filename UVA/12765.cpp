#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int sz = 2e5 + 10;
const int inf = 1 << 25;

int n, m;
int ar[4];
int pr[4] = { 2, 3, 5, 7 };

void add( int x ) {
        for( int i=0; i<4; i++ ) {
                int h = pr[i];
                while( h <= x ) {
                        ar[i] += x / h;
                        h *= pr[i];
                }
        }
}

void del( int x ) {
        for( int i=0; i<4; i++ ) {
                int h = pr[i];
                while( h <= x ) {
                        ar[i] -= x / h;
                        h *= pr[i];
                }
        }
}

bool check() {
        bool ret = true;
        for( int i=0; i<4; i++ ) ret &= ( ar[i] == 0 );
        return ret;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        while( scanf( "%d %d", &n, &m ) == 2 && ( n + m ) ) {

                memset( ar, 0, sizeof ar );

                for( int i=0; i<n; i++ ) {
                        int x;
                        scanf( "%d", &x );
                        add( x );
                }

                for( int i=0; i<m; i++ ) {
                        int x;
                        scanf( "%d", &x );
                        del( x );
                }

                puts( check() ? "YES" : "NO" );

        }

        return 0;
}

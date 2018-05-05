/**
*       Solution Idea: Backtrack the columns.
                        For each column configuration, count number rows that still has targets.
                        if number of rows with targets is less then rooks, then we can rearrange the rooks to cover all the targets.
*
**/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int sz = 2e5 + 10;
const int inf = 1 << 25;

string s[15];
int ans;

int check( int mask ) {
        int row = 0;
        int col = __builtin_popcount( mask );
        for( int i=0; i<15; i++ ) {
                for( int j=0; j<15; j++ ) {
                        if( mask & ( 1 << j ) ) continue;
                        if( s[i][j] == '#' ) {
                                row++;
                                break;
                        }
                }
        }
        return row <= col ? col : 15;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        while( cin >> s[0] && s[0] != "END" ) {

                for( int i=1; i<15; i++ ) cin >> s[i];

                ans = 15;

                int chol = 1 << 15;

                for( int i=0; i<chol; i++ ) {
                        ans = min( ans, check( i ) );
                }

                cout << ans << "\n";

        }

        return 0;
}

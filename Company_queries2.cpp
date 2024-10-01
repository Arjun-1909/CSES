#include<iostream>
#include <fstream>     
#include <sstream>     
#include <iomanip>      // Input/output manipulators
#include <string>       // String class and functions
#include <vector>       // Dynamic array
#include <list>         // Doubly linked list
#include <set>          // Set container
#include <map>          // Map container
#include <queue>        // Queue container
#include <stack>        // Stack container
#include <algorithm>    // Algorithms on sequences (e.g., sort, find)
#include <cmath>        // Mathematical functions
#include <ctime>        // Date and time functions
#include <cstdlib>      // General purpose functions (e.g., memory management)
#include <cstring>      // C-style string functions
#include <cctype>       // Character classification functions
#include <cassert>      // Assert function for debugging
#include <exception>    // Standard exceptions
#include <functional>   // Function objects
#include <iterator>     // Iterator classes
#include <limits>       // Numeric limits
#include <locale>       // Localization and internationalization
#include <numeric>      // Numeric operations (e.g., accumulate)
#include <random>       // Random number generators
#include <stdexcept>    // Standard exception classes
#include <typeinfo>     // Runtime type information
#include <utility>   
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

 
//#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
//tree<pii, null_type, less<pii>, rb_tree_tag,
//tree_order_statistics_node_update> T;
typedef long long ll;
const int maxN = 2e5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
/*struct range{
    int l,r;
    bool operator<(const range &other) const{
        if(r==other.r)
        {
            return l>other.l;
        }
        return r<other.r;
    }
};*/
    vector<int> v; vector<int> adj[maxN+1]; int up[maxN+1][21];
    vector<int> in, out; int timer = 0;
  int n; int q;
  void dfs(int nod, int par){
    up[nod][0] = par;
    in[nod] = ++timer;

    for(int i = 1;i<=20;i++)
    {
        if(up[nod][i-1]!=-1)
        up[nod][i] = up[up[nod][i-1]][i-1];
        else
        up[nod][i] = -1;

    }
    for(int u : adj[nod]){
        if(u!=par) dfs(u,nod);
    }
    out[nod] =  ++timer;
    return;

  }

  bool isAnc(int x, int y){
    if(x==-1 || y==-1) return true;
    return in[x]<=in[y] && out[x]>=out[y] ;
  }
  int query(int x, int y){
    if(isAnc(x,y)) return x;
    if(isAnc(y,x)) return y;

    for(int i = 20;i>=0;i--){
        if(!isAnc(up[x][i],y)){
            x = up[x][i];
        }
    }
    return up[x][0];
  }




 


void solve(){
    int p;
    cin>>n;
    cin>>q;
    v.resize(n+1);
    in.resize(n+1);
    out.resize(n+1);
     
    

   
    
    
    for(int i = 2;i<=n;i++) {cin>>v[i]; adj[v[i]].push_back(i);}
    dfs(1,-1);
   // cout<<endl;
    while(q--){
        int x,y;
        
        
        cin>>x;cin>>y;
       
        cout<<query(x,y)<<endl;
    }

    
    
    
    
   
   
   
   

   
   


    return;
}





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1 ;
   // cin>>t;
    while(t--)
    {
        solve();

    }
 
   return 0;
}

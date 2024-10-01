
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
vector<int> v(maxN+1);  vector<int> sz(maxN+1); vector<int> adj[maxN+1];
 
 void dfs(int node){
    sz[node] = 1;
    for(int i : adj[node]){
        dfs(i);
        sz[node] += sz[i];
    }
 
 }
 
 
 
void solve(){
    int n;
    cin>>n;
   
    map<int,int> mp;
    
    for(int i = 2;i<=n;i++) {cin>>v[i]; adj[v[i]].push_back(i);}
 
    dfs(1);
   for(int i = 1;i<=n;i++) cout<<sz[i]-1<<" ";
 
 
 
 
}
 
 
 
 
 
int main(){
    int t =1;
    //cin>>t;
    while(t--)
    {
        solve();
 
    }
 
   return 0;
}

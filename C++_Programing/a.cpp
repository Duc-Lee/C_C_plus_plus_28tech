#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    // dung map de luu cac gia tri cua mang
    map<long long,bool> a;
    for(int i = 0;i<n;i++){
      long long x;
      cin >> x;
      a[x] = true;
    }
    // in ra ket qua
    for(int i = 0;i <n;i++){
      // 
      if(a[i]){
        cout << i << " ";
      }
      else{
        cout << -1 << " ";
      }
    }
    cout << endl;
  }
}
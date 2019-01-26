#include<bits/stdc++.h>
using namespace std;



double logn(double x){
  double totalValue = 0, z, power = 1, y;
  
  int it=2000;
  
  
  z = 1;
  
  int chang=0;
  if(x>2) 
   { x=1/x;
    chang=1;
   }
   double step = -(x - 1);
  while (power <= it){
      z *= step;
      y = (1 / power)*z;
      totalValue = totalValue + y;
      power = power + 1;
     
  }
  if(chang==0)
  return (-totalValue)/log(10);
 else
  return (totalValue)/log(10);
}

void prin(vector<pair<double,string> >v){
  sort(v.begin(),v.end());
  for(int i=0;i<v.size();i++){
    cout<<"("<<v[i].second<<" = "<<v[i].first<<")";
    if(i<v.size()-1)cout<<" <= ";
  }
  cout<<'\n';
}

int main(){
  int arr[]={0,1,10,100,1000,1000000};
  int n;
  double k;
  for(int i=0;i<6;i++){
    vector<pair<double,string> > v;
    n=arr[i];
    k=logn(1.0*n);
    v.push_back(make_pair(1.0*k,"log(n)"));
    v.push_back(make_pair(1.0*n,"n"));
    v.push_back(make_pair(1.0*n*k,"nlog(n)"));
    v.push_back(make_pair(1.0*n*n,"n^2"));
    v.push_back(make_pair(1.0*pow(2,n),"2^n"));
    cout<<"Sorted order for n="<<arr[i]<<":"<<endl;
    prin(v);
  }
  return 0;
}

#include <iostream>
using namespace std;

int main() {
      int out[6]={1,1,1,1};
   for (int i=0; i<6; i++){
      cout << i+1;
      out[i]+=i+1;
   }
   cout << endl;
   for (int i=0; i<6; i++){
      for (int j=3; j<=i; j++){
         cout << out[j];
      }  
   }
   return 0;
}
#include<iostream>
using namespace std;
int main() {
    int n; cin >> n;
     int temp;
    for(int x = -n; x <= n; x++){
        if(x <= 0) {
            for(int y = -n; y <= n; y++){
            temp = x;
            if (y >= -(n + temp) && y <= n + temp){
                cout<<"* ";
            }else{
                cout<<". ";
            }
        }
        cout<<endl;
        }
        else {
            for(int y = -n; y <= n; y++){
            temp = x - n;
            if( y >= temp && y <= -temp) {
                cout<<"* ";
            }
            else{
                cout<<". ";
            }}
            cout << endl;
        }
    }
    
}
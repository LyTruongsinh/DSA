#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
char result[26];   
bool used[26] = {false};  

void generate(int pos) {
    if (pos == K) {  
        for (int i = 0; i < K; i++) cout << result[i];
        cout << endl;
        return;
    }

    for (int i = 0; i < N; i++) {  
        if (!used[i]) {  
            used[i] = true;        
            result[pos] = 'a' + i; 
            generate(pos + 1);     
            used[i] = false;       
        }
    }
}

int main() {
    cin >> N >> K;
    if (K > N || N > 26 || K < 1) { 
        cout << "-1\n";
        return 0;
    }

    generate(0);  
    return 0;
}

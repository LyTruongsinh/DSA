#include <iostream>
#include <vector>

using namespace std;

void generateWords(const string &alphabet, int length) {
    string s(length, alphabet[0]); // Khởi tạo từ có độ dài `length` với ký tự đầu tiên trong bảng chữ cái
    vector<string> words;
    
    while (true) {
        words.push_back(s); // Lưu từ hiện tại
        
        // Tạo từ tiếp theo
        int i = length - 1;
        while (i >= 0) {
            auto pos = alphabet.find(s[i]); // Vị trí hiện tại trong bảng chữ cái
            if (pos == alphabet.size() - 1) { // Nếu là ký tự cuối cùng, đặt lại và lùi về ký tự trước
                s[i] = alphabet[0];
                i--;
            } else { // Chưa phải ký tự cuối, tăng lên và tiếp tục
                s[i] = alphabet[pos + 1];
                break;
            }
        }
        
        if (i < 0) break; // Nếu đã quay về ký tự đầu tiên và tràn, kết thúc
    }
    
    // In ra tất cả các từ
    for (const string &word : words) {
        cout << word << " ";
    }
}

int main() {
    string alphabet;
    cin >> alphabet; 

    generateWords(alphabet, 2);
    generateWords(alphabet, 3);

    return 0;
}

// Yêu cầu:
// Cho một bảng chữ cái của ngôn ngữ X
//  với thứ tự từ điển là thứ tự cho trong input. Viết chương trình liệt kê tất cả các từ độ dài 2
//  hoặc 3
//  theo thứ tự từ điển của ngôn ngữ X
// .

// Giới hạn: có tối đa 25
//  chữ cái là các chữ cái a..z
//  hoặc chữ số 0..9
// .

// Input:
// Một chuỗi tối đa 25
//  kí tự là các chữ cái từ a
//  đến z
//  hoặc chữ số từ 0
//  đến 9
// , thể hiện từ điển của ngôn ngữ X
// .
// Output:
// Một dòng liệt kê tất cả các từ có độ dài 2
//  hoặc 3
//  theo thứ tự từ điển của ngôn ngữ X
// .
#include <iostream>
#include <string>
using namespace std;

void generateWords(const string &dict, string word, int n)
{
    if (word.length() >= 2 && word.length() <= 3)
    {
        cout << word << " ";
    }
    if (word.length() == 3)
        return;

    for (int i = 0; i < n; i++)
    {
        generateWords(dict, word + dict[i], n);
    }
}

int main()
{
    string dict;
    cin >> dict;

    generateWords(dict, "", dict.length());
    cout << endl;
    return 0;
}

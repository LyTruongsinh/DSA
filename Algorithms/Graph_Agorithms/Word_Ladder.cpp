#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end())
            return 0; // Nếu endWord không có trong danh sách từ

        queue<pair<string, int>> q; // Cặp (từ, độ dài)
        q.push({beginWord, 1});      // Bắt đầu với beginWord và độ dài 1

        while (!q.empty())
        {
            auto [word, length] = q.front();
            q.pop();

            if (word == endWord)
                return length; // Nếu tìm thấy endWord, trả về độ dài

            for (int i = 0; i < word.size(); ++i)
            {
                char originalChar = word[i];
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    if (c == originalChar)
                        continue; // Bỏ qua ký tự gốc

                    word[i] = c;
                    if (wordSet.find(word) != wordSet.end())
                    {
                        q.push({word, length + 1});
                        wordSet.erase(word); // Xóa từ đã sử dụng để tránh lặp lại
                    }
                }
                word[i] = originalChar; // Khôi phục ký tự gốc
            }
        }
        return 0; // Không tìm thấy đường đi đến endWord
    }
};
int main() {
    Solution s;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    int result = s.ladderLength(beginWord, endWord, wordList);
    cout << "Length of shortest transformation sequence: " << result << endl;
    return 0;
}
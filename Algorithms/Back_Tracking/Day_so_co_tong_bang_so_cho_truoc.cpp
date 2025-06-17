#include <iostream>
#include <vector>
using namespace std;
void findCombinations(int n, int start, vector<int> &current)
{
    if (n == 0)
    {
        for (unsigned i = 0; i < current.size(); i++)
        {
            cout << current[i];
            if (i == current.size() - 1)
            {
                cout << "\n";
            }
            else
            {
                cout << " ";
            }
        }
        return;
    }
    if (n < start && n != 0)
    {
        return;
    }
    for (int i = start; i <= n; i++)
    {
        current.push_back(i);
        findCombinations(n - i, i, current);
        current.pop_back();
    }
}
int main()
{
    int n;
    cin >> n;
    cout << n << "\n";
    vector<int> current;
    findCombinations(n, 1, current);
    return 0;
}
// EMAMPLE với n = 5
// current = []
// findCombinations(5, 1, current)
// loop (1 -> 5)
// với i = 1 => current = [1]
//     findCombinations(4, 1, current)
//     loop(1 -> 4)
//     + với i = 1 => current = [1,1]
//         findCombinations(3, 1, current)
//         loop(1 -> 3)
//         + với i = 1 => current = [1,1,1]
//             findCombinations(2, 1, current)
//             loop(1 -> 2)
//             + với i = 1 => current = [1,1,1,1]
//                 findCombinations(1, 1, current)
//                 loop(1 -> 1)
//                 với i = 1 => current = [1,1,1,1,1]
//                     findCombinations(0 , 1, current) vì n = 0 print cấu hình đầu tiên 1 1 1 1 1
//                     thực hiện pop_back() => current = [1,1,1,1]

//                 thực hiện pop_back() => current = [1,1,1]
//             + với i = 2 => current = [1,1,1,2]
//                 findCombinations(0, 2, current) vì n = 0 print cấu hình thứ hai 1 1 1 2
//                 thực hiện pop_back() => current = [1,1,1]

//             thực hiện pop_back() => current = [1,1]

//         + với i = 2 => current = [1,1,2]
//             findCombinations(1, 2, current) // ko thực hiện hàm này
//             thực hiện pop_back() => current = [1,1]
//         + với i = 3 => current = [1,1,3]
//             findCombinations(0, 3, current) print cấu hình thứ ba 1 1 3
//             thực hiện pop_back() => current = [1,1]

//         thực hiện pop_back() => current = [1]

//     + với i = 2 => current = [1,2]
//         findCombinations(2, 2, current)
//         loop(2 -> 2)
//         với i = 2 => current = [1,2,2]
//            findCombinations(0, 2, current) print cấu hình thứ tư 1 2 2
//            pop_back() => current = [1,2]

//         pop_back() => current = [1]

//     + với i = 3 => current = [1,3]
//         findCombinations(1, 3, current) return luôn vì 1 < 3
//         pop_back() => current = [1]

//     + với i = 4 => current = [1,4]
//         findCombinations(0, 4, current) print cấu hình thứ năm 1 4
//         pop_back() => current = [1]

//     pop_back() => current = []
// với i = 2 => current = [2]
//   findCombinations(3, 2, current)
//   loop(2 -> 3)
//   + với i = 2 => current = [2,2]
//        findCombinations(1, 2, current) return vì 1 < 2
//        pop_back() => current = [2]
//   + với i = 3 => current = [2,3]
//        findCombinations(0, 3, current) print cấu hình thứ sáu 2 3
//        pop_back() => current = [2]

//   pop_back() => current = []

// với i = 3 => current = 3
//    findCombinations(2, 3, current) return vì  2 < 3
//    pop_back() => current = []
// với i = 4 => current = [4]
//    findCombinations(1, 4, current) return vì  1 < 4
//    pop_back() => current = []
// với i = 5 => current = [5]
//    findCombinations(0, 4, current) print cấu hình thứ bảy 5
//    pop_back() => current = []

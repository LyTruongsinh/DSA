#include <iostream>
#include <vector>

using namespace std;

// Định nghĩa cấu trúc của một node trong cây nhị phân
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Lớp giải bài toán
class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return generateTrees(1, n);
    }

private:
    vector<TreeNode *> generateTrees(int start, int end)
    {
        vector<TreeNode *> trees;
        if (start > end)
        {
            trees.push_back(nullptr);
            return trees;
        }

        for (int i = start; i <= end; ++i)
        {
            TreeNode *root = new TreeNode(i);
            vector<TreeNode *> leftSubtrees = generateTrees(start, i - 1);
            vector<TreeNode *> rightSubtrees = generateTrees(i + 1, end);

            for (int j = 0; j < leftSubtrees.size(); ++j)
            {
                for (int k = 0; k < rightSubtrees.size(); ++k)
                {
                    root->left = leftSubtrees[j];
                    root->right = rightSubtrees[k];
                    trees.push_back(root);
                }
            }
        }

        return trees;
    }
};

// Hàm hỗ trợ để in cây nhị phân theo dạng preorder (NLR)
void printPreorder(TreeNode *root)
{
    if (!root)
    {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Hàm xóa cây để tránh rò rỉ bộ nhớ
void deleteTree(TreeNode *root)
{
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    Solution solution;
    int n = 5; // Chọn số n bất kỳ
    vector<TreeNode *> result = solution.generateTrees(n);

    cout << "Danh sách tất cả các BST có thể có với n = " << n << ":\n";
    for (size_t i = 0; i < result.size(); ++i)
    {
        cout << "BST " << i + 1 << ": ";
        printPreorder(result[i]);
        cout << endl;
    }

    // Giải phóng bộ nhớ đã cấp phát cho các cây
    for (TreeNode *root : result)
    {
        deleteTree(root);
    }

    return 0;
}

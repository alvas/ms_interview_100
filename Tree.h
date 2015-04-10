#include <vector>

using namespace std;

class TreeNode
{
    public:
        int val;
        TreeNode *parent;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), parent(NULL), left(NULL), right(NULL) {}
};


void ReBuildTreeFromPreIn(int *preOrder, int *inOrder, int nTreeLen, TreeNode *&root);
void ReBuildTreeFromPreIn2(int *preOrder, int *inOrder, int nTreeLen, TreeNode *&root);
void ReBuildTreeFromPrePost(int *preOrder, int *postOrder, int nTreeLen, TreeNode *&root);
void ReBuildTreeFromPrePost2(int *preOrder, int *postOrder, int nTreeLen, TreeNode *&root);
void ReBuildTreeFromInPost(int *inOrder, int *postOrder, int nTreeLen, TreeNode *&root);
void ReBuildTreeFromInPost2(int *inOrder, int *postOrder, int nTreeLen, TreeNode *&root);
void ReBuildTreeFromOrderLevel(TreeNode *&root, const vector<string> &s);
void BuildOrderLevelVector(TreeNode * const root, vector<string> &v);
void CleanUp(TreeNode *&root);
void CleanUp2(TreeNode *&root);

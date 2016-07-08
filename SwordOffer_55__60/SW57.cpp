using namespace std;
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == NULL) return NULL;
        TreeLinkNode* pr = pNode, *rg = NULL;
        while (pr->next){
            if (pr->right&&pr->right!=rg) break;
            if (pr->next){
                rg = pr;
                pr = pr->next;
                if (pr->left&&pr->left == rg)
                    return pr;
            }
        }
        if (pr->next==NULL&&pr->right == rg||pr->right==NULL)
            return NULL;
        pr = pr->right;
        while (pr->left)
            pr = pr->left;
        return pr;
    }
};
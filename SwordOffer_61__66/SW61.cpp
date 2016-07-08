class Solution {
public:

    char a[1000] = {'\0'};
    int gi=0, gk=0,gs=0;
    TreeNode *tr[100];

    void sch(TreeNode *root)
    {
        if (root != NULL)
        {
            int v = root->val;
            if (v == 0)
                a[gi++] = '0';
            else
            {
                int k = 0, w[10] = { 0 };
                while (v != 0)
                {
                    w[k++] = v % 10;
                    v /= 10;
                }
                for (int i = 1; i <= k;i++)
                {
                    a[gi++] = w[k - i] + 48;
                }
            }

            a[gi++] = ',';
            //a[gi++] = root->val;
            sch(root->left);
            sch(root->right);
        }
        else
        {
            a[gi++] = '#';
            a[gi++] = ',';
        }

    }
    TreeNode* bud(char *str)
    {
        //if (*(str+gs) != '#')
        if (str[gs] != '#')
        {
            int sum = 0;
            while (str[gs] != ',')
            {
                sum = sum * 10 + str[gs] - 48;
                gs++;
            }
            gs++;

            TreeNode *root = new TreeNode(sum);
            root->left = bud(str);
            root->right = bud(str);
            return root;
        }
        else
        {
            gs += 2;
            return NULL;
        }

    }
    char* Serialize(TreeNode *root) {
        if (root == NULL)
            return "#";
        else
            sch(root);
        return a;
    }
        TreeNode* Deserialize(char *str) {
        if (str=="#")
            return NULL;
        else
            return bud(str);

    }
};
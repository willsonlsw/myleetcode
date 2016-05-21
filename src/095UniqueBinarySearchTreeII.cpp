class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> tmp;
        if (n == 0) return tmp;
        return treeGenerator(1, n);
    }
    
    vector<TreeNode*> treeGenerator(int s, int e) {
        vector<TreeNode*> rst;
        if (s > e) rst.push_back(NULL);
        if (s == e) rst.push_back(new TreeNode(s));
        if (s < e){
            for (int i = s; i <= e; ++i){
                vector<TreeNode*> ltrees = treeGenerator(s, i - 1);
                vector<TreeNode*> rtrees = treeGenerator(i + 1, e);
                
                for (int j = 0; j < ltrees.size(); ++j)
                    for (int k = 0; k < rtrees.size(); ++k){
                        TreeNode *node = new TreeNode(i);
                        //if (ltrees[j]->val != 0) 
                        node->left = ltrees[j];
                        //if (rtrees[k]->val != 0) 
                        node->right = rtrees[k];
                        rst.push_back(node);
                    }
            }
        }
        return rst;
    }
};
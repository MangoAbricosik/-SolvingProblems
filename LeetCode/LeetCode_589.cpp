class Solution {
    vector<int> arr;
public:
    vector<int> preorder(Node* root) {
        if (root) {
            arr.push_back(root->val);
            for (auto item : root->children) {
                if (!root->children.empty())
                    preorder(item);
            }
        }
        return arr;
    }
};
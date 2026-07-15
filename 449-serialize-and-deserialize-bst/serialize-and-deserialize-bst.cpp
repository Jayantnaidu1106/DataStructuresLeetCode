class Codec {
public:
    // Encodes a tree to a single string 
    string serialize(TreeNode* root) {
        if (!root) return "#_";
        
      
        return to_string(root->val) + "_" 
             + serialize(root->left) 
             + serialize(root->right);
    }


    TreeNode* build(const string& data, int& index) {
        if (index >= data.size()) return nullptr;

  
        int next_delim = data.find('_', index);
        string val = data.substr(index, next_delim - index);
        index = next_delim + 1; 

        if (val == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        root->left = build(data, index);
        root->right = build(data, index);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return build(data, index);
    }

};
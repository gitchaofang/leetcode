class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "*";
        std::string str = std::to_string(root -> val);
        str += (" " + serialize(root -> left));
        str += (" " + serialize(root -> right));
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* des(std::stringstream& ss){
        std::string str;
        ss >> str;
        if(str == "*") return nullptr;
        TreeNode* node = new TreeNode(std::stoi(str));
        node -> left = des(ss);
        node -> right = des(ss);
        return node;
    }
    TreeNode* deserialize(string data) {
        std::stringstream ss;
        ss << data;
        return des(ss);
    }
};



class Codec {
public:

    // Encodes a tree to a single string.
    /*0 no cildren, 1 left, 2 right, 3 both*/
    string serialize(TreeNode* root) {
        if(!root) return "";
        std::string str = std::to_string(root -> val);
        if(root -> left && root -> right){
            str += " 3 " + serialize(root -> left) + ' ' + serialize(root -> right);
        }
        else if(root -> left) str += " 1 " + serialize(root -> left);
        else if(root -> right) str += " 2 " + serialize(root -> right);
        else str += " 0";
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* decode(std::stringstream& ss){
        std::string val;
        ss >> val;
        TreeNode* root = new TreeNode(std::stoi(val));
        std::string sig;
        ss >> sig;
        if(sig == "3"){
            root -> left = decode(ss);
            root -> right = decode(ss);
        }
        else if(sig == "1") root -> left = decode(ss);
        else if(sig == "2") root -> right = decode(ss);
        return root;
        
    }
    TreeNode* deserialize(string data) {
         if(data.empty()) return nullptr;
        std::stringstream ss;
        ss << data;
        return decode(ss);
    }
};

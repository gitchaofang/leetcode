class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if(!root) return "null";
        int n = (root -> children).size();
        std::vector<Node*>& v = root -> children;
        std::string res(std::to_string(root -> val) + " "+ std::to_string(n));
        if(n == 0) return res;
        for(int i = 0; i < v.size(); ++i){
            std::string str = serialize(v[i]);
            res += " " + str;
        }
        return res;
    }
	
    // Decodes your encoded data to tree.
    Node* des(std::stringstream& ss){
        std::string str;
        ss >> str;
        Node* root = new Node(std::stoi(str));
        ss >> str;
        int num = std::stoi(str);
        if(num == 0) return root;
        std::vector<Node*> v;
        for(int i = 0; i < num; ++i) (root -> children).push_back(des(ss));
        return root;
        
    }
    Node* deserialize(string data) {
        if(data == "null") return nullptr;
        std::stringstream ss;
        ss << data;
        return des(ss);
    }
};

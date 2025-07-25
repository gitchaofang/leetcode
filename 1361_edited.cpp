#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<set>
std::string buildS(char root,  std::vector<std::set<char>>& cnt_child){
	std::string res(1, root);
	res = "(" + res;
	for(char child: cnt_child[root - 'A']){
		res += buildS(child, cnt_child);
	}
	res += ")";
	return res;

}
std::string validateBinaryTreeNodes(const std::string& input) {
	std::vector<std::set<char>> cnt_child(26);
	std::vector<bool> node(26,false);
	for(int i = 0; i < input.size(); ++i){
		int pos = input.find(' ',i);
		std::string pair;
		if(pos == std::string::npos){
			pair = input.substr(i);
			i = input.size();
		}else{
			pair = input.substr(i, pos - i);
			i = pos;
		}
		++pos;
		// checking if pair is valid
		if(pair.size() != 5) return "E1";
		if(pair[0]!= '(' || pair.back() != ')' || pair[2] != ',') return "E1";
		char parent = pair[1];
		if(parent > 'Z' || parent < 'A') return "E1";
		char child = pair[3];
		if(child > 'Z' || child < 'A') return "E1";
		// check duplication
		if(cnt_child[parent - 'A'].find(child) != cnt_child[parent - 'A'].end()) return "E2";
		cnt_child[parent - 'A'].insert(child);
		// check if parent has more than two children
		cnt_child[parent - 'A'].insert(child);
		if(cnt_child.at(parent - 'A').size() > 2) return "E3";
		node[parent - 'A'] = true;
		node[child - 'A'] = true;
	}


        std::vector<int> in(26,0);
        for(int i = 0; i < 26; ++i){
        	if(node[i] == false) continue;
		for(char child: cnt_child[i]){
			++in[child - 'A'];
		}
        }

        std::queue<int> q;
        for(int i = 0; i < 26; ++i){
 		if(node[i] == false) continue;
             	if(in[i] == 0) q.push(i);
             	//check two nodes pointing to one node.
            	if(in[i] > 1) return "E5";
        }
        // check multiple roots
        if(q.size() != 1) return "E4";
	char root = 'A' + q.front();
        // check loop.
        while(!q.empty()){
 		int parent = q.front();
 		q.pop();
		for(char child: cnt_child[parent]){
			int child_num = child - 'A';
			--in[child_num];
			if(in[child_num] == 0) q.push(child_num);
		}
        	
	}
        for(const int& d: in){
            	if(d != 0) return "E5";   
        }
 
	// valid, print out S-Expression
	return buildS(root, cnt_child);
    }

int main(){
	std::string test1 = "(A,B) (B,C) (A,E) (B,D)";
	std::string test2 = "(A,B) (B,D) (D,E) (A,C) (C,F) (E,G)";
	std::string test3 = "(A,B) (A,C) (B,D) (D,C)";
	std::string test = test3;
	std::string res = validateBinaryTreeNodes(test);
	std::cout << res << std::endl;
	return 0;
}

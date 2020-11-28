class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        std::unordered_map<int,Employee*> m;
        for(int i = 0; i < employees.size(); ++i) m[employees[i] -> id] = employees[i]; 
        std::queue<Employee*>q({m[id]});
        while(!q.empty()){
            Employee* id = q.front();
            q.pop();
            res += id -> importance;
            for(const int& d: id -> subordinates) q.push(m[d]);
        }
        return res;
    }
};

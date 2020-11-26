class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        std::sort(people.begin(),people.end(),[](const std::vector<int>& v1, const std::vector<int>& v2){
            return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] > v2[0];
        });   
        std::vector<std::vector<int>> res;
        for(const std::vector<int>& v: people) res.insert(res.begin() + v[1], v);
        return res;
    }
};

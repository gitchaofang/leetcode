class Solution {
public:
    std::string getHost(const std::string& url){
        size_t pos = url.find('/',  url.find("//") + 2);
        return url.substr(0,pos);
    }
    std::vector<std::string> getUrl(std::string&& parent_url, HtmlParser& htmlParser){
        std::vector<std::string> urls = htmlParser.getUrls(parent_url);
        std::vector<std::string> res;
        for(int i = 0; i < urls.size(); ++i){
            if(getHost(urls[i]) != head) continue;
            res.push_back(std::move(urls[i]));
        }
        return res;
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        uint32_t thread_size = std::thread::hardware_concurrency();
        head = getHost(startUrl);
        std::stack<std::string> st({startUrl});
        visited.insert(startUrl);
        std::vector<std::future<std::vector<std::string>>> futs;
        futs.reserve(thread_size);
        while(!st.empty()){
            for(int i = 0; i < thread_size && !st.empty(); ++i){
                std::string url_name = st.top();
                st.pop();
                std::future<std::vector<std::string>> fut =
                std::async(std::launch::async, &Solution::getUrl, this, std::move(url_name), std::ref(htmlParser));
                futs.push_back(std::move(fut));
            }

            while(!futs.empty()){
                std::vector<std::string> url_vec = futs.back().get();
                futs.pop_back();
                if(url_vec.empty()) continue;
                for_each(url_vec.begin(), url_vec.end(), [&](const std::string& url){
                    if(visited.find(url) == visited.end()){
                        visited.insert(url);
                        st.push(url);
                    }
                });
            }
        }
        std::vector<std::string> res;
        res.reserve(visited.size());
        for_each(visited.begin(), visited.end(), [&](const std::string& url){
            res.push_back(url);
        });
        return res;

    }
private:
    std::unordered_set<std::string> visited;
    std::string head;
};

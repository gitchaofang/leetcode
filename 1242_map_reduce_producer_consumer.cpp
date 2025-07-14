std::string getHost(const std::string& url){
    size_t pos = url.find('/',  url.find("//") + 2);
    return url.substr(0,pos);
 }
class crawler{
    private:
        std::atomic<uint32_t> working_cnt; 
        std::mutex lk;
        std::condition_variable cv;
        std::queue<std::string> q;
        std::unordered_set<std::string> visited;
        std::string head;
    public:
        crawler():working_cnt(0){
        }
        crawler(const std::string& url, const std::string& h): working_cnt(0), head(h){
            q.push(url);
            visited.insert(url);
        }
        void craw(std::vector<std::string>& res, HtmlParser& htmlParser){
            while(true){
                std::string cur_url;
                //consumer
                {
                    std::unique_lock<std::mutex> lg(lk);
                    cv.wait(lg,[this](){
                        return !q.empty() || working_cnt == 0;
                        });
                    if(q.empty() && working_cnt == 0) return;
                    if(!q.empty()){
                        cur_url = q.front();
                        res.push_back(cur_url);
                        q.pop(); 
                    }  
                    ++working_cnt;
                }

                //producer
                std::vector<std::string> url_vec = htmlParser.getUrls(cur_url);
                std::lock_guard<std::mutex> lg(lk);
                for(const std::string& next_url: url_vec){ 
                    if(getHost(next_url) != head) continue;
                    if(visited.find(next_url) == visited.end()){
                        visited.insert(next_url);
                        q.push(next_url);
                    }
                }
                --working_cnt;
                cv.notify_all();
            }
            return;
        }

};
class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        std::vector<std::string> res;
        std::unordered_set<std::string> visited({startUrl});
        uint32_t tot_thread = std::thread::hardware_concurrency();
        crawler cw(startUrl, getHost(startUrl));
        std::vector<std::thread> thread_pool;
        thread_pool.reserve(tot_thread);
        for(int i = 0; i < tot_thread; ++i){
            std::thread th(&crawler::craw, &cw, std::ref(res), std::ref(htmlParser));
            thread_pool.push_back(std::move(th));
        }

        for_each(thread_pool.begin(), thread_pool.end(), [](std::thread& th){
            th.join();
        });
        return res;

    }
};

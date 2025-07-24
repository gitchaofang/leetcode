class Solution {
public:
    std::vector<int> readDate(const std::string& date){
        std::vector<int> res;
        int pos = date.find('-');
        res.push_back(std::stoi(date.substr(0,pos)));
        ++pos;
        res.push_back(std::stoi(date.substr(pos, date.find('-',pos) - pos)));
        pos = date.find('-',pos) + 1;
        res.push_back(std::stoi(date.substr(pos)));
        return res;
    }
    
    int daysFromBegin(int y, int m, int d){
        static const int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        for (int i = 0; i < m - 1; ++i)
            d += monthDays[i];
        if (m > 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) d += 1;
        d += 365 * y + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
        return d;

    }
    int daysBetweenDates(string date1, string date2) {
        std::vector<int> date_v1 = readDate(date1);
        std::vector<int> date_v2 = readDate(date2);
         return std::abs(daysFromBegin(date_v2[0], date_v2[1], date_v2[2]) - daysFromBegin(date_v1[0], date_v1[1], date_v1[2]));
    }
};

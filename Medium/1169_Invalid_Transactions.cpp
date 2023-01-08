//
//Runtime 46
//Memory Usage 14.3

class Solution {
public:
    struct E {
        int time, amount;
        string city;
        bool prob;
    };
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, pair<string, int>> mp;
        unordered_map<string, vector<E>> cnt;
        
        vector<string> res;
        
        string city, name;
        int time, amount;
        
        
        for(const auto &transaction : transactions) {
            vector<string> v(4);
            int i = 0;
            stringstream ss(transaction);
            while(getline(ss, v[i++], ','));
            
            name = v[0];
            city = v[3];
            time = stoi(v[1]);
            amount = stoi(v[2]);
            
            bool prob = false;

            if(amount > 1000) 
                prob = true;
            
            for(auto &e : cnt[name]) 
                if(abs(e.time - time) <= 60 && e.city != city) {
                    if(!e.prob)
                        res.push_back(name + "," + to_string(e.time) + "," + to_string(e.amount) + "," + e.city), e.prob = true;
                    prob = true;
                }

            if(prob)
                res.push_back(transaction);
            
            cnt[name].push_back({time, amount, city, prob});
        }
        
        
        return res;
    }
};
//Greedy + Sort
//Runtime 4
//Memory Usage 11.6

class dat{
    public:
        string str;
        int val;
        dat(int a, string &&b){val = a, str = b;}
};

bool cmpFunc(const dat &a,const  dat &b){
    return (a.str + b.str > b.str + a.str);
}


class Solution {
    
public:
    string largestNumber(vector<int>& nums) {
        vector<dat> dats;
        for(int &num : nums) dats.push_back(dat(num, to_string(num)));
        sort(dats.begin(), dats.end(), cmpFunc);
        string result;
        for(auto &i : dats) result += i.str;
        if(result[0] == '0') return "0";
        return result;
    }

};

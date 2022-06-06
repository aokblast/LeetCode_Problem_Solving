//
//Runtime 18
//Memory Usage 13.7
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        
        for(const auto &email : emails){
            string mail;
            int i = 0, n = email.size();
            for(; i < n && email[i] != '@'; ++i){
                char c = email[i];
                if(c == '.')
                    continue;
                else if(c == '+')
                    break;
                mail += c;
            }
            mail += email.substr(email.find('@'));
            set.insert(mail);
        }
        return set.size();
    }
};
//
//Runtime 172
//Memory Usage 81.6
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(), candyType.end());
        return min((size_t)(unique(candyType.begin(), candyType.end()) - candyType.begin()),candyType.size() / 2);
    }
};
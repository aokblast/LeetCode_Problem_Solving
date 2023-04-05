//DJS
//Runtime 40
//Memory Usage 31.3

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int djs[n];
        int in[n];

        memset(in, 0, sizeof(in));

        int g = n;

        for(int i = 0; i < n; ++i)
            djs[i] = i;

        function<int(int)> parent = [&](int u) {
            return u == djs[u] ? u : djs[u] = parent(djs[u]);
        };

        for(int i = 0; i < n; ++i) {
            int p1 = parent(i);
            
            if(leftChild[i] != -1) {
                if(++in[leftChild[i]] == 2)
                    return false;
                int p2 = parent(leftChild[i]); 
                if(p1 == p2)
                    return false;
                djs[p2] = p1;
                g--;
            }
            
            if(rightChild[i] != -1) {
                if(++in[rightChild[i]] == 2)
                    return false;
                int p3 = parent(rightChild[i]);
                if(p1 == p3)
                    return false;
                djs[p3] = p1;
                g--;
            }
        }

        return g == 1;
    }
};
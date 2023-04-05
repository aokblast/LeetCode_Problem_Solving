//
//Runtime 274
//Memory Usage 120.5

class Cashier {
private:
    int n;
    int discount;
    int cnt = 0;
    unordered_map<int, int> prod;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) : n(n), discount(discount) {
        int m = products.size();

        for(int i = 0; i < m; ++i)
            prod[products[i]] = prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double res = 0;

        int m = product.size();

        for(int i = 0; i < m; ++i)
            res += prod[product[i]] * amount[i];
        
        return ((++cnt) % n == 0 ? (100 - discount) : 100) / 100.0 * res;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
int isDiv(int n, int t){
    int product = 1;
    while(n > 0){
        product *= n % 10;
        n /= 10;
    }

    if(product % t == 0) return true;
    return false;
}

class Solution {
public:
    int smallestNumber(int n, int t) {
        for( ; ; n++){
            if(isDiv(n, t))
                return n;
        }
        return 0;
    }
};
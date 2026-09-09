
class Solution {
    public:
long long countCommas(long long n) {
    long long count = 0;

    long long start = 1000;  
    int commas = 1;

    while (start <= n) {
        long long end = start * 1000 - 1;

        if (end > n)
            end = n;

        count += (end - start + 1) * commas;

        start *= 1000;
        commas++;
    }

    return count;
}

};
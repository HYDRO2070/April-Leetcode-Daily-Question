class Solution {
public:
    int mySqrt(int x) {
        // Needs to be 64 bits so that it doesn't overflow
        int64_t result = x;

        int i = 2;
        while(true)
        {
            result -= result / i;
            while(result * result <= x)
            {
                // Result squared is either smaller or equals to x
                // If we add one and square it, and it turns out to be bigger than x
                // Then result is either the exact or the next best value rounded down to the actual square root of x
                if((result + 1) * (result + 1) > x)
                    return result;
                
                // Get closer to the desired value by stepping forward a bit less than before
                i++;
                result += result / i;
            }
        }
        return -1;
    }
};

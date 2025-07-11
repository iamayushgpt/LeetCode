class Solution {
public:
    int getSum(int a, int b) {
        // Loop until there is no carry
        while (b != 0) {
            // carry now contains common set bits of a and b
            int carry = a & b;

            // Sum of bits of a and b where at least one of the bits is not set
            a = a ^ b;

            // Carry is shifted by one so that adding it to a gives the required sum
            b = carry << 1;
        }

        // When there is no carry, a contains the final sum
        return a;
    }
};

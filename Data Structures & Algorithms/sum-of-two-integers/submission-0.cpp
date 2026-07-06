class Solution {
public:
    int getSum(int a, int b) {
        int c = 0; // This will hold our final answer
        int carry = 0;
        
        for (int i = 0; i < 32; i++) {
            // Get the i-th bit of a and b
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;
            
            // Logic for a Full Adder:
            // The bit at this position is bitA XOR bitB XOR carry
            int currentBit = bitA ^ bitB ^ carry;
            
            // Set the i-th bit in our result c
            c |= (currentBit << i);
            
            // Carry is generated if (bitA + bitB + carry) >= 2
            carry = (bitA + bitB + carry) >= 2 ? 1 : 0;
        }
        return c;
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        int i = 0; 
        string res = "";
        while(i < a.length() && i < b.length())
        {
            int x = a[i] - '0';
            int y = b[i] - '0';
            
            int sum = x + y + carry;
            carry = sum / 2;
            sum = sum % 2; 
            
            res += to_string(sum); 
            i++;
        }
        while(i < a.length())
        {
            int x = a[i] - '0';
            
            int sum = x + carry;
            carry = sum / 2;
            sum = sum % 2; 
            
            res += to_string(sum); 
            i++;
        }
        while(i < b.length())
        {
            int x = b[i] - '0';
            
            int sum = x + carry;
            carry = sum / 2;
            sum = sum % 2; 
            
            res += to_string(sum); 
            i++;
        }
        res = (carry > 0)?(res + "1"):res;
        reverse(res.begin(), res.end());
        return res;
    }
};
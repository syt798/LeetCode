class Solution {
public:
    int romanToInt(string s) {
                int deci;
        int deci_pre = 4000;//max
        int result = 0;
        for( int i = 0; i < s.size(); ++i )
        {
            switch(s[i])
            {
                case 'I': deci = 1;
                break; 
                case 'V': deci = 5;
                break;
                case 'X': deci = 10;
                break;
                case 'L': deci = 50;
                break;
                case 'C': deci = 100;
                break;
                case 'D': deci = 500;
                break;
                case 'M': deci = 1000;
            }
            result += deci;
            if( deci > deci_pre )
                result -= deci_pre*2;
            deci_pre = deci;
        }
        return result;
    }
};
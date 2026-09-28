class Solution {
public:
    int maxDepth(string s) {
        int openbracket = 0;
        int result =0;
        for(char ch :s ){
            if (ch =='('){
                openbracket++;
            }
            else if(ch == ')'){
                openbracket--;
            }
            result =max(result,openbracket);
        }
        return result;
        
    }
};

// APPROACH 2 
// class Solution {
// public:
//     int maxDepth(string s) {
//         stack <char> st;
//         int result = 0;
//         for( char ch : s){
//             if (ch =='('){
//                 st.push(ch);
//             }
//             else if (ch ==')'){
//                 st.pop();
//             }
//             result = max(result , (int)st.size());

//         }
//         return result;
        
//     }
// };
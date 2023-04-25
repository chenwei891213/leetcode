//Use stack
class Solution {
public:
    bool isValid(string s) {
        stack<char>record;
        for(char i:s){
            if(i=='('||i=='{'||i=='[')record.push(i);
            else if(!(record.empty())&&((i==')'&&record.top()=='(')||
                    (i=='}'&&record.top()=='{')||
                    (i==']'&&record.top()=='[')))record.pop();
            else return false;
        }
        return record.empty();
    }
};
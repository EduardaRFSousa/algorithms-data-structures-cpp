//Validação de Parênteses
 #include <iostream>
#include <stack>

using namespace std;

class Solution {
    public:
    bool isValid(const string &s) {
        
        stack<char> pilha;
        if(s.length() == 0){
            cout << "Pilha vazia!";
            exit(1);
        } else {
            for (char c : s) {
                if(c == '(' || c == '[' || c == '{'){
                    pilha.push(c);
                    
                } else if (c == ')'){
                    if(pilha.empty() || pilha.top() != '('){
                        return false;
                    } else pilha.pop();
                    
                } else if (c == ']'){
                    if(pilha.empty() || pilha.top() != '['){
                        return false;
                    } else pilha.pop();
                        
                } else if(c == '}'){
                    if(pilha.empty() || pilha.top() != '{'){
                        return false;
                    } else pilha.pop();
                }
                    
            }
        }
        
        if(pilha.empty()){
            return true;
        } else {
            return false;
        }
    
    }
};

int main() {
    string testes[] = { "[{()}]", "()[]{}", "{[(}])", "(][){}", "}{)(][" };
    
    for (auto &s : testes) {
        cout << s << ": " << (Solution().isValid(s)?"Valida":"Invalida") << endl;
    }
}
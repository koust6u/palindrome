#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int index;
int palindrome(char* str){
    int left = 0, right = strlen(str)-1;
    while(left <= right){
        if(str[left++]!= str[right--]) return 0;
    }
    return strlen(str);
}

bool quasi(int left, int right,bool check, char* str){
    if(left > right) return true;
    if(str[left] == str[right]) return quasi(left+1, right-1,check,str);
    else if(check) {
        return max(quasi(left+index, right, false,str),quasi(left,right-index,false,str));
    }
    else {
        return false;
    }
}


int getAns(char* str){
    int result;
    result = palindrome(str);
    bool flag =false;

    if(result == 0 && str[0] == str[strlen(str)-1]){
        for(int i = 0; i < strlen(str)-2; i++){
            index++;
            flag = quasi(0,strlen(str)-1,true, str);
            if(flag){
                return strlen(str)- index;
            }
        }
        return 0;
    }
    return result;
}
int main(){
    int n;
    cin >> n;
    vector<int> v;
    cin.ignore();
    for(int i = 0 ; i < n ; i++){
        index= 0;
        char temp[250];
        cin.getline(temp,250);
        v.push_back(getAns(temp));
    }
    for(auto iter = v.begin(); iter!= v.end(); iter++){
        cout << *iter << endl;
    }
}
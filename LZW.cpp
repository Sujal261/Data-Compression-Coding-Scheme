#include<iostream>
#include<string>
using namespace std ; 
string Encoder(string word){
    string dictionary[100];
    string ans;
    bool check = false;
    int i =0;
    for (char ch : word) {
    bool already_in = false;
    string ch_str(1, ch);
    for (int j = 0; j < i; j++) {
        if (dictionary[j] == ch_str) {
            already_in = true;
            break;
        }
    }
    if (!already_in) {
        dictionary[i] = ch_str;
        i++;
    }
}
    string str = std::string(1,word[0]);

    for(int q =1 ;q<word.length();++q){
        check = false;
        char ch = word[q];
        int k =0;
        for(int j = 0; j < i ; j++){
            if((str+ std::string(1, ch))==dictionary[j]){
             check = true;
             break;
            }
        }
        
        if(check){
            str = str +std::string(1,ch);
        }
        else{
            for (int j = 0;j<i;j++)
            {
                
                
                if(dictionary[j]==str){
                    k = j;  
                    break;
                
                }

            }
            dictionary[i] = str+std::string(1,ch);
            i=i+1;
            ans = ans+to_string(k);
            str = std::string(1, ch);
        }
    }
    
   
    int k = 0;
    for (int j = 0; j < i; j++) {
        if (dictionary[j] == str) {
            k = j ;  
            break;
        }
    }
    ans = ans + to_string(k);
    int q=0;
    for(string ch: dictionary){
        if(ch==""){
            break;
        }
        cout<<"|"<<ch<<"|"<<q<<"|"<<endl;
        q=q+1;
        
    }
   
    return ans;
}
string Decoder(string word, string out){
    string dictionary[100];
    string output;
    bool check = false;
    string ans;
    int j =0;
    for (char ch : word) {
    bool already_in = false;
    string ch_str(1, ch);
    for (int i = 0; i < j; i++) {
        if (dictionary[i] == ch_str) {
            already_in = true;
            break;
        }
    }
    if (!already_in) {
        dictionary[j] = ch_str;
        j++;
    }
}
    string c = string(1,out[0]);
   
    output = dictionary[stoi(c)];
    for (int i =1 ; i<out.length();i++){
        string s = dictionary[stoi(c)];
      
        c = string(1,out[i]);
        
        for(int k =0; k<j;k++){
            if(s==dictionary[k]){
               check = true;
               break;
        }
    }
        if(check){
         dictionary[j] = s+dictionary[stoi(c)][0];
         
                j=j+1;
                output=output+dictionary[stoi(c)];
            }
            else{
                dictionary[j] = s+s[0];
                j=j+1;
                output=output+s[0];
            }

    }
    int q=0;
    for(string ch: dictionary){
        if(ch==""){
            break;
        }
        cout<<"|"<<ch<<"|"<<q<<"|"<<endl;
        q=q+1;
        
    }
   
 return output;
}
int main(){
    string word;
    string output;
    string decoded;

    cout<<"Enter the string: ";
    std::getline(std::cin, word);

    output = Encoder(word);
    cout<<output<<endl;
    decoded= Decoder(word, output);
    cout<<decoded<<endl;
}


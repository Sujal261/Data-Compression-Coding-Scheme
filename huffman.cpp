#include<iostream>
#include<string>
struct node
{
    std::string data;
    int freq;
};

void calculatefrequency(std::string input, std::string sequence){
    int frequency=0;
    for(char ch: sequence){
        for(char c: input){
            frequency+=1;

        }
    }

}
std::string HuffmanEncoding(std::string input){
    node node1;
    std::string answer;
  
    node1.data +=input[0];
    // std::cout<<node1.data[0]<<std::endl;;
    int j=1;
    for(int k =1;k<input.length();k++){
        bool check = false;
    for(int i =0;i<j;i++){
        // std::cout<<node1.data<<std::endl;
        if(input[k]==node1.data[i]){
         check = true;
         break;
        }
    }
    if(!check){
        node1.data = node1.data+ input[k];
        j=j+1; 
    }
}
    for(char c : node1.data){
        answer = answer+c;
    }
    return answer;
}


int main(){
    std::string input;
    std::string encoded_sequence;
    std::cout<<"Enter the sequence you want to encode"<<std::flush;
    std::cin>>input;
    // std::flush;
    encoded_sequence = HuffmanEncoding(input);
    std::cout<<encoded_sequence;
    
}

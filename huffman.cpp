#include<iostream>
#include<string>
#include<climits>
struct node
{
    std::string data;
    int freq;
    node* next;

    node(std::string value){
        data = value;
        next = nullptr;
        freq=0;
    }
};
node* head = nullptr;

void calculatefrequency(std::string sequence){
    
    for(char ch: sequence){
    node* temp = head;
    while(temp!=nullptr){
        if(temp->data == std::string(1,ch)){
            temp->freq = temp->freq+1;
            
        }
        temp = temp->next;
    }
    
}
}

void calculatesmallestfrequency(){
    int smallestfrequency = INT_MAX;
    node* temp = head;
    while(temp!=head){
        if(temp->freq<smallestfrequency){
            smallestfrequency = temp->freq;
        }

    }
}
void seefrequency(){
    node* temp = head;
    while(temp!= nullptr)
    {
        std::cout<<temp->data<<"-"<<temp->freq<<std::endl;
        temp = temp->next;
    }
  
}


std::string HuffmanEncoding(std::string input){
    
    std::string answer;
  
    answer +=input[0];
    // std::cout<<node1.data[0]<<std::endl;;
    int j=1;
    for(int k =1;k<input.length();k++){
        bool check = false;
    for(int i =0;i<j;i++){
        // std::cout<<node1.data<<std::endl;
        if(input[k]==answer[i]){
         check = true;
         break;
        }
    }
    if(!check){
        answer= answer+ input[k];
        j=j+1; 
    }
}
int p =0;
    for(char c : answer){
        node* newNode = new node(std::string(1,c));
        if(p==0){
          head = newNode;
        
        }
        else{
            node* temp = head;
            while(temp->next!=nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
          
        
        }
        p=p+1;

    }
    return answer;
}


int main(){
    std::string input;
    std::string encoded_sequence;
    std::cout<<"Enter the sequence you want to encode"<<std::flush;
    std::cin>>input;
    encoded_sequence = HuffmanEncoding(input);
    std::cout<<encoded_sequence<<std::endl;
    calculatefrequency(input);
    seefrequency();
}

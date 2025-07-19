#include<iostream>
#include<string>
#include<climits>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<bitset>
struct dictionary{
    std::string data;
    std::string code;

};

struct node
{
    std::string data;
    int freq=0;
    node* next;
    node* left;
    node* right;
    bool calc;

    node(std::string value){
        data = value;
        next = nullptr;
        freq=0;
        calc = false;
        
    }
};
class Huffman{
    private:
        std::vector<node*> nodes;
        node* head = nullptr;
        std::string answer;
        int p =0;
        int s=0;
        dictionary dict[100];
    public:

        void sort_vector_array(std::vector<node*> &nodes){
            sort(nodes.begin(), nodes.end(),[](node* a, node* b){
                return a->freq<b->freq;
            });
        }
         
        void generatehuffmancodes(node* root, std::string code){
           
            if(!root) return;
            if(root->left==nullptr && root->right==nullptr){
                std::cout<<root->data<<":"<<code<<std::endl;
                  
                     dict[s].data = root->data;
                     dict[s].code= code;
                     s=s+1;
            

                return;
            }
            generatehuffmancodes(root->left, code+"0");
            generatehuffmancodes(root->right, code+"1");
        }


        node* HuffmanEncoding(std::string input){
            std::string answer;
            answer +=input[0];
            int j=1;
            for(int k =1;k<input.length();k++){
                bool check = false;
            for(int i =0;i<j;i++){
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
            for(char ch: input){
            node* temp = head;
            while(temp!=nullptr){
                if(temp->data == std::string(1,ch)){
                    temp->freq = temp->freq+1;
                    
                }
                temp = temp->next;
            } 
        }
        node* temp = head;
            while(temp!=nullptr){
                nodes.push_back(temp);
                temp = temp->next;
            }

        sort_vector_array(nodes);
        
        while(nodes.size()>1){
                node* left = nodes[0];
                node* right = nodes[1];
                node* newNode = new node(left->data +right->data);
                newNode->freq = left->freq+right->freq;
                newNode->left = left;
                newNode->right = right;
                
                nodes.erase(nodes.begin());
                nodes.erase(nodes.begin());
                nodes.push_back(newNode);
                sort_vector_array(nodes);
                std::cout << "Nodes frequencies: ";
        for (auto n : nodes) {
            std::cout << n->freq << " ";
        }
        std::cout << std::endl;

        }
        node* root = nodes[0];
        return root;
        }

        // void checkdict(){
        //     for(int i =0; i<p;i++){
                
        //         std::cout<<"\n"<<dict[i].data<<":"<<dict[i].code<<std::endl;
        //     }
        // }
        void huffmanencode(std::string input){
            std::string ouptut;
            for(char ch:input){
                for(int i =0;i<p;i++){
                    if(std::string(1,ch)==dict[i].data){
                        ouptut=ouptut+dict[i].code;
                        // int number = stoi(dict[i].code);
                        // std::ofstream file("encoded.bin", std::ios::binary|std::ios::app);
                        // file.put(number);
                        // file.close();
                    }
                }
            }
            std::ofstream file("encoded.bin",std::ios::binary|std::ios::app);

            unsigned char byte =0;
            int count =0;
            for(char bit:ouptut){
                byte = (byte<<1)|(bit-'0');
                count++;
            
            if(count ==8){
                file.put(byte);
                count =0;
                byte=0;
            }
        }
            if(count>0){
                byte<<=(8-count);
                file.put(byte);
        }
        file.close();
    }
    void seebinary(){
        std::ifstream file("encoded.bin", std::ios::binary);
        std::stringstream buffer;
        buffer<<file.rdbuf();
        std::string input = buffer.str();
        for (unsigned char c : input) {
        std::bitset<8> bits(c);
        std::cout << bits;
}

        file.close();
    }

};


int main(){
    Huffman h;
    node* root;
    // std::string input;
    // std::cout<<"Enter the sequence you want to encode"<<std::flush;
    // std::getline(std::cin, input);
    std::ifstream file("sample.txt");
    std::stringstream buffer;
    buffer<<file.rdbuf();
    std::string input = buffer.str();
    file.close();
    std::cout<<"String from the file"<<input<<std::endl;
    root = h.HuffmanEncoding(input);
    h.generatehuffmancodes(root, "");
    h.huffmanencode(input);
    h.seebinary();

}
// #1111011111100100000010111101011100001101001000110100110100101010101101100111110100111000
// #11110111111001000000101111010111000011010010001101001101001010101011011001111101001110
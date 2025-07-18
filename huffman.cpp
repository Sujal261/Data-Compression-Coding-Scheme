#include<iostream>
#include<string>
#include<climits>
#include<vector>
#include<algorithm>
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
};


int main(){
    Huffman h;
    node* root;
    std::string input;
    std::string encoded_sequence;
    std::cout<<"Enter the sequence you want to encode"<<std::flush;
    std::cin>>input;
    root = h.HuffmanEncoding(input);
    h.generatehuffmancodes(root, "");
}

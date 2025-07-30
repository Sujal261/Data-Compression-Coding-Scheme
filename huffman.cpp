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
struct newdictionary{
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
        left = nullptr;
        right=nullptr;
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
        void huffmanencode(std::string input){
            std::string ouptut;
            std::string message;
             std::string number;
            for(char ch:input){
                for(int i =0;i<p;i++){
                    if(std::string(1,ch)==dict[i].data){
                        ouptut=ouptut+dict[i].code;
                        
                    }
                }
            }
            std::ofstream myfile("encoded.txt");
                myfile<<ouptut;
                myfile.close();
            std::ofstream file("encoded.bin",std::ios::binary|std::ios::app);
             
             std::string lent = std::to_string(input.length());
            
            for(int i =0;i<s;i++){
                 message= dict[i].data;
                number = dict[i].code;
                file<<message;
                 file<<":";
                file<<number;
                
                 file<<",";
                        }
                
                file<<lent;
                file<<";";
               

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
        newdictionary newdict[100];
        int w=0;
        std::string ans;
        std::string symbol ;
        std::string pode;
        std::string encodedfromfile;
        std::ifstream file("encoded.bin", std::ios::binary);
        std::stringstream buffer;
        std::string len;
        std::streampos pos;
        std::string somevalue;
        char ch;
        int d=0;
        while(file.get(ch)){
            
            if(ch==':'){
               
                newdict[d].data = somevalue;
               
                somevalue.clear();
                continue;
            }
            if(ch==','){
                newdict[d].code = somevalue;
                somevalue.clear();
                d=d+1;
                continue;
            }
            if(ch==';'){
                len = somevalue;
                pos = file.tellg();
                break;
            }
             somevalue = somevalue+ch;
             

        }
     
        file.clear();
        file.seekg(pos);
        while (file.get(ch)){
          std::bitset<8> bits(ch);
           encodedfromfile +=bits.to_string();
        }

        file.close();

        std::string s(1,'0');
        node* decoderoot = new node(s);
        for(int i =0;i<d;i++){
            symbol = newdict[i].data;
            pode = newdict[i].code;
           
            node* current = decoderoot;

            for(char bit :pode){
                if(bit =='0'){
                    if(!current->left) current->left = new node(s);
                    current = current->left;
                }else if(bit=='1'){
                    if(!current->right) current->right = new node(s);
                    current = current->right;
                }
            }
            current->data = symbol;

        }
        
        node* temp = decoderoot;
        int count =0;
        int leng = stoi(len);
        
        for(int i =0;count<leng;i++){
            if(encodedfromfile[i]=='0'){
                temp = temp->left;
            }
            else{
                 temp = temp->right;

            }
            if(temp->left == nullptr and temp->right == nullptr){
                ans+=temp->data;
                count = count+1;
                temp = decoderoot;
            }
        }
        ans = ans+'\0';
        std::cout<<ans<<std::endl;
    }
 };
int main(){
    Huffman h;
    node* root;
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

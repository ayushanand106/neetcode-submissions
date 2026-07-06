
class Node{
    public:
    Node* link[26];
    int prefix_cnt=0;
    int end_cnt=0;
    bool contain_letter(char ch){
        return link[ch - 'a']!=nullptr;
    }
    Node* get_char(char ch){return link[ch - 'a'];}
    void insert(char ch, Node* node){
        link[ch-'a']=node;
    }
    void decrease_end(){end_cnt--;}
    void increase_end(){end_cnt++;}
    void decrease_pref(){prefix_cnt--;}
    void increase_pref(){prefix_cnt++;}
    bool is_prefix(){return prefix_cnt!=0;}
    bool is_end(){return end_cnt!=0;}

};

class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* runner=root;
        for(auto& ch:word){
            if(!runner->contain_letter(ch)){
                runner->insert(ch,new Node());
            }
            runner=runner->get_char(ch);
            runner->increase_pref();
        }
        runner->increase_end();

    }
    
    bool search(string word) {
        Node* runner =root;
        for(auto& ch:word){
            if(!runner->contain_letter(ch)){
                return false;
            }
            runner=runner->get_char(ch);
        }
        return runner->is_end();
        
    }
    
    bool startsWith(string prefix) {
        Node* runner =root;
        for(auto& ch:prefix){
            if(!runner->contain_letter(ch)){
                return false;
            }
            runner=runner->get_char(ch);
        }
        return runner->is_prefix();
        
    }
};

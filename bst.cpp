#include <iostream>
#include <string>

using namespace std;
class bst_node{
    public:
    string s_id;
    string name;
    double score;
    bst_node *left, *right;
    bst_node();
    bst_node(string s1, string s2, double n);
    void set_data(string s1, string s2, double n);
};

bst_node::bst_node(){

}
bst_node::bst_node(string s1, string s2, double n){
    s_id = s1;
    name = s2;
    score = n;
}
void bst_node:: set_data(string s1, string s2, double n){
    s_id = s1;
    name = s2;
    score = n;
}

class bst_tree{
    bst_node* root;
    int csize;
    public:
    bst_tree();
    void insert_node(bst_node t);
    void show_inorder();
    bst_node search(string tid);
};
bst_tree::bst_tree(){
    int csize =0;
}
void inorder(bst_node *t);

void bst_tree::show_inorder(){
    inorder(root);
}
void inorder(bst_node *t){
    if(t==NULL) return ;

    inorder(t->right);
    cout << t->s_id <<" : "<<t->name<<" : "<<t->score<<endl;
    inorder(t->left);
}
void bst_tree:: insert_node(bst_node t){
    bst_node *p;
    bst_node *temp;
    temp = new bst_node;
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL){
        root = temp;
        return ;
    }
    p=root;
    while(1){
        if(p->s_id == t.s_id){
            cout << t.s_id <<"이미 존재하는 학번입니다\n";
            return ;
        }
        if(p->s_id < t.s_id){//입력할 값이 더 크다면 right
            if(p->right == NULL){
                p->right = temp;
                return ;
            }else
            p = p->right;
        }else{
            if(p->left == NULL){
                p->left = temp;
                return ;
            }else
            p = p->left;
        }
    }
}
bst_node bst_tree::search(string tid){
    /*
    root가 일치하면 변환
    while(1)반복작업
    p이면 반환
    tid가 더 크면 오른쪽 으로
    else
    */
    bst_node *p;
    if(root==NULL){
        bst_node temp;
        temp.set_data("00000000", "None", -1);
        cout << tid << "라는 학번이 존재하지 않습니다\n";
        return temp;
    }
    p = root;
    while(1){
        if(p->s_id == tid){
            return (*p);
        }
        if(p->s_id > tid){
            if(p->left == NULL){
                bst_node temp;
                temp.set_data("00000000", "None", -1);
                cout << tid << "라는 학번이 존재하지 않습니다\n";
                return temp;
            }
            p=p->left;
        }else{
            if(p->right == NULL){
                bst_node temp;
                temp.set_data("00000000", "None", -1);
                cout << tid << "라는 학번이 존재하지 않습니다\n";
                return temp;
            }
            p=p->right;
        }
    }
}
int main(){
    bst_node temp;
    bst_tree t1;
    temp.set_data("21900013", "Kim", 6.5);
    t1.insert_node(temp);
    temp.set_data("21900136", "Lee", 8.8);
    t1.insert_node(temp);
    temp.set_data("21900333", "Park", 9.2);
    t1.insert_node(temp);
    temp.set_data("21800442", "Choi", 7.1);
    t1.insert_node(temp);
    temp.set_data("21900375", "Ryu", 5.4);
    t1.insert_node(temp);
    temp.set_data("21700248", "Cho", 6.3);
    t1.insert_node(temp);
    cout << "\n\n Node List : inorder sequence \n";
    t1.show_inorder();
    string s_key = "21800442";
    temp = t1.search(s_key);
    cout << "\n -- " << s_key << "\'s record ---" << endl;
    cout << " Student ID   : "<< temp.s_id << endl;
    cout << " Student Name : "<< temp.name << endl;
    cout << " Score  : " << temp.score << endl;
    return 0;
}

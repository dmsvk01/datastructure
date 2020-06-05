#include <iostream>
#include <string>

using namespace std;

class bst_node{
    public:
    string phone;
    string birth;
    string name;
    bst_node *left, *right;
    bst_node();
    bst_node(string s1, string s2, string s3);
    void set_data(string s1, string s2, string s3);
};

bst_node::bst_node(){

}
bst_node::bst_node(string s1, string s2, string s3){
    phone = s1;
    birth = s2;
    name = s3;
}
void bst_node:: set_data(string s1, string s2, string s3){
    phone = s1;
    birth = s2;
    name = s3;
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
    cout << t->phone <<" : "<<t->birth<<" : "<<t->name<<endl;
    inorder(t->left);
}
void bst_tree::insert_node(bst_node t){
        /*
        temp설정
        널이면 넣고 리턴
        while 
        같으면 이미있음
        대소연산 작업
        */
    bst_node *p;
    bst_node *temp;
    temp = new bst_node;
    *temp = t;
    temp->left = NULL;
    temp->right = NULL;
    
    if(root==NULL){
        root = temp;
        return;
    }
    p=root;
    while(1){
        if(p->name == t.name){
            cout << "이미 같은 이름이 있습니다.\n";
            return ;
        }
        if(p->name > t.name){
            if(p->left == NULL){
                p->left = temp;
                return ;
            }else{
                p=p->left;
            }
        }else{
            if(p->right == NULL){
                p->right = temp;
                return ;
            }else{
                p=p->right;
            }
        }
    }
}
bst_node bst_tree::search(string n){
    /*
    root 널이면 리턴
    while
    p이면 출력
    대소비교 연산
    */
    bst_node *p;
    p=root;
    if(p==NULL){
        bst_node temp;
        temp.set_data("000-0000-0000", "00000000", "None");
        return temp;
    }
    while(1){
        if(p->name == n){
            return (*p);
        }
        if(p->name > n){
            if(p->left == NULL){
                //못찾음
                bst_node temp;
                temp.set_data("000-0000-0000", "00000000", "None");
                return temp;
            }else
            p=p->left;
        }else{
            if(p->right == NULL){
                //못찾음
                bst_node temp;
                temp.set_data("000-0000-0000", "00000000", "None");
                return temp;
            }else
            p=p->right;
        }
    }
}

/*실습 과제 
: {전화번호, 생일 . .  } 목록을 
binary search tree로 구현
(Menu 예)1. 새로운 원소 추가2. 원소 조회3. 전체 목록 보기4. 종료명령 */
void insert();
void show_node();
void show_all();

bst_tree t1; // 전역변수로 t1선언 tree.

int main(){
    int n;
    while(1){
        cout << "1.새로운 원소 추가 2.원소 조회 3.전체 목록 보기 4.종료" << endl;
        cin >> n;
        switch(n){
            case 1 :
                insert();
                break;
            case 2 :
                show_node();
                break;
            case 3 :
                show_all();
                break;
            case 4 :
                return 0;
        }
    }
}

void insert(){
    string phone;
    string birth;
    string name;
    bst_node p;
    cout << "전화번호는 ? ";
    cin >> phone;
    cout << "생일은 ? ";
    cin >> birth;
    cout << "이름은 ? ";
    cin >> name;
    p.set_data(phone, birth, name);
    t1.insert_node(p);
}
void show_node(){
    string name;
    bst_node t;
    cout << "찾을 분의 이름을 입력하시오 > ";
    cin >> name;
    t = t1.search(name);
    cout << t.phone <<" : "<<t.birth<<" : "<<t.name<<endl;
}
void show_all(){
    t1.show_inorder();
}

#include <iostream>
#include <string>
#define MAX 100

using namespace std;


/*
Programming Assignment 14 2020-04-15 00:00 ~ 2020-05-07 00:00
Date
Writer hjkim(김호준)
Read0
{성명, 점수}의 원소를 저장하는 Heap 구현

다음과 같은 main 함수가 동작하는프로그램을 작성
*/

class element{
    public:
    string name;
    double score;
    void set_data(string n, double s);
};

void element :: set_data(string n, double s){
    name = n;
    score = s;
}

class my_heap{
    element h[MAX];
    int size;
    void adjust(int t_root);
    public:
    my_heap();
    my_heap(element p[], int n);
    void insert_heap(element a);
    element delete_heap();
    int h_size();
    bool heap_full();
    bool heap_empty();
};
void my_heap::adjust(int t_root){
    int t = t_root;

    element temp = h[t];
    double key = h[t].score;
    int child = t*2;
    while(child <= size){
        if(child < size && h[child].score < h[child+1].score){
            child++;
        }
        if(key > h[child].score){
            break;
        }else{
            h[child/2] = h[child];
            child*=2;
        }
    }
    h[child/2]  = temp;
}
my_heap::my_heap(element p[], int n){
    for(int i=1; i<=n ;i++){
        h[i] = p[i-1];
    }
    size = n;
    for(int i = n/2; i>=1; i--){
        adjust(i);
    }
}
my_heap::my_heap(){
    size =0;
}
int my_heap::h_size(){
    return size;
}
void my_heap::insert_heap(element t){
    size++;
    int k = size;
    while(1){
        if(t.score <= h[k/2].score || k==1) break;
        h[k] = h[k/2];
        k/=2;
    }
    h[k] = t; 
}

element my_heap::delete_heap(){
    element t = h[1];
    element temp = h[size];
    size--;
    int parent =1;
    int child=2;
    while(1){
        if(child > size) break;
        if(child < size && h[child].score < h[child+1].score)
            child++;
        if(temp.score >= h[child].score) break;
        h[parent] = h[child];
        parent = child;
        child*=2;
    }
    h[parent] = temp;
    return t;
}

bool my_heap::heap_full(){
    if(h_size() >= MAX) return true;
    else return false;
}
bool my_heap::heap_empty(){
    if(size==0) return true;
    else return false;
}

int main(){
    element   temp;
    element a[10] = { {"Kim",88}, {"Lee", 77}, {"Park", 98}, {"Choi", 74}, {"Ryu",94}, {"Cho", 85}  };
    my_heap h1(a, 6);
    while (h1.h_size()>0){
        temp = h1.delete_heap();
        cout << temp.name << " : " << temp.score << "\n";
    }
    return 0;
}
/*
< 예상 출력 >
Park : 98
Ryu : 94
Kim : 88
Cho : 85 
Lee : 77
Choi : 74
*/

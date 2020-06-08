#include <iostream>
#include <string>
#define MAX 100

using namespace std;

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
    int score_sum();
    double score_average();
    int node_delete_by_name(string n);
};
int summation(element a[], int troot, int _size){
    if(troot > _size) return 0;

    return a[troot].score + summation(a, troot*2, _size) + summation(a, troot*2+1, _size);
}
int my_heap::score_sum(){
    return summation(h, 1, size);
}
double my_heap::score_average(){
    if(size==0) return 0.0;
    return (double)score_sum()/size;
}

void heap_adjust(element a[], int troot, int size){
    size--;
    int parent = troot;
    int child = troot*2;
    while(child <= size){
        if(child < size && a[child].score < a[child+1].score)
            child++;
        if(a[troot].score > a[child].score) break;
        a[parent] = a[child];
        parent = child;
        child*=2;
    }
    a[child/2] = a[troot];
    //cout << "troot가 들어간곳 : " << child/2<< endl;
    return ;
}

int node_delete(element a[], int troot, string n, int size){
    if(troot > size){
        //cout << "초과 : " << troot << endl;
        return 0;
    }
    //cout << "name : " << a[troot].name << endl;
    //cout << "찾는 name : " << n << endl;
    if(a[troot].name==n){
        //cout << "발견!!!! name : " << n << endl;
        element temp = a[size];
        a[size] = a[troot];
        a[troot] = temp;
        //cout << "a[" << size << "] : " << a[size].name << endl;
        //cout << "a[" << troot << "] : " << a[troot].name << endl;
        heap_adjust(a,troot,size);
        return 1;
    }
    int result = node_delete(a, troot*2, n, size);
    if(result == 1) return result;
    return node_delete(a, troot*2+1, n, size);
}
int my_heap::node_delete_by_name(string n){
    //cout << "size : " << size << endl;
    if(size == 0 ) return 0;
    if(node_delete(h, 1, n, size)==1){
        size--;
        return 1;
    }
    return 2;
}

void my_heap::adjust(int t_root){
    int t = t_root;

    element temp = h[t];
    double key = h[t].score;
    int child = t*2;
    while(child <= size){//사이즈 범위를 초과할때 까지 반복
        if(child < size && h[child].score < h[child+1].score){//오른쪽 노드가 있고,,,, 오른쪽 노드가 더 크다면 오른쪽 노드로
            child++;
        }
        if(key > h[child].score){//노드보다 키값이 더 크다면 브레이크
            break;
        }else{
            h[child/2] = h[child];//아니라면 해당 차일드 값을 페런츠값과 바꾼후
            child*=2;//해당 차일드의 차일드로 넘어감.
        }
    }
    h[child/2]  = temp;//
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
    element t = h[1];//반환할 값 (가장 큰)
    element temp = h[size];//가장작은 값. root에서 부터 내려가면서 자리찾기 할 값.
    size--;
    int parent =1;
    int child=2;
    while(1){
        if(child > size) break;//차일드가 사이즈를 벗어날때 까지 반복.
        if(child < size && h[child].score < h[child+1].score)//오른쪽 차일드가 있고, 그것이 더 크다면 오른쪽 차일드 선택.
            child++;
        if(temp.score >= h[child].score) break;// 자리찾으면서 내려가는데 temp가 더 크면 당연히 맞는자리니까 break;

        //아래의 차일드의 값이 더 크다면
        h[parent] = h[child];//아래의 차일드 값을 페런츠로 올림.
        parent = child;//페런츠를 차일드값으로 하여 한칸더 내려옴
        child*=2;//차일드도 한칸더 내려옴.
    }
    h[parent] = temp;//값을 찾았다면 그 자리(페런츠)에 temp값을 집어넣음.
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
int main ()
{
    element temp;
    element a [10] = {{"Kim", 88}, {"Lee", 77}, {"Park", 98}, {"Choi", 74}, {"Ryu", 94 }, { "Cho", 85}};
    my_heap h1 (a, 6);
    cout << "노드 수 :"<< h1.h_size () << endl;
    cout << "Score Sum ="<< h1.score_sum () << endl;
    cout << "점수 평균 ="<< h1.score_average () << endl;
    int b = h1.node_delete_by_name("Kim");
    cout << "b : " << b <<endl;
    cout << "\n-- 삭제 작업 후--\n";
    cout << "노드 수 :"<< h1.h_size () << endl;
    cout << "Score Sum ="<< h1.score_sum () << endl;
    cout << "점수 평균 ="<< h1.score_average () << endl;
    while (h1.h_size ()> 0) {
            temp = h1.delete_heap ();
            cout << temp.name << ":"<< temp.score << "\n";
    }
    return 0;
}
/*
<예상 출력>
노드 수 : 6
점수 합 = 516
점수 평균 = 86

-삭제 작업 후. -

노드 수 : 5
점수 합계 = 428
평균 점수 = 85.6
Park : 98
Ryu : 94
Cho : 85
Lee : 77
Choi : 74
*/

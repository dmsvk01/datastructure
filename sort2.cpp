#include <iostream>
#include <string>

using namespace std;

class s_record{
    public:
    string s_id;
    string s_name;
    double s_score;
};

void insertion_sort(s_record a[], int size);
void bubble_sort(s_record a[], int size);
void selection_sort(s_record a[], int size);



void show_thelist(s_record a[], int size){
    for(int i=0; i<size; i++){
        cout << a[i].s_id << " : " << a[i].s_name << " - " << a[i].s_score << endl;
    }
}


int main()
{
     s_record s_list[12] = { {"21900013", "Kim", 6.5}, {"21900136", "Lee", 8.8 }, {"21900333", "Park", 9.2 },
                            { "21800442", "Choi", 7.1}, {"21900375", "Ryu", 5.4  }, {"21700248", "Cho", 6.3 },
                            { "21700302", "Jung", 8.3}, {"21800255", "Han", 6.9  }, {"21800369", "Kang", 6.3 },
                            { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo", 7.9 } };
    int n = 12;

    insertion_sort(s_list, n);
    //bubble_sort(s_list, n);
    //selection_sort(s_list, n);     

    cout << "< The result of the sorting >" << endl;
    show_thelist(s_list, n);
    return 0;
}

void insertion_sort(s_record a[], int size){
    for(int i=1; i<size; i++){
        s_record tmp = a[i];
        int k=i-1;
            while(k>=0 && a[k].s_id > tmp.s_id){
                a[k+1] = a[k];
                k--;
            }
            a[k+1] = tmp;
        }
    }

void bubble_sort(s_record a[], int size){
    for(int i=size-1; i>=0; i--){
        for(int j=0; j<i; j++){
            if(a[j].s_id > a[j+1].s_id){
                s_record temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void selection_sort(s_record a[], int size){
    for(int i=0; i<size; i++){
        int min=i;
        for(int j=i+1; j<size; j++){
            if(a[min].s_id > a[j].s_id){
                min = j;
            }
            s_record temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}


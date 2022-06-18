#include <bits/stdc++.h>
using namespace std;
void insertion_sort(vector <int> &vec){
    int key;
    for(int i=1;i<vec.size();++i){
        key=vec[i];
        int j=i-1;
        while (j>=0&&vec[j]>key)
        {
            vec[j+1]=vec[j];
            j--;
        }
        vec[j+1]=key;

    }
}
void print(vector<int> & vec){
    for (int i=0;i<vec.size();++i){
        cout<<vec[i]<<" ";
    }
}
int main(){
    vector<int> vec ={3,15,6,11,12,2,1,4,6};
	cout <<"Input interge Array::\n";
	print(vec);
	insertion_sort(vec);
	cout << "\nSort using Inerstion sort: \n";
	print(vec);
    return 0;
}
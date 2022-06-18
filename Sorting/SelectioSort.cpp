#include<bits/stdc++.h>
using namespace std;
void selection_sort(vector<int>& vec)
{
    int min_idx;
    for (int i=0; i < vec.size(); ++i)
    { 
        min_idx = i;
        for (int j = i+1; j < vec.size(); ++j)
        {
            if (vec[j] < vec[min_idx])
                min_idx = j;
        }
        if(min_idx!=i)
        swap(vec[min_idx], vec[i]);
    }
}
void print(vector<int>& vec)
{
    int i = 0;
    for (;i < vec.size()-1; ++i)
        cout << vec[i] << ", ";
    cout << vec[i];
    cout << endl;
}
int main(){
	vector<int> vec ={3,15,6,11,12,2,1,4,6};
	cout <<"Input interge Array::";
	print(vec);
	selection_sort(vec);
	cout << "Sort using Selection sort: ";
	print(vec);
	return 0;
}
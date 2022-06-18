#include<bits/stdc++.h>
// using namespace std;
void swap(int &ino1,int &ino2){
	int temp =ino1;
	ino1=ino2;
	ino2=temp;
}
int main(){
	int size=0;
	int arr[100];
	int swapped=1;
	std::cin>>size;
	for(int i=0;i<size;i++){
		std::cin >>arr[i];
	}
	for(int i=0;i<size&&swapped;i++){
		std::cout<<"outer\n";
		swapped=0;
		for(int j=0;j<size-i-1;j++){
			std::cout<<"inner\n";
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				swapped=1;
			}
		}
	}
	for(int i=0;i<size;i++){
		std::cout <<arr[i]<<" ";
	}
	return 0;
} 
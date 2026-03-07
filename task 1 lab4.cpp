# include <iostream>
# include <string>
using namespace std;
int main(){
	int rows = 6;
	int** arr = new int *[rows];
	for(int i=0; i<rows; i++){
		arr[i] = new int[i+1];
		arr[i][0] = 1;
		arr[i][i] = 1;
		for(int j=1; j<i; j++){
			arr[i][j] = arr[i-1][j]+arr[i-1][j-1];
		}
	}
	for(int i=0; i<rows; i++){
		for(int s = 0; s < rows-i-1; s++){
                 cout << " ";}
		for(int j=0; j<=i;j++){
			
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0; i<rows; i++){
		delete[] arr[i];
	}
	delete []arr;
	return 0;
}
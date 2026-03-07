//bsdsf25m053
# include<iostream>
# include <string>
using namespace std;
struct matrix{
	int rows;
	int cols;
	int** data;
};
void createMatrix (matrix &m, const int row = 1, const int col =1){
	m.rows = row;
	m.cols = col;
	m.data = new int*[row];
	for(int i=0; i<row; i++){
		m.data[i] = new int[col];
	}
}
void input(matrix &m){
	for(int i=0; i<m.rows; i++){
		for(int j=0; j<m.cols; j++){
			cin>>m.data[i][j];
		}
	}
}
int& at(matrix m, const int r, const int c){
	int a = m.data[r][c];
	return m.data[r][c];
}
void printMatrix (const matrix m){
	for(int i=0; i<m.rows; i++){
		for(int j=0; j<m.cols; j++){
			cout<<m.data[i][j]<<" ";
		}
		cout<<endl;
	}
}
int isIdentity(const matrix m){
	for(int i=0; i<m.rows; i++){
		for(int j=0; j<m.cols; j++){
			if(i==j && m.data[i][j] != 1){
				return 0;
			}
		}
	}
	return 1;
}
bool isRectangular (const matrix m){
	if(m.rows!= m.cols){
		return true;
	}
		return false;
}
bool isDiagonal(const matrix m){
	if(m.rows!=m.cols){
		return false;
	}
	for(int i=0; i<m.rows; i++){
		for(int j=0; j<m.cols; j++){
			if(i!=j && m.data[i][j] !=0){
				return false;
			}
		}
	}
	return true;
}
bool isNullMatrix(const matrix m){
	for(int i=0; i<m.rows; i++){
		for(int j=0; j<m.cols; j++){
			if(m.data[i][j]!= 0){
				return false;
			}
		}
	}
	return true;
}
matrix getMatrixCopy(const matrix m){
	matrix a;
	createMatrix(a,m.rows, m.cols);
	for(int i=0; i<m.rows; i++){
		for(int j=0; j<m.cols; j++){
			a.data[i][j] = m.data[i][j];
		}
	}
	return a;
}
void freeMatrix(matrix& m){
	for(int i=0; i<m.rows; i++){
		delete[]m.data[i];
	}
	delete[]m.data;
}
bool isequal(const matrix m1, const matrix m2){
	if(m1.rows!= m2.rows){
		return false;
	}
	for(int i=0; i<m1.rows; i++){
		for(int j=0; j<m1.cols; j++){
			if(m1.data[i][j]!= m2.data[i][j]){
				return false;
			}
		}
	}
	return true;
}
matrix transpose(const matrix m){
	matrix t;
	createMatrix(t, m.cols, m.rows);
	for(int i=0; i<m.rows; i++){
		for(int j=0; j<m.cols; j++){
			t.data[j][i] = m.data[i][j];
		}
	}
	return t;
}
matrix minus(const matrix m1, const matrix m2){
	matrix a;
	createMatrix(a,m1.rows, m1.cols);
	for(int i=0; i<m1.rows; i++){
		for(int j=0; j<m1.cols; j++){
			a.data[i][j] = m1.data[i][j] - m2.data[i][j];
		}
	}
	return a;
}
void reSize(matrix &m, int newrow, int newcol){
	int **newdata = new int*[newrow];
	for(int i=0; i<newrow; i++){
		newdata[i] = new int [newcol];
	}
	for(int i=0; i<newrow; i++){
		for(int j=0; j<newcol; j++){
			if(i<m.rows){
			newdata[i][j] = m.data[i][j];}
			else{
				newdata[i][j] = 0;
			}
		}
	}
	m.rows = newrow;
	m.cols = newcol;
	delete[] m.data;
	m.data = newdata;
}
bool isSymmetric(const matrix m){
	for(int i=0; i<m.rows; i++){
		for(int j=0; j<m.cols; j++){
			if(m.data[i][j]!=m.data[j][i]){
				return false;
			}
		}
	}
	return true;
}
bool isSkewSymmetric (const matrix m){
	matrix a = transpose(m);
	for(int i=0; i<m.rows; i++){
		for(int j=0; j<m.cols; j++){
		if(a.data[j][i]!= -m.data[i][j]){
				return false;
			}
		}
	}
	return true;
}
matrix addMatrix(const matrix m1, const matrix m2){
	matrix a;
	createMatrix(a,m1.rows, m1.cols);
	for(int i=0; i<m1.rows; i++){
		for(int j=0; j<m1.cols; j++){
			a.data[i][j] = m1.data[i][j]+ m2.data[i][j];
		}
	}
	return a;
}
matrix multiply(const matrix m1, const matrix m2){
	
	matrix a;
	createMatrix(a, m1.rows, m2.cols);
	for(int i=0; i<m1.rows; i++){
		for(int j=0; j<m2.cols; j++){
			for(int k=0; k<m1.cols; k++){
				a.data[i][j] += m1.data[i][k]*m2.data[k][j];
			}
		}
	}
	return a;
}
bool isTriangle(const matrix m){
	for(int i=0; i<m.rows;i++){
		for(int j=0; j<m.cols; j++){
			if(m.data[i][j] != m.data[j][i]){
				return false;
			}
		}
	}
	return true;
}
bool isLowerTriangle (const matrix m){
	for(int i=0; i<m.rows;i++){
		for(int j=0; j<m.cols; j++){
			if(m.data[i][j] != 0){
				return false;
			}
		}
	}
	return true;
}
bool isUpperTriangle(const matrix m){
	for(int i=0; i<m.rows;i++){
		for(int j=0; j<m.cols; j++){
			if(m.data[j][i] != 0){
				return false;
			}
		}
	}
	return true;
}
int main(){
	matrix m;
	int row = 2;
	int col = 2;
	createMatrix(m, row, col);
	input(m);
	printMatrix(m);
	int identity = isIdentity(m);
	cout<<"identity "<<identity<<endl;
	bool rectangular = isRectangular(m);
	cout<<"rectangle "<<rectangular<<endl;
	bool diagonal = isDiagonal(m);
	cout<<"diagonal "<<diagonal<<endl;
    int *a = &at(m,1,2);
	cout<<a<<endl;
	bool null = isNullMatrix(m);
	cout<<"null "<<null<<endl;
	matrix duplicate = getMatrixCopy(m);
	cout<<"duplicate matrix is: "<<endl;
	printMatrix(duplicate);
	bool equal = isequal(m, duplicate);
	cout<<"equal "<<equal<<endl;
	cout<<endl;
	cout<<"transpose of m: "<<endl;
	matrix transposee;
	transposee = transpose(m);
	printMatrix(transposee);
	cout<<"result of matrix minus: ";
	cout<<endl;
	bool symmetric = isSymmetric(m);
	cout<<"symmetric: "<<symmetric<<endl;
	bool skew = isSkewSymmetric(m);
	cout<<"skew symmetric: "<<skew<<endl;
	cout<<"add matrix result: "<<endl;
	matrix add = addMatrix(m,duplicate);
     printMatrix(add);
     cout<<endl;
     cout<<"multiply:"<<endl;
     matrix mul;
	 mul =  multiply(m,duplicate);
     printMatrix(mul);
     bool tri = isTriangle(m);
     cout<<"triangle: "<<tri<<endl;
     bool lower = isLowerTriangle(m);
     cout<<"lower: "<<lower<<endl;
     bool upper = isUpperTriangle(m);
     cout<<"upper: "<<upper<<endl;
	freeMatrix(m);
	freeMatrix(mul);
	freeMatrix(transposee);
	freeMatrix(add);
	freeMatrix(duplicate);
	return 0;
}

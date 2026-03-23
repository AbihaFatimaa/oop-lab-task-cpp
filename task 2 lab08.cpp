//bsdsf25m053
# include <iostream>
# include <string>
using namespace std;
class Matrix
{
	private:
		int row;
		int col;
		int **data;
	public:
		Matrix();
		Matrix(const Matrix &);
		Matrix(int, int);
		void setRow(int);
		void setCol(int);
		int getRow() const;
		int getCol() const;
		int& at(const int r, const int c); 
		void printMatrix() const;
		int isIdentity() const;
		bool isRectangular()const ;
		bool isDiagonal()const ;
		bool isNullMatrix() const ;
		bool isLowerTriangular() const;
		bool isUpperTriangular() const;
		bool isTriangular()const ;
		Matrix getMatrixCopy()const;
		bool isEqual(const Matrix m2) const;
		void reSize(const int newrow, const int newcol);
		bool isSymmetric() const;
		bool isSkewSymmetric()const ;
		~Matrix();
		Matrix Transpose() const;
		Matrix add(const Matrix& ) const;
		Matrix minus(const Matrix& ) const;
		Matrix multiply(const Matrix& ) const;
		void input();
		void display();
		Matrix& operator=(const Matrix & ref);
		Matrix operator+(const Matrix & ref);
		Matrix operator-(const Matrix & ref);
		Matrix operator*(const Matrix & ref);
};
Matrix Matrix::operator*(const Matrix& ref){
		if(col!=ref.row){
				cout<<"multiplication not possible!";
				return Matrix(0,0);
			}
			Matrix result(row, ref.col);
			for(int i=0; i<row; i++){
				for(int j=0; j<ref.col; j++){
					result.data[i][j]=0;
					for(int k=0; k<col; k++){
						result.data[i][j] += data[i][k]*ref.data[k][j];
					}
				}
			}
			return result;
}
Matrix Matrix::operator-(const Matrix& ref){
	if(row != ref.row || col != ref.col) {
            cout << "Subtraction not possible";
            return Matrix(0,0);
        }
			Matrix m1(ref.row, ref.col);
			for(int i=0; i<row; i++){
				for(int j=0; j<col; j++){
					m1.data[i][j] = data[i][j] - ref.data[i][j];
				}
			}
			return m1;
}
Matrix Matrix::operator+(const Matrix& ref){
	if(row != ref.row || col != ref.col) {
            cout << "Addition not possible";
            return Matrix(0,0);
        }
			Matrix m1(ref.row, ref.col);
			for(int i=0; i<row; i++){
				for(int j=0; j<col; j++){
					m1.data[i][j] = data[i][j]+ref.data[i][j];
				}
			}
			return m1;
}
Matrix& Matrix::operator=(const Matrix& ref){
	if(this == &ref){
		return *this;
	}
	if (data != nullptr) {
        for (int i = 0; i < row; i++) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
	this->row = ref.row;
	this->col = ref.col;
	data=new int*[row];
		for(int i=0; i<row; i++){
			data[i] = new int[col];
		}
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				data[i][j] = ref.data[i][j];
			}
		}
		return *this;
}
	Matrix::Matrix(){
	row = 1;
    col = 1;
    data = new int*[row];
    for(int i=0;i<row;i++){
        data[i] = new int[col];
        for(int j=0; j<col; j++){
        data[i][j] = 0;
    }
    }
	}
	Matrix::Matrix(const Matrix& m){
		row = m.row;
		col=m.col;
		data=new int*[row];
		for(int i=0; i<row; i++){
			data[i] = new int[col];
		}
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				data[i][j] = m.data[i][j];
			}
		}
	}
	Matrix::Matrix(int a, int b){
		row = a;
		col = b;
		data= new int*[row];
		for(int i=0; i<row; i++){
			data[i] = new int[col];
			for(int j=0; j<col; j++){
				data[i][j] = 0;
			}
		}
	}
	void Matrix::setCol(int a){
		col = a;
	}
	void Matrix::setRow(int b){
		row = b;
	}
	int Matrix::getCol() const{
		return col;
	}
	int Matrix::getRow()const{
		return row;
	}
	int& Matrix::at(const int r, const int c){
		return data[r][c];
	}
	void Matrix::printMatrix() const{
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				cout<<data[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	int Matrix::isIdentity() const{
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(i==j && data[i][j] != 1){
				return 0;
			}
			if(i!=j && data[i][j] != 0) return 0;
		}
	}
	return 1;
 }
 	bool Matrix::isRectangular()const{
 		if(row!=col){
 			return true;
		 }
		 return false;
	 }
	 bool Matrix::isDiagonal()const{
	 	if(row!=col){
		return false;
	}
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(i!=j && data[i][j] !=0){
				return false;
			}
		}
	}
	return true;
	 }
	 bool Matrix::isNullMatrix() const{
	 	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(data[i][j]!= 0){
				return false;
			}
		}
	}
	return true;
	 }
	 bool Matrix::isLowerTriangular() const{
	 	for(int i=0; i<row;i++){
			for(int j=i+1; j<col; j++){
				if(data[i][j]!=0){
					return false;
				}
			}
		}
		return true;
	 }
	 bool Matrix::isUpperTriangular() const{
	 	for(int i=0; i<row; i++){
			for(int j=0; j<i; j++){
				if(data[i][j]!=0){
					return false;
				}
			}
		}
		return true;
	 }
	 bool Matrix::isTriangular()const{
	 	if(isUpperTriangular() || isLowerTriangular()){
	 		return true;
		 }
		 return false;
	 }
	 Matrix Matrix::getMatrixCopy()const{
	 	Matrix a(row, col);
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			a.data[i][j] = data[i][j];
		}
	}
	return a;
	 }
	 bool Matrix::isEqual(const Matrix m2) const{
	 	if(row != m2.row || col != m2.col){
		return false;
	}
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(data[i][j]!= m2.data[i][j]){
				return false;
			}
		}
	}
	return true;
	 }
	 void Matrix::reSize(const int newrow, const int newcol){
	 	int **newdata = new int*[newrow];
	for(int i=0; i<newrow; i++){
		newdata[i] = new int [newcol];
	}
	for(int i=0; i<newrow; i++){
		for(int j=0; j<newcol; j++){
			if(i<row){
			newdata[i][j] = data[i][j];}
			else{
				newdata[i][j] = 0;
			}
		}
	}
	for(int i=0;i<row;i++)
    delete[] data[i];

	delete[] data;
    row = newrow;
	col = newcol;
	data = newdata;
	 }
	 bool Matrix::isSymmetric() const{
	 	 if(row != col)
        return false;
	 	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(data[i][j]!=data[j][i]){
				return false;
			}
		}
	}
	return true;
	 }
	 bool Matrix::isSkewSymmetric()const{
	 	if(row != col) 
		 return false;

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(data[i][j] != -data[j][i])
				return false;
		}
	}
	return true;
	 }
	 Matrix::~Matrix(){
	 	for(int i=0; i<row; i++){
	 		delete[] data[i];
		 }
		 delete[]data;
	 }
	 Matrix Matrix::Transpose() const{
	 	Matrix t(col, row);
	 for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			t.data[j][i] = data[i][j];
		}
	}
	return t;
	 }
	 Matrix Matrix::add(const Matrix& m ) const{
	 	if(row != m.row || col != m.col) {
            cout << "Addition not possible";
            return Matrix(0,0);
        }
			Matrix m1(m.row, m.col);
			for(int i=0; i<row; i++){
				for(int j=0; j<col; j++){
					m1.data[i][j] = data[i][j]+m.data[i][j];
				}
			}
			return m1;
	 }
	 Matrix Matrix::minus(const Matrix& m) const{
	 	if(row != m.row || col != m.col) {
            cout << "Subtraction not possible";
            return Matrix(0,0);
        }
			Matrix m1(m.row, m.col);
			for(int i=0; i<row; i++){
				for(int j=0; j<col; j++){
					m1.data[i][j] = data[i][j] - m.data[i][j];
				}
			}
			return m1;
	 }
	 Matrix Matrix::multiply(const Matrix& m ) const{
	 	if(col!=m.row){
				cout<<"multiplication not possible!";
				return Matrix(0,0);
			}
			Matrix result(row, m.col);
			for(int i=0; i<row; i++){
				for(int j=0; j<m.col; j++){
					result.data[i][j]=0;
					for(int k=0; k<col; k++){
						result.data[i][j] += data[i][k]*m.data[k][j];
					}
				}
			}
			return result;
	 }
	 void Matrix::input(){
			for(int i=0; i<row; i++){
				for(int j=0; j<col; j++){
					cin>>data[i][j];
				}
			}
		}
		void Matrix::display(){
				for(int i=0; i<row; i++){
				for(int j=0; j<col; j++){
					cout<<data[i][j]<<" ";
				}
				cout<<endl;
			}
		}
int main() {
	Matrix m1(2,2);
	m1.input();
	Matrix m2(2,2);
	m2.input();
	cout<<"Null Matrix: "<< m1.isNullMatrix()<<endl;
	Matrix m3(2,2);
	m3.input();
	m3.display();
	cout<<"M1 equal M2: "<<m1.isEqual(m2)<<endl;
	cout<<"rectagle: "<<m3.isRectangular()<<endl;
	cout<<"Diagonal: "<<m3.isDiagonal()<<endl;
	cout<<"lower tri: "<<m2.isLowerTriangular()<<endl;
	cout<<"upper tri: "<<m1.isUpperTriangular()<<endl;
	Matrix add = m1.add(m2);
	add.display();
	Matrix sub = m1.minus(add);
	sub.display();
	cout<<"skew symmetric: "<<m1.isSkewSymmetric()<<endl;
	cout<<"symmetric: "<<m2.isSymmetric()<<endl;
	cout<<"multiplication: "<<endl;
	Matrix mul = m1.multiply(m3);
	mul.display();
	Matrix a;
	a = m1+m2;
	cout<<"addition through operator: "<<endl;
	a.display();
	Matrix b;
	b = m1-m2;
	cout<<"subtraction through operator: "<<endl;
	b.display();
	a=b;
	cout<<"assignment operator: "<<endl;
	a.display();
	Matrix c ;
	c=a*b;
	cout<<"Multiplication through operator: "<<endl;
	c.display();
	return 0;
	   }


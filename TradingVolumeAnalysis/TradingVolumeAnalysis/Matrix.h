#ifndef Matrix_H
#define Matrix_H

//define a customized matrix class
template<class T> class Matrix {
private:
	int dim_row;
	int dim_col;
	T** data;
public:
	//constructors and destructors
	Matrix(int, int);
	Matrix(const Matrix<T>&);//copy constructor
	~Matrix();

	//operators overloading
	Matrix<T>& operator =(const Matrix<T>&);//overloading assignment operator
	Matrix<T> operator *(const T&) const;//matrix times a scaler
	Matrix<T> operator *(const Matrix<T>&) const;//matrix dot-product matrix
	Matrix<T> operator /(const Matrix<T>&) const;//matrix dot-divide matrix
	Matrix<T> operator +(const T&) const;//matrix plus a scaler
	Matrix<T> operator +(const Matrix<T>&) const;//matrix dot-sum matrix
	Matrix<T> operator %(const Matrix<T>&) const;//serious matrix times matrix
	Matrix<T> operator ^(const T&) const;//matrix power a scaler
	Matrix<T> operator ~() const;//matrix transpose

	T* operator [](int r) {
		return data[r];
	}

	const T* operator [](int r) const {
		return data[r];
	}


	//utilities
	int Dim_row() const {
		//get row size
		return this->dim_row;
	}

	int Dim_col() const {
		//get col size
		return this->dim_col;
	}

	int Num() const {
		return this->dim_row*this->dim_col;
	}

	inline void Set(const int r, const int c, const T& t) {
		//set m(row,col)=element
		this->data[r][c] = t;
	}

	inline T& Get(const int r, const int c) const {
		return this->data[r][c];
	}
};



#endif
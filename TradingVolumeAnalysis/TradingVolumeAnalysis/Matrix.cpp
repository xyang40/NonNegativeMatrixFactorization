 #include<math.h>
#include "Matrix.h"

//constructors and destructors;
template<class T>
Matrix<T>::Matrix(int row, int col):dim_row(row),dim_col(col) {
	//create row pointer
	data = (T**) malloc(row*sizeof(T*));
	//create column pointer
	for (int r = 0; r < row; ++r) {
		*(data + r) = (T*)malloc(col*sizeof(T));
	}
	//initialize all to 0
	for (int r = 0; r < row; ++r) {
		for (int c = 0; c < col; ++c) {
			data[r][c] = 0;
		}
	}
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& m):dim_row(m.Dim_row()),dim_col(m.Dim_col()) {
	//create row pointer
	data = (T**)malloc(dim_row*sizeof(T*));
	//create column pointer
	for (int r = 0; r < dim_row; ++r) {
		*(data + r) = (T*)malloc(dim_col*sizeof(T));
	}
	//copy values
	for (int r = 0; r < dim_row; ++r) {
		for (int c = 0; c < dim_col; ++c) {
			data[r][c] = m[r][c];
		}
	}
}

template<class T>
Matrix<T>::~Matrix() {
	for (int r = 0; r < dim_row; ++r) {
		free(data[r]);
	}
}


//operators overloading
template<class T>
Matrix<T>& Matrix<T>::operator =(const Matrix<T>& m){
	//overloading assignment operator
	if (this == &m) {
		//check if assigning to self
		return *this;
	}
	//delete current data:
	for (int r = 0; r < this->dim_row; ++r) {
        free(data[r]);
	}

	//alloc new space:
	this->dim_row = m.Dim_row();
	this->dim_col = m.Dim_col();
	//create row pointer
	this->data = (T**)malloc(this->dim_row*sizeof(T*));
	//create column pointer
	for (int r = 0; r < this->dim_row; ++r) {
		*(data + r) = (T*)malloc(this->dim_col*sizeof(T));
	}

	//assign values:
	for (int r = 0; r < this->dim_row; ++r) {
		for (int c = 0; c < this->dim_col; ++c) {
			data[r][c] = m[r][c];
		}
	}

	return *this;
}


template<class T>
Matrix<T> Matrix<T>::operator *(const T& d) const {
	Matrix<T> nm(this->dim_row, this->dim_col);
	for (int r = 0; r < this->dim_row; ++r) {
		for (int c = 0; c < this->dim_col; ++c) {
			nm.data[r][c] = this->data[r][c] * d;
		}
	}

	return nm;
}

template<class T>
Matrix<T> Matrix<T>::operator *(const Matrix<T>& m) const {
	Matrix<T> nm(this->dim_row, this->dim_col);
	for (int r = 0; r < this->dim_row; ++r) {
		for (int c = 0; c < this->dim_col; ++c) {
			nm.data[r][c] = this->data[r][c] * m[r][ c];
		}
	}

	return nm;
}

template<class T>
Matrix<T> Matrix<T>::operator /(const Matrix<T>& m) const {
	Matrix<T> nm(this->dim_row, this->dim_col);  
	for (int r = 0; r < this->dim_row; ++r) {
		for (int c = 0; c < this->dim_col; ++c) {
			nm.data[r][c] = this->data[r][c] / m[r][c];
		}
	}

	return nm;
}

template<class T>
Matrix<T> Matrix<T>::operator +(const Matrix<T>& m) const {
	Matrix<T> nm(this->dim_row, this->dim_col);
	for (int r = 0; r < this->dim_row; ++r) {
		for (int c = 0; c < this->dim_col; ++c) {
			nm.data[r][c] = this->data[r][c] + m[r][ c];
		}
	}

	return nm;
}

template<class T>
Matrix<T> Matrix<T>::operator +(const T& t) const {
	Matrix<T> nm(this->dim_row, this->dim_col);
	for (int r = 0; r < this->dim_row; ++r) {
		for (int c = 0; c < this->dim_col; ++c) {
			nm.data[r][c] = this->data[r][c] + t;
		}
	}

	return nm;
}

template<class T>
Matrix<T> Matrix<T>::operator %(const Matrix<T>& m) const {
//should check dim first
Matrix<T> nm(this->dim_row, m.Dim_col());

//brute force
for (int r = 0; r < nm.Dim_row(); ++r) {
	for (int c_t = 0; c_t < nm.Dim_col(); ++c_t) {
		for (int c = 0; c < this->dim_col; ++c) {
			nm[r][c_t] += this->data[r][c] * m[c][c_t];
		}
	}
}

return nm;
}

template<class T>
Matrix<T> Matrix<T>::operator ^(const T& d) const {
	Matrix<T> nm(this->dim_row, this->dim_col);
	for (int r = 0; r < this->dim_row; ++r) {
		for (int c = 0; c < this->dim_col; ++c) {
			nm.data[r][c] = Math.pow(this->data[r][c], t);
		}
	}
}

template<class T>
Matrix<T> Matrix<T>:: operator ~() const{
     Matrix<T> nm(this->dim_col, this->dim_row);

	 for (int r = 0; r < this->dim_col; ++r) {
		 for (int c = 0; c < this->dim_row; ++c) {
			 nm.data[r][c] = this->data[c][r];
		 }
	 }

	 return nm;
}





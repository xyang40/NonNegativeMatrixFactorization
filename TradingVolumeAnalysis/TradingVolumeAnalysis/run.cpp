#include<iostream>
#include "Matrix.h"
#include "Matrix.cpp"
#include<fstream>
#include<sstream>
#include<tuple>
#include<ctime>
#include<stdio.h>
#include<math.h>
#include<random>

#define DATE_NUM 4152
#define IB_NUM 9

//retrieve data for JPmorgan, Goldman Sachs, Morgan Stanley, Deutsche Bank, Citigroup, Barclays, UBS, Lazard and Wells Fargo
std::string tickers[] = { "JPM", "GS", "MS",  "DB",  "C",  "BCS", "UBS", "LAZ", "WFC" };

//the original data matrix
Matrix<double> m(DATE_NUM, IB_NUM);

//loss function:
template<class T>
T getloss(Matrix<T> l, Matrix<T> r) {
	T sum = 0;
	for (int i = 0; i < l.Dim_row(); ++i) {
		for (int j = 0; j < l.Dim_col(); ++j) {
			sum += pow(l[i][j] - r[i][j], 2);
		}
	}
	return sum;
}


//Non-Negative Matrix Factorization:
template<class T>
std::tuple<Matrix<T>, Matrix<T>> nmf(Matrix<T> data, int fnum, int n_iter, T stop_criterion) {
	//initialize weight and features matrices
	Matrix<T> w(data.Dim_row(), fnum);
	Matrix<T> f(fnum, data.Dim_col());

	//for random number generation
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 100);

	//assign random values:
	for (int i = 0; i < w.Dim_row(); ++i) {
		for (int j = 0; j < w.Dim_col(); ++j) {
			w[i][j] =  dis(gen)/ 100.0;
		}
	}

	for (int i = 0; i < f.Dim_row(); ++i) {
		for (int j = 0; j < f.Dim_col(); ++j) {
			f[i][j] = dis(gen)/ 100.0;
		}
	}

	//update for n_iter times and then stop
	int iter = 0;
	while (iter != n_iter) {
		
		Matrix<double> wf(w%f);

		//measure delta:
		T loss = getloss(data, wf);
		std::cout << "LOSS: " << loss << std::endl;

		//test stop criterion:
		if (loss < stop_criterion) {
			break;
		}

		//update intermediate matrices
		Matrix<T> fn(~w%data);
		Matrix<T> fd(~w%w%f);
		f = (f*fn) / fd;
		Matrix<T> wn(data%~f);
		Matrix<T> wd(w%f%~f);
		w = (w*wn) / wd;

		++iter;
	}

	return std::make_tuple(w, f);
}

//driver 
int main() {
	//read data into memory
	std::ifstream file;
	for (int i = 0; i != IB_NUM; ++i) {
		std::ifstream file(tickers[i] + "_data.csv");
		std::string line;
		std::getline(file, line);//skip the topic row
		int row = 0;
		while (std::getline(file, line)) {
			//convert string to double
			m[row++][i] = std::stod(line, nullptr);
		}
	}


	//test factorization
	int fnum = 1000;
	int n_iter = 500;
	double stop_criterion = 0.00001;
	std::tuple<Matrix<double>, Matrix<double>> tup = nmf(m, fnum, n_iter, stop_criterion);

	std::cin.get();
	return 0;
}
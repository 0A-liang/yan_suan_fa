#include <iostream>
#include <algorithm>
#include "algorithm.h"
#include <iomanip>
#include <vector>
#include <chrono>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;
using namespace std;

void generate_random_data(std::vector<int>& v, int size)
{
	v.resize(size);
	/*
	auto f = [size]() -> int { return rand() % size; };
	generate(v.begin(), v.end(), f);
	*/

	for (int i = 0; i < v.size(); i++) {
		v[i] = rand() % size;
	}
}


void time_count(void(*fun)(vector<int>&), const vector<double> data_size, vector<double>& running_time)
{
	chrono::high_resolution_clock::time_point start, end;
	vector<int> A;

	for (int i = 0; i < data_size.size(); i++) {
		// 產生資料
		generate_random_data(A, data_size[i]);
		// 開始計時
		start = chrono::high_resolution_clock::now();
		fun(A);
		end = chrono::high_resolution_clock::now();
		// 結束計時
		chrono::duration<double> diff = end - start;
		running_time.push_back(diff.count());
	}
}

void time_log(const string name, const vector<double>& x, const vector<double>& y) {
	cout << name << ":" << endl;
	for (int i = 0; i < x.size(); i++) {
		cout << "Size:" << setw(6) << (int)x[i] << " Time:" << fixed << setprecision(7) << y[i] << endl;
	}
	cout << endl;
}

int main()
{
	vector<double> data_size;
	for (int i = 1; i <= 30; i++) {
		data_size.push_back(i * 1000);
	}
	vector<double> result1, result2, result3, result4, result5;

	time_count(insertion_sort, data_size, result1);
	time_log("insertion_sort", data_size, result1);
	time_count(selection_sort, data_size, result2);
	time_log("selection_sort", data_size, result2);
	time_count(bubble_sort, data_size, result3);
	time_log("bubble_sort", data_size, result3);
	time_count(merge_called, data_size, result4);
	time_log("merge_sort", data_size, result4);
	time_count(heap_sort, data_size, result5);
	time_log("heap_sort", data_size, result5);

	plt::figure_size(1200, 780);
	plt::named_plot("insertion_sort", data_size, result1);
	plt::named_plot("selection_sort", data_size, result2);
	plt::named_plot("bubble_sort", data_size, result3);
	plt::named_plot("merge_sort", data_size, result4);
	plt::named_plot("heap_sort", data_size, result5);
	plt::title("Search Methods Comparison");
	plt::legend();
	plt::pause(1);//最好加上該句，否則有時候顯示不了圖像，或者圖像顯示很慢
	plt::show();

}

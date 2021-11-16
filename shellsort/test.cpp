#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void InsertSort(vector<int>& v) {
	
	int index = 0;
	while (index < v.size()) {
		int key = v[index];
		int i = index - 1;
		while (i >= 0 && v[i] > key) {
			v[i + 1] = v[i];
			i--;
		}
		v[i + 1] = key;
		index++;
	}
}

void ShellSort(vector<int>& v) {
	int gap = v.size();
	while (gap > 1) {
		gap = gap / 3 + 1;

		int index = 0;
		while (index < v.size()) {
			int i = index - gap;
			int key = v[index];
			while (i >= 0 && v[i] > key) {
				v[i + gap] = v[i];
				i -= gap;
			}
			v[i + gap] = key;
			index += gap;
		}
	}
}


int main() {
	srand((unsigned)time(nullptr));

	vector<int> v = {5, 4, 3, 1};
	int n = 7;
	for (int i = 0; i < n; i++) {
		v.push_back(rand() % 100);
	}

	ShellSort(v);

	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}
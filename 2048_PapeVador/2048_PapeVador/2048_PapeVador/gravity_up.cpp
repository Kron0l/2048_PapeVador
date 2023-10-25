#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include "common.h"


vector<vector<int>> gravityUp(vector<vector<int>> grid) {
	vector<int> st;
	vector<int> nd;
	vector<int> rd;
	vector<int> th;
	for (int a = 0; a <= 3; a++) {
		for (int b = 0; b < numberList.size(); b++) {
			if (numberList[b].position[0] == a) {
				if (a == 0) {
					th.push_back(numberList[b].position[1]);
					sort(th.begin(), th.end());
				}
				if (a == 1) {
					rd.push_back(numberList[b].position[1]);
					sort(rd.begin(), rd.end());
				}
				if (a == 2) {
					nd.push_back(numberList[b].position[1]);
					sort(nd.begin(), nd.end());
				}
				if (a == 3) {
					st.push_back(numberList[b].position[1]);
					sort(st.begin(), st.end());
				}
			}
		}


		if (a == 1) {
			for (int b = 0; b < rd.size(); b++) {
				if (!binary_search(th.begin(), th.end(), rd[b])) {
					for (int i = 0; i < numberList.size(); i++) {
						if (numberList[i].position[0] == a && numberList[i].position[1] == rd[b]) {
							cout << numberList[i].position[0] << " || ";
							grid[numberList[i].position[0]][numberList[i].position[1]] = 0;
							numberList[i].position[0] = 0;
							grid[numberList[i].position[0]][numberList[i].position[1]] = numberList[i].value;
							cout << numberList[i].position[0];
							cout << "x = 2 & y = " << rd[b] << " || ";
						}
					}
					cout << rd[b] << " third line ok to fourth" << endl;
				}
			}
		}


		if (a == 2) {
			for (int b = 0; b < nd.size(); b++) {
				if (!binary_search(rd.begin(), rd.end(), nd[b])) {
					if (!binary_search(th.begin(), th.end(), nd[b])) {
						for (int i = 0; i < numberList.size(); i++) {
							if (numberList[i].position[0] == a && numberList[i].position[1] == nd[b]) {
								grid[numberList[i].position[0]][numberList[i].position[1]] = 0;
								numberList[i].position[0] = 0;
								grid[numberList[i].position[0]][numberList[i].position[1]] = numberList[i].value;
								cout << "x = 1 & y = " << nd[b] << " || ";
							}
						}
						cout << nd[b] << " second line ok to fourth" << endl;
					}
					else {
						for (int i = 0; i < numberList.size(); i++) {
							if (numberList[i].position[0] == a && numberList[i].position[1] == nd[b]) {
								grid[numberList[i].position[0]][numberList[i].position[1]] = 0;
								numberList[i].position[0] = 1;
								grid[numberList[i].position[0]][numberList[i].position[1]] = numberList[i].value;
								cout << "x = 1 & y = " << nd[b] << " || ";
							}
						}
						cout << nd[b] << " second line ok to third" << endl;

					}

				}
			}
		}

		if (a == 3) {
			for (int b = 0; b < st.size(); b++) {
				if (!binary_search(nd.begin(), nd.end(), st[b])) {
					if (!binary_search(rd.begin(), rd.end(), st[b])) {
						if (!binary_search(th.begin(), th.end(), st[b])) {
							for (int i = 0; i < numberList.size(); i++) {
								if (numberList[i].position[0] == a && numberList[i].position[1] == st[b]) {
									grid[numberList[i].position[0]][numberList[i].position[1]] = 0;
									numberList[i].position[0] = 0;
									grid[numberList[i].position[0]][numberList[i].position[1]] = numberList[i].value;
									cout << "x = 0 & y = " << st[b] << " || ";
								}
							}
							cout << st[b] << " first line ok to fourth" << endl;
						}
						else {
							for (int i = 0; i < numberList.size(); i++) {
								if (numberList[i].position[0] == a && numberList[i].position[1] == st[b]) {
									grid[numberList[i].position[0]][numberList[i].position[1]] = 0;
									numberList[i].position[0] = 1;
									grid[numberList[i].position[0]][numberList[i].position[1]] = numberList[i].value;
									cout << "x = 0 & y = " << st[b] << " || ";
								}
							}
							cout << st[b] << " first line ok to third" << endl;
						}
					}
					else {
						for (int i = 0; i < numberList.size(); i++) {
							if (numberList[i].position[0] == a && numberList[i].position[1] == st[b]) {
								grid[numberList[i].position[0]][numberList[i].position[1]] = 0;
								numberList[i].position[0] = 2;
								grid[numberList[i].position[0]][numberList[i].position[1]] = numberList[i].value;
								cout << "x = 0 & y = " << st[b] << " || ";
							}
						}
						cout << st[b] << " first line ok to second" << endl;
					}
				}
			}
		}
	}

	/*cout << "first line" << endl;
	for (int i = 0; i < st.size(); i++) {
		cout << st[i] << endl;
	}
	cout << "second line" << endl;
	for (int i = 0; i < nd.size(); i++) {
		cout << nd[i] << endl;
	}
	cout << "third line" << endl;
	for (int i = 0; i < rd.size(); i++) {
		cout << rd[i] << endl;
	}
	cout << "fourth line" << endl;
	for (int i = 0; i < th.size(); i++) {
		cout << th[i] << endl;
	}*/
	return grid;
}
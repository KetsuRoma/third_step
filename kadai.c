#include <stdio.h>
#include <math.h>

#define class_int 20
#define class_dob 20.0
#define sec 2

int main() {
	int point[sec][class_int] = { { 65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70 },
						 { 44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84 } };
	int point_sci[class_int] = { 65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70 };
	int point_eng[class_int] = { 44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84 };
	double point_ss[sec][class_int] = { 0 };
	double ave[sec] = {0};
	double dev[sec] = {0};
	int sum[sec] = {0};
	int tmp = 0;
	double d = 0;

	for (int i = 0; i < sec; i++) {
		for (int j = 0; j < 20; j++) {
			tmp += point[i][j];
		}
		sum[i] = tmp;
		ave[i] = tmp / class_dob;
		tmp = 0;
	}

	for (int i = 0; i < sec; i++) {
		for (int j = 0; j < 20; j++) {
			d += pow(point[i][j] - ave[i], 2.0);
		}
		dev[i] = sqrt(d / class_dob);
		tmp = 0;
	}
	for (int i = 0; i < sec; i++) {
		for (int j = 0; j < 20; j++) {
			point_ss[i][j] = (point[i][j] - ave[i]) / dev[i] * 10 + 50;
		}
	}


	for (int i = 0; i < class_int; i++) {
		for (int j = i + 1; j < class_int; j++) {
			if (point_sci[i] < point_sci[j]) {
				tmp = point_sci[i];
				point_sci[i] = point_sci[j];
				point_sci[j] = tmp;
			}
			if (point_eng[i] < point_eng[j]) {
				tmp = point_eng[i];
				point_eng[i] = point_eng[j];
				point_eng[j] = tmp;
			}
		}
	}



	for (int i = 0; i < sec; i++) {
		printf("%d : ave %lf, dev %lf, sum %d\n", i, ave[i], dev[i], sum[i]);
	}
	for (int i = 0; i < sec; i++) {
		printf("%d\n", i);
		for (int j = 0; j < class_int; j++) {
			printf(" %lf |", point_ss[i][j]);
		}
		printf("\n");
	}
	printf("science\n");
	for (int i = 0; i < class_int; i++) {
		printf(" %d |", point_sci[i]);
	}
	printf("\nenglish\n");
	for (int i = 0; i < class_int; i++) {
		printf(" %d |", point_eng[i]);
	}

	return 0;
}

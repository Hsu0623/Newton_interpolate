#define _CRT_SECURE_NO_WARNINGS
/*
we need to use 2 times Newton_interpolate, one is for x = P(t), and the other is for y = P(t)
smaple points t is chord_length
*/

#include "definition.h"

int main() {
	double data[10][2] = { {1.0,3.45},{-1.0,2.6},{-2.8,0.0},{-2.0,-2.1},{0.1,-3.0},{1.5,-2.7},{0.2,-1.5},{-0.3,0.5}, {0.3,1.8},{1.0,3.45} };
	//double data[10][2] = { {1.0,3.45},{0.0,3.2},{-2.4,1.8},{-2.8,0.0},{-2.0,-2.1},{0.1,-3.0},{1.5,-2.7},{0.2,-1.5},{0.3,1.8},{1.0,3.45} };
	//double data[10][2] = {{22.2,35.0},{0.0,32.0},{-24.0,18.0},{-28.0,0.0},{-20.0,-21.0},{1.0,-30.0},{20.0,-33.0},{2.0,-15.0},{3.0,18.0},{22.2,35.0}};
	//double data[10][2] = { {2.2,3.5},{0.0,3.2},{-2.4,1.8},{-2.8,0.0},{-2.0,-2.1},{0.1,-3.0},{2.0,-3.3},{0.2,-1.5},{0.3,1.8},{2.2,3.5} };
	//double data[10][2] = { {2.2,3.5},{-2.4,1.8},{-2.8,0.0},{-2.0,-2.1},{2.0,-3.3},{1.5,-2.7},{0.2,-1.5},{-0.4,0.5},{0.3,1.8},{2.2,3.5} };
	double X[10][2];
	double Y[10][2];
	double points[40][2];
	double t[40];
	double tmp, m;
	double* L_k = chord_length(data, N);
	int i, j= 1;

	//generate 40 points
	t[0] = 0.0, t[39] = 1.0;
	for (i = 0; i <= 8; i++) {
		tmp = L_k[i];
		m = (L_k[i+1]-L_k[i])/5;
		if (j == 5 || j == 10)t[j++] = L_k[i];
		for (int l = 0; l < 4; l++) {
			tmp += m;
			t[j++] = tmp;
		}
	}
//	printf("%lf, %lf, %lf,\n", t[37], t[38] ,t[39]);
	
	/* X */
	for (i = 0; i <= N; i++) {
		X[i][0] = L_k[i];
		X[i][1] = data[i][0];
	}
	//compute coefficent
	comp_Newton_coef(X, N);
	//Newton_interpolate
	for (i = 0; i < 40; i++) {
		points[i][0] = Newton_interpolate(X, t[i], N);
	}
	printf("\n");
	
	/* Y */
	for (i = 0; i <= N; i++) {
		Y[i][0] = L_k[i];
		Y[i][1] = data[i][1];
	}
	//compute coefficent
	comp_Newton_coef(Y, N);
	//Newton_interpolate
	for (i = 0; i < 40; i++) {
		points[i][1] = Newton_interpolate(Y, t[i], N);
	}

	FILE* fp;
	fp = fopen("Q3A_chord_length_X1.txt", "w");
	for (i = 0; i < 39; i++) {
		fprintf(fp, "%lf;", points[i][0]);
	}
	fprintf(fp, "%lf;", points[i][0]);

	fp = fopen("Q3A_chord_length_Y1.txt", "w");
	for (i = 0; i < 39; i++) {
		fprintf(fp, "%lf;", points[i][1]);
	}
	fprintf(fp, "%lf;", points[i][1]);

	fp = fopen("data1.txt", "w");
	for (i = 0; i < N; i++) {
		fprintf(fp, "%lf;", data[i][0]);
	}
	fprintf(fp, "%lf;\n", data[i][0]);
	for (i = 0; i < N; i++) {
		fprintf(fp, "%lf;", data[i][1]);
	}
	fprintf(fp, "%lf;\n", data[i][1]);

	return 0;
}
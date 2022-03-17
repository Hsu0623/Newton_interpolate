#include "definition.h"

int main() {
	double data[10][2] = { {2.2,3.5},{0.0,3.2},{-2.4,1.8},{-2.8,0.0},{-2.0,-2.1},{0.1,-3.0},{2.0,-3.3},{0.2,-1.5},{0.3,1.8},{2.2,3.5} };
	//double data[9][2] = { {22.2,35.0},{0.0,32.0},{-24.0,18.0},{-28.0,0.0},{-20.0,-21.0},{1.0,-30.0},{20.0,-33.0},{2.0,-15.0},{3.0,18.0} };
	double* L_k = chord_length(&data, N);
	printf("Chord-length\n");
	printf("T[i]\t");
	for (int i = 0; i <= N; i++) {
		printf("%lf\t", L_k[i]);
		if (i == 7)printf("\t");
	}
	printf("\n");
	printf("X[i]\t");
	for (int i = 0; i <= N; i++) {
		printf("%lf\t",data[i][0]);
		if (i == 7)printf("\t");
	}
	printf("\n");
	printf("Y[i]\t");
	for (int i = 0; i <= N; i++) {
		printf("%lf\t", data[i][1]);
	}
	printf("\n");
	printf("---------------------------------------------------------------------------\n");
	printf("Uniform\n");
	printf("T[i]\t");
	for (int i = 0; i <= N; i++) {
		printf("%08d\t", i);
		if (i == 7)printf("\t");
	}
	printf("\n");
	printf("X[i]\t");
	for (int i = 0; i <= N; i++) {
		printf("%lf\t", data[i][0]);
		if (i == 7)printf("\t");
	}
	printf("\n");
	printf("Y[i]\t");
	for (int i = 0; i <= N; i++) {
		printf("%lf\t", data[i][1]);
	}
	printf("\n");
	free(L_k);
	return 0;
}
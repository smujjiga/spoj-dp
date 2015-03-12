#include <stdio.h>
#include <climits>

namespace SCUBADIV {
	int min(int i,int j) {
		return i<j?i:j;
	}
}
	int oxygen[1010], nitrogen[1010], weight[1010], sol[1010][1010];

int main_SCUBADIV() {
	int t,nit,oxy,n;
	scanf("%d",&t);

	while(t--) {
		scanf("%d%d",&oxy,&nit);
		scanf("%d",&n);
		for (int i=0;i<n;i++) {
			scanf("%d%d%d",&oxygen[i], &nitrogen[i], &weight[i]);
		}

		sol[0][0] = 0;
		for (int i=0;i<=oxy;i++)
			sol[i][0] = 0;

		for (int i=0;i<=nit;i++)
			sol[0][nit] = 0;


		for (int i=1;i<=oxy;i++) {
			for (int j=1;j<=nit;j++) {
				sol[i][j] = INT_MAX;
				printf("\n");
				for (int k=0;k<n;k++) {
					if (oxygen[k] <= i && nitrogen[k] <= j)
						sol[i][j] = SCUBADIV::min(sol[i][j], sol[i-oxygen[k]][j-nitrogen[k]]+weight[k]);

					else if (oxygen[k] <= i) {
						for (int z=1;z<=nit;z++)
							sol[i][j] = SCUBADIV::min(sol[i][j], sol[i-oxygen[k]][z]+weight[k]);
					} 

					else if (nitrogen[k] <= j) {
						for (int z=1;z<=oxy;z++)
							sol[i][j] = SCUBADIV::min(sol[i][j], sol[z][j-nitrogen[k]]+weight[k]);
					}
					else {
						sol[i][j] = SCUBADIV::min(sol[i][j], weight[k]);
					}
				}

				printf("[%d][%d] = [%d]",i,j,sol[i][j]);
		}
		}
		printf("%d\n",sol[oxy][nit]);
	}

	return 0;
}
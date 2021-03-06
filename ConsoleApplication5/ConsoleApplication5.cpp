// 1932.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <stdio.h>
#include <algorithm>
int arMax[501][501]{};
int arData[501][501]{};
int main()
{
	int nN(0);
	int nCount(0);
	int nFloor(0);
	int nIndexCount(0);


	scanf_s("%d",&nN);

	nCount = nN;
	nIndexCount = 0;
	while (nFloor < nCount)
	{
		nIndexCount++;
		for (int i = 0; i < nIndexCount; i++)
		{
			scanf_s("%d", &arData[nFloor][i]);
		}	
		nFloor++;
	}
	arMax[0][0] = arData[0][0];
	nIndexCount = 0;
	for (int i = 1; i < nCount; i++)
	{
		nIndexCount++;
		arMax[i][0] = arData[i][0] + arMax[i - 1][0];
		for (int j = 1; j < nIndexCount; j++)
		{
			arMax[i][j] = arData[i][j] + std::max(arMax[i-1][j],arMax[i-1][j-1]);
		}
		arMax[i][nIndexCount] = arData[i][nIndexCount] + arMax[i - 1][nIndexCount - 1];
	}

	nIndexCount = 0;
	for (int i = 0; i < nCount; i++)
	{
		nIndexCount++;
		for (int j = 0; j < nIndexCount; j++)
		{
			printf("%d ", arMax[i][j]);
		}
		printf("\n");
	}

	int nMax(0);
	nMax = arMax[nCount - 1][0];
	for (int j = 1; j < nIndexCount+1; j++)
	{
		nMax = std::max(arMax[nCount - 1][j], nMax);
	}

	printf("%d\n", nMax);
    return 0;
}


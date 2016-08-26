/* 從零開始, 實現歸併排序. */

#include <stdio.h>
/* 歸併排序的關鍵點. 第一個是遞歸, 第二個是分割, 第三個是融合(融合函數). */
/* 歸併排序的分割要點, 體現的是分而治之的思想.*/
/* 分而治之, 需要分割游標的輔助, 體現在歸併排序上, 就是需要設立左游標leftBoundaryCursor和右游標rightBoundaryCursor這兩個輔助變量. */

/* 那麼問題來了, c語言中給一個數組賦值是什麼語法? */
	/* "int a[] = {1, 2, 3};"或"int a[3] = {1, 2, 3};". "int a[n]"為定義長度為n的整型數組. */
		/* "int a[]"這種在java中定義不定長度的數組的語法, 在c語言中不合法. */
			/* 因為java中數組是開在堆中, 而c語言中數組是開在棧中, 數組的長度必須預先指定. */

/* 歸併算法的核心部件, 合併函數. */
/* 由於合併函數事實上是對兩個數組進行融合, 因此輸入參數應當是兩個數組. 由於這兩個數組是連續的, 是一個大數組上面的連續片段. */
	/* 因此合併函數的輸入參數, 只要4個足矣. */
void merge(int *a, int leftBoundary, int middleDivision, int rightBoundary);
void mergesort(int *a, int leftBoundary, int rightBoundary);

void merge(int *a, int leftBoundary, int middleDivision, int rightBoundary)
{
	int tempArray[rightBoundary-leftBoundary+1];
	int leftBoundaryCursor = leftBoundary;
	int rightBoundaryCursor = middleDivision+1;
	int tempCursor = 0;
	
	/* 升級版, 一個while循環解決問題. */	
	while (leftBoundaryCursor<=middleDivision || rightBoundaryCursor<=rightBoundary)
	{
		if (a[leftBoundaryCursor] <= a[rightBoundaryCursor])
		{
			if (leftBoundaryCursor<=middleDivision)
			{
				tempArray[tempCursor] = a[leftBoundaryCursor];
				tempCursor++;
				leftBoundaryCursor++;
			}else
			{
				tempArray[tempCursor] = a[rightBoundaryCursor];
				tempCursor++;
				rightBoundaryCursor++;
			}
		}else
		{
			if (rightBoundaryCursor<=rightBoundary)
			{
				tempArray[tempCursor] = a[rightBoundaryCursor];
				tempCursor++;
				rightBoundaryCursor++;
			}else
			{
				tempArray[tempCursor] = a[leftBoundaryCursor];
				tempCursor++;
				leftBoundaryCursor++;
			}
		}
	}
	
	/* 原始版, 先比較完, 然後再把餘下的尾部填入.
	while (leftBoundaryCursor<=middleDivision && rightBoundaryCursor<=rightBoundary)
	{
		if (a[leftBoundaryCursor] <= a[rightBoundaryCursor])
		{
				tempArray[tempCursor] = a[leftBoundaryCursor];
				tempCursor++;
				leftBoundaryCursor++;
		}else
		{
				tempArray[tempCursor] = a[rightBoudaryCursor];
				tempCursor++;
				rightBoundaryCursor++;
		}
	}
	
	while (leftBoundaryCursor<=middleDivision)
	{
		tempArray[tempCursor] = a[leftBoundaryCursor];
		leftBoundary++;
		tempCursor++;
	}
	while (rightBoundaryCursor<=rightBoundary)
	{
		tempArray[tempCursor] = a[rightBoundaryCursor];
		rightBoundary++;
		tempCursor++;
	}
	*/
	
	/* 把排好序的臨時數列的數據寫入到原數據中. */
	for (int i=0; i<=rightBoundary-leftBoundary; i++)
	{
		a[leftBoundary+i] = tempArray[i];
	}
}

/* 輸入參數3個, 數組首個元素的地址, 數組左邊界, 數組右邊界. */
void mergesort(int *a, int leftBoundary, int rightBoundary)
{
	/* 遞歸的終點, 如果(leftBoundary>=rightBoundary), 說明只剩1個了, 只剩1個之後. */
	/* 遞歸的終點, 意味著展開之後再重新折疊. 重新折疊就是return返回到上一層. */
	if (leftBoundary >= rightBoundary)
	{
		return;
	}else
	{
		int middleDivision = (leftBoundary+rightBoundary) / 2;
		mergesort(a, leftBoundary, middleDivision);
		mergesort(a, middleDivision+1, rightBoundary);
		merge(a, leftBoundary, middleDivision, rightBoundary);
	}
	
}
	
int main(void)
{
	int length = 0;
	
	printf("please input the length of the array: ");
	scanf("%d", &length);
	
	int a[length];
	
	for (int i=0; i<length; i++)
	{
		printf("please input the value of the element[%d]: ", i);
		scanf("%d", &a[i]);
	}
	
	mergesort(a, 0, length-1);
	
	printf("{");
	/* c語言中, 循環獨立成棧, 因此即使前面的循環已經定義了變量i"int i=0;", 後面的循環仍然可以再次定義變量i"int i=0;". */
	for (int i=0; i<length; i++)
	{
		printf("%d, ", a[i]);
	}
	/* c語言中, 如果想要去掉字符串結尾的", ", 可以使用退格控制符"\b". */
	printf("\b\b}\n");
	
	return 0;
}
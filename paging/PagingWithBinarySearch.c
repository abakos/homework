/* 帶二分搜索元素的分頁算法. */
/* 從零開始實現. */
/* 使用c語言編寫. */

#include <stdio.h>
/* 那麼問題來了, c語言中如何使用bool類型變量? 引入"stdbool.h"頭文件, 即可以使用bool類型變量. */
	/* "#include <stdbool.h>"之後, 定義布爾類型變量的關鍵字為"bool", 真值為"true", 假值為"false". */
#include <stdbool.h>

/* 那麼問題來了, 分頁算法的基本參數有哪些? */
	/* 分頁算法的基本參數. 總頁數, pageCount. pageCount由總行數和每頁顯示的行數確定, 即"pageCount = rowCount/displayedRowCount;". */
	/* 分頁算法的基本參數. 當前頁碼, currentPageNumber. */
	/* 分頁算法的基本參數. 頁碼欄顯示頁碼的最大個數, displayedPageCount. */
	/* 綜上所述, 分頁算法一共有四個基本參數, 總行數rowCount, 每頁顯示的行數displayedRowCount, 當前頁碼currentPageNumber, 顯示頁碼的個數displayedPageCount. */

/* 先寫一個方法, 求得pageCount. */

/* 那麼問題來了, c語言中函數的前置聲明是怎樣的? 猜測應該是"#define 函數名(輸入參數);"格式. */
/* 猜測錯誤, c語言中函數的前置聲明就是函數定義第一行然後末尾加個分號. */
int getPageCount(int rowCount, int displayedRowCount);
void pagingWithBinarySearch(int rowCount, int displayedRowCount, int currentPageNumber, int displayedPageCount);
/* 廢除. "int max(int a, int b);" */

int getPageCount(int rowCount, int displayedRowCount)
{
	int pageCount = 0;
	
	/* 首先進行輸入參數的清洗. */
	if (rowCount <= 0)
	{
		return 0;
	}else if (displayedRowCount <= 0)
	{
		return 0;
	}else{}
	
	if (0 == rowCount%displayedRowCount)
	{
		pageCount = rowCount/displayedRowCount;
	}else
	{
		pageCount = rowCount/displayedRowCount + 1;
	}
	
	return pageCount;
}

/* 採用模擬蠕蟲身體的可伸縮結構. */
/* 游碼邊界問題. */
/* 先打印出首頁. */
/* 有如下幾個重要節點, pass. */
	/* 首頁firstPageNumber, 左二分查找頁leftBinarySearchPageNumber, 左鄰起始頁leftNeighborhoodFirstPageNumber. */
	/* 當前頁currentPageNumber. */
	/* 右鄰尾頁rightNeighborhoodEndPageNumber, 右二分查找頁rightBinarySearchPageNumber, 尾頁endPageNumber. */
/* 先確定displayedPageCount不同數值時都要顯示哪些頁碼. */
	/* 如果"displayedPageCount = 1", 則只顯示當前頁碼currentPageNumber. */
	/* 如果"displayedPageCount = 2", 則只顯示當前頁碼currentPageNumber和尾頁endPageNumber. */
	/* 如果"displayedPageCount = 3", 則只顯示首頁firstPageNumber, 當前頁碼currentPageNumber, 和尾頁endPageNumber. */
	/* 如果"displayedPageCount = 4", 則只顯示首頁firstPageNumber, 當前頁碼currentPageNumber, 右二分查找頁rightBinarySearchPageNumber, 和尾頁endPageNumber. */
	/* 如果"displayedPageCount = 5", 則顯示首頁firstPageNumber, 左二分查找頁leftBinarySearchPageNumber, 當前頁碼currentPageNumber, 右二分查找頁rightBinarySearchPageNumber, 和尾頁endPageNumber. */
	/* 右側要優先於左側. */

/* 已知currentPageNumber和neighborhoodLength, currentPageNumber會在neighborhood範圍內左右滑動, 確定leftNeighborhoodFirstPageNumber和rightNeighborhoodEndPageNumber這兩個變量的值. */
	/* 已知currentPageNumber和neighborhoodLength求neighbor的邊界, 屬於經典的游碼模型問題. */
	/* 確定游碼邊界問題, 一個經典解法就是藉助左右輔助游標. */ 
	/* 可以把左右輔助游標看作兩個隧道挖掘機器人, 以游碼位置為起點, 同時向左右出發進行挖掘, 兩個機器人共用同一個電池, 即neighborLength. */
	/* 當游標機器人挖到障礙物時停止挖掘, 當游標機器人電量耗盡時停止挖掘. 當兩個游標機器人都停止挖掘時, 挖出的隧道兩端的邊界就是游碼邊界. */
	/* neighborhoodLength = displayedPageCount-5; */
	/* 如果"currentPageNumber<=2", 則表示leftBinarySearchPageNumber沒有機會被打印, 節省下來的1個打印名額分配給neighborhoodLength.
		即"if (2 >= currentPageNumber) neighborhoodLength = neighborhoodLenght+1;"
	 */
	/* 如果"1 == currentPageNumber", 則表示firstPageNumber沒有機會被打印, 節省下來的1個打印名額分配給neighborhoodLength.
		即"if (1 == currentPageNumber) neighborhoodLength = neighborhoodLenght+1;"
	 */
	/* 如果"currentPageNumber >= endPageNumber-1", 則表示rightBinarySearchPageNumber沒有機會被打印, 節省下來的1個打印名額分配給neighborhoodLength.
		即"if (currentPageNumber >= endPageNumber-1) neighborhoodLength = neighborhoodLenght+1;"
	 */
	/* 如果"currentPageNumber == endPageNumber", 則表示endPageNumber沒有機會被打印, 節省下來的1個打印名額分配給neighborhoodLength.
		即"if (currentPageNumber == endPageNumber) neighborhoodLength = neighborhoodLenght+1;"
	 */

/* 廢除. 創建工具函數max(); */
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}else
	{
		return b;
	}
}

void pagingWithBinarySearch(int rowCount, int displayedRowCount, int currentPageNumber, int displayedPageCount)
{
	/* 輸入參數清洗. */
	if (rowCount<=0 || displayedRowCount<=0 || currentPageNumber<=0 || displayedPageCount<=0)
	{
		return;
	}
	
	int	endPageNumber = getPageCount(rowCount, displayedRowCount);
	
	if (0 == endPageNumber)
	{
		return;
	}
	
	int neighborhoodLength = displayedPageCount-5;
	/* 利用flag變量來控制某一頁碼是否打印. */
	/* flag變量如果起到開關控制作用的話, 則初始狀態最好設置成關閉. 這裡把所有的flag變量設置成false, 關閉狀態. */
	bool firstPageNumberPrintFlag = false;
	bool endPageNumberPrintFlag = false;
	bool leftBinarySearchPageNumberPrintFlag = false;
	bool rightBinarySearchPageNumberPrintFlag = false;
	/* 集中處理neighborhoodLength和各種flag變量. */
	if (displayedPageCount > 1)
	{
		endPageNumberPrintFlag = true;
	}
	if (displayedPageCount > 2)
	{
		firstPageNumberPrintFlag = true;
	}
	if (displayedPageCount > 3)
	{
		rightBinarySearchPageNumberPrintFlag = true;
	}
	if (displayedPageCount > 4)
	{
		leftBinarySearchPageNumberPrintFlag = true;
	}
	
	if (currentPageNumber <= 2)
	{
		neighborhoodLength = neighborhoodLength+1;
		leftBinarySearchPageNumberPrintFlag = false;
	}
	if (1 == currentPageNumber)
	{
		neighborhoodLength = neighborhoodLength+1;
		firstPageNumberPrintFlag = false;
	}
	if (currentPageNumber >= endPageNumber-1)
	{
		neighborhoodLength = neighborhoodLength+1;
		rightBinarySearchPageNumberPrintFlag = false;
	}
	if (endPageNumber == currentPageNumber)
	{
		neighborhoodLength = neighborhoodLength+1;
		endPageNumberPrintFlag = false;
	}
	
	/* 確定游碼邊界. */
	int leftNeighborhoodPageCursor = currentPageNumber;
	int rightNeighborhoodPageCursor = currentPageNumber;
	while (!(leftNeighborhoodPageCursor<=3 && rightNeighborhoodPageCursor>=endPageNumber-2) && neighborhoodLength>0)
	{
		/* 由於是右側優先, 因此讓右側的游標先運行. */
		if ((rightNeighborhoodPageCursor<endPageNumber-2) && neighborhoodLength>0)
		{
			rightNeighborhoodPageCursor++;
			neighborhoodLength--;
		}
		if (leftNeighborhoodPageCursor>3 && neighborhoodLength>0)
		{
			leftNeighborhoodPageCursor--;
			neighborhoodLength--;
		}
	}
	
	/* 算出leftBinarySearchPageNumber和rightBinarySearchPageNumber. */
	int leftBinarySearchPageNumber = (1+leftNeighborhoodPageCursor) / 2;
	int rightBinarySearchPageNumber = (rightNeighborhoodPageCursor+endPageNumber) / 2;
	
	/* 打印頁碼. */
	/* 打印上一頁. */
	if (currentPageNumber > 1)
	{
		printf("previous ");
	}
	
	if (true == firstPageNumberPrintFlag)
	{
		printf("%d ", 1);
	}
	
	if (true == leftBinarySearchPageNumberPrintFlag)
	{
		if (leftBinarySearchPageNumber-1 > 1)
		{
			printf("... ");
		}
		printf("%d ", leftBinarySearchPageNumber);
		if (leftNeighborhoodPageCursor-leftBinarySearchPageNumber > 1)
		{
			printf("... ");
		}
	}
	
	int leftNeighborhoodPageNumber = leftNeighborhoodPageCursor;
	while (leftNeighborhoodPageNumber < currentPageNumber)
	{
		printf("%d ", leftNeighborhoodPageNumber);
		leftNeighborhoodPageNumber++;
	}
	
	printf("%d ", currentPageNumber);
	
	int rightNeighborhoodPageNumber = currentPageNumber+1;
	while (rightNeighborhoodPageNumber <= rightNeighborhoodPageCursor)
	{
		printf("%d ", rightNeighborhoodPageNumber);
		rightNeighborhoodPageNumber++;
	}
	
	if (true == rightBinarySearchPageNumberPrintFlag)
	{
		if (rightBinarySearchPageNumber-rightNeighborhoodPageCursor > 1)
		{
			printf("... ");
		}
		printf("%d ", rightBinarySearchPageNumber);
		if (endPageNumber-rightBinarySearchPageNumber > 1)
		{
			printf("... ");
		}
	}
	
	if (true == endPageNumberPrintFlag)
	{
		printf("%d ", endPageNumber);
	}
	
	if (currentPageNumber < endPageNumber)
	{
		printf("next\n");
	}
}

int main(void)
{
	int rowCount = 1000;
	int displayedRowCount = 10;
	int currentPageNumber = 96;
	int displayedPageCount = 4;
	pagingWithBinarySearch(rowCount, displayedRowCount, currentPageNumber, displayedPageCount);
	
	return 0;
}

/* unix系統內, 編譯c語言源代碼文件的命令是"make", 用法是"make c語言源代碼文件名(不加'.c'後綴)". 執行時在命令行直接鍵入"c語言源代碼文件名(不加'.c'後綴)"或"./c語言源代碼文件名(不加'.c'後綴)". */
#include <bits/stdc++.h>

using namespace std;

/*
¿ÎÌâÃû³Æ£º¿ÍÔË(TRANSPORTATION)

×÷Õß£º¼ÆËã»ú032  ºúÓÂ½¡  03095218
*/

int tranCapicity, numStations, numOrders;
/*
tranCapicity »ð³µÈÝÁ¿£»
numStations  ³µÕ¾×ÜÊý£»
numOrders    ¶©µ¥×ÜÊý£»
*/

struct Order
{
	int from, to, passengers;//ÆðÊ¼Õ¾£¬ÏÂ¿ÎÕ¾£¬³Ë¿ÍÊý£»
	int price, remainings;
	/*
	    price = (to-from)*passengers Ã¿ÕÅ¶©µ¥µÄ¼ÛÖµ£»
	    remainings ´ú±í´Ë¶©µ¥ºóËùÓÐ¶©µ¥µÄ¼ÛÖµ×ÜºÍ£»
	*/
} order[50];

int maxProfit;//È«¾Ö±äÁ¿£¬¼ÇÂ¼ËùÓÐ¿ÉÄÜ·½°¸µÄ×î´óÐ§Òæ£»
int tran[100];//¼ÇÂ¼»ð³µµÄ³Ë¿ÍÈÝÁ¿Çé¿ö£»

void solve(int start, int earnings)
/*
start ´ú±íÆðÊ¼µÄ¶©µ¥ºÅ£»
earnings ´ú±íÔÚ´ËÖ®Ç°Ëù³¢ÊÔµÄ¶©µ¥µÄ×Ü¼ÛÖµ
*/
{
	if (earnings > maxProfit)//µ±²úÉúµÄ¼ÛÖµ±ÈmaxProfit´óÊ±£¬½«Æä¸³¸ømaxProfit;
	{
		maxProfit = earnings;
	}
	for (; start < numOrders; start++)//°ÑÃ¿ÕÅ¶©µ¥½øÐÐÒ»´Î±éÀú
	{
		int i, flag = false;
		if (earnings + order[start].remainings < maxProfit)
		//ÕâÖÖÇé¿öÏÂ£¬×î´óÐ§Òæ×ÜÊÇÐ¡ÓÚmaxProfit,Ã»ÓÐ±ØÒªÔÙ½øÐÐ±éÀú
		{
			return;
		}
		for (i = order[start].from; i < order[start].to; i++)
		//°Ñ´Ë¶©µ¥´ÓÆðÊ¼Õ¾µ½ÏÂ¿ÎÕ¾½øÐÐÄ£Äâ
		{
			if ((tran[i] += order[start].passengers) > tranCapicity)
			//µ±ÓÐ³Ë¿Í×ÜÊý³¬¹ý»ð³µÈÝÁ¿Ê±£¬²»½ÓÊÜ´Ë¶©µ¥
			{
				flag = true;
				for (; i >= order[start].from; i--)
				{
					tran[i] -= order[start].passengers;
				}
				break;
			}
		}
		if (!flag)
		{
			solve(start + 1, earnings + order[start].price);//ÓÃµÝ¹éÄ£ÄâÏÂÒ»ÕÅ¶©µ¥µÄÇé¿ö
			i--;
			for (; i >= order[start].from; i--)
			{
				tran[i] -= order[start].passengers;
			}
		}
	}
}

int qsort_cmp(const void *a, const void *b)
{
	return (*(struct Order *)b).price - (*(struct Order *)a).price;
}

int main()
{
	while (cin >> tranCapicity >> numStations >> numOrders && tranCapicity)
	{
		int i, s = 0;
		for (i = 0; i < numOrders; i++)
		{
			cin >> order[i].from >> order[i].to >> order[i].passengers;
			order[i].price = (order[i].to - order[i].from) * order[i].passengers;
		}
		memset(tran, 0, sizeof(tran));
		maxProfit = 0;
		qsort(order, numOrders, sizeof(order[0]), qsort_cmp);
		for (i = numOrders - 1; i >= 0; i--)
		{
			order[i].remainings = (s += order[i].price);
		}
		solve(0, 0);
		cout << maxProfit << endl;
	}
	return 0;
}

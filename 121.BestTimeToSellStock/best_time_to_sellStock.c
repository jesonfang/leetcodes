int maxProfit(int* prices, int pricesSize) {
    if (NULL == prices || pricesSize <= 0)
    	return  0;
    	
    int minPrice = prices[0];
    int max_profit = 0, i = 0;
	
//	printf("First in price: %d\n", minPrice);
	
	for(i = 1; i < pricesSize; i ++)
	{
		int tmpProfit = prices[i] - minPrice;
		
		//printf("tmpProfit:%d\n", tmpProfit);
		
		if (prices[i] < minPrice)
		{
			//printf("i:%d, price: %d, min: %d\n", i, prices[i], minPrice);
			minPrice = prices[i];
		}
		
		if ((max_profit < tmpProfit))
		{
			max_profit = tmpProfit;
		}
	}
			
    return max_profit;
}

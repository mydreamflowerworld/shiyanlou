

int Max3(int A,int B,int C){
	return A>B?A>C?A:C:B>C?B:C;
}
/*分治法求List[left]到List[right]的最大子列和*/
int DivideAndConquer(int List[],int left, int right){
	int MaxLeftSum,MaxRightSum;
	int MaxLeftBorderSum,MaxRightBorderSum;

	int LeftBorderSum,RightBorderSum;
	int center,i;

	if(left==right){/*递归的终止条件，子列只有一个数字*/
		if(List[right]>0) return List[left];
		else return 0;
	}
    /*分*/
	center=(left+right)/2;
	/*递归求两边子列的最大和*/
	MaxLeftSum=DivideAndConquer(List,left,center);
    MaxRightSum=DivideAndConquer(List,center+1,right);

    MaxLeftBorderSum=0;LeftBorderSum=0;
    for(i=center;i>=left;i--){
    	LeftBorderSum+=List[i];
    	if(LeftBorderSum>MaxLeftBorderSum)
    		MaxLeftBorderSum=LeftBorderSum;
    }/*左边扫描*/
    MaxRightBorderSum=0;RightBorderSum=0;
    for(i=center+1;i<=right;i++){
        RightBorderSum+=List[i];
        if(RightBorderSum>MaxRightBorderSum)
        	MaxRightBorderSum=RightBorderSum;
    }/*右边扫描*/
    /*返回“治”的结果*/    
    return Max3(MaxLeftSum,MaxRightSum,MaxLeftBorderSum+MaxLeftBorderSum);
    
    int MaxSubseqSum3(int List[],int N){
    	/*保持与前两种算法相同的接口*/
    	return DivideAndConquer(List,0,N-1);
    }
}
/*
请用一个数组实现两个堆栈，
要求最大地利用数组空间，
使数组只要有空间入栈就可以成功
*/
/*一个栈从左向右加元素，另一个栈从右向左加元素，
当两个栈的栈顶指针相遇，表示两个栈都满了*/
#define MaxSize
struct DStack{
	ElementType Data[MaxSize];
	int Top1;
	int Top2;
}S;
S.Top1=-1;
S.Top2=MaxSize;//两个栈都是空
 
void Push(struct DStack *ptrS,ElementType item,int Tag){

	if(PtrS->Top2 - PtrS->Top1==1){
		printf("堆栈满");  return;
	}
	/*对第一个堆栈进行操作*/
	if(Tag==1){
		PtrS->Data[++(PtrS->Top1)]=item;
	}
	/*对第二个堆栈进行操作*/
	else{
		PtrS->Data[--(PtrS->Top1)]=item;
	}
}
ElementType Pop(struct DStack *ptrS,int Tag){
	if(Tag==1){
		if(PtrS->Top1==-1){
			printf("堆栈空");  return NULL;
		}else return PtrS->Data[(PtrS->Top1)--];
	}else{
		if(PtrS->Top2==MaxSize){
			printf("堆栈空");  return NULL;
		}else return PtrS->Data[(PtrS->Top2)++];
	}
}

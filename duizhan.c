/*定义堆栈*/
#define MaxSize/*存储数据元素的最大个数*/
typedef struct SNode *Stack;
struct SNode{
	ElementType Data[MaxSize];
	int Top;
};
/*入栈*/
void Push(Stack PtrS,ElementType item){
	if(PtrS->Top==MaxSize-1){
		printf("栈满");
	}else{
		PtrS->Data[++(PtrS->Top)]=item;
		return;
	}
}
/*出栈*/
void Pop(Stack PtrS){
	if(PtrS->Top==-1){
		printf("栈空");
		return ERROR;
	}else{
		return PtrS->Data[(PtrS->Top)--];
	}
}
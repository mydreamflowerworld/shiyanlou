/*定义堆栈*/
typedef struct SNode *Stack;
struct SNode{
	ElementType Data;
	struct SNode *Next;
};

/*建立空栈*/
Stack CreateStack(){
	/*构建一个堆栈的头指针，返回指针*/
	Stack S;
	S=(Stack)malloc(sizeof(struct SNode));
	S->Next=NULL;
	return S;
}
int IsEmpty(Stack S){
	/*判断堆栈是否为空，*/
	return (S->Next==NULL)
}
/*插入元素*/
void Push(ElementType item,Stack S){
	struct SNode *TmpCell;
	TmpCell=(struct SNode *)malloc(sizeof(struct SNode));
	TmpCell->ElementType=item;
	TmpCell->Next=S->Next;
	S->Next=TmpCell;
}
/*删除元素*/
ElementType Pop(Stack S){
	struct SNode *FirstCell;
	ElementType TopElem;
	if(IsEmpty(S)){
		printf("堆栈空"); return NULL;
	}else{
		FirstCell=S->Next;
		S->Next=FirstCell->Next;
		TopElem=FirstCell->ElementType;
		free(FirstCell);
		return TopElem;
	}
}
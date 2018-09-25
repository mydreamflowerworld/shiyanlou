struct  Node
{
	ElementType Data;
	struct Node *Next;
};
struct QNode{/*链队列指针*/
	struct Node *rear;
	struct Node *front;
};
typedef struct QNode *Queue;
Queue PtrQ;
/*不带头结点的链式队列出队操作*/
ElementType DeleteQ(Queue PtrQ){
	struct Node *FrontCell;
	ElementType FrontCell;

	if(PtrQ->front==NULL){
		printf("队列空"); return ERROR；
	}
	FrontCell=PtrQ->front;
	if(PtrQ->front==PtrQ->rear)/*队列只有一个元素*/
	  PtrQ->front=PtrQ->rear=NULL;
	else
	   PtrQ->front=PtrQ->front->Next;
	FrontElem=FrontCell->Data;    
	free(FrontCell);
	return FrontElem;
}

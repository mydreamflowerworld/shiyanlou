//1.定义链表
typedef struct LNode*List;
struct LNode{
	ElementType Data;
	List Next;
}
struct LNode L;
List PtrL;
//求表长
int Length(List PtrL){
	List p=PtrL;//p指向表的第一个结点
	int j=0;
	while(p){
		p=p->Next;//指针向后遍历
		j++;
	}
	return j;//返回的是链表的长度
}
//2.查找
//（按序号查找：FindKth）
List FindKth(int K,List PtrL){
	List p=PtrL;
	int i=1;
	while(p!=NULL&&i<K){
		p=p->Next;
		i++;
	}
	if(i==K)return p;//找到返回指针
	else return NULL;
}
//(按值查找：Find)
List Find(ElementType X,ListPtrL){
	List p=PtrL;
	while(p!=NULL&&p->Data!=X)
		p=p->Next;
	return p;
}
/*
3.插入（在第i-1（1<=i<=n+1）个结点后插入一个值为X的新结点）
（1）先构造一个新的结点
（2）再找到链表的第i-1个结点，用p指向
（3）然后修改指针，插入结点（p之后结点就是s）
*/
List Insert(ElementType X,int i, List PtrL)
{
	List p,s;
	if(i==1){//新结点插入在表头
		s=(List)malloc(sizeof(struct LNode));//申请，装填结点
        s->Data=X;
        s->Next=PtrL;
        return s;//返回新的头指针
	}
	p=FindKth(i-1,PtrL);
	if(p==NULL){
		printf("参数i出错")；
		return NULL;
	}else{
		s=(List)malloc(sizeof(struct LNode));
		s->Data=X;
		s->Next=p->Next;//新结点插入在第i-1结点后，两步的顺序不可改变
		p->Next=s;
		return PtrL;
	}
}
/*4.删除（删除链表的第i（1<i<n）个位置上的结点）
（1）先找到链表的第i-1个结点，用p指向
（2）再用指针s指向要被删除的结点（p的下一个结点）
（3）然后修改指针，删除s所指向的结点
（4）最后释放s所指结点的空间
*/
List Delete(int i,List PtrL){
	List p,s;
	if(i==1){
		s=PtrL;
		if(PtrL!=NULL) PtrL=PtrL->Next;
		else return NULL;
		free(s);
		return PtrL;
	}
	p=FindKth(i-1,PtrL);
	if(p==NULL){
		printf("第%d个结点不存在"，i-1)； return NULL；
	}else if (p->Next==NULL){
		printf("第%d个结点不存在"，i)； return NULL；
	}else{
		s=p->Next;
		p->Next=s->Next;
		free(s);
		return PtrL;
	}
}
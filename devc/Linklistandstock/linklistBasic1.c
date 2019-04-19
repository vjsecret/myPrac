#include <stdio.h>
#include <stdlib.h>

//https://dotblogs.com.tw/ibllcwhchiu/2017/05/03/datastructure_part1
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;


//https://lakesd6531.pixnet.net/blog/post/329288496-c%E8%AA%9E%E8%A8%80-%E9%8F%88%E7%B5%90%E4%B8%B2%E5%88%97(link-list)%E7%9A%84%E5%AF%A6%E4%BD%9C%E7%AF%84%E4%BE%8B
void func1(void){	
  Node a,b,c;
  Node *ptr=&a; //�ŧiptr�A�ñN�L�u�V�`�Ia
  
  a.data=12;
  a.next=&b;
  b.data=30;
  b.next=&c;
  c.data=64;
  c.next=NULL;

  while(ptr!=NULL){
  	printf("address=%p, ",ptr); //�L�X�`�I����} 
  	printf("data=%d ",ptr->data); //�L�X�`�I����� 
  	printf("next=%p\n",ptr->next); //�L�X�U�@�Ӹ`�I��} 
  	ptr=ptr->next;  //�Nptr���V�U�@�Ӹ`�I 
  } 
}


struct node1{
	int data;
	struct node *next;
};
typedef struct node1 NODE;

NODE* GetNode(void)
{
    NODE* ptr = (NODE*)malloc(sizeof(NODE)); // �ŧi����ptr�A�ë��VNODE�j�p���Ŷ�
    if(ptr == NULL)
        exit(1);
    return ptr; //�^�ǳo�ӪŶ�������
}
NODE* InsertNode(NODE* pHead, NODE* ptr, int data)
{
    NODE* NewNode = GetNode();
    NewNode->data = data;
    NewNode->next = NULL;

    if( ptr == NULL )           //���bHead���e�Aptr��NULL
    {
        NewNode->next = pHead;
        pHead = NewNode;
    }
    else if( ptr->next == NULL) //���b���ڤ���Aptr���U�Ӹ`�I��NULL
    {
        ptr->next = NewNode;
    }
    else                        //���b�����A���e�����VNew�A��New���V�᭱
    {
        NewNode->next = ptr->next;
        ptr->next = NewNode;
    }
    return pHead;               //�]���Y���Хi��|�ܡA�^���Y����
}
void FreeNode( NODE* ptr )
{
    free(ptr);
}
NODE* FindNode(NODE* ptr, int data)
{
    NODE* pTempNode = ptr;    //���F���ʨ�쥻���СA�ŧi�@�ӷs���а�����
    while( pTempNode->next != NULL && pTempNode != data )
    {
        pTempNode = pTempNode->next;
    }
    return pTempNode;
}

//https://jax-work-archive.blogspot.com/2009/04/c-link-list.html 
/* �w�q���c���A */  
typedef struct link_node{  
   int data;  
   struct link_node *link;  
} LINK_NODE;

/* ���ͷs�`�I */  
LINK_NODE *new_node(int data){  
   LINK_NODE *node;  
   node=(LINK_NODE *) malloc(sizeof(LINK_NODE));/*<stdlib.h>*/  
     
   // �O���餣��  
   if(node == NULL){ return NULL;}  
     
   node->data=data;    
   node->link=NULL;       
   return node;  
}  

/* �[�J�s����Ʃ�̫� */  
LINK_NODE *push_node(LINK_NODE *list, int data){  
   /*���ͷs�`�I*/  
   LINK_NODE *node=new_node(data);    
  
   // �[�J�Ĥ@�ӷs�`�I  
   if(list==NULL){      
       list=node;  
   }else{  
       LINK_NODE *p=list;    
       // ���o�̫�@�Ӹ`�I  
       while(p->link!=NULL){p=p->link;}  
       p->link=node;  
   }     
   return list;  
}  
  
  
/* �ƧǴ��J�s�`�I */  
LINK_NODE *sort_insert(LINK_NODE *list,int data){  
   // �[�J�Ĥ@�����  
     
   // ���ͷs�`�I  
   LINK_NODE *node=new_node(data);      
   if(list==NULL){ list=node; return list; }    
  
   // �M��j����(data)����}  
   LINK_NODE *r=list,*q=list;      
   while(r!=NULL && r->data<data){ q=r; r=r->link; }  
  
   if(r==list){ // ���`�I  
       node->link=list; list=node;   
   }else{ // �[�J�s�`�I�󤤶�  
       node->link=q->link;   
       q->link=node;   
   }      
   return list;   
}  
  
  
/* �p���C���� */  
int get_length(LINK_NODE *list){  
   LINK_NODE *p=list;  
   int count=0;    
   while(p!=NULL){      
       count++;    
       p=p->link;    
   }  
     
   return count;  
}  
  
  
/* �j�M���(data)���`�I��l */  
LINK_NODE *search_node(LINK_NODE *list, int data){  
   LINK_NODE *p=list;    
   while(p!=NULL && p->data!=data){ p=p->link; }  
   return p ;  
}  
  
  
/* �L�X�Ҧ���C���Ҧ���� */  
int display(LINK_NODE *list){  
   LINK_NODE *p=list;  
   while(p!=NULL){   
       printf("%d\n",p->data);/*<stdio.h>*/  
       p=p->link;    
   }  
   return 1;  
}


int main(int argc, char *argv[])
{
  //func1();
/*
  NODE a,b,c;
  NODE *ptr=&a; //�ŧiptr�A�ñN�L�u�V�`�Ia
    
  a.data=12;
  a.next=&b;
  b.data=30;
  b.next=&c;
  c.data=64;
  c.next=NULL;

	//create:
	NODE* NewNode = (NODE*)malloc(sizeof(NODE)); // �ŧi����NewNode�A�ë��VNODE�j�p���Ŷ�
    if(NewNode == NULL)
        exit(1);
	NewNode->data = 15;
    NewNode->next = NULL;
    //insert:
	NewNode->next = ptr->next;
    ptr->next = NewNode;

  while(ptr!=NULL){
  	printf("address=%p, ",ptr); //�L�X�`�I����} 
  	printf("data=%d ",ptr->data); //�L�X�`�I����� 
  	printf("next=%p\n",ptr->next); //�L�X�U�@�Ӹ`�I��} 
  	ptr=ptr->next;  //�Nptr���V�U�@�Ӹ`�I 
  }
 */
  //FindNode(&a,12); 
	/* 
   LINK_NODE *list=NULL;  
     
   list=sort_insert(list,4);  
   list=sort_insert(list,2);  
   list=sort_insert(list,7);  
   list=sort_insert(list,9);  
   list=sort_insert(list,14);  
   display(list);  
*/ 

printf("=============================================\n"); 	
	NODE* head = (NODE*)malloc(sizeof(NODE)); // �ŧi����head�A�ë��VNODE�j�p���Ŷ�
    if(head == NULL)
        exit(1);
	printf("Head=%p\n",head);
	head->data = 12;
    head->next = NULL;
    
	NODE *Current;
	NODE *pre;
	int *first=NULL;
	int i;
	for(i=0;i<=3;i++){

		//create:
		NODE* newNode = (NODE*)malloc(sizeof(NODE)); // �ŧi����NewNode�A�ë��VNODE�j�p���Ŷ�
	    if(newNode == NULL)
	    	exit(1);
	    newNode->next = NULL;
	    newNode->data=i;
	    printf("New=%p\n",newNode);
	    
		if (i==0){
			Current=head;
			first=newNode;
			printf("first=%p\n",first); //printf("Head=%p\n",Current);	
		}
		else{
			Current=Current->next;	
		}	
		Current->next=newNode;
		
		printf("Current=%p, ",Current);
		printf("Current->next=%p,",Current->next);
		printf("data Current=%d\n",Current->data);
		printf("=======\n");		 
	}
	printf("=====================Current========================\n");
	Current=head;
  	while(Current!=NULL){
	  	printf("address=%p, ",Current); //�L�X�`�I����} 
	  	printf("data=%d ",Current->data); //�L�X�`�I����� 
	  	printf("next=%p\n",Current->next); //�L�X�U�@�Ӹ`�I��} 
	  	Current=Current->next;  //�Nptr���V�U�@�Ӹ`�I 
  	}

/*
printf("=============================================\n"); 	
	NODE* head = (NODE*)malloc(sizeof(NODE)); // �ŧi����head�A�ë��VNODE�j�p���Ŷ�
    if(head == NULL)
        exit(1);
	printf("Head=%p\n",head);
	head->data = 12;
    head->next = NULL;
    
	NODE *Current;
	NODE *pre;
	int *first=NULL;
	int i;
	for(i=0;i<=3;i++){

		//create:
		NODE* newNode = (NODE*)malloc(sizeof(NODE)); // �ŧi����NewNode�A�ë��VNODE�j�p���Ŷ�
	    if(newNode == NULL)
	    	exit(1);
	    newNode->next = NULL;
	    newNode->data=i;
	    printf("New=%p\n",newNode);
	    
		if (i==0){
			Current=head;
			first=newNode;
			printf("first=%p\n",first); //printf("Head=%p\n",Current);	
		}
		else{
			Current=pre;	
		}	
		Current->next=newNode;
		pre=newNode;	
		
		printf("Current=%p, ",Current);
		printf("Current->next=%p,",Current->next);
		printf("data Current=%d\n",Current->data);
		printf("address pre=%p,",pre);
		printf("address pre->next=%p,",pre->next);
		//printf("data=%d",ptrT->next->data);
		printf("data=%d\n",pre->data); //�L�X�`�I�����
		printf("=======\n");		 
	}
	printf("=====================Current========================\n");
	Current=head;
  	while(Current!=NULL){
	  	printf("address=%p, ",Current); //�L�X�`�I����} 
	  	printf("data=%d ",Current->data); //�L�X�`�I����� 
	  	printf("next=%p\n",Current->next); //�L�X�U�@�Ӹ`�I��} 
	  	Current=Current->next;  //�Nptr���V�U�@�Ӹ`�I 
  	}
	printf("====================pre=========================\n");
	pre=first;
  	while(pre!=NULL){
	  	printf("address=%p, ",pre); //�L�X�`�I����} 
	  	printf("data=%d ",pre->data); //�L�X�`�I����� 
	  	printf("next=%p\n",pre->next); //�L�X�U�@�Ӹ`�I��} 
	  	pre=pre->next;  //�Nptr���V�U�@�Ӹ`�I 
  	}

printf("=============================================\n"); 	
	NODE* head = (NODE*)malloc(sizeof(NODE)); // �ŧi����head�A�ë��VNODE�j�p���Ŷ�
    if(head == NULL)
        exit(1);
	printf("Head=%p\n",head);
	head->data = 12;
    head->next = NULL;
    
	NODE *preBefore;
	NODE *ptrNow;
	int *first=NULL;
	int i;
	for(i=0;i<=3;i++){
		//create:
		NODE* Current = (NODE*)malloc(sizeof(NODE)); // �ŧi����NewNode�A�ë��VNODE�j�p���Ŷ�
	    if(Current == NULL)
	    	exit(1);
	    Current->next = NULL;
	    Current->data=i;
	    printf("New=%p\n",Current);
	    
		if (i==0){
			preBefore=head;
			first=Current;
			printf("first=%p\n",first); //printf("Head=%p\n",Current);	
		}
		else{
			preBefore=ptrNow;
			//preBefore=Current;	
		}	
		preBefore->next=Current;
		ptrNow=Current;	
		
		printf("preBefore=%p, ",preBefore);
		printf("preBefore->next=%p,",preBefore->next);
		printf("data preBefore=%d\n",preBefore->data);
		printf("address ptrNow=%p,",ptrNow);
		printf("address ptrNow->next=%p,",ptrNow->next);
		//printf("data=%d",ptrT->next->data);
		printf("data=%d\n",ptrNow->data); //�L�X�`�I�����
		printf("=======\n");		 
	}
	printf("=====================preBefore========================\n");
	preBefore=head;
  	while(preBefore!=NULL){
	  	printf("address=%p, ",preBefore); //�L�X�`�I����} 
	  	printf("data=%d ",preBefore->data); //�L�X�`�I����� 
	  	printf("next=%p\n",preBefore->next); //�L�X�U�@�Ӹ`�I��} 
	  	preBefore=preBefore->next;  //�Nptr���V�U�@�Ӹ`�I 
  	}
	printf("====================ptrNow=========================\n");
	ptrNow=first;
  	while(ptrNow!=NULL){
	  	printf("address=%p, ",ptrNow); //�L�X�`�I����} 
	  	printf("data=%d ",ptrNow->data); //�L�X�`�I����� 
	  	printf("next=%p\n",ptrNow->next); //�L�X�U�@�Ӹ`�I��} 
	  	ptrNow=ptrNow->next;  //�Nptr���V�U�@�Ӹ`�I 
  	}

/*
printf("=============================================\n");
int i;
for(i=0;i<=3;i++){ 
	NODE* Current = (NODE*)malloc(sizeof(NODE)); // �ŧi����NewNode�A�ë��VNODE�j�p���Ŷ�
    if(Current == NULL)
    	exit(1);
    Current->next = NULL;
    Current->data=i;
    printf("Head=%p\n",Current);
    //int *Current=NULL;    
    int *first=NULL;
    NODE *ptrT;
    
	if (i==0){
		first=Current;
		//ptrT=Current;
		printf("first=%p\n",first); //printf("Head=%p\n",Current);
		
	}
	else
		ptrT->next=Current;
	
	ptrT=Current;
	//ptrT->data=Current->data;	
	
	printf("address ptrT=%p,",ptrT);
	printf("address ptrT->next=%p,",ptrT->next);
	//printf("data=%d",ptrT->next->data);
	printf("data=%d\n",ptrT->data); //�L�X�`�I����� 
}*/


/*
int j=0;
while(j<sizeof(ptrT)){
	printf("address=%p, ",ptrT); //�L�X�`�I����} 
  	printf("data=%d ",ptrT->data); //�L�X�`�I����� 
  	printf("next=%p\n",ptrT->next); //�L�X�U�@�Ӹ`�I��} 
  	//ptr=ptr->next;  //�Nptr���V�U�@�Ӹ`�I 
  	j=j+1;
}
*/

//https://kopu.chat/2017/06/02/c-%E8%AA%9E%E8%A8%80%EF%BC%9A%E9%8F%88%E7%B5%90%E4%B8%B2%E5%88%97linked-list%E7%9A%84%E5%BB%BA%E7%AB%8B%E8%88%87%E5%88%AA%E9%99%A4/
//http://alrightchiu.github.io/SecondRound/linked-list-xin-zeng-zi-liao-shan-chu-zi-liao-fan-zhuan.html
  system("PAUSE");	 
  return 0;
}
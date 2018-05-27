#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include <conio.h>  
#include <io.h>
#include <ctype.h>
#define MAX_STU_NUM 10
#define MAX_STU_NAME 20
#define MAX_PRO 10
#define MAX_PROFESSION 20
#define MAX_PHONE_NUM 15
#define MAX_KEY 10 

struct Date{
	char year[6];
	char month[6];
	char day[6];
}; 

struct Teacher{
	char num[MAX_STU_NUM];/*����*/
	char name[MAX_STU_NAME];/*����*/
	char key[MAX_KEY];/*����*/
	struct Teacher *next;
};

struct Student{
	char num[MAX_STU_NUM];/*ѧ�Ż򹤺�*/
	char name[MAX_STU_NAME];/*����*/
	char sex[10];/*�Ա�*/ 
	struct Date Birthday;/*����*/
	char province[MAX_PRO];/*����*/
	char profession[MAX_PROFESSION];/*רҵ*/
	char classnum[10];/*�༶*/ 
	char phonenum[MAX_PHONE_NUM];/*�绰*/
	char key[MAX_KEY];/*����*/
	struct Student *next;
	int yu;
	int shu;
	int ying;
	int sum;
};

void teachermenu();
void studentmenu(struct Student *pHead);
int isExisted(struct Student *pHead, char* stunum);
void teacherlogin(struct Teacher *pHead);
struct Student *read();
void print(struct Student *pHead);
void add();
void Delete(struct Student *pHead);
void resave(struct Student *pHead);
void change(struct Student *pHead);
void find(struct Student *pHead);
void zhuce();
void addtea();
struct Teacher *readtea();
void grademenu();
void input(struct Student *pHead);
void printgrade(struct Student *pHead);
void gaichengji(struct Student *pHead);
struct Student *paixu(struct Student *h);
void gaimimastu(struct Student *pTemp);


/********�жϽ���********/
void judge()
{
	struct Student *pHead;
	struct Teacher *phead;
	pHead = read();
	phead = readtea();
	system("color F0");
	char a[200] = {0};
	do{
		printf("\t\t��---���ã���ӭ����ѧ������ϵͳ��---��\n");
		printf("\t====================================================\n");
		printf("\t--------�� 1.����ѧ����ѧ������ϵͳ ��--------\n\n");
		printf("\t--------�� 2.�����ʦ��ѧ������ϵͳ ��--------\n\n");
		printf("\t--------�� 3.ע��ѧ����Ϣ ��--------\n\n");
		printf("\t--------�� 4.ע����ʦ��Ϣ ��--------\n\n");
		printf("\t--------�� 0.�˳� ��--------\n\n");
		printf("\t====================================================\n");
		printf("����0~2��ѡ���Իس�������\n");
		gets(a);
		if ( !strcmp(a,"1") ) {
			system("CLS");
			studentmenu(pHead);
			break;
		}
		else if ( !strcmp(a,"2") ) {
			system("CLS");
			teacherlogin(phead);
			break;
		}
		else if ( !strcmp(a,"3") ) {
			system("CLS");
			zhuce();
			system( "pause" );
			system("CLS");
		}
		else if ( !strcmp(a,"4") ) {
			system("CLS");
			addtea();
			system( "pause" );
			system("CLS");
		}
		else if ( !strcmp(a,"0") ) ;
		else{
			printf("��������ȷ����Ϣ��\n\n");
			system( "pause" );
			system("CLS");
		}
	}while( strcmp(a,"0") );
}


/********��ʦ�˵�¼ע��ҳ��********/
void teacherlogin(struct Teacher *pHead)
{
	struct Teacher *pTemp;
	int p,flag=0;  
    char ch,acnt[20],pwd[20];    
     
    
    while(1){
    	pTemp = pHead->next ;
		p=0; 
   	 	printf("\t\t��---���ã���ӭ�����ʦ��ѧ������ϵͳ��---��\n");
		printf("\t====================================================\n");
		printf("\t\t\t �������˺ţ�"); 
    	scanf("%s",acnt);
		printf("\t\t\t ���������룺");
    	while((ch=getch())!='\r')//�ж��Ƿ��ǻس�  
    	{  
        	if(ch==8)//ʵ��backspace���Ĺ��ܣ�����backspace����ascii����8  
        	    {  
            	putchar('\b');  
                putchar(' ');  
               	putchar('\b');
                if(p>0)//���ֻ��ɾ��û���ַ�  
                p--;  
            }  
        	if(!isdigit(ch)&&!isalpha(ch))//�ж��Ƿ������ֻ��ַ�  
        	    continue;  
       		putchar('*');//����Ļ�ϴ�ӡ�Ǻ�  
        	pwd[p++]=ch;//��������  
    	}  
    	pwd[p]=0;//�����ַ��� 
		getchar();
    	while(pTemp != NULL){
		if(!strcmp(acnt, pTemp->num) &&!strcmp(pwd, pTemp->key ) ){
			system("CLS"); 
			teachermenu();
			flag = 1;
		}

		pTemp = pTemp->next;
		
		}
		if(flag == 0) {
		printf("\n");
		printf("�����˺Ż��������\n");
		system( "pause" );
		system("CLS");
		}
		if(flag == 1) break;
	}
}


/********��ʦ��������********/
void teachermenu()
{
	char a[200];
	while(1){
		printf("\n");
		printf("\t\t��---���ã���ӭ�����ʦ��ѧ������ϵͳ��---��\n");
		printf("\t====================================================\n");
		printf("\t--------�� 1.���ѧ����Ϣ  2.���ѧ����Ϣ ��--------\n\n");
		printf("\t--------�� 3.�޸�ѧ����Ϣ  4.ɾ��ѧ����Ϣ ��--------\n\n");
		printf("\t--------�� 5.����ѧ����Ϣ  6.����ɼ�ϵͳ ��--------\n\n");
		printf("\t--------�� 7.�޸����� ��--------\n\n");
		printf("\t--------�� 0.�˳� ��--------\n\n");
		printf("\t====================================================\n");
		printf("����0~6��ѡ���Իس�����������\n");
		gets(a);
		if ( !strcmp(a,"0") ) exit(1);
		else if ( !strcmp(a,"1") ){
			system("CLS");
			add();
			system( "pause" );
			system("CLS");
		}
		else if ( !strcmp(a,"2") ){
			system("CLS");
			print( read() );
			system( "pause" );
			system("CLS");
		}
		else if ( !strcmp(a,"3") ){
			system("CLS");
			change( read() );
			system( "pause" );
			system("CLS");
		}
 		else if ( !strcmp(a,"4") ){
			system("CLS");
			Delete( read() );
			system( "pause" );
			system("CLS");
		} 
		else if ( !strcmp(a,"5") ){
			system("CLS");
			find( read() );
			system( "pause" );
			system("CLS");
		}
		else if ( !strcmp(a,"6") ){
			system("CLS");
			grademenu();
			system( "pause" );
			system("CLS");
		}
		else{
			printf("��������ȷ����Ϣ��\n\n");
			system( "pause" );
			system("CLS");
		}
	}
}


/********ѧ����������********/
void studentmenu(struct Student *pHead)
{
	struct Student *pTemp;
	int p,flag=0;  
    char ch,acnt[15],pwd[15],a,b;    
      
    while(1){
    	p=0;
		pTemp = pHead->next ;
   	 	printf("\t\t��---���ã���ӭ����ѧ����ѧ������ϵͳ��---��\n");
		printf("\t====================================================\n");
		printf("\t\t\t �������˺ţ�"); 
    	scanf("%s",acnt);
		printf("\t\t\t ���������룺");
    	while((ch=getch())!='\r')//�ж��Ƿ��ǻس�  
    	{  
        	if(ch==8)//ʵ��backspace���Ĺ��ܣ�����backspace����ascii����8  
        	    {  
            	putchar('\b');  
                putchar(' ');  
               	putchar('\b');
                if(p>0)//���ֻ��ɾ��û���ַ�  
                p--;  
            }  
        	if(!isdigit(ch)&&!isalpha(ch))//�ж��Ƿ������ֻ��ַ�  
        	    continue;  
       		putchar('*');//����Ļ�ϴ�ӡ�Ǻ�  
        	pwd[p++]=ch;//��������  
    	}  
    	pwd[p]=0;//�����ַ���   
    	while(pTemp != NULL){
		if((!strcmp(acnt, pTemp->num)) &&(!strcmp(pwd, pTemp->key )) ){
			printf("\n");
			printf("ѧ��:%s\n", pTemp->num );
			printf("����:%s\n", pTemp->name );
			printf("�Ա�:%s\n", pTemp->sex );
			printf("����:%s-%s-%s\n", pTemp->Birthday.year, pTemp->Birthday.month ,pTemp->Birthday.day );
			printf("����:%s\n", pTemp->province );
			printf("רҵ:%s\n", pTemp->profession );
			printf("�༶:%s\n", pTemp->classnum );
			printf("�绰:%s\n", pTemp->phonenum );
			printf("\n");
			flag = 1;
			printf("�Ƿ��޸����룺(ȷ��������Y)\n");
			getchar();
			scanf("%c", &b);
			if(b=='Y'){
				gaimimastu(pTemp);
				resave(pHead);
				system("CLS");
			}else exit(1); 
		}
		pTemp = pTemp->next;
		}
		if(flag == 0) {
		printf("\n");
		printf("�����˺Ż��������\n");
		system( "pause" );
		system("CLS");
		}
		
	}
}



/********������Ϣ���ļ�********/ 
void save(struct Student *pHead)
{
	FILE *fp;
	struct Student *pTemp;
	if( (fp = fopen("stu.txt", "at")) == NULL ){//���ļ����ж��Ƿ����
		printf("�����ļ�ʧ�ܣ�\n\n");
		getchar();
		return; 
	} 
	pTemp = pHead;
	while( pTemp != NULL ){	
		fputc('\n', fp);
		fprintf(fp,"%s %s %s %s %s %s %s %s %s %s %s %d %d %d %d",pTemp->num,pTemp->name,
		pTemp->sex,pTemp->Birthday.year, pTemp->Birthday.month, pTemp->Birthday.day,pTemp->province,
		pTemp->profession,pTemp->classnum,pTemp->phonenum,pTemp->key,pTemp->yu,pTemp->shu,pTemp->ying,
		pTemp->sum); 
		pTemp = pTemp->next;
	}
	fclose(fp);
} 


/********������ʦ��Ϣ���ļ�********/ 
void savetea(struct Teacher *pHead)
{
	FILE *fp;
	struct Teacher *pTemp;
	if( (fp = fopen("tea.txt", "at")) == NULL ){//���ļ����ж��Ƿ����
		printf("�����ļ�ʧ�ܣ�\n\n");
		getchar();
		return; 
	} 
	pTemp = pHead;
	while( pTemp != NULL ){	
		fputc('\n', fp);
		fprintf(fp,"%s %s %s",pTemp->num,pTemp->name,pTemp->key); 
		pTemp = pTemp->next;
	}
	fclose(fp);
} 

/********������Ϣ���ļ�(��д)********/ 
void resave(struct Student *pHead)
{
	FILE *fp;
	struct Student *pTemp;
	if( (fp = fopen("stu.txt", "wt")) == NULL ){//���ļ����ж��Ƿ����
		printf("�����ļ�ʧ�ܣ�\n\n");
		getchar();
		return; 
	} 
	pTemp = pHead->next ;
	while( pTemp != NULL ){	
		
		fprintf(fp,"%s %s %s %s %s %s %s %s %s %s %s %d %d %d %d",pTemp->num,pTemp->name,
		pTemp->sex,pTemp->Birthday.year, pTemp->Birthday.month, pTemp->Birthday.day,pTemp->province,
		pTemp->profession,pTemp->classnum,pTemp->phonenum,pTemp->key,pTemp->yu,pTemp->shu,pTemp->ying,
		pTemp->sum); 
		
		pTemp = pTemp->next;
		fputc('\n', fp);
	}
	fputc('\b', fp);
	fclose(fp);
} 


/********��ȡѧ����Ϣ********/
struct Student *read()
{
	FILE *fp;;
	struct Student *pHead, *pEnd, *pNew;
	pHead = (struct Student *)malloc(sizeof(struct Student));
	pHead->next = NULL;
	pEnd = pHead;
	if( (fp = fopen("stu.txt", "rt")) == NULL ){//���ļ����ж��Ƿ����
		printf("�����ļ�ʧ�ܣ�\n\n");
		getchar(); 
	} else{
		while(!feof(fp)){  
			pNew = (struct Student *)malloc(sizeof(struct Student)); 
			fscanf(fp,"%s %s %s %s %s %s %s %s %s %s %s %d %d %d %d",pNew->num,pNew->name,
			pNew->sex,pNew->Birthday.year, pNew->Birthday.month, pNew->Birthday.day,pNew->province,
			pNew->profession,pNew->classnum,pNew->phonenum,pNew->key,&pNew->yu,&pNew->shu,&pNew->ying,
			&pNew->sum); 
      		 
      		pNew->next = NULL;  
       		pEnd->next = pNew;  
        	pEnd = pNew;
    	}
	}	

	fclose(fp);
	return pHead;
}

/********��ȡ��ʦ��Ϣ********/
struct Teacher *readtea()
{
	FILE *fp;;
	struct Teacher *pHead, *pEnd, *pNew;
	pHead = (struct Teacher *)malloc(sizeof(struct Teacher));
	pHead->next = NULL;
	pEnd = pHead;
	if( (fp = fopen("tea.txt", "rt")) == NULL ){//���ļ����ж��Ƿ����
		printf("�����ļ�ʧ�ܣ�\n\n");
		getchar(); 
	} else{
		while(!feof(fp)){  
			pNew = (struct Teacher *)malloc(sizeof(struct Teacher)); 
			fscanf(fp,"%s %s %s",pNew->num,pNew->name, pNew->key );
      		 
      		pNew->next = NULL;  
       		pEnd->next = pNew;  
        	pEnd = pNew;
    	}
	}	

	fclose(fp);
	return pHead;
}


/********���ѧ����Ϣ********/ 
void add()
{
	struct Student *pHead = NULL;
	struct Student *pEnd, *pNew, *pTemp, *phead;
	char flag;
	phead = read();
	int iIndex = 1;
	pEnd = pNew = (struct Student *)malloc(sizeof(struct Student));
	printf("������ѧ��\n");
	scanf("%s", pNew->num );
	if(isExisted(phead, pNew->num)){
		printf("��ѧ���Ѵ���\n");
		exit(1);
	}
	strcpy(pNew->key, pNew->num);
	printf("����������\n");
	scanf("%s", pNew->name );
	printf("�������Ա�(��/Ů)\n");
	scanf("%s", pNew->sex );
	printf("����������(����:1999 09 29)\n");
	scanf("%s %s %s", pNew->Birthday.year, pNew->Birthday.month, pNew->Birthday.day );
	printf("�����뼮��\n");
	scanf("%s", pNew->province );
	printf("������רҵ\n");
	scanf("%s", pNew->profession );
	printf("������༶\n");
	scanf("%s", pNew->classnum );
	printf("������绰\n");
	scanf("%s", pNew->phonenum );
	pNew->yu = pNew->shu =pNew->ying =pNew->sum = 0;
	getchar();
	pNew->next = pHead;  
    pHead = pNew;  
    pEnd = pNew;
    
	printf("�Ƿ��������ѧ�����ݣ�����Y����¼�룬����ֹͣ¼��\n");  
	scanf("%c", &flag);
	getchar();
	while(flag == 'Y'){  
		pNew=(struct Student *)malloc(sizeof(struct Student));  
       	printf("������8λѧ��\n");
		scanf("%s", pNew->num );
		strcpy(pNew->key, pNew->num);
		printf("����������\n");
		scanf("%s", pNew->name );
		printf("�������Ա�(��/Ů)\n");
		scanf("%s", pNew->sex );
		printf("����������(����:1999 09 29)\n");
		scanf("%s %s %s", pNew->Birthday.year, pNew->Birthday.month, pNew->Birthday.day );
		printf("�����뼮��\n");
		scanf("%s", pNew->province );
		printf("������רҵ\n");
		scanf("%s", pNew->profession );
		printf("������༶\n");
		scanf("%s", pNew->classnum );
		printf("������11λ�绰\n");
		scanf("%s", pNew->phonenum );
		pNew->yu = pNew->shu =pNew->ying =pNew->sum = 0;
		getchar();
		
		pNew->next = NULL;  
        pEnd->next = pNew;  
        pEnd = pNew;
		 
		printf("�Ƿ��������ѧ�����ݣ�����Y����¼�룬����ֹͣ¼��\n");  
		scanf("%c", &flag);
		getchar();	
    } 
	if(flag != 'Y'){
		save(pHead);
		pTemp = pHead;
		while( pTemp != NULL ){
			printf("����ĵ�%d��ѧ����:\n", iIndex);
			printf("ѧ��:%s\n", pTemp->num );
			printf("����:%s\n", pTemp->name );
			printf("�Ա�:%s\n", pTemp->sex );
			printf("����:%s-%s-%s\n", pTemp->Birthday.year, pTemp->Birthday.month ,pTemp->Birthday.day );
			printf("����:%s\n", pTemp->province );
			printf("רҵ:%s\n", pTemp->profession );
			printf("�༶:%s\n", pTemp->classnum );
			printf("�绰:%s\n", pTemp->phonenum );
			printf("\n");
			pTemp = pTemp->next;
			iIndex++; 
		} 
	} 
    free(pNew);   
}


/********ע��ѧ����Ϣ********/ 
void zhuce()
{
	struct Student *pHead = NULL;
	struct Student *pEnd, *pNew, *pTemp, *phead;
	char flag;
	int iIndex = 1;
	phead = read();
	pEnd = pNew = (struct Student *)malloc(sizeof(struct Student));
	printf("������ѧ��\n");
	scanf("%s", pNew->num );
	if(isExisted(phead, pNew->num)){
		printf("��ѧ���Ѵ���\n");
		exit(1);
	}
	strcpy(pNew->key, pNew->num);
	printf("����������\n");
	scanf("%s", pNew->name );
	printf("�������Ա�(��/Ů)\n");
	scanf("%s", pNew->sex );
	printf("����������(����:1999 09 29)\n");
	scanf("%s %s %s", pNew->Birthday.year, pNew->Birthday.month, pNew->Birthday.day );
	printf("�����뼮��\n");
	scanf("%s", pNew->province );
	printf("������רҵ\n");
	scanf("%s", pNew->profession );
	printf("������༶\n");
	scanf("%s", pNew->classnum );
	printf("������绰\n");
	scanf("%s", pNew->phonenum );
	pNew->yu = pNew->shu =pNew->ying =pNew->sum = 0;
	getchar();
	pNew->next = pHead;  
    pHead = pNew;  
    pEnd = pNew;
    save(pHead);
    printf("ע��ɹ���\n");
}


/********��ӽ�ʦ��Ϣ********/ 
void addtea()
{
	struct Teacher *pHead = NULL;
	struct Teacher *pEnd, *pNew, *pTemp;
	char flag;
	int iIndex = 1;
	pEnd = pNew = (struct Teacher *)malloc(sizeof(struct Teacher));
	printf("�����빤��\n");
	scanf("%s", pNew->num );
	strcpy(pNew->key, pNew->num);
	printf("����������\n");
	scanf("%s", pNew->name );
	getchar();
	pNew->next = pHead;  
    pHead = pNew;  
    pEnd = pNew;
    
	printf("�Ƿ���������ʦ���ݣ�����Y����¼�룬����ֹͣ¼��\n");  
	scanf("%c", &flag);
	getchar();
	while(flag == 'Y'){  
		pNew=(struct Teacher *)malloc(sizeof(struct Teacher)); 
       	printf("������8λ����\n");
		scanf("%s", pNew->num );
		strcpy(pNew->key, pNew->num);
		printf("����������\n");
		scanf("%s", pNew->name );
		getchar();
		
		pNew->next = NULL;  
        pEnd->next = pNew;  
        pEnd = pNew;
		 
		printf("�Ƿ���������ʦ���ݣ�����Y����¼�룬����ֹͣ¼��\n");  
		scanf("%c", &flag);
		getchar();	
    } 
	if(flag != 'Y'){
		savetea(pHead);
		pTemp = pHead;
		while( pTemp != NULL ){
			printf("����ĵ�%d����ʦ��:\n", iIndex);
			printf("����:%s\n", pTemp->num );
			printf("����:%s\n", pTemp->name );
			printf("\n");
			pTemp = pTemp->next;
			iIndex++; 
		} 
	} 
    free(pNew);  
}


/********��������********/ 
struct Student *create()
{
	struct Student *pHead = NULL;
	struct Student *pEnd, *pNew, *pTemp;
	char flag;
	int iIndex = 1;
	pEnd = pNew = (struct Student *)malloc(sizeof(struct Student));
	printf("������ѧ�Ż򹤺�\n");
	scanf("%s", pNew->num );
	strcpy(pNew->key, pNew->num);
	printf("����������\n");
	scanf("%s", pNew->name );
	printf("�������Ա�(��/Ů)\n");
	scanf("%s", &pNew->sex );
	printf("����������(����:1999 9 29)\n");
	scanf("%s %s %s", pNew->Birthday.year, pNew->Birthday.month, pNew->Birthday.day );
	printf("�����뼮��\n");
	scanf("%s", pNew->province );
	printf("������רҵ\n");
	scanf("%s", pNew->profession );
	printf("������༶\n");
	scanf("%s", &pNew->classnum );
	printf("������绰\n");
	scanf("%s", pNew->phonenum );
	getchar();
	pNew->next = pHead;  
    pHead = pNew;  
    pEnd = pNew;
    
	printf("�Ƿ��������ڵ����ݣ�����Y����¼�룬����ֹͣ¼��\n");  
	scanf("%c", &flag);
	getchar();
	while(flag == 'Y'){  
		pNew=(struct Student *)malloc(sizeof(struct Student));  
       	printf("������8λѧ�Ż򹤺�\n");
		scanf("%s", pNew->num );
		strcpy(pNew->key, pNew->num);
		printf("����������\n");
		scanf("%s", pNew->name );
		printf("�������Ա�(��/Ů)\n");
		scanf("%s", &pNew->sex );
		printf("����������(����:1999 09 29)\n");
		scanf("%s %s %s", pNew->Birthday.year, pNew->Birthday.month, pNew->Birthday.day );
		printf("�����뼮��\n");
		scanf("%s", pNew->province );
		printf("������רҵ\n");
		scanf("%s", pNew->profession );
		printf("������༶\n");
		scanf("%s", pNew->classnum );
		printf("������11λ�绰\n");
		scanf("%s", pNew->phonenum );
		getchar();
		
		pNew->next = NULL;  
        pEnd->next = pNew;  
        pEnd = pNew;
		 
		printf("�Ƿ��������ڵ����ݣ�����Y����¼�룬����ֹͣ¼��\n");  
		scanf("%c", &flag);
		getchar();	
    } 
	if(flag != 'Y'){
		save(pHead);
		pTemp = pHead;
		while( pTemp != NULL ){
			printf("��%d��ѧ����:\n", iIndex);
			printf("ѧ��:%s\n", pTemp->num );
			printf("����:%s\n", pTemp->name );
			printf("�Ա�:%s\n", pTemp->sex );
			printf("����:%s-%s-%s\n", pTemp->Birthday.year, pTemp->Birthday.month ,pTemp->Birthday.day );
			printf("����:%s\n", pTemp->province );
			printf("רҵ:%s\n", pTemp->profession );
			printf("�༶:%s\n", pTemp->classnum );
			printf("�绰:%s\n", pTemp->phonenum );
			printf("\n");
			pTemp = pTemp->next;
			iIndex++; 
		} 
	} 
    free(pNew);  
    return pHead;  
}


/********ѧ����ɾ��********/
void Delete(struct Student *pHead)//*pHeadΪͷ�ڵ�
{
	char xh[15];
	struct Student *pTemp;//��ʱָ�� 
	struct Student *pPre;//��ʾҪɾ���ڵ�ǰ�Ľڵ�
	pTemp = pHead->next;
	pPre = pTemp;
	printf("������Ҫɾ��ѧ����ѧ��\n");
	scanf("%s", xh);
	if( !strcmp(xh, pTemp->num) ) pHead = pTemp->next;
	else{ while( strcmp(xh, pTemp->num) ){ //ͨ��forѭ��ʹpTempָ��Ҫɾ���Ľڵ� 
		pPre = pTemp;
		pTemp = pTemp->next; 
	}
	pPre->next = pTemp->next;
	}
	resave(pHead);
} 


/********ѧ����Ϣ���޸�********/
void change(struct Student *pHead)
{
	struct Student *pTemp;
	char xh[15];
	pTemp = pHead->next ;
	printf("������Ҫ�޸�ѧ����ѧ��\n");
	scanf("%s", xh);
	while( strcmp(xh, pTemp->num) ) pTemp = pTemp->next;
	system("CLS");
	printf("�������޸�ѧ����Ϣ\n");
	printf("������ѧ�Ż򹤺�\n");
	scanf("%s", pTemp->num );
	strcpy(pTemp->key, pTemp->num);
	printf("����������\n");
	scanf("%s", pTemp->name );
	printf("�������Ա�(��/Ů)\n");
	scanf("%s", pTemp->sex );
	printf("����������(����:1999 09 29)\n");
	scanf("%s %s %s", pTemp->Birthday.year, pTemp->Birthday.month, pTemp->Birthday.day );
	printf("�����뼮��\n");
	scanf("%s", pTemp->province );
	printf("������רҵ\n");
	scanf("%s", pTemp->profession );
	printf("������༶\n");
	scanf("%s", pTemp->classnum );
	printf("������绰\n");
	scanf("%s", pTemp->phonenum );
	resave(pHead);
	getchar();
} 


/********����ı���********/
void print(struct Student *pHead)
{
	struct Student *pTemp;
	int iIndex = 1;//��ʾ����ڵ�����
	pTemp = pHead->next;
	while( pTemp != NULL ){
		printf("��%d��ѧ����:\n", iIndex);
		printf("ѧ��:%s\n", pTemp->num );
		printf("����:%s\n", pTemp->name );
		printf("�Ա�:%s\n", pTemp->sex );
		printf("����:%s-%s-%s\n", pTemp->Birthday.year, pTemp->Birthday.month ,pTemp->Birthday.day );
		printf("����:%s\n", pTemp->province );
		printf("רҵ:%s\n", pTemp->profession );
		printf("�༶:%s\n", pTemp->classnum );
		printf("�绰:%s\n", pTemp->phonenum );
		pTemp->yu = pTemp->shu =pTemp->ying =pTemp->sum = 0;
		printf("\n");
		pTemp = pTemp->next;
		iIndex++; 
	} 

}


/********ѧ����Ϣ�Ĳ���********/
void find(struct Student *pHead)
{
	struct Student *pTemp;
	char xh[15];
	char xm[15];
	char jg[15];
	char zy[10];
	char a[100];
	while(1){
		pTemp = pHead;
		printf("\t\t��---���ã���ӭ����ѧ������ϵͳ�������ܣ�---��\n");
		printf("\t====================================================\n");
		printf("\t--------�� 1.���������� ��--------\n\n");
		printf("\t--------�� 2.��ѧ������ ��--------\n\n");
		printf("\t--------�� 3.���������� ��--------\n\n");
		printf("\t--------�� 4.��רҵ���� ��--------\n\n");
		printf("\t--------�� 0.�˳� ��--------\n\n");
		printf("\t====================================================\n");
		printf("����0~4��ѡ��������ʽ���Իس�������\n");
		gets(a);
		if ( !strcmp(a,"0") ) exit(1);
		if ( !strcmp(a,"1") ){
			printf("������Ҫ����ѧ��������\n");
			scanf("%s", xm);
			getchar();
			while( pTemp != NULL ){
				if( !strcmp(xm, pTemp->name) ){
				printf("ѧ��:%s\n", pTemp->num );
				printf("����:%s\n", pTemp->name );
				printf("�Ա�:%s\n", pTemp->sex );
				printf("����:%s-%s-%s\n", pTemp->Birthday.year, pTemp->Birthday.month ,pTemp->Birthday.day );
				printf("����:%s\n", pTemp->province );
				printf("רҵ:%s\n", pTemp->profession );
				printf("�༶:%s\n", pTemp->classnum );
				printf("�绰:%s\n", pTemp->phonenum );
				printf("\n");
				}
				pTemp = pTemp->next; 
			}
			system( "pause" );
			system("CLS");
		}
		 
		else if ( !strcmp(a,"2") ){
			printf("������Ҫ����ѧ����ѧ��\n");
			scanf("%s", xh);
			getchar();
			while( pTemp != NULL ){
				if( !strcmp(xh, pTemp->num) ){
				printf("ѧ��:%s\n", pTemp->num );
				printf("����:%s\n", pTemp->name );
				printf("�Ա�:%s\n", pTemp->sex );
				printf("����:%s-%s-%s\n", pTemp->Birthday.year, pTemp->Birthday.month ,pTemp->Birthday.day );
				printf("����:%s\n", pTemp->province );
				printf("רҵ:%s\n", pTemp->profession );
				printf("�༶:%s\n", pTemp->classnum );
				printf("�绰:%s\n", pTemp->phonenum );
				printf("\n");
				}
				pTemp = pTemp->next; 
			}
			system( "pause" );
			system("CLS");
		}
		else if ( !strcmp(a,"3") ){
			printf("������Ҫ����ѧ���ļ���\n");
			scanf("%s", jg);
			getchar();
			while( pTemp != NULL ){
				if( !strcmp(jg, pTemp->province) ){
				printf("ѧ��:%s\n", pTemp->num );
				printf("����:%s\n", pTemp->name );
				printf("�Ա�:%s\n", pTemp->sex );
				printf("����:%s-%s-%s\n", pTemp->Birthday.year, pTemp->Birthday.month ,pTemp->Birthday.day );
				printf("����:%s\n", pTemp->province );
				printf("רҵ:%s\n", pTemp->profession );
				printf("�༶:%s\n", pTemp->classnum );
				printf("�绰:%s\n", pTemp->phonenum );
				printf("\n");
				}
				pTemp = pTemp->next; 
			}
			system( "pause" );
			system("CLS");
		}
		else if ( !strcmp(a,"4") ){
			printf("������Ҫ����ѧ����רҵ\n");
			scanf("%s", zy);
			getchar();
			while( pTemp != NULL ){
				if( !strcmp(zy, pTemp->profession ) ){
				printf("ѧ��:%s\n", pTemp->num );
				printf("����:%s\n", pTemp->name );
				printf("�Ա�:%s\n", pTemp->sex );
				printf("����:%s-%s-%s\n", pTemp->Birthday.year, pTemp->Birthday.month ,pTemp->Birthday.day );
				printf("����:%s\n", pTemp->province );
				printf("רҵ:%s\n", pTemp->profession );
				printf("�༶:%s\n", pTemp->classnum );
				printf("�绰:%s\n", pTemp->phonenum );
				printf("\n");
				}
				pTemp = pTemp->next;
			}
			system( "pause" );
			system("CLS");
		}
		else{
			printf("��������ȷ����Ϣ��\n\n");
			system( "pause" );
			system("CLS");
		}
	}
}


/********�ɼ�����ϵͳ�˵�ҳ��********/
void grademenu()
{
	char a[200];
	struct Student *pHead;
	struct Student *h;
	pHead = read();
	while(1){
		printf("\n");
		printf("\t\t��---���ã���ӭ����ɼ�����ϵͳ��---��\n");
		printf("\t====================================================\n");
		printf("\t--------�� 1.����ѧ���ɼ�  2.����ɼ���Ϣ ��--------\n\n");
		printf("\t--------�� 3.�޸�ѧ���ɼ�  4.ѧ���ɼ�������� ��--------\n\n");
		printf("\t--------�� 0.�˳� ��--------\n\n");
		printf("\t====================================================\n");
		printf("����0~3��ѡ���Իس�����������\n");
		gets(a);
		if ( !strcmp(a,"0") ) break;
		else if ( !strcmp(a,"1") ){
			system("CLS");
			input(pHead);
			system( "pause" );
			system("CLS");
		}
		else if ( !strcmp(a,"2") ){
			system("CLS");
			printgrade(pHead);
			system( "pause" );
			system("CLS");
		}
		else if ( !strcmp(a,"3") ){
			system("CLS");
			gaichengji(pHead);
			system( "pause" );
			system("CLS");
		}
		else if ( !strcmp(a,"4") ){
			system("CLS");
			h = paixu(pHead);
			printgrade(h);
			system( "pause" );
			system("CLS");
		}
		else{
			printf("��������ȷ����Ϣ��\n\n");
			system( "pause" );
			system("CLS");
		}
	}
}
 
/********����ѧ���ɼ� ********/
void input(struct Student *pHead)
{
	struct Student *pTemp;
	char a[50];
	pTemp = pHead->next ;
	printf("%s","������Ҫ����Ŀ�Ŀ��(1.���� 2.��ѧ 3.Ӣ��)");
	gets(a);
	if ( !strcmp(a,"1") ){
			system("CLS");
			while(pTemp!=NULL){
				printf("������%sͬѧ�����ĳɼ���",pTemp->name);
			   	scanf("%d",&pTemp->yu);
			  	pTemp->sum += pTemp->yu;
				pTemp = pTemp->next; 
			}
			system( "pause" );
			system("CLS");
	}
	else if ( !strcmp(a,"2") ){
			system("CLS");
			while(pTemp!=NULL){
				printf("������%sͬѧ����ѧ�ɼ���",pTemp->name);
			   	scanf("%d",&pTemp->shu);
			  	pTemp->sum += pTemp->shu;
				pTemp = pTemp->next; 
			}
			system( "pause" );
			system("CLS");
	}
	else if ( !strcmp(a,"3") ){
			system("CLS");
			while(pTemp!=NULL){
				printf("������%sͬѧ��Ӣ��ɼ���",pTemp->name);
			   	scanf("%d",&pTemp->ying);
			  	pTemp->sum += pTemp->ying;
				pTemp = pTemp->next; 
			}
			system( "pause" );
			system("CLS");
	}
	else{
			printf("��������ȷ����Ϣ��\n\n");
			system( "pause" );
			system("CLS");
	}
	resave(pHead);
}


/********��ӡ�ɼ�********/
void printgrade(struct Student *pHead)
{
	struct Student *pTemp;
	pTemp = pHead->next ;
	while( pTemp != NULL ){
		printf("ѧ��:%s\n", pTemp->num );
		printf("����:%s\n", pTemp->name );
		printf("����:%d\n", pTemp->yu );
		printf("��ѧ:%d\n", pTemp->shu );
		printf("Ӣ��:%d\n", pTemp->ying );
		printf("�ܷ�:%d\n", pTemp->sum );
		printf("\n");
		pTemp = pTemp->next;
	} 
}


/********�޸ĳɼ�********/
void gaichengji(struct Student *pHead)  
{
	struct Student *pTemp;
	int j;
	char ch, xh[10];
	pTemp = pHead->next ;
	printf("\t\t������Ҫ�޸ĵ�ͬѧ��ѧ�ţ�");
	scanf("%s",xh);
	while(pTemp != NULL){
		if( !strcmp(xh, pTemp->num ) ) break;
	}
	printf("\t\t������Ҫ�޸ĵĿ�Ŀ��(1.���� 2.��ѧ 3.Ӣ��)");
	scanf("%d",&j);
	printf("�������޸ĺ�ĳɼ���");
	switch(j)
	{
	case 1:scanf("%d",&pTemp->yu);break;
	case 2:scanf("%d",&pTemp->shu);break;
	case 3:scanf("%d",&pTemp->ying);break;
	}
	pTemp->sum = pTemp->yu + pTemp->shu +pTemp->ying;
	printf("\t\t\t\t�޸ĳɹ�");
	resave(pHead);
} 


/********�ɼ�����********/
struct Student *paixu(struct Student *h)
{
	struct Student *p, *p1;
	int n=0, j ,t,i;
	char a[50];
	p = h;
	while(p){
		n++;
		p=p->next;
	}
	printf("\t--------�� \t��ѡ�����򷽷�\t ��--------\n\n");
	printf("\t--------�� 1.�������  2.������� ��--------\n\n");
	gets(a);
	if ( !strcmp(a,"1") ){
			system("CLS");
			for(i = 0; i < n-2; i++){
			p=h;
			p1=p->next;
			for(j=0; j<n-i-2; j++){
			if(p1->sum > (p1->next->sum )){
				p->next = p1->next;
				p1->next = p1->next->next;
				p->next->next = p1;     
			}
			p = p->next;
			p1 = p->next; 
			} 
		}
		return h;
			system( "pause" );
			system("CLS");
	}
	else if ( !strcmp(a,"2") ){
			system("CLS");
			for(i = 0; i < n-2; i++){
			p=h;
			p1=p->next;
			for(j=0; j<n-i-2; j++){
			if(p1->sum < (p1->next->sum)){
				p->next = p1->next;
				p1->next = p1->next->next;
				p->next->next = p1;     
			}
			p = p->next;
			p1 = p->next; 
			} 
		}
		return h;
			system( "pause" );
			system("CLS");
	}
	else{
			printf("��������ȷ����Ϣ��\n\n");
			system( "pause" );
			system("CLS");
	}
}


/********�ж�ѧ����Ϣ�Ƿ����********/
int isExisted(struct Student *pHead, char *stunum)
{
	int f = 0;
	struct Student *pTemp;
	pTemp = pHead->next ;
	while( pTemp != NULL ){
		if( !strcmp(stunum, pTemp->num ) ){
			f = 1;
			return f;	
		}
		pTemp = pTemp->next;
	} 
	return f;
}


/********ѧ��������********/
void gaimimastu(struct Student *pTemp)
{
	char mm[50];
	printf("������Ҫ�޸ĵ�����\n");
	scanf("%s",mm);
	strcpy(pTemp->key, mm ); 
}


/********������********/
int main()
{ 
	system("color F0");
	judge();
	return 0; 
}



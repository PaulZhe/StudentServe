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
	char num[MAX_STU_NUM];/*工号*/
	char name[MAX_STU_NAME];/*姓名*/
	char key[MAX_KEY];/*密码*/
	struct Teacher *next;
};

struct Student{
	char num[MAX_STU_NUM];/*学号或工号*/
	char name[MAX_STU_NAME];/*姓名*/
	char sex[10];/*性别*/ 
	struct Date Birthday;/*生日*/
	char province[MAX_PRO];/*籍贯*/
	char profession[MAX_PROFESSION];/*专业*/
	char classnum[10];/*班级*/ 
	char phonenum[MAX_PHONE_NUM];/*电话*/
	char key[MAX_KEY];/*密码*/
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


/********判断界面********/
void judge()
{
	struct Student *pHead;
	struct Teacher *phead;
	pHead = read();
	phead = readtea();
	system("color F0");
	char a[200] = {0};
	do{
		printf("\t\t☆---您好，欢迎进入学生管理系统！---☆\n");
		printf("\t====================================================\n");
		printf("\t--------☆ 1.进入学生端学生管理系统 ☆--------\n\n");
		printf("\t--------☆ 2.进入教师端学生管理系统 ☆--------\n\n");
		printf("\t--------☆ 3.注册学生信息 ☆--------\n\n");
		printf("\t--------☆ 4.注册老师信息 ☆--------\n\n");
		printf("\t--------☆ 0.退出 ☆--------\n\n");
		printf("\t====================================================\n");
		printf("请在0~2中选择，以回车键结束\n");
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
			printf("请输入正确的信息。\n\n");
			system( "pause" );
			system("CLS");
		}
	}while( strcmp(a,"0") );
}


/********教师端登录注册页面********/
void teacherlogin(struct Teacher *pHead)
{
	struct Teacher *pTemp;
	int p,flag=0;  
    char ch,acnt[20],pwd[20];    
     
    
    while(1){
    	pTemp = pHead->next ;
		p=0; 
   	 	printf("\t\t☆---您好，欢迎进入教师端学生管理系统！---☆\n");
		printf("\t====================================================\n");
		printf("\t\t\t 请输入账号："); 
    	scanf("%s",acnt);
		printf("\t\t\t 请输入密码：");
    	while((ch=getch())!='\r')//判断是否是回车  
    	{  
        	if(ch==8)//实现backspace键的功能，其中backspace键的ascii码是8  
        	    {  
            	putchar('\b');  
                putchar(' ');  
               	putchar('\b');
                if(p>0)//最多只能删到没有字符  
                p--;  
            }  
        	if(!isdigit(ch)&&!isalpha(ch))//判断是否是数字或字符  
        	    continue;  
       		putchar('*');//在屏幕上打印星号  
        	pwd[p++]=ch;//保存密码  
    	}  
    	pwd[p]=0;//结束字符串 
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
		printf("输入账号或密码错误\n");
		system( "pause" );
		system("CLS");
		}
		if(flag == 1) break;
	}
}


/********教师端主界面********/
void teachermenu()
{
	char a[200];
	while(1){
		printf("\n");
		printf("\t\t☆---您好，欢迎进入教师端学生管理系统！---☆\n");
		printf("\t====================================================\n");
		printf("\t--------☆ 1.添加学生信息  2.浏览学生信息 ☆--------\n\n");
		printf("\t--------☆ 3.修改学生信息  4.删除学生信息 ☆--------\n\n");
		printf("\t--------☆ 5.查找学生信息  6.进入成绩系统 ☆--------\n\n");
		printf("\t--------☆ 7.修改密码 ☆--------\n\n");
		printf("\t--------☆ 0.退出 ☆--------\n\n");
		printf("\t====================================================\n");
		printf("请在0~6中选择，以回车键结束输入\n");
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
			printf("请输入正确的信息。\n\n");
			system( "pause" );
			system("CLS");
		}
	}
}


/********学生端主界面********/
void studentmenu(struct Student *pHead)
{
	struct Student *pTemp;
	int p,flag=0;  
    char ch,acnt[15],pwd[15],a,b;    
      
    while(1){
    	p=0;
		pTemp = pHead->next ;
   	 	printf("\t\t☆---您好，欢迎进入学生端学生管理系统！---☆\n");
		printf("\t====================================================\n");
		printf("\t\t\t 请输入账号："); 
    	scanf("%s",acnt);
		printf("\t\t\t 请输入密码：");
    	while((ch=getch())!='\r')//判断是否是回车  
    	{  
        	if(ch==8)//实现backspace键的功能，其中backspace键的ascii码是8  
        	    {  
            	putchar('\b');  
                putchar(' ');  
               	putchar('\b');
                if(p>0)//最多只能删到没有字符  
                p--;  
            }  
        	if(!isdigit(ch)&&!isalpha(ch))//判断是否是数字或字符  
        	    continue;  
       		putchar('*');//在屏幕上打印星号  
        	pwd[p++]=ch;//保存密码  
    	}  
    	pwd[p]=0;//结束字符串   
    	while(pTemp != NULL){
		if((!strcmp(acnt, pTemp->num)) &&(!strcmp(pwd, pTemp->key )) ){
			printf("\n");
			printf("学号:%s\n", pTemp->num );
			printf("姓名:%s\n", pTemp->name );
			printf("性别:%s\n", pTemp->sex );
			printf("生日:%s-%s-%s\n", pTemp->Birthday.year, pTemp->Birthday.month ,pTemp->Birthday.day );
			printf("籍贯:%s\n", pTemp->province );
			printf("专业:%s\n", pTemp->profession );
			printf("班级:%s\n", pTemp->classnum );
			printf("电话:%s\n", pTemp->phonenum );
			printf("\n");
			flag = 1;
			printf("是否修改密码：(确定请输入Y)\n");
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
		printf("输入账号或密码错误\n");
		system( "pause" );
		system("CLS");
		}
		
	}
}



/********保存信息到文件********/ 
void save(struct Student *pHead)
{
	FILE *fp;
	struct Student *pTemp;
	if( (fp = fopen("stu.txt", "at")) == NULL ){//打开文件并判断是否出错
		printf("创建文件失败！\n\n");
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


/********保存老师信息到文件********/ 
void savetea(struct Teacher *pHead)
{
	FILE *fp;
	struct Teacher *pTemp;
	if( (fp = fopen("tea.txt", "at")) == NULL ){//打开文件并判断是否出错
		printf("创建文件失败！\n\n");
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

/********保存信息到文件(重写)********/ 
void resave(struct Student *pHead)
{
	FILE *fp;
	struct Student *pTemp;
	if( (fp = fopen("stu.txt", "wt")) == NULL ){//打开文件并判断是否出错
		printf("创建文件失败！\n\n");
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


/********读取学生信息********/
struct Student *read()
{
	FILE *fp;;
	struct Student *pHead, *pEnd, *pNew;
	pHead = (struct Student *)malloc(sizeof(struct Student));
	pHead->next = NULL;
	pEnd = pHead;
	if( (fp = fopen("stu.txt", "rt")) == NULL ){//打开文件并判断是否出错
		printf("创建文件失败！\n\n");
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

/********读取老师信息********/
struct Teacher *readtea()
{
	FILE *fp;;
	struct Teacher *pHead, *pEnd, *pNew;
	pHead = (struct Teacher *)malloc(sizeof(struct Teacher));
	pHead->next = NULL;
	pEnd = pHead;
	if( (fp = fopen("tea.txt", "rt")) == NULL ){//打开文件并判断是否出错
		printf("创建文件失败！\n\n");
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


/********添加学生信息********/ 
void add()
{
	struct Student *pHead = NULL;
	struct Student *pEnd, *pNew, *pTemp, *phead;
	char flag;
	phead = read();
	int iIndex = 1;
	pEnd = pNew = (struct Student *)malloc(sizeof(struct Student));
	printf("请输入学号\n");
	scanf("%s", pNew->num );
	if(isExisted(phead, pNew->num)){
		printf("该学生已存在\n");
		exit(1);
	}
	strcpy(pNew->key, pNew->num);
	printf("请输入姓名\n");
	scanf("%s", pNew->name );
	printf("请输入性别(男/女)\n");
	scanf("%s", pNew->sex );
	printf("请输入生日(例如:1999 09 29)\n");
	scanf("%s %s %s", pNew->Birthday.year, pNew->Birthday.month, pNew->Birthday.day );
	printf("请输入籍贯\n");
	scanf("%s", pNew->province );
	printf("请输入专业\n");
	scanf("%s", pNew->profession );
	printf("请输入班级\n");
	scanf("%s", pNew->classnum );
	printf("请输入电话\n");
	scanf("%s", pNew->phonenum );
	pNew->yu = pNew->shu =pNew->ying =pNew->sum = 0;
	getchar();
	pNew->next = pHead;  
    pHead = pNew;  
    pEnd = pNew;
    
	printf("是否继续输入学生数据，输入Y继续录入，否则停止录入\n");  
	scanf("%c", &flag);
	getchar();
	while(flag == 'Y'){  
		pNew=(struct Student *)malloc(sizeof(struct Student));  
       	printf("请输入8位学号\n");
		scanf("%s", pNew->num );
		strcpy(pNew->key, pNew->num);
		printf("请输入姓名\n");
		scanf("%s", pNew->name );
		printf("请输入性别(男/女)\n");
		scanf("%s", pNew->sex );
		printf("请输入生日(例如:1999 09 29)\n");
		scanf("%s %s %s", pNew->Birthday.year, pNew->Birthday.month, pNew->Birthday.day );
		printf("请输入籍贯\n");
		scanf("%s", pNew->province );
		printf("请输入专业\n");
		scanf("%s", pNew->profession );
		printf("请输入班级\n");
		scanf("%s", pNew->classnum );
		printf("请输入11位电话\n");
		scanf("%s", pNew->phonenum );
		pNew->yu = pNew->shu =pNew->ying =pNew->sum = 0;
		getchar();
		
		pNew->next = NULL;  
        pEnd->next = pNew;  
        pEnd = pNew;
		 
		printf("是否继续输入学生数据，输入Y继续录入，否则停止录入\n");  
		scanf("%c", &flag);
		getchar();	
    } 
	if(flag != 'Y'){
		save(pHead);
		pTemp = pHead;
		while( pTemp != NULL ){
			printf("新添的第%d个学生是:\n", iIndex);
			printf("学号:%s\n", pTemp->num );
			printf("姓名:%s\n", pTemp->name );
			printf("性别:%s\n", pTemp->sex );
			printf("生日:%s-%s-%s\n", pTemp->Birthday.year, pTemp->Birthday.month ,pTemp->Birthday.day );
			printf("籍贯:%s\n", pTemp->province );
			printf("专业:%s\n", pTemp->profession );
			printf("班级:%s\n", pTemp->classnum );
			printf("电话:%s\n", pTemp->phonenum );
			printf("\n");
			pTemp = pTemp->next;
			iIndex++; 
		} 
	} 
    free(pNew);   
}


/********注册学生信息********/ 
void zhuce()
{
	struct Student *pHead = NULL;
	struct Student *pEnd, *pNew, *pTemp, *phead;
	char flag;
	int iIndex = 1;
	phead = read();
	pEnd = pNew = (struct Student *)malloc(sizeof(struct Student));
	printf("请输入学号\n");
	scanf("%s", pNew->num );
	if(isExisted(phead, pNew->num)){
		printf("该学生已存在\n");
		exit(1);
	}
	strcpy(pNew->key, pNew->num);
	printf("请输入姓名\n");
	scanf("%s", pNew->name );
	printf("请输入性别(男/女)\n");
	scanf("%s", pNew->sex );
	printf("请输入生日(例如:1999 09 29)\n");
	scanf("%s %s %s", pNew->Birthday.year, pNew->Birthday.month, pNew->Birthday.day );
	printf("请输入籍贯\n");
	scanf("%s", pNew->province );
	printf("请输入专业\n");
	scanf("%s", pNew->profession );
	printf("请输入班级\n");
	scanf("%s", pNew->classnum );
	printf("请输入电话\n");
	scanf("%s", pNew->phonenum );
	pNew->yu = pNew->shu =pNew->ying =pNew->sum = 0;
	getchar();
	pNew->next = pHead;  
    pHead = pNew;  
    pEnd = pNew;
    save(pHead);
    printf("注册成功！\n");
}


/********添加教师信息********/ 
void addtea()
{
	struct Teacher *pHead = NULL;
	struct Teacher *pEnd, *pNew, *pTemp;
	char flag;
	int iIndex = 1;
	pEnd = pNew = (struct Teacher *)malloc(sizeof(struct Teacher));
	printf("请输入工号\n");
	scanf("%s", pNew->num );
	strcpy(pNew->key, pNew->num);
	printf("请输入姓名\n");
	scanf("%s", pNew->name );
	getchar();
	pNew->next = pHead;  
    pHead = pNew;  
    pEnd = pNew;
    
	printf("是否继续输入教师数据，输入Y继续录入，否则停止录入\n");  
	scanf("%c", &flag);
	getchar();
	while(flag == 'Y'){  
		pNew=(struct Teacher *)malloc(sizeof(struct Teacher)); 
       	printf("请输入8位工号\n");
		scanf("%s", pNew->num );
		strcpy(pNew->key, pNew->num);
		printf("请输入姓名\n");
		scanf("%s", pNew->name );
		getchar();
		
		pNew->next = NULL;  
        pEnd->next = pNew;  
        pEnd = pNew;
		 
		printf("是否继续输入教师数据，输入Y继续录入，否则停止录入\n");  
		scanf("%c", &flag);
		getchar();	
    } 
	if(flag != 'Y'){
		savetea(pHead);
		pTemp = pHead;
		while( pTemp != NULL ){
			printf("新添的第%d个教师是:\n", iIndex);
			printf("工号:%s\n", pTemp->num );
			printf("姓名:%s\n", pTemp->name );
			printf("\n");
			pTemp = pTemp->next;
			iIndex++; 
		} 
	} 
    free(pNew);  
}


/********创建链表********/ 
struct Student *create()
{
	struct Student *pHead = NULL;
	struct Student *pEnd, *pNew, *pTemp;
	char flag;
	int iIndex = 1;
	pEnd = pNew = (struct Student *)malloc(sizeof(struct Student));
	printf("请输入学号或工号\n");
	scanf("%s", pNew->num );
	strcpy(pNew->key, pNew->num);
	printf("请输入姓名\n");
	scanf("%s", pNew->name );
	printf("请输入性别(男/女)\n");
	scanf("%s", &pNew->sex );
	printf("请输入生日(例如:1999 9 29)\n");
	scanf("%s %s %s", pNew->Birthday.year, pNew->Birthday.month, pNew->Birthday.day );
	printf("请输入籍贯\n");
	scanf("%s", pNew->province );
	printf("请输入专业\n");
	scanf("%s", pNew->profession );
	printf("请输入班级\n");
	scanf("%s", &pNew->classnum );
	printf("请输入电话\n");
	scanf("%s", pNew->phonenum );
	getchar();
	pNew->next = pHead;  
    pHead = pNew;  
    pEnd = pNew;
    
	printf("是否继续输入节点数据，输入Y继续录入，否则停止录入\n");  
	scanf("%c", &flag);
	getchar();
	while(flag == 'Y'){  
		pNew=(struct Student *)malloc(sizeof(struct Student));  
       	printf("请输入8位学号或工号\n");
		scanf("%s", pNew->num );
		strcpy(pNew->key, pNew->num);
		printf("请输入姓名\n");
		scanf("%s", pNew->name );
		printf("请输入性别(男/女)\n");
		scanf("%s", &pNew->sex );
		printf("请输入生日(例如:1999 09 29)\n");
		scanf("%s %s %s", pNew->Birthday.year, pNew->Birthday.month, pNew->Birthday.day );
		printf("请输入籍贯\n");
		scanf("%s", pNew->province );
		printf("请输入专业\n");
		scanf("%s", pNew->profession );
		printf("请输入班级\n");
		scanf("%s", pNew->classnum );
		printf("请输入11位电话\n");
		scanf("%s", pNew->phonenum );
		getchar();
		
		pNew->next = NULL;  
        pEnd->next = pNew;  
        pEnd = pNew;
		 
		printf("是否继续输入节点数据，输入Y继续录入，否则停止录入\n");  
		scanf("%c", &flag);
		getchar();	
    } 
	if(flag != 'Y'){
		save(pHead);
		pTemp = pHead;
		while( pTemp != NULL ){
			printf("第%d个学生是:\n", iIndex);
			printf("学号:%s\n", pTemp->num );
			printf("姓名:%s\n", pTemp->name );
			printf("性别:%s\n", pTemp->sex );
			printf("生日:%s-%s-%s\n", pTemp->Birthday.year, pTemp->Birthday.month ,pTemp->Birthday.day );
			printf("籍贯:%s\n", pTemp->province );
			printf("专业:%s\n", pTemp->profession );
			printf("班级:%s\n", pTemp->classnum );
			printf("电话:%s\n", pTemp->phonenum );
			printf("\n");
			pTemp = pTemp->next;
			iIndex++; 
		} 
	} 
    free(pNew);  
    return pHead;  
}


/********学生的删除********/
void Delete(struct Student *pHead)//*pHead为头节点
{
	char xh[15];
	struct Student *pTemp;//临时指针 
	struct Student *pPre;//表示要删除节点前的节点
	pTemp = pHead->next;
	pPre = pTemp;
	printf("请输入要删除学生的学号\n");
	scanf("%s", xh);
	if( !strcmp(xh, pTemp->num) ) pHead = pTemp->next;
	else{ while( strcmp(xh, pTemp->num) ){ //通过for循环使pTemp指向要删除的节点 
		pPre = pTemp;
		pTemp = pTemp->next; 
	}
	pPre->next = pTemp->next;
	}
	resave(pHead);
} 


/********学生信息的修改********/
void change(struct Student *pHead)
{
	struct Student *pTemp;
	char xh[15];
	pTemp = pHead->next ;
	printf("请输入要修改学生的学号\n");
	scanf("%s", xh);
	while( strcmp(xh, pTemp->num) ) pTemp = pTemp->next;
	system("CLS");
	printf("请输入修改学生信息\n");
	printf("请输入学号或工号\n");
	scanf("%s", pTemp->num );
	strcpy(pTemp->key, pTemp->num);
	printf("请输入姓名\n");
	scanf("%s", pTemp->name );
	printf("请输入性别(男/女)\n");
	scanf("%s", pTemp->sex );
	printf("请输入生日(例如:1999 09 29)\n");
	scanf("%s %s %s", pTemp->Birthday.year, pTemp->Birthday.month, pTemp->Birthday.day );
	printf("请输入籍贯\n");
	scanf("%s", pTemp->province );
	printf("请输入专业\n");
	scanf("%s", pTemp->profession );
	printf("请输入班级\n");
	scanf("%s", pTemp->classnum );
	printf("请输入电话\n");
	scanf("%s", pTemp->phonenum );
	resave(pHead);
	getchar();
} 


/********链表的遍历********/
void print(struct Student *pHead)
{
	struct Student *pTemp;
	int iIndex = 1;//表示链表节点的序号
	pTemp = pHead->next;
	while( pTemp != NULL ){
		printf("第%d个学生是:\n", iIndex);
		printf("学号:%s\n", pTemp->num );
		printf("姓名:%s\n", pTemp->name );
		printf("性别:%s\n", pTemp->sex );
		printf("生日:%s-%s-%s\n", pTemp->Birthday.year, pTemp->Birthday.month ,pTemp->Birthday.day );
		printf("籍贯:%s\n", pTemp->province );
		printf("专业:%s\n", pTemp->profession );
		printf("班级:%s\n", pTemp->classnum );
		printf("电话:%s\n", pTemp->phonenum );
		pTemp->yu = pTemp->shu =pTemp->ying =pTemp->sum = 0;
		printf("\n");
		pTemp = pTemp->next;
		iIndex++; 
	} 

}


/********学生信息的查找********/
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
		printf("\t\t☆---您好，欢迎进入学生管理系统搜索功能！---☆\n");
		printf("\t====================================================\n");
		printf("\t--------☆ 1.按姓名搜索 ☆--------\n\n");
		printf("\t--------☆ 2.按学号搜索 ☆--------\n\n");
		printf("\t--------☆ 3.按籍贯搜索 ☆--------\n\n");
		printf("\t--------☆ 4.按专业搜索 ☆--------\n\n");
		printf("\t--------☆ 0.退出 ☆--------\n\n");
		printf("\t====================================================\n");
		printf("请在0~4中选择搜索方式，以回车键结束\n");
		gets(a);
		if ( !strcmp(a,"0") ) exit(1);
		if ( !strcmp(a,"1") ){
			printf("请输入要查找学生的姓名\n");
			scanf("%s", xm);
			getchar();
			while( pTemp != NULL ){
				if( !strcmp(xm, pTemp->name) ){
				printf("学号:%s\n", pTemp->num );
				printf("姓名:%s\n", pTemp->name );
				printf("性别:%s\n", pTemp->sex );
				printf("生日:%s-%s-%s\n", pTemp->Birthday.year, pTemp->Birthday.month ,pTemp->Birthday.day );
				printf("籍贯:%s\n", pTemp->province );
				printf("专业:%s\n", pTemp->profession );
				printf("班级:%s\n", pTemp->classnum );
				printf("电话:%s\n", pTemp->phonenum );
				printf("\n");
				}
				pTemp = pTemp->next; 
			}
			system( "pause" );
			system("CLS");
		}
		 
		else if ( !strcmp(a,"2") ){
			printf("请输入要查找学生的学号\n");
			scanf("%s", xh);
			getchar();
			while( pTemp != NULL ){
				if( !strcmp(xh, pTemp->num) ){
				printf("学号:%s\n", pTemp->num );
				printf("姓名:%s\n", pTemp->name );
				printf("性别:%s\n", pTemp->sex );
				printf("生日:%s-%s-%s\n", pTemp->Birthday.year, pTemp->Birthday.month ,pTemp->Birthday.day );
				printf("籍贯:%s\n", pTemp->province );
				printf("专业:%s\n", pTemp->profession );
				printf("班级:%s\n", pTemp->classnum );
				printf("电话:%s\n", pTemp->phonenum );
				printf("\n");
				}
				pTemp = pTemp->next; 
			}
			system( "pause" );
			system("CLS");
		}
		else if ( !strcmp(a,"3") ){
			printf("请输入要查找学生的籍贯\n");
			scanf("%s", jg);
			getchar();
			while( pTemp != NULL ){
				if( !strcmp(jg, pTemp->province) ){
				printf("学号:%s\n", pTemp->num );
				printf("姓名:%s\n", pTemp->name );
				printf("性别:%s\n", pTemp->sex );
				printf("生日:%s-%s-%s\n", pTemp->Birthday.year, pTemp->Birthday.month ,pTemp->Birthday.day );
				printf("籍贯:%s\n", pTemp->province );
				printf("专业:%s\n", pTemp->profession );
				printf("班级:%s\n", pTemp->classnum );
				printf("电话:%s\n", pTemp->phonenum );
				printf("\n");
				}
				pTemp = pTemp->next; 
			}
			system( "pause" );
			system("CLS");
		}
		else if ( !strcmp(a,"4") ){
			printf("请输入要查找学生的专业\n");
			scanf("%s", zy);
			getchar();
			while( pTemp != NULL ){
				if( !strcmp(zy, pTemp->profession ) ){
				printf("学号:%s\n", pTemp->num );
				printf("姓名:%s\n", pTemp->name );
				printf("性别:%s\n", pTemp->sex );
				printf("生日:%s-%s-%s\n", pTemp->Birthday.year, pTemp->Birthday.month ,pTemp->Birthday.day );
				printf("籍贯:%s\n", pTemp->province );
				printf("专业:%s\n", pTemp->profession );
				printf("班级:%s\n", pTemp->classnum );
				printf("电话:%s\n", pTemp->phonenum );
				printf("\n");
				}
				pTemp = pTemp->next;
			}
			system( "pause" );
			system("CLS");
		}
		else{
			printf("请输入正确的信息。\n\n");
			system( "pause" );
			system("CLS");
		}
	}
}


/********成绩管理系统菜单页面********/
void grademenu()
{
	char a[200];
	struct Student *pHead;
	struct Student *h;
	pHead = read();
	while(1){
		printf("\n");
		printf("\t\t☆---您好，欢迎进入成绩管理系统！---☆\n");
		printf("\t====================================================\n");
		printf("\t--------☆ 1.输入学生成绩  2.浏览成绩信息 ☆--------\n\n");
		printf("\t--------☆ 3.修改学生成绩  4.学生成绩排序输出 ☆--------\n\n");
		printf("\t--------☆ 0.退出 ☆--------\n\n");
		printf("\t====================================================\n");
		printf("请在0~3中选择，以回车键结束输入\n");
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
			printf("请输入正确的信息。\n\n");
			system( "pause" );
			system("CLS");
		}
	}
}
 
/********输入学生成绩 ********/
void input(struct Student *pHead)
{
	struct Student *pTemp;
	char a[50];
	pTemp = pHead->next ;
	printf("%s","请输入要输入的科目：(1.语文 2.数学 3.英语)");
	gets(a);
	if ( !strcmp(a,"1") ){
			system("CLS");
			while(pTemp!=NULL){
				printf("请输入%s同学的语文成绩：",pTemp->name);
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
				printf("请输入%s同学的数学成绩：",pTemp->name);
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
				printf("请输入%s同学的英语成绩：",pTemp->name);
			   	scanf("%d",&pTemp->ying);
			  	pTemp->sum += pTemp->ying;
				pTemp = pTemp->next; 
			}
			system( "pause" );
			system("CLS");
	}
	else{
			printf("请输入正确的信息。\n\n");
			system( "pause" );
			system("CLS");
	}
	resave(pHead);
}


/********打印成绩********/
void printgrade(struct Student *pHead)
{
	struct Student *pTemp;
	pTemp = pHead->next ;
	while( pTemp != NULL ){
		printf("学号:%s\n", pTemp->num );
		printf("姓名:%s\n", pTemp->name );
		printf("语文:%d\n", pTemp->yu );
		printf("数学:%d\n", pTemp->shu );
		printf("英语:%d\n", pTemp->ying );
		printf("总分:%d\n", pTemp->sum );
		printf("\n");
		pTemp = pTemp->next;
	} 
}


/********修改成绩********/
void gaichengji(struct Student *pHead)  
{
	struct Student *pTemp;
	int j;
	char ch, xh[10];
	pTemp = pHead->next ;
	printf("\t\t请输入要修改的同学的学号：");
	scanf("%s",xh);
	while(pTemp != NULL){
		if( !strcmp(xh, pTemp->num ) ) break;
	}
	printf("\t\t请输入要修改的科目：(1.语文 2.数学 3.英语)");
	scanf("%d",&j);
	printf("请输入修改后的成绩：");
	switch(j)
	{
	case 1:scanf("%d",&pTemp->yu);break;
	case 2:scanf("%d",&pTemp->shu);break;
	case 3:scanf("%d",&pTemp->ying);break;
	}
	pTemp->sum = pTemp->yu + pTemp->shu +pTemp->ying;
	printf("\t\t\t\t修改成功");
	resave(pHead);
} 


/********成绩排序********/
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
	printf("\t--------☆ \t请选择排序方法\t ☆--------\n\n");
	printf("\t--------☆ 1.升序输出  2.降序输出 ☆--------\n\n");
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
			printf("请输入正确的信息。\n\n");
			system( "pause" );
			system("CLS");
	}
}


/********判断学生信息是否存在********/
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


/********学生改密码********/
void gaimimastu(struct Student *pTemp)
{
	char mm[50];
	printf("请输入要修改的密码\n");
	scanf("%s",mm);
	strcpy(pTemp->key, mm ); 
}


/********主函数********/
int main()
{ 
	system("color F0");
	judge();
	return 0; 
}



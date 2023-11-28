#include<stdio.h>
#include<string.h>
//���Ա���
double BigRoom=99;


void CheckIn();
void CheckRe();
void BookRoom();
int ChangeRoom();
void BuildRoom();
void DeleteRoom();
void ChangeFee();

// ����ṹ��
typedef struct {
	int roomNumber;
	int type;
	double price;
	int time;
	char name[20];
	int phone;
	int status=0;  // 0��ʾδ������1��ʾ�Ѷ���
} Room;
// ȫ�ֱ���
int bulidings=50;
Room rooms[50];
int Admin=0;


int main(){
	int step;
	BuildRoom();
	int *roomCount1;
	do{
		do{
		// �˿Ͳ˵�
		int i,j=0;
		for(i=0;i<bulidings;i++){
		j+=rooms[i].status;}
		int roomCount = bulidings-j;
		if(roomCount==0){
			printf("\n\t���շ����ѿգ����޷�����Ԥ������\n");
		}
		printf("\n\t�����ػ�,���ʴ󴲷�����99Ԫ������ʱ����~\n");
		printf("\t�����ʣ��%d�䣡����\n",roomCount);
		printf("\t------��ӭ���ٳ��ؾƵ�------\n");
		printf("\t\t1. ��ѯԤ��\n");
		printf("\t\t2. Ԥ������\n");
		printf("\t\t3. ����Ա���\n");
		printf("\t\t0. �˳�\n");
		printf("\t�������������");
		scanf("%d",&step);
		if(step<0||step>3){
			printf("\n\t��������������������0-3֮���������룡��\n");
		}
	}while(step<0||step>3);
	switch(step){
		case 0:return 0;
		case 1:CheckRe();break;
		case 2:BookRoom();break;
		case 3:ChangeRoom();break;
	}}while(1);
	return 0;
}
void BookRoom(){
	FILE *fp = NULL;
	int i,j;
	if ((fp = fopen("user.data", "rb")) != NULL){
			fp = fopen("user.data", "w");
	for(j=0;j<bulidings;j++){
	fread(&rooms[j], sizeof(Room), 1, fp);
	}}
	fclose(fp);
	for(i=0;i<bulidings;i++){
	if(rooms[i].status==0)
	break;
	}
	rooms[i].roomNumber=i;
	do{
	printf("\n��ѡ�񷿼����ͣ�\n");
	printf("1.���ʴ󴲷�\n");
	scanf("%d", &rooms[i].type);
	if(rooms[i].type==1){
		printf("\n���ʴ󴲷��ļ۸�Ϊ%.2fԪÿ��\n",BigRoom);
		rooms[i].price=BigRoom;
	}else{
		printf("���ޣ����������룡\n");
	}}while(rooms[i].type!=1);
	printf("��������ס������\n");
	scanf("%d", &rooms[i].time);
	printf("����������������\n");
	getchar();
	gets(rooms[i].name);
	//scanf("%s", &rooms[i].name);
	printf("���������ĵ绰���룺\n");
	scanf("%d", &rooms[i].phone);
	double bill,money=0;
	bill=rooms[i].price*rooms[i].time;
	do{
		printf("\n\t%s���ã���Ԥ���ķ��乲��֧��%.2fԪ��",rooms[i].name,bill);
		if(Admin==0){
		printf("\n\t������Ʊ�棺");
		scanf("%lf",&money);
		getchar();}
		if(money>=bill||Admin==1){
			if(money>bill){
				printf("\n\t����%.2fԪ",money-bill);
			}
			if(Admin==1){
			printf("\n\t����Ա����ɹ��������Ϊ%d��\n",rooms[i].roomNumber+1);	
			}else{
			printf("\n\tԤ���ɹ������ķ����Ϊ%d���뵽ǰ̨��������ס��лл�ݹˡ�\n",rooms[i].roomNumber+1);}
			rooms[i].status=1;
			if ((fp = fopen("user.data", "rb")) != NULL){
			fp = fopen("user.data", "w");
			if (fp) {
					for(j=0;j<bulidings;j++){
	 		fwrite(&rooms[j], sizeof(Room), 1, fp);
			}}}
			printf("\n����Ԥ���ɹ������س�������......");		
			getchar();
		}else{
			printf("\n\t����Ʊ�治�㣬������֧����\n");
		}
	}while(money<bill&&Admin==0);
fclose(fp);
}

void CheckRe(){
	Room check;
	int i;
	printf("\n����������������\n");
	getchar();
	gets(check.name);
	printf("��������Ԥ���ĵ绰���룺\n");
	scanf("%d",&check.phone);
	FILE *fp=fopen("user.data","r");
	getchar();
	for(i=0;i<bulidings;i++){
		if(strcmp(check.name,rooms[i].name)==0&&check.phone==rooms[i].phone){
			printf("\n\t%s���ã�������������ס��Ϣ��\n",rooms[i].name);
			printf("\t\t���ķ����Ϊ��%d\n",rooms[i].roomNumber+1);
			printf("\t\t����Ԥ��ʱ��Ϊ:%d��%d��\n",rooms[i].time+1,rooms[i].time);
			printf("\t\t����������Ϊ%.2fԪ\n",rooms[i].price*rooms[i].time);
			break;
		}
	}
	if(i==bulidings){
		printf("\n���ź���δ��ѯ������Ԥ����Ϣ�����������Ϣ�Ƿ���д��ȷ����ѯǰ̨�ͷ���\n");
	}
	printf("\n��ѯ�ɹ������س�������......");		
	getchar();
	fclose(fp);
}
//�������� �ĺ�������ϵͳ�������ݵĳ�ʼ��
void BuildRoom() {
	 FILE *fp = NULL;
	 int i;
	 	if ((fp = fopen("user.data", "r")) == NULL) {
		fp = fopen("user.data", "w");
		for (i = 0; i < bulidings; i++) {
	 		   	rooms[i].phone=0;
	 		   	rooms[i].price=0.0;
	 		   	rooms[i].roomNumber=i;
	 		   	rooms[i].status=0;
	 		   	rooms[i].time=0;
	 		   	rooms[i].type=0;
				fwrite(&rooms[i], sizeof(Room), 1, fp);
			}
	} else {
			 for(i=0;i<bulidings;i++){
	 		 fread(&rooms[i], sizeof(Room), 1, fp);
	 		 }
	}
	fclose(fp);
}
	

int ChangeRoom(){
	char password[50];
	printf("\n���������Ա���룺");
	getchar();
	gets(password);
	if(strcmp(password,"admin")==0){		
		printf("\n��¼�ɹ���\n");
		int step;
		Admin=1;
	do{
		do{
		printf("\n\t--------����Ա�˵�--------\n");
		printf("\t\t1. ��ѯ��ס����\n");
		printf("\t\t2. �û��˷�\n");
		printf("\t\t3. ��������\n");
		printf("\t\t0. ����������\n");
		printf("\t�������������");
		scanf("%d",&step);
		if(step<0||step>4){
			printf("\n\t��������������������0-3֮���������룡��\n");
		}
	}while(step<0||step>4);
	switch(step){
		case 0:Admin=0;printf("\n\n\n");return 0;
		case 1:CheckIn();break;
		case 2:DeleteRoom();break;
		case 3:BookRoom();break;
	}
		
	}while(1);
	}else{
		printf("\n�������\n");
	}
	Admin=0;
	return 0;
}

void CheckIn(){
	getchar();
	int i;
	for(i=0;i<bulidings;i++){
		if(rooms[i].status==1){
			printf("\n\t����ţ�%d\n",rooms[i].roomNumber+1);
			printf("\t\t�������ͣ�");
			switch(rooms[i].type){
				case 1:printf("���ʴ󴲷�\n");break;
			}
			printf("\t\t�û�������%s\n",rooms[i].name);
			printf("\t\t�û�Ԥ�����룺%d\n",rooms[i].phone);
			printf("\t\tԤ��ʱ��Ϊ��%d��%d��\n",rooms[i].time+1,rooms[i].time);
			printf("\t\t��������Ϊ��%.2fԪ\n",rooms[i].price*rooms[i].time);
		}
	}
	 	printf("\n�����ɹ������س�������......");		
		getchar();
}

void DeleteRoom(){
	FILE *fp = NULL;
	int a;
	int i,j;
	if ((fp = fopen("user.data", "rb")) != NULL){
			fp = fopen("user.data", "w");
	for(j=0;j<bulidings;j++){
	fread(&rooms[j], sizeof(Room), 1, fp);
	}}
	fclose(fp);
	printf("\n������Ҫ�˷��ķ���ţ�");
	scanf("%d",&a);
	a--;
	getchar();
	if(rooms[a].status==1){
			 	rooms[a].phone=0;
	 		   	rooms[a].price=0.0;
	 		   	rooms[a].roomNumber=a;
	 		   	rooms[a].status=0;
	 		   	rooms[a].time=0;
	 		   	rooms[a].type=0;
	if ((fp = fopen("user.data", "rb")) != NULL){
			fp = fopen("user.data", "w");
			if (fp) {
			for(j=0;j<bulidings;j++){
	 		fwrite(&rooms[j], sizeof(Room), 1, fp);
			}}}
	 		printf("\n�����˷��ɹ������س�������......");		
			getchar();
			}else{
				printf("\n���������������󣡣�\n");
			}

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tsabt{
	int y;
	int m;
	int d;
};
struct ghetee{
	int id;
	char name[30];
	char model[30];
	int price;
	struct tsabt tsabt;
};
int menu(void);
void printghetee (struct ghetee *,int);
int id(struct ghetee *,struct ghetee *,int);
void load (struct ghetee *,struct ghetee *,int);
void add(struct ghetee *,struct ghetee *,int);
void show(struct ghetee *,int);
void savefile(struct ghetee *,int);
void save (struct ghetee *,struct ghetee*,int);
void strcopy (char[],char[]);
int searcharray(char[],char[]);
void search(struct ghetee *,int);
void forosh (struct ghetee *, struct ghetee *, int);
void showforosh (struct ghetee *,struct ghetee *,int);
void deleteghetee (struct ghetee *, struct ghetee *, int);
int main(){
	printf("                                             Computer Shop\n");
    printf("                                               A R M I N   H E I D A R I\n");
	struct ghetee *f,*del;
	int m,choice;
	printf("zarfiate foroshgah dar majmoo chand ghetee ast ? ");
	scanf("%d",&m);
	f=malloc(m * sizeof(struct ghetee));
	del=malloc(200 * sizeof(struct ghetee));
	int a;
	for (a=0;a<m;a++) f[a].id=0;
	for (a=0;a<200;a++) del[a].id=0;	
	while (1){
		choice=menu ();
		switch(choice){
			case 1: load(f,del,m); break;
			case 2: add(f,del,m); break;
			case 3: show(f,m); break;
			case 4: savefile(f,m); break;
			case 5: save(f,del,m); break;
			case 6: search(f,m); break;
			case 7: forosh(f,del,m); break;
			case 8: showforosh(del,f,m); break;
			case 9: deleteghetee(f,del,m); break;		
			case 10: exit(0); break;
		}
	}
return 0;
}
int menu(void){
	int choice;
	printf ("Menu: \n");
	printf("1: Load Shop\n2: Add \n3: show shop \n4: Save in a file \n5: Save \n6: search\n7: Sell \n8: sale list\n9: Delete\n10:exit\n");
	printf ("\nEnter your choice: \n");
	scanf ("%d" ,& choice);
	while(choice<1 || choice>11){
		printf ("\nsahih nist.\n");
		printf ("Enter your choice: \n");
		scanf ("%d" ,& choice);
	}
	return choice;
}
void printghetee (struct ghetee *a,int i){
	printf ("ID: %d\n",a[i].id);
	printf ("Name: %s\n",a[i].name);
	printf ("model: %s\n",a[i].model);
	printf ("price: %d\n",a[i].price);
	printf ("Tarikhe sabt: %d/%d/%d\n",a[i].tsabt.y,a[i].tsabt.m,a[i].tsabt.d);
}
int id(struct ghetee *a,struct ghetee *b,int m){
	int di,check=0,i;
	while(check==0){
		check=1;
		printf("baraye ghetee ID entekhab konid :\n");
		scanf("%d",&di);
		for(i=0; a[i].id!=0 && m>i; i++){
			if(a[i].id==di) check=0;
		}	
		for(i=0; b[i].id!=0 && 200>i; i++){
			if(b[i].id==di) check=0;
		}
	}
	return di;
}			
void load (struct ghetee *a,struct ghetee *b,int m){
	FILE *fp;
	int t,i;
	fp=fopen("foroshgah.txt","rt");
	fscanf(fp,"%d",&t);
	if (t>m) printf("Gonjayeshe Maximum kafi nist. file nemitavanad load shavad.\n");
	else{
		for(i=0; t>i; i++){
			fscanf(fp,"%d",& a[i].id);
			fscanf(fp,"%s",a[i].name);
			fscanf(fp,"%s",a[i].model);
			fscanf(fp,"%d",&a[i].price);
			fscanf(fp,"%d%d%d",&a[i].tsabt.y,&a[i].tsabt.m,&a[i].tsabt.d);
		}
		for(; a[i].id!=0 && m>i; i++) a[i].id=0;
		fscanf(fp,"%d",&t);
		for(i=0; t>i; i++){
			fscanf(fp,"%d",& b[i].id);
			fscanf(fp,"%s",b[i].name);
			fscanf(fp,"%s",b[i].model);
			fscanf(fp,"%d",&b[i].price);
			fscanf(fp,"%d%d%d",&b[i].tsabt.y,&b[i].tsabt.m,&b[i].tsabt.d);
		}
		for(; b[i].id!=0 && 200>i; i++) b[i].id=0;	
		printf("Shop Loaded.\n");	
	}	 
}	
void add(struct ghetee *a,struct ghetee *b,int m){
	int t,i,j,anjam=1;
	printf ("\nChe tedad ghetee ra ezafe mikonid? \n");
	scanf ("%d" ,& t);
	for(i=0; a[i].id !=0 && m>i; i++);
	if (i==m && a[i].id!=0){
		printf("List kamelan por ast.\n");
		anjam=0;
	}
	if (m-i<t && anjam==1){
		printf ("List zarfiate in tedad ghetee ra nadarad. \n");
	}
	else if(anjam==1){
		for(j=0; t>j; j++,i++){
			printf("\nID ghetee:\n");
			a[i].id=id(a,b,m);
			printf("lotfan name ghetee ra vared konid :\n");
			scanf("%s",a[i].name);
			printf("lotfan name model ra vared konid :\n");
			scanf("%s",a[i].model);
			printf("lotfan gheymate ghetee ra vared konid :\n");
			scanf("%d",&a[i].price);
			printf("lotfan be tartib sal/mah/rooz tarikh sabt ra vared konid :\n");
			scanf("%d%d%d",&a[i].tsabt.y,&a[i].tsabt.m,&a[i].tsabt.d);
		}
	}
}
void strcopy (char a[],char b[]){
	int i;
	for(i=0; b[i]!=0; i++) a[i]=b[i];
	a[i]=0;
}
void show (struct ghetee *a,int m){
	int i;
	for (i=0; a[i].id!=0 && m>i; i++){
		if (i==0) printf("\nListe gheteehaye forushgah:\n");
		printf ("\ngheteeye %d: \n",i+1);
		printf ("ID: %d\n",a[i].id);
		printf ("Name: %s\n",a[i].name);
		printf ("model: %s\n",a[i].model);
		printf ("price: %d\n",a[i].price);
		printf ("Tarikhe sabt: %d/%d/%d\n",a[i].tsabt.y,a[i].tsabt.m,a[i].tsabt.d);
	}
	if (i==0) printf ("\nHich gheteeei ezafe nashode ast.\n");
}
void savefile(struct ghetee *a,int m){
	int i;
	FILE *fp;
	fp=fopen("gheteeha.txt","wt");
	for (i=0; a[i].id!=0 && m>i; i++){
		fprintf (fp,"\ngheteeye %d: \n",i+1);
		fprintf (fp,"ID: %d\n",a[i].id);
		fprintf (fp,"Name: %s\n",a[i].name);
		fprintf (fp,"model: %s\n",a[i].model);
		fprintf (fp,"price: %d\n",a[i].price);
		fprintf (fp,"Tarikhe sabt: %d/%d/%d\n",a[i].tsabt.y,a[i].tsabt.m,a[i].tsabt.d);
	}
	fclose(fp); fp=0;
	printf ("Saved in a file.\n");
}	
void save (struct ghetee *a,struct ghetee *b,int m){
	FILE *fp; fp=0;
	int t,i;
	fp= fopen("foroshgah.txt","wt");
	for(t=0; a[t].id!=0 && m>t; t++);
	fprintf(fp,"%d\n",t);
	for(i=0; t>i; i++){
		fprintf(fp,"%d\n",a[i].id);
		fprintf(fp,"%s\n",a[i].name);
		fprintf(fp,"%s\n",a[i].model);
		fprintf(fp,"%d\n",a[i].price);
		fprintf(fp,"%d\n%d\n%d\n",a[i].tsabt.y,a[i].tsabt.m,a[i].tsabt.d);
	}
	for(t=0; b[t].id!=0 && 200>t; t++);
	fprintf(fp,"%d\n",t);
	for(i=0; t>i; i++){
		fprintf(fp,"%d\n",b[i].id);
		fprintf(fp,"%s\n",b[i].name);
		fprintf(fp,"%s\n",b[i].model);
		fprintf(fp,"%d\n",b[i].price);
		fprintf(fp,"%d\n%d\n%d\n",b[i].tsabt.y,b[i].tsabt.m,b[i].tsabt.d);
	}
	fclose(fp); fp=0;
	printf ("Shop Saved.\n");
}
int searcharray(char a[],char b[]){
	int n1,n2,i,i1,i2,check=0;
	for (n1=0; a[n1]!=0; n1++);
	for (n2=0; b[n2]!=0; n2++);
	for (i=0; n1-n2>=i; i++){
		if(b[0]==a[i] || b[0]==(a[i]+32) || b[0]==(a[i]-32)){
			check=1;
			for(i2=1,i1=i+1; n2>i2 && check==1; i1++,i2++) if(b[i2]!=a[i1] && b[i2]!=(a[i1]+32) && b[i2]!=(a[i1]-32)) check=0;
			if (check==1) return check;
		}
	}
	return 0;
}
void search(struct ghetee *a,int m){
	int peyda[100],t=0,i=0;
	char s[100];
	printf("\nname ghetee ya modele an ra vared konid:\n");
	scanf("%s",s);
	for(i=0; a[i].id!=0 && m>i; i++){
		if (searcharray(a[i].name,s)==1 || searcharray(a[i].model,s)==1){
			peyda[t]=i;
			t++;
		}
	}
	if (t==0) printf ("Hich gheteeei ba in moshakhasat peyda nashod.\n");
	else{
		printf("\nListe gheteehaye peyda shodeh:\n\n");
		for(i=0; t>i; i++) printghetee(a,peyda[i]);
	}
}	
void forosh (struct ghetee *b,struct ghetee *a,int m){
    //in ghesmat va ghesmate liste forosh kamel nistand.dar hengame tahvile hozori kamel mikonm.
	int t,id,i,y=0,ib;
	for(t=0; a[t].id !=0 && m>t; t++);
	printf("ID gheteeei ke mikhahid beforoshid ra vared konid:\n");
	scanf("%d" ,& id);
	for(i=0; t>i && y==0; i++){
		if(a[i].id==id){
			y=1;
			i--;
		}
	}
	if (y==0) printf("gheteeei ba in ID peyda nashod.\n");
	else if(y==1){
			for(ib=0; b[ib].id !=0 && 200>ib; ib++);
			if (ib==(200-1) && b[ib].id!=0){
				printf("Liste forosh kamelan por ast.\n");
			}
			else {
				b[ib].id=a[i].id;
				strcopy(b[ib].name,a[i].name);
				strcopy(b[ib].model,a[i].name);		
				b[ib].price=a[i].price;
				b[ib].tsabt.y=a[i].tsabt.y;
				b[ib].tsabt.m=a[i].tsabt.m;
				b[ib].tsabt.d=a[i].tsabt.d;
				printf("\ngheteeye zekr shodeh forokhte shod.\n");
			}
	}
}
void showforosh (struct ghetee *b,struct ghetee *a,int m){
	int i,id,y=0,t,ib,c2;
			for (i=0; b[i].id!=0 && 200>i; i++){
			if(i==0) printf("\nListe ghetee haei ke forokhte shodand.\n");
			printf ("\ngheteeye %d: \n",i+1);
			printf ("ID: %d\n",b[i].id);
			printf ("Name: %s\n",b[i].name);
			printf ("model: %s\n",b[i].model);
			printf ("price: %d\n",b[i].price);
			printf ("Tarikhe sabt: %d/%d/%d\n",b[i].tsabt.y,b[i].tsabt.m,b[i].tsabt.d);
		}
		if(i==0) printf("\nHich gheteeei forokhte nashode.\n");
	}
	void deleteghetee (struct ghetee *a, struct ghetee *b, int m){
	int choice,t,id,i,y=0,ib,anjam=0;
	for(t=0; a[t].id !=0 && m>t; t++);
	printf("ID gheteeei ke mikhahid hazf konid ra vared konid:\n");
	scanf("%d" ,& id);
	for(i=0; t>i && y==0; i++){
		if(a[i].id==id){
			y=1;
			i--;
		}
	}
	if (y==0) printf("gheteeei ba in ID peyda nashod.\n");
	else if (y==1){
		printf ("\nAya Motmaenid ke '%s' ba ID %d  hazf shavad? (1:Bale  2: Na)\n",a[i].name,a[i].id);
		scanf ("%d",& anjam);
		while(anjam!=1 && anjam!=2){
			printf("\nsahih nist.\n");
			printf ("Aya Motmaenid ke '%s' ba ID %d hazf shavad? (1:Bale  2: Na)\n",a[i].name,a[i].id);
			scanf ("%d",& anjam);
		}
		if (anjam==1){
			a[i].id=a[t-1].id;
			strcopy(a[i].name,a[t-1].name);
			strcopy(a[i].model,a[t-1].name);		
			a[i].price=a[t-1].price;
			a[i].tsabt.y=a[t-1].tsabt.y;
			a[i].tsabt.m=a[t-1].tsabt.m;
			a[i].tsabt.d=a[t-1].tsabt.d;	
			a[t-1].id=0;
			printf("\ngheteeye zekr shodeh hazf shod.\n");
		}
	}
}

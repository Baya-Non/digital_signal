#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

#define PI 3.14159265359;

typedef struct{
	double re;
	double im;
} rack;

void file_open(char fname1[128],rack base_data[500],int m){
	
	FILE *fp0;
	int i=0;
	fp0=fopen(fname1,"r");
	if(fp0==NULL){
		printf("can't open file <%s>\n",fname1);
		exit(1);
	}
	while(fscanf(fp0,"%lf\n",&base_data[i])!=EOF){
		i++;
		if(i>m) break;
	}
	fclose(fp0);
}

void file_print(char fname2[128],rack qua_data[500],int m){
	FILE *fp0;
	int i=0,check;
	fp0=fopen(fname2,"w");
	while((check=fscanf(fp0,"%lf,%lf",&qua_data[i].re,qua_data[500].im))!=EOF){
		i++;
		if(i>m) break;
	}
	fclose(fp0);

}

void C_Dsp(int k,rack xn[500],rack xk[500],int a,int b)
{
	int i,j;
	for(i=0;i<k;i++){
		xk[i].re=0;
		xk[i].im=0;
		for(j=0;j<k;j++){
			xk[i].re+=(xn[j].re * cos(2*M_PI/k*i*j) + a * xn[j].im *sin(2*M_PI/k*i*j));
			xk[i].im+=(xn[j].im * cos(2*M_PI/k*i*j) - a * xn[j].im *sin(2*M_PI/k*i*j));
		}
	}
}


int main(){
	int m,n,x,i,j;
	rack xn[500],xk[500];
	char a[20],b[20];
	printf("DFT-->0  IDFT-->1\n");
	scanf("%d",&x);
	printf("点数を入力");
	scanf("%d",&m);
	printf("入力ファイル名");
	scanf("%s",&a);
	printf("出力ファイル名");
	scanf("%s",&b);
	
	if(x==0){
		file_open(a,xn,m);
		C_Dsp(m,xn,xk,1,1);
		file_print(b,xk,m);
	}
}

	
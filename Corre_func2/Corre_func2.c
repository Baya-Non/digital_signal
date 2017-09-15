#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double I_product(double x[701],double y[701],int m){
	int i;
	double sum=0;
	for(i=0;m+i<701;i++){
		sum=sum+x[i]*y[m+i];
	}
	sum=sum/701;
	return sum;
}

double Im_product(double x[71],double y[71],int m){
	int i;
	double sum=0;
	for(i=0;m+i<71;i++){
		sum=sum+x[i]*y[m+i];
	}
	sum=sum/71;
	return sum;
}


void file_open(char fname1[128],double base_data[1000]){//?t?@?C???f?[?^????????
	
	FILE *fp0;
	int i=0;
	fp0=fopen(fname1,"r");
	if(fp0==NULL){
		printf("can't open file <%s>\n",fname1);
		exit(1);
	}
	while(fscanf(fp0,"%lf\n",&base_data[i])!=EOF){
		i++;
	}
	fclose(fp0);
}

void file_print(char fname2[128],double qua_data[1000]){
	FILE *fp0;
	int i=0;
	fp0=fopen(fname2,"w");
	for(i=0;i<701;i++){
		fprintf(fp0,"%lf\n",qua_data[i]);
	}
	fclose(fp0);

}

void mfile_print(char fname3[128],double m_data[1000]){
	FILE *fp0;
	int i=0;
	fp0=fopen(fname3,"w");
	for(i=0;i<71;i++){
		fprintf(fp0,"%lf\n",m_data[i]);
	}
	fclose(fp0);

}

int main(){
	int i=0,j=0,m,num;
	int quantity;
	double basedata1[701],basedata2[701],basedata3[71];
	double qua[701],sum1[71];
	double data[4][128],subdata[4][128];
	double sum=0;
	
	
	file_open("rdata1.txt",basedata1);
	file_open("rdata2.txt",basedata2);
	printf("相互関数\n");
	for(m=0;m<701;m++){
		qua[m]=I_product(basedata1,basedata2,m);
		if(qua[m]>sum){
			sum=qua[m];
			num=m;
		}
		if (m%100==0) printf("Rxy(%d)=%lf\n",m,qua[m]);
	}
	
	file_print("rdata4.txt",qua);
	
	printf("自己関数\n");
	file_open("rdata3.txt",basedata3);
	for(m=0;m<71;m++){
		sum1[m]=Im_product(basedata3,basedata3,m);
		if (m%10==0) printf("Rxx(%d)=%lf\n",m,sum1[m]);
	}
	mfile_print("rdata5.txt",sum1);
	return;
	
}
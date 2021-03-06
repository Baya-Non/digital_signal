#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double I_product(double y[],double z[],int quantity){
	int i;
	double dsum1=0;
	for(i=0;i<quantity;i++){
		dsum1=dsum1+y[i]*z[i];
	}
	return dsum1;
}

double AddSum(double data[],int quantity){
	double sum=0;
	int i;
	for(i=0;i<quantity;i++){
		sum=sum+data[i];
	}
	return sum;
}

int main(){
	FILE *fp1;
	FILE *fp2;
	FILE *fp3;
	FILE *fp4;
	int i=0,j=0;
	int quantity;
	double data[4][128],subdata[4][128];
	double sum[4],ave[4],sub[4],denom[3],sqr[4];
	double numer[3],ans[3];
	
	double subdata1[4][128];
	double sum1[4],ave1[4],sub1[4],denom1[3],sqr1[4];
	double numer1[3],ans1[3];
	
	for(i=0;i<4;i++){
		for(j=0;j<128;j++){
			data[i][j]=0;
			subdata[i][j]=0;
		}
	}
	for(i=0;i<4;i++){
		sub[i]=0;
	}
	i=0;
	
	/*rdata1.txt*/
	//printf("gets the data.....\n");
	fp1=fopen("rdata1.txt","r");
	if(fp1==NULL){
		printf("can't open file <%s>\n","rdata1.txt");
		exit(1);
	}
	while(fscanf(fp1,"%lf",&data[0][i])==1){
		i++;
	}
	fclose(fp1);
	quantity=i;
	i=0;
	
	/*rdata2.txt*/
	fp2=fopen("rdata2.txt","r");
	if(fp2==NULL){
		printf("can't open file <%s>\n","rdata2.txt");
		exit(1);
	}
	while(fscanf(fp2,"%lf",&data[1][i])==1){
		i++;
	}
	fclose(fp2);
	i=0;
	
	/*rdata3.txt*/
	fp3=fopen("rdata3.txt","r");
	if(fp3==NULL){
		printf("can't open file <%s>\n","rdata3.txt");
		exit(1);
	}
	while(fscanf(fp3,"%lf",&data[2][i])==1){
		i++;
	}
	fclose(fp3);
	i=0;
	
	/*rdata4.txt*/
	fp4=fopen("rdata4.txt","r");
	if(fp4==NULL){
		printf("can't open file <%s>\n","rdata4.txt");
		exit(1);
	}
	while(fscanf(fp4,"%lf",&data[3][i])==1){
		i++;
	}
	fclose(fp4);
	i=0;
	//printf("	The data quantity = %d\n\n",quantity);
	
	//printf("----------a correlation coefficient------------\n\n");
	/*Calculate Sum & ave*/
	//printf("Calculate Sum and average.....\n");
	for(i=0;i<4;i++){
		sum[i]=AddSum(data[i],quantity);
	}
	for(i=0;i<4;i++){
		ave[i]=sum[i]/quantity;
	}
	
	/*for(i=0;i<4;i++){
		printf("	average data%d = %lf\n",i,ave[i]);
	}
	*/
	//printf("\n");
	/*Calculate denom sub*/
	//printf("Calculate denom.....\n");
	for(i=0;i<4;i++){
		for(j=0;j<quantity;j++){
			sub[i]+=(data[i][j]-ave[i])*(data[i][j]-ave[i]);
		}
	}
	
	denom[0]=sqrt(sub[0]*sub[1]);
	denom[1]=sqrt(sub[0]*sub[2]);
	denom[2]=sqrt(sub[0]*sub[3]);
	
	/*for(i=0;i<3;i++){
		printf("	denom data%d = %lf\n",i,denom[i]);
	}
	printf("\n");
	*/
	//printf("Calculate numer.....\n");
	/*Calculate sub average*/
	for(i=0;i<4;i++){
		for(j=0;j<quantity;j++){
			subdata[i][j]=data[i][j]-ave[i];
		}
	}
	
	/*Calculate numer*/
	numer[0]=I_product(subdata[0],subdata[1],quantity);
	numer[1]=I_product(subdata[0],subdata[2],quantity);
	numer[2]=I_product(subdata[0],subdata[3],quantity);
	
	/*for(i=0;i<3;i++){
		printf("	numer data%d = %lf\n",i,numer[i]);
	}
	printf("\n");
	*/
	/*Calcurate Anser*/
	//printf("Calcurate Anser.....\n");
	for(i=0;i<3;i++){
		ans[i]=numer[i]/denom[i];
	}
	printf("相関係数結果：\n");
	printf("	H16男性・女性 = %lf\n",ans[0]);
	printf("	H16男性・総人口 = %lf\n",ans[1]);
	printf("	H16男性・S24 = %lf\n",ans[2]);
	printf("\n\n");
	
	
	
	
	
	//printf("--------DC component Not removal----------\n\n");
	
	//printf("Calculate denom.....\n");
	for(i=0;i<4;i++){
		for(j=0;j<quantity;j++){
			sub1[i]+=data[i][j]*data[i][j];
		}
	}
	
	denom1[0]=sqrt(sub1[0]*sub1[1]);
	denom1[1]=sqrt(sub1[0]*sub1[2]);
	denom1[2]=sqrt(sub1[0]*sub1[3]);
	
	/*for(i=0;i<3;i++){
		printf("	denom data%d = %lf\n",i,denom1[i]);
	}
	printf("\n");
	*/
	//printf("Calculate numer.....\n");
	for(i=0;i<4;i++){
		for(j=0;j<quantity;j++){
			subdata1[i][j]=data[i][j];
		}
	}
	
	numer1[0]=I_product(subdata1[0],subdata1[1],quantity);
	numer1[1]=I_product(subdata1[0],subdata1[2],quantity);
	numer1[2]=I_product(subdata1[0],subdata1[3],quantity);
	
	/*for(i=0;i<3;i++){
		printf("	numer data%d = %lf\n",i,numer1[i]);
	}
	printf("\n");
	*/
	//printf("Calcurate Anser.....\n");
	for(i=0;i<3;i++){
		ans1[i]=numer1[i]/denom1[i];
	}
	printf("直流成分未除去の場合：\n");
	printf("	H16男性・女性 = %lf\n",ans1[0]);
	printf("	H16男性・総人口 = %lf\n",ans1[1]);
	printf("	H16男性・S24 = %lf\n",ans1[2]);
	
	return;
}
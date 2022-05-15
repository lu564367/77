#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Item
{
	char country[100];
	int goldNum;
	int silverNum;
	int bronzeNum;
	int totalNum;
};

void printItem(struct Item item)
{
	printf("%s\t%d\t%d\t%d\t%d\n",item.country,item.goldNum,item.silverNum,item.bronzeNum,item.totalNum);
}

void fillItem(struct Item* item,char str[])
{
	char country[100]={'\0'};
	int countryIndex=0;
	int sIndex=0;
	while(str[sIndex]!='\t') country[countryIndex++]=str[sIndex++];
	strcpy(item->country,country);
	
	sIndex++;
	char goldNum[100]={'\0'}; 
	int goldIndex=0;
	while(str[sIndex]!='\t') goldNum[goldIndex++]=str[sIndex++];
	item->goldNum=atoi(goldNum);
	
	sIndex++;
	char silverNum[100]={'\0'};
	int silverIndex=0;
	while(str[sIndex]!='\t') silverNum[silverIndex++]=str[sIndex++]; 
	item->silverNum=atoi(silverNum);
	
	sIndex++;
	char bronzeNum[100]={'\0'};
	int bronzeIndex=0;
	while(str[sIndex]!='\t') bronzeNum[bronzeIndex++]=str[sIndex++];
	item->bronzeNum=atoi(bronzeNum);
	
	sIndex++;
	char totalNum[100]={'\0'};
	int totalIndex=0;
	while(str[sIndex]!='\n') totalNum[totalIndex++]=str[sIndex++];
	item->totalNum=atoi(totalNum);
}

int main()
{
	FILE* infp=fopen("G:\\win.txt","r");
	if(infp==NULL)
	{
		printf("Error\n");
		return 0;
	} 
	char str[8][100];
	int isFirstline=1,i=0;
	while(fgets(str[i],100,infp)!=NULL)
	{
		if(isFirstline==1) isFirstline=0;
		else i++;
	}
	fclose(infp);
	
	struct Item items[8];
	for(i=0;i<8;i++)
	{
		fillItem(&items[i],str[i]);
		printItem(items[i]);
	}
	printf("\n");
	
	struct Item max=items[0],min=items[0];
	for(i=1;i<8;i++)
	{
		if(items[i].totalNum>max.totalNum) max=items[i];
		if(items[i].totalNum<min.totalNum) min=items[i];
	}
	
	printItem(max);
	printItem(min);
	
	return 0;
}

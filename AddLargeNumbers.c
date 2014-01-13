/*
date: 2014-01-13
知识点:
1- printf("%0*s", 5, "ab"); 000ab %0*s 表示动态长度输出, 左补0 
2- 字符串数组,每位在内存中按照ascii存储,如果想要计算如相加,需要先转化为int
	eg:
	char a[]="123";
	char b[]="456";
	char c[4];
	c[0] = ((a[0] - '0') + (b[0] - '0')) + '0';
	printf("%c\n", c[0]);
	提取a[0]+b[0]时a[0]按照ascii存储,需要转化为int,所以-'0'
	计算的结果为int需要转化为ascii存储到c[0] 所以需要+'0'
	结论:
	字符每位按照ascii存储在内存中
	ascii 转int: - '0' eg: 49 - 48 = 1
	int 转 ascii: + '0' eg: 1 + 48 = 49
	0ascii为48
3- 直接打印字符串数组与指针
*/
#include<stdio.h>
#include<string.h>

#define MAXLEN 100

char *func(char *str1, char *str2)
{
	int i, ilen1 = 0, ilen2 = 0, imax = 0;
	int idec = 0, isum = 0, ioverflow = 0;
	char strTmp1[MAXLEN];
	char strTmp2[MAXLEN];
	char *p;
	
	ilen1 = strlen(str1);
	ilen2 = strlen(str2);

	/*补齐位数,为了使两字符串长度相等*/
	if(ilen1 > ilen2)
	{
		sprintf(strTmp2, "%0*s", ilen1, str2);
		strcpy(strTmp1, str1);
		imax = ilen1;
		printf("str1 = [%s]\n", strTmp1);
		printf("str2 = [%s]\n", strTmp2);
	}
	else
	{
		sprintf(strTmp1, "%0*s", ilen2, str1);
		strcpy(strTmp2, str2);
		imax = ilen2;
		printf("str1 = [%s]\n", strTmp1);
		printf("str2 = [%s]\n", strTmp2);
	}
	
	char iRes[imax + 2]; //存放结果
	for(i = imax - 1; i >= -1; i--)
	{
		/*结果值得最高位*/
		if( i == -1)
		{
			iRes[i+1]=(char)idec  + '0';
			break;
		}
		/*两值相加*/
		isum =  strTmp1[i] - '0' + strTmp2[i] - '0' + idec;
		/*判断进位*/
		ioverflow = isum - 10;
		if(ioverflow >= 0 )
		{
			idec = 1; //进1位
			iRes[i+1]=ioverflow + '0'; //赋值
		}
		else
		{
			idec = 0; //无进位
			iRes[i+1]=(char)isum  + '0'; //赋值
		}
	}
	iRes[imax+1] = '\0'; //最后一位加\0
	printf("iRes =[%s]\n", iRes); //打印结果
	p = iRes;
	return p;
}

int main()
{
	char *str1 = "654321234567890987654322";
	char *str2 = "88879991099887765543322112457689999";
	char *p;

	p = func(str1, str2);
	printf("  p = [%s]\n", p);
	
	/**
	char a[]="123";
	char b[]="456";
	char c[4];
	c[0] = ((a[0] - '0') + (b[0] - '0')) + '0';
	printf("%c\n", c[0]);
	**/
	
	system("PAUSE");
	return 1;
}

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int is_left_move(char* str1, char* str2);
int get_len(char* str);
int str_catenate(char* str1, char* str2, int count);
int str_str(char* str1, char* str2);

int is_left_move(char* str1, char* str2)
{
	if (get_len(str1) != get_len(str2)) return 0;
	/*if (strlen(str1) != strlen(str2)) return 0;*/

	str_catenate(str1, str1, get_len(str1));
	/*strncat(str1, str1, strlen(str1));*/

	char* ret = (char*)str_str(str1, str2);
	/*char* ret = strstr(str1, str2);*/
	
	if (ret == NULL) return 0;
	else return 1;
}

int get_len(char* str)
{
	char* p = str;
	int count = 0;
	while (*p++ != '\0')
	{
		count++;
	}
	return count;
}

int str_catenate(char* str1, char* str2, int count)
{
	char* p0 = str1;
	char* ps = str2;
	for (; *p0 != '\0'; p0++);
	while (count)
	{
		*p0 = *ps;
		p0++;
		ps++;
		count--;
	}
	*p0 = '\0';
	p0++;
	return *str1;

}

int str_str(char* str1, char* str2)
{
	int i = get_len(str1) - get_len(str2);
	if (i < 0) return NULL;
	char* p1 = str1;
	char* p2 = str2;
	char* p = p1;

	while(*p1!='\0')
	{
		if (*p1 != *p2)	p = ++p1;
		else if(*p1 == *p2)
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')	return *(p + 1);
	}
	return NULL;
}

int main()
{
	char arr1[30] = "abcdef";
	char arr2[] = "defabc";
	
	int ret = is_left_move(arr1, arr2);
	if (ret) printf("Yes!");
	else printf("No!");
	
	return 0;
}
/*
Герасименко Владимир Александрович
Лабораторная работа №2.
Вариант №5
Задание:
*/
#define _CRT_SECURE_NO_WARNINGS 

#define MAX 100
#define SIZE 50
#define MAX_RECORD 50

#include <stdio.h> 
#include <locale> 
#include <conio.h> 
#include <string.h> 
#include <iostream>
#include <cstdlib>

struct user
{
	char surname[SIZE];
	char name[SIZE];
	char patronymic[SIZE];
	char phone[SIZE];
	char startContract[SIZE];
	char finishContract[SIZE];
	char debt[SIZE];
	char credit[SIZE];
}user_str[MAX_RECORD];

struct dateStartContract
{
	char day[SIZE];
	char month[SIZE];
	char year[SIZE];
}start_contract[MAX_RECORD];

struct dateFinishContract
{
	char day[SIZE];
	char month[SIZE];
	char year[SIZE];
}finish_contract[MAX_RECORD];

struct services
{
	char linkName[SIZE];
	int code[SIZE];
	float time[SIZE];
	char codeSec[SIZE];
}services_str[MAX_RECORD];

struct useUser
{
	char phone[SIZE];
	int codeServices[SIZE];
	char dateUse[SIZE];
	char timeUse[SIZE];
	char duration[SIZE];
}useUser_str[MAX_RECORD];


void menu(void);
void readFileUserList(void), readFileServicesList(void), readFileUseUserList(void),printFile(void), calculations(void);
void splitDateStartContract(int J), splitDateFinishContract(int J);

int J;

int main()
{
	system("chcp 1251");
	system("cls");
	menu();
	_getch();
}

void menu()
{
	int result;
L:	printf("-----Что вы хотитетите сделать?-----\n |1.Считать файл с данными о пользователях\n |2.Считать данные о услугах\n |3.Считать данные о услугах, предоставляемые пользователям\n |4.Записать данные в файл\n |5.расчитать что-то\n |6.Выход\n-----Введите пункт: ");
	scanf("%d", &result);
	if ((result > 0) && (result <= 4))
	{
		switch (result)
		{
		case 1: readFileUserList(); break;
		case 2: readFileServicesList(); break;
		//case 3: readFileUseUserList(); break;
		//case 4: printFile(); break;
		case 5: calculations(); break;
		case 6: exit(0);
		}
	}
	else goto L;
}

void readFileUserList()
{
	FILE *userList;
	userList = fopen("userList.txt", "r");
	///*	while (!feof(userList))
	//{
	//	if (fgetc(userList) == '\n')
	//		length++;
	//}*/
	for (J = 0; J < 2; J++)
	{
		fscanf(userList, "%s %s %s , %s , %s , %s , %s , %s", user_str[J].surname, user_str[J].name, user_str[J].patronymic, user_str[J].phone, user_str[J].startContract, user_str[J].finishContract, user_str[J].debt, user_str[J].credit);
		splitDateStartContract(J);
		splitDateFinishContract(J);
	}

	//char chr[1000];
	//int k = 0, s = 0;
	//for (int i = 0; i < 5; i++)
	//{
	//	fgets(chr, MAX_RECORD, userList);
	//	if (!feof(userList))
	//	{
	//		chr[strlen(chr) - 1] = ',';
	//	}
	//	//Getting name
	//	while (chr[k] != ',')
	//	{
	//		user_str[i].surname[k] = chr[k];
	//		k++;
	//	}
	//	user_str[i].surname[k] = '\0';
	//	k++;
	//	if (chr[k] == ' ')
	//	{
	//		k++;
	//	}
	//	//Getting telephone number
	//	while (chr[k] != ',')
	//	{
	//		user_str[i].phone[s] = chr[k];
	//		k++;
	//		s++;
	//	}
	//	user_str[i].phone[s] = '\0';
	//	k += 2;
	//	s = 0;

	//	//Getting date of starting deal
	//	while (chr[k] != ',')
	//	{
	//		user_str[i].startContract[s] = chr[k];
	//		s++;
	//		k++;
	//	}
	//	user_str[i].startContract[s] = '\0';
	//	k++;
	//	s = 0;
	//	if (chr[k] == ' ')
	//	{
	//		k++;
	//	}

	//	//Getting date of ending deal
	//	while (chr[k] != ',')
	//	{
	//		user_str[i].finishContract[s] = chr[k];
	//		s++;
	//		k++;
	//	}
	//	user_str[i].finishContract[s] = '\0';
	//	k++;
	//	s = 0;
	//	if (chr[k] == ' ')
	//	{
	//		k++;
	//	}

	//	//Getting bill
	//	while (chr[k] != ',')
	//	{
	//		user_str[i].debt[s] = chr[k];
	//		s++;
	//		k++;
	//	}
	//	user_str[i].debt[s] = '\0';
	//	k++;
	//	s = 0;
	//	if (chr[k] == ' ')
	//	{
	//		k++;
	//	}

	//	//Getting credit
	//	while (chr[k] != ',' && k != strlen(chr))
	//	{
	//		user_str[i].credit[s] = chr[k];
	//		s++;
	//		k++;
	//	}
	//	user_str[i].credit[s] = '\0';
	//	k++;
	//	s = 0;
	//	if (chr[k] == ' ')
	//	{
	//		k++;
	//	}
	//	printf_s( "%s , %s , %s , %s , %s , %s", user_str[J].surname, user_str[J].phone, user_str[J].startContract, user_str[J].finishContract, user_str[J].debt, user_str[J].credit);
	//	k = 0;
	//}

		fclose(userList);
		menu();
	
}


void splitDateStartContract(int J)
{
	char sep[SIZE] = ".";
	char *istr;
	istr = strtok(user_str[J].startContract, sep);
	while (istr != NULL)
	{
	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0: strcpy(start_contract[J].day, istr); break;
		case 1: strcpy(start_contract[J].month, istr); break;
		case 2: strcpy(start_contract[J].year, istr); break;

		}
		istr = strtok(NULL, sep);
	}
	}
}

void splitDateFinishContract(int J)
{
	char sep[SIZE] = ".";
	char *istr;
	istr = strtok(user_str[J].finishContract, sep);
	while (istr != NULL)
	{
		for (int i = 0; i < 3; i++)
		{
			switch (i)
			{
			case 0: strcpy(finish_contract[J].day, istr); break;
			case 1: strcpy(finish_contract[J].month, istr); break;
			case 2: strcpy(finish_contract[J].year, istr); break;

			}
			istr = strtok(NULL, sep);
		}
		printf("%s", finish_contract[J].month);
	}
}

void readFileServicesList(void)
{
		FILE *servicesList;
		servicesList = fopen("servicesList.txt", "r");
		services str;
		if (servicesList == NULL)
			printf("Файл с услугами не найден");
		else
		{
			for (int j = 0; j < 10; j++)
			{
				int n[100];
				for (int q = 0; q < 99; q++)
				{
					n[q] = n[99];
				}
				int k = 0;
				char str[SIZE];
				for (int w = 0; w < strlen(fgets(str, sizeof(str), servicesList)); w++)
				{
					if (str[w] == ','|| w == 0)
					{
						if (str[w] == ',')
						{
							n[k] = w - 1;
							k++;
							n[k] = w + 1;
							k++;
						}
						else
						{
							n[k] = w;
							k++;
						}
					}
				}
				int count = 0;
				for (int t = 0; t<8; t = t + 2) 
				{
					for (int e = n[t]; e <= n[t + 1]; e++)
					{
						if (count == 0)
						{
							*services_str[j].linkName += str[e];
						}
						if (count == 1)
						{
							*services_str[j].code += str[e];
						}
						if (count == 2)
						{
							*services_str[j].time += str[e];
						}
						if (count == 3)
						{
							*services_str[j].codeSec += str[e];
						}
						printf("%s , %d , %f , %s", services_str[j].linkName, services_str[j].code, services_str[j].codeSec);
					}
					count++;
				}
			}
	}
	fclose(servicesList);
}

void readFileUseUserList(void)
{
	FILE *useUserList;
	useUserList = fopen("useUserList.txt", "r");
	fscanf(useUserList, "%s , %d , %s , %s , %s", useUser_str[J].phone, useUser_str[J].codeServices, useUser_str[J].dateUse, useUser_str[J].timeUse, useUser_str[J].duration);

	fclose(useUserList);
}

void printFile()
{
	FILE *printUserList, *printServicesList, *printUseUserList;
	printUserList = fopen("printUserList.txt", "w");
	printServicesList = fopen("printServicesList.txt", "w");
	printUseUserList = fopen("printUseUserList.txt", "w");

	for (J = 0; J < 2; J++)
	{
		fprintf_s(printUserList, "%s %s %s , %s , %s , %s , %s , %s", user_str[J].surname, user_str[J].name, user_str[J].patronymic, user_str[J].phone, user_str[J].startContract, user_str[J].finishContract, user_str[J].debt, user_str[J].credit);
		
	}
	fclose(printUserList);
	fclose(printServicesList);
	fclose(printUseUserList);
	menu();
}

void calculations(void)
{
}

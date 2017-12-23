#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <string> 
#include <time.h> 
#include <windows.h> 

#define SIZE 256 

struct Aminities_st {
	char name[1000];
	char code[1000];
	char price[1000];
	char points[1000];

};

struct Used_aminities_st {
	char t_number[11];
	char code[1000];
	char date[1000];
	char time[1000];
	char time_of_using[1000];
	int converted_time_of_using;
	int count = 0;
};

struct Clients_st {
	char name[1000];
	char t_number[11];
	char date_s[11];
	char date_e[11];
	char bill[1000];
	char credit[1000];
	int count;
};

struct options {
	char name[1000];
	char date_1[1000];
	char date_2[1000];
};

struct Date {
	int dayS;
	int monthS;
	int yearS;
	int dayE;
	int monthE;
	int yearE;
};


int fileNotExist(FILE *clients, FILE *aminities, FILE *used_aminities, FILE *report);
void fillClients(Clients_st *people, FILE *clients);
void fillAminities(Aminities_st *amin, FILE *aminities);
void fillUsedAminities(Used_aminities_st *used_amin, FILE *used_aminities);
void fillData(Clients_st *people, Aminities_st *amin, Used_aminities_st *used_amin, FILE *clients, FILE *aminities, FILE *used_aminities);
void alignment(char *a, char *b);
int CharToInt32(char *x);
int compare(char *a, char *b);
int compareOfDate(char *a, char *b);
int dateInterval(char *dS, char *d, char *dE);
void Report(char *name, char *dtS, char *dtE, Clients_st *clients, Aminities_st *aminities, Used_aminities_st *used_aminities, FILE *report);

int main() {
	system("chcp 1251");
	system("cls");

	FILE *clients = NULL;
	FILE *aminities = NULL;
	FILE *used_aminities = NULL;
	FILE *report = NULL;

	clients = fopen("Clients.txt", "r");
	aminities = fopen("Aminities.txt", "r");
	used_aminities = fopen("Used_aminities.txt", "r");
	report = fopen("Report.txt", "w");

	if (fileNotExist(clients, aminities, used_aminities, report)) {
		return 0;
	}

	struct Clients_st people[10];
	struct Aminities_st amin[50];
	struct Used_aminities_st used_amin[50];
	struct options options = { "", "" };
	struct Date dt;

	fillData(people, amin, used_amin, clients, aminities, used_aminities);

	fclose(clients);
	fclose(aminities);
	fclose(used_aminities);

	printf("Введите ФИО клиента : ");
	fgets(options.name, SIZE, stdin);
	options.name[strlen(options.name) - 1] = '\0';
	printf("\nВведите начальную дату : ");
	scanf("%s", options.date_1);
	printf("\nВведите конечную дату : ");
	scanf("%s", options.date_2);

	Report(options.name, options.date_1, options.date_2, people, amin, used_amin, report);

	fclose(report);
	return 0;
}

/*Проверка наличия файлов*/
int fileNotExist(FILE *clients, FILE *aminities, FILE *used_aminities, FILE *report) {
	if (clients == NULL || aminities == NULL || used_aminities == NULL || report == NULL) {
		printf("Один из файлов не был найден!\n\n");
		return true;
	}
}

/*Заполнение данных о клиентах*/
void fillClients(Clients_st *people, FILE *clients) {
	char chr[1000];
	int k = 0, s = 0, sch = 0;
	while (!feof(clients)) {
		fgets(chr, 1000, clients);
		if (!feof(clients))
		{
			chr[strlen(chr) - 1] = ',';
		}
		//Getting name 
		while (chr[k] != ',')
		{
			people[sch].name[k] = chr[k];
			k++;
		}
		people[sch].name[k] = '\0';
		k++;
		if (chr[k] == ' ')
		{
			k++;
		}
		//Getting telephone number 
		while (chr[k] != ',')
		{
			people[sch].t_number[s] = chr[k];
			k++;
			s++;
		}
		people[sch].t_number[s] = '\0';
		k++;
		s = 0;

		//Getting date of starting deal 
		while (chr[k] != ',')
		{
			people[sch].date_s[s] = chr[k];
			s++;
			k++;
		}
		people[sch].date_s[s] = '\0';
		k++;
		s = 0;
		if (chr[k] == ' ')
		{
			k++;
		}

		//Getting date of ending deal 
		while (chr[k] != ',')
		{
			people[sch].date_e[s] = chr[k];
			s++;
			k++;
		}
		people[sch].date_e[s] = '\0';
		k++;
		s = 0;
		if (chr[k] == ' ')
		{
			k++;
		}

		//Getting bill 
		while (chr[k] != ',')
		{
			people[sch].bill[s] =
				chr[k];
			s++;
			k++;
		}
		people[sch].bill[s] = '\0';
		k++;
		s = 0;
		if (chr[k] == ' ')
		{
			k++;
		}

		//Getting credit 
		while (chr[k] != ',' && k != strlen(chr))
		{
			people[sch].credit[s] = chr[k];
			s++;
			k++;
		}
		people[sch].credit[s] = '\0';
		k++;
		s = 0;
		if (chr[k] == ' ')
		{
			k++;
		}
		sch++;
		k = 0;
	}
	people[1].count = sch;
}

/*Заполнение данных об услугах*/
void fillAminities(Aminities_st *amin, FILE *aminities) {
	char rd[1000], chr[1001];
	int k = 0, s = 0, sch = 0;
	while (!feof(aminities)) {
		fgets(rd, 1000, aminities);
		strcpy(chr, rd);
		if (!feof(aminities)) {
			chr[strlen(rd) - 1] = ',';
		}

		//Getting name 
		while (chr[k] != ',') {
			amin[sch].name[k] = chr[k];
			k++;
		}
		amin[sch].name[k] = '\0';
		k++;
		if (chr[k] == ' ') {
			k++;
		}

		//Getting code 
		while (chr[k] != ',') {
			amin[sch].code[s] = chr[k];
			k++;
			s++;
		}
		amin[sch].code[s] = '\0';
		k++;
		if (chr[k] == ' ') {
			k++;
		}
		s = 0;

		//Getting price 
		while (chr[k] != ',') {
			amin[sch].price[s] = chr[k];
			k++;
			s++;
		}
		amin[sch].price[s] = '\0';
		k++;
		if (chr[k] == ' ') {
			k++;
		}
		s = 0;

		//Getting points 
		while (chr[k] != ',') {
			amin[sch].points[s] = chr[k];
			k++;
			s++;
		}
		amin[sch].points[s] = '\0';
		s = 0;
		sch++;
		k = 0;
	}
}

/*Заполнение данных об использованных услугах*/
void fillUsedAminities(Used_aminities_st *used_amin, FILE *used_aminities) {
	char rd[1000], chr[1001];
	int k = 0, s = 0, sch = 0;
	while (!feof(used_aminities)) {
		fgets(rd, 1000, used_aminities);
		strcpy(chr, rd);
		if (!feof(used_aminities)) {
			chr[strlen(rd) - 1] = ',';
		}

		//Getting telephone number 
		while (chr[k] != ',') {
			used_amin[sch].t_number[k] = chr[k];
			k++;
		}
		used_amin[sch].t_number[k] = '\0';
		k++;
		if (chr[k] == ' ') {
			k++;
		}

		//Getting code 
		while (chr[k] != ',') {
			used_amin[sch].code[s] = chr[k];
			k++;
			s++;
		}
		used_amin[sch].code[s] = '\0';
		k++;
		s = 0;
		if (chr[k] == ' ') {
			k++;
		}

		//Getting date 
		while (chr[k] != ',') {
			used_amin[sch].date[s] = chr[k];
			k++;
			s++;
		}
		used_amin[sch].date[s] = '\0';
		s = 0;
		k++;
		if (chr[k] == ' ') {
			k++;
		}

		//Getting time 
		while (chr[k] != ',') {
			used_amin[sch].time[s] = chr[k];
			k++;
			s++;
		}
		used_amin[sch].time[s] = '\0';
		s = 0;
		k++;
		if (chr[k] == ' ') {
			k++;
		}

		//Getting time of using 
		while (chr[k] != ',') {
			used_amin[sch].time_of_using[s] = chr[k];
			s++;
			k++;
		}
		used_amin[sch].time_of_using[s] = '\0';
		s = 0;
		k++;
		if (chr[k] == ' ') {
			k++;
		}
		k = 0;
		sch++;
		used_amin[1].count++;
	}
}

/*Заполнение структур из трех файлов*/
void fillData(Clients_st *people, Aminities_st *amin, Used_aminities_st *used_amin, FILE *clients, FILE *aminities, FILE *used_aminities) {
	fillClients(people, clients);
	fillAminities(amin, aminities);
	fillUsedAminities(used_amin, used_aminities);
	printf("Данные были загружены\n\n");
}

/*Приравнивание первой строки ко второй*/
void alignment(char *a, char *b) {
	int len = strlen(b);
	for (int i = 0; i < len; i++) {
		a[i] = b[i];
	}
	a[len] = '\0';
}

/*Преобразование строки в число*/
int CharToInt32(char *x) {
	if (x != "#") {
		int len = strlen(x), razr = 1, res = 0;
		for (int i = 0; i < len - 1; i++) {
			razr *= 10;
		}

		for (int i = 0; i < len; i++) {
			switch (x[i]) {
			case '1': {res += razr; razr /= 10; break; }
			case '2': {res += 2 * razr; razr /= 10; break; }
			case '3': {res += 3 * razr; razr /= 10; break; }
			case '4': {res += 4 * razr; razr /= 10; break; }
			case '5': {res += 5 * razr; razr /= 10; break; }
			case '6': {res += 6 * razr; razr /= 10; break; }
			case '7': {res += 7 * razr; razr /= 10; break; }
			case '8': {res += 8 * razr; razr /= 10; break; }
			case '9': {res += 9 * razr; razr /= 10; break; }
			case '0': {razr /= 10; break; }
			}
		}
		return res;
	}
	else {
		return 0;
	}
}

/*Сравнивание строк*/
int compare(char *a, char *b) {
	if (strlen(a) == strlen(b)) {
		for (int i = 0; i < strlen(a); i++) {
			if (a[i] != b[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

/*Сравнивание двух дат*/
int compareOfDate(char *a, char *b) {
	char daysA[3] = { a[0], a[1], '\0' }, monthsA[3] = { a[3], a[4], '\0' }, yearsA[5] = { a[6], a[7], a[8], a[9], '\0' };
	char daysB[3] = { b[0], b[1], '\0' }, monthsB[3] = { b[3], b[4], '\0' }, yearsB[5] = { b[6], b[7], b[8], b[9], '\0' };

	int daysAI = CharToInt32(daysA), monthsAI = CharToInt32(monthsA), yearsAI = CharToInt32(yearsA);
	int daysBI = CharToInt32(daysB), monthsBI = CharToInt32(monthsB), yearsBI = CharToInt32(yearsB);

	if (yearsAI != yearsBI) {
		if (yearsAI > yearsBI) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (monthsAI != monthsBI) {
			if (monthsAI > monthsBI) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			if (daysAI > daysBI) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

/*Проверка интервала*/
int dateInterval(char *dS, char *d, char *dE) {
	if (compareOfDate(d, dS) && compareOfDate(dE, d)) {
		return true;
	}
	else {
		return false;
	}
}

/*Запись результата в файл*/
void Report(char *name, char *dtS, char *dtE, Clients_st *clients, Aminities_st *aminities, Used_aminities_st *used_aminities, FILE *report) {
	char number[11];
	for (int i = 0; i < clients[1].count; i++) {
		if (compare(clients[i].name, name)) {
			alignment(number, clients[i].t_number);
			break;
		}
	}

	for (int i = 0; i < used_aminities[1].count; i++) {
		if (compare(used_aminities[i].t_number, number) && dateInterval(dtS, used_aminities[i].date, dtE)) {
			fprintf(report, "%s was using aminity with code %s by %s.\n", name, used_aminities[i].code, used_aminities[i].date);
		}
	}
}
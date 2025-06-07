#define _CRT_SECURE_NO_WARNINGS
#define ROOM_WIDTH	10
#define HME_POS	1
#define BWL_POS (ROOM_WIDTH -2)
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

int main(void) {
	int soup = 0;
	int relationship = 2;
	printf("****�߿��̿ͼ���****\n\n");
	printf("  /\\   /\\_/\\ \n");
	printf(" //\\\\ / o o \\ \n");
	printf("// \\\\ \\~(*)~/ \n");
	printf("`  \\  /  ^ / \n");
	printf("    | \\|| || \n");
	printf("    \\ '|| || \n");
	printf("     \\)()-()) \n");
	printf("�߿��� �̸��� �Է����ּ���: ");
	char str[100];
	scanf("%s", str);
	printf("�߿��� �̸��� %s �Դϴ�.", str);
	Sleep(1000);
	int interaction;
	int r;
	int cat = 1;
	int beforeCat;
	system("cls");
	while (1) {
		printf("==================== �������===================\n��������������: %d��\n������ǰ���(0~4): %d\n", soup, relationship);
		switch (relationship)
		{
		case 0:

			printf("�翡 ���� ������ �Ⱦ��մϴ�.\n==================================================\n\n");
			break;

		case 1:

			printf("�������Ǳ� ����Դϴ�.\n==================================================\n\n");
			break;


		case 2:

			printf("�׷����� �� ���� �����Դϴ�.\n==================================================\n\n");
			break;


		case 3:

			printf("�Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n==================================================\n\n");
			break;


		case 4:

			printf("���� �������Դϴ�.\n==================================================\n\n");
			break;

		}
		printf("%s �̵�: ����� ģ���Ҽ��� ���� ������ �� Ȯ���� �������ϴ�.\n�ֻ��� ���� %d �̻��̸� ���� ������ �̵��մϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n", str, (6 - relationship));
		r = rand() % 6 + 1;
		printf("%d��(��) ���Խ��ϴ�.\n", r);
		if (r >= (6 - relationship)) {
			printf("���� ������ �����Դϴ�.\n");

			beforeCat = cat;
			cat++;
			if (cat > BWL_POS) {
				cat = BWL_POS;
			}
		}
		else {
			printf("�� ������ �����Դϴ�.\n");

			beforeCat = cat;
			cat--;
			if (cat < HME_POS) cat = HME_POS;
		}
		if (cat == HME_POS) printf("%s��(��) �ڽ��� ������ ������� �����ϴ�.\n", str);
		if (cat == BWL_POS) {
			r = rand() % 2;
			switch (r)
			{
			case 0:
				printf("%s��(��) ���� ������ ��������ϴ�!\n", str);
				break;
			case 1:
				printf("%s��(��) ����� ������ ��������ϴ�!\n", str);
				break;
			case 2:
				printf("%s��(��) ����ݸ� ������ ��������ϴ�!\n", str);
				break;
			}
			soup++;
		}
		for (int i = 0; i < ROOM_WIDTH; i++)printf("#");
		printf("\n");

		for (int i = 0; i < ROOM_WIDTH; i++)
		{
			if (i == 0 || i == ROOM_WIDTH - 1) printf("#");
			else if (i == HME_POS)printf("H");
			else if (i == BWL_POS)printf("B");
			else printf(" ");

		}
		printf("\n");
		for (int i = 0; i < ROOM_WIDTH; i++)
		{
			if (i == 0 || i == ROOM_WIDTH - 1) printf("#");
			else if (i == cat) printf("C");
			else if (i == beforeCat) printf(".");
			else printf(" ");
		}
		printf("\n");

		for (int i = 0; i < ROOM_WIDTH; i++) printf("#");
		printf("\n\n");

		printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?    0. �ƹ��͵� ���� ����  1. �ܾ��ֱ�\n>>");
		scanf_s("%d", &interaction);
		if (interaction == 0) {
			printf("�ƹ��͵� ���� �ʾҽ��ϴ�.\n4/6�� Ȯ���� ģ�е��� �������ϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n");
			r = rand() % 6 + 1;
			printf("%d��(��) ���Խ��ϴ�.\n", r);
			if (r <= 4) {
				printf("ģ�е��� �������ϴ�.\n");
				relationship--;
				printf("���� ģ�е�: %d", relationship);
				if (relationship < 0) {
					relationship = 0;
				}
			}
			else {
				printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n");
				printf("���� ģ�е�: %d", relationship);
			}
		}
		else
		{
			printf("%s�� ���� �ܾ��־����ϴ�.\n2/6�� Ȯ���� ģ�е��� �������ϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n", str);
			r = rand() % 6 + 1;
			printf("%d��(��) ���Խ��ϴ�.\n", r);
			if (r <= 5) {
				printf("ģ�е��� �������ϴ�.\n");
				relationship++;
				if (relationship > 4) {
					relationship = 4;
				}
				printf("���� ģ�е�: %d", relationship);

			}
			else {
				printf("ģ�е��� �״�� �Դϴ�.\n");
				printf("���� ģ�е�: %d", relationship);
			}
		}
		Sleep(2500);
		system("cls");

	}
	return 0;
}
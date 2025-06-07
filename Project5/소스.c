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
	int mood = 3; 
	int cp = 0;   
	int hasScratcher = 0;
	int hasTower = 0;
	int scratcherPos = -1;
	int towerPos = -1;
	int hasToyMouse = 0;
	int hasLaser = 0;
	system("cls");
	while (1) {
		printf("==================== �������===================\n��������������: %d��\nCP : %d ����Ʈ\n   %s�� ���(0~3): %d\n", soup,cp ,str, mood);
		switch (mood) {
		case 0:
			printf("����� �ſ� ���޴ϴ�.\n");
			break;
		case 1:
			printf("�ɽ����մϴ�.\n");
			break;
		case 2:
			printf("�Ļ��� �����ϴ�.\n");
			break;
		case 3:
			printf("������ �θ��ϴ�.\n");
			break;
		}
		printf("������� ����(0~4): %d\n", relationship);
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
		printf("\n6-2: �ֻ��� ���� 4�����̸� �׳� ����� �������ϴ�.\n");
		printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
		r = rand() % 6 + 1;
		printf("%d��(��) ���Խ��ϴ�.\n", r);
		if (r <= (6 - relationship)) {
			printf("%s�� ����� �������ϴ�: %d -> ", str, mood);
			mood--;
			if (mood < 0) mood = 0;
			printf("%d\n", mood);
		}
		else {
			printf("������ ����� �������� �ʾҽ��ϴ�.\n");
		}
		Sleep(1500);
		beforeCat = cat;
		if (mood == 0) {
			printf("����� �ſ� ���� %s��(��) ������ ���մϴ�.\n", str);
			if (cat > HME_POS) cat--;
			else printf("%s��(��) ���� ������ ������ �ֽ��ϴ�.\n", str);
		}
		else if (mood == 1) {
			
			if (!hasScratcher && !hasTower) {
				printf("�� �Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
				mood--;
				if (mood < 0) mood = 0;
			}
			else {
				
				int target = -1;
				if (hasScratcher && hasTower) {
					int distS = abs(cat - scratcherPos);
					int distT = abs(cat - towerPos);
					target = (distS <= distT) ? scratcherPos : towerPos;
				}
				else if (hasScratcher) {
					target = scratcherPos;
				}
				else {
					target = towerPos;
				}

				if (cat < target) cat++;
				else if (cat > target) cat--;

				printf("%s��(��) �ɽ��ؼ� ���̱ⱸ ������ �̵��մϴ�.\n", str);
			}
		}
		else if (mood == 2) {
			printf("%s��(��) ������� �Ļ��� ���� �ֽ��ϴ�.\n", str);
			
		}
		else if (mood == 3) {
			printf("%s��(��) ������ �θ��� ������ ���鷯 ���ϴ�.\n", str);
			if (cat < BWL_POS) cat++;
			else printf("%s��(��) �̹� ���� �տ� �ֽ��ϴ�.\n", str);
		}
		if (cat == HME_POS && beforeCat == HME_POS) {
			printf("%s��(��) ������ ����� ���ϴ�.\n", str);
			if (mood < 3) {
				mood++;
				printf("����� ���� ���������ϴ�: %d -> %d\n", mood - 1, mood);
			}
		}
		else if (cat == BWL_POS) {
			r = rand() % 3;
			switch (r) {
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
		else if (cat == scratcherPos) {
			if (mood < 3) {
				mood++;
				printf("%s��(��) ��ũ��ó�� �ܰ� ��ҽ��ϴ�.\n����� ���� ���������ϴ�: %d -> %d\n", str, mood - 1, mood);
			}
		}
		else if (cat == towerPos) {
			int before = mood;
			mood += 2;
			if (mood > 3) mood = 3;
			printf("%s��(��) ĹŸ���� �پ�ٴմϴ�.\n����� ���� ���������ϴ�: %d -> %d\n", before, mood);
		}
		for (int i = 0; i < ROOM_WIDTH; i++) printf("#");
		printf("\n");

		for (int i = 0; i < ROOM_WIDTH; i++) {
			if (i == 0 || i == ROOM_WIDTH - 1) printf("#");
			else if (i == HME_POS) printf("H");
			else if (i == BWL_POS) printf("B");
			else printf(" ");
		}
		printf("\n");

		for (int i = 0; i < ROOM_WIDTH; i++) {
			if (i == 0 || i == ROOM_WIDTH - 1) printf("#");
			else if (i == cat) printf("C");
			else if (i == beforeCat) printf(".");
			else printf(" ");
		}
		printf("\n");

		for (int i = 0; i < ROOM_WIDTH; i++) printf("#");
		printf("\n\n");

		int option = 1;
		printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n");
		printf("0. �ƹ��͵� ���� ����\n");
		printf("1. �ܾ��ֱ�\n");
		if (hasToyMouse) {
			printf("%d. �峭�� ��� ��� �ֱ�\n", option + 1);
		}
		if (hasLaser) {
			printf("%d. ������ �����ͷ� ��� �ֱ�\n", option + (hasToyMouse ? 2 : 1));
		}
		printf(">> ");
		int interaction;
		scanf("%d", &interaction);

		// �Է� ���� ó��
		int maxOption = 1 + hasToyMouse + hasLaser;
		while (interaction < 0 || interaction > maxOption) {
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���:\n>> ");
			scanf("%d", &interaction);
		}

		// ��ȣ�ۿ� ó��
		if (interaction == 0) {
			printf("�ƹ��͵� ���� �ʾҽ��ϴ�.\n");
			mood--;
			if (mood < 0) mood = 0;
			printf("����� ���������ϴ�: %d\n", mood);
			r = rand() % 6 + 1;
			printf("�ֻ����� �����ϴ�... %d\n", r);
			if (r <= 5) {
				relationship--;
				if (relationship < 0) relationship = 0;
				printf("������� ���谡 ���������ϴ�: %d\n", relationship);
			}
			else {
				printf("������ ����� �״���Դϴ�.\n");
			}
		}
		else if (interaction == 1) {
			printf("%s�� ���� �ܾ��־����ϴ�.\n", str);
			r = rand() % 6 + 1;
			printf("�ֻ����� �����ϴ�... %d\n", r);
			if (r >= 5) {
				relationship++;
				if (relationship > 4) relationship = 4;
				printf("������� ���谡 ���� ���������ϴ�: %d\n", relationship);
			}
			else {
				printf("����� �״���Դϴ�.\n");
			}
		}
		else if (interaction == 2 && hasToyMouse) {
			printf("�峭�� ��� %s�� ��� �־����ϴ�.\n", str);
			mood++;
			if (mood > 3) mood = 3;
			printf("����� ���� ���������ϴ�: %d\n", mood);
			r = rand() % 6 + 1;
			printf("�ֻ����� �����ϴ�... %d\n", r);
			if (r >= 4) {
				relationship++;
				if (relationship > 4) relationship = 4;
				printf("������� ���谡 ���������ϴ�: %d\n", relationship);
			}
			else {
				printf("����� �״���Դϴ�.\n");
			}
		}
		else {
			printf("������ �����ͷ� %s�� �ų��� ��� �־����ϴ�.\n", str);
			mood += 2;
			if (mood > 3) mood = 3;
			printf("����� �� ���������ϴ�: %d\n", mood);
			r = rand() % 6 + 1;
			printf("�ֻ����� �����ϴ�... %d\n", r);
			if (r >= 2) {
				relationship++;
				if (relationship > 4) relationship = 4;
				printf("������� ���谡 ���������ϴ�: %d\n", relationship);
			}
			else {
				printf("����� �״���Դϴ�.\n");
			}
		}
		Sleep(2500);
		system("cls");

	}
	return 0;
}
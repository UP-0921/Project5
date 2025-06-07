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
	printf("****야옹이와수프****\n\n");
	printf("  /\\   /\\_/\\ \n");
	printf(" //\\\\ / o o \\ \n");
	printf("// \\\\ \\~(*)~/ \n");
	printf("`  \\  /  ^ / \n");
	printf("    | \\|| || \n");
	printf("    \\ '|| || \n");
	printf("     \\)()-()) \n");
	printf("야옹이 이름을 입력해주세요: ");
	char str[100];
	scanf("%s", str);
	printf("야옹이 이름은 %s 입니다.", str);
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

	system("cls");
	while (1) {
		printf("==================== 현재상태===================\n현재까지만든수프: %d개\nCP : %d 포인트\n   %s의 기분(0~3): %d\n", soup,cp ,str, mood);
		switch (mood) {
		case 0:
			printf("기분이 매우 나쁩니다.\n");
			break;
		case 1:
			printf("심심해합니다.\n");
			break;
		case 2:
			printf("식빵을 굽습니다.\n");
			break;
		case 3:
			printf("골골송을 부릅니다.\n");
			break;
		}
		printf("집사와의 관계(0~4): %d\n", relationship);
		switch (relationship)
		{
		case 0:

			printf("곁에 오는 것조차 싫어합니다.\n==================================================\n\n");
			break;

		case 1:

			printf("간식자판기 취급입니다.\n==================================================\n\n");
			break;


		case 2:

			printf("그럭저럭 쓸 만한 집사입니다.\n==================================================\n\n");
			break;


		case 3:

			printf("훌륭한 집사로 인정 받고 있습니다.\n==================================================\n\n");
			break;


		case 4:

			printf("집사 껌딱지입니다.\n==================================================\n\n");
			break;

		}
		printf("\n6-2: 주사위 눈이 4이하이면 그냥 기분이 나빠집니다.\n");
		printf("주사위를 굴립니다. 또르륵...\n");
		r = rand() % 6 + 1;
		printf("%d이(가) 나왔습니다.\n", r);
		if (r <= (6 - relationship)) {
			printf("%s의 기분이 나빠집니다: %d -> ", str, mood);
			mood--;
			if (mood < 0) mood = 0;
			printf("%d\n", mood);
		}
		else {
			printf("다행히 기분이 나빠지지 않았습니다.\n");
		}
		Sleep(1500);
		beforeCat = cat;
		if (mood == 0) {
			printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n", str);
			if (cat > HME_POS) cat--;
			else printf("%s은(는) 집에 도착해 가만히 있습니다.\n", str);
		}
		else if (mood == 1) {
			
			if (!hasScratcher && !hasTower) {
				printf("놀 거리가 없어서 기분이 매우 나빠집니다.\n");
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

				printf("%s은(는) 심심해서 놀이기구 쪽으로 이동합니다.\n", str);
			}
		}
		else if (mood == 2) {
			printf("%s은(는) 기분좋게 식빵을 굽고 있습니다.\n", str);
			
		}
		else if (mood == 3) {
			printf("%s은(는) 골골송을 부르며 수프를 만들러 갑니다.\n", str);
			if (cat < BWL_POS) cat++;
			else printf("%s은(는) 이미 냄비 앞에 있습니다.\n", str);
		}
		if (cat == HME_POS) printf("%s은(는) 자신의 집에서 편안함을 느낍니다.\n", str);
		if (cat == BWL_POS) {
			r = rand() % 2;
			switch (r)
			{
			case 0:
				printf("%s은(는) 감자 수프를 만들었습니다!\n", str);
				break;
			case 1:
				printf("%s은(는) 양송이 수프를 만들었습니다!\n", str);
				break;
			case 2:
				printf("%s은(는) 브로콜리 수프를 만들었습니다!\n", str);
				break;
			}
			soup++;
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

		printf("어떤 상호작용을 하시겠습니까?    0. 아무것도 하지 않음  1. 긁어주기\n>>");
		scanf_s("%d", &interaction);
		if (interaction == 0) {
			printf("아무것도 하지 않았습니다.\n4/6의 확률로 친밀도가 떨어집니다.\n주사위를 굴립니다. 또르륵...\n");
			r = rand() % 6 + 1;
			printf("%d이(가) 나왔습니다.\n", r);
			if (r <= 4) {
				printf("친밀도가 떨어집니다.\n");
				relationship--;
				printf("현재 친밀도: %d", relationship);
				if (relationship < 0) {
					relationship = 0;
				}
			}
			else {
				printf("다행히 친밀도가 떨어지지 않았습니다.\n");
				printf("현재 친밀도: %d", relationship);
			}
		}
		else
		{
			printf("%s의 턱을 긁어주었습니다.\n2/6의 확률로 친밀도가 높아집니다.\n주사위를 굴립니다. 또르륵...\n", str);
			r = rand() % 6 + 1;
			printf("%d이(가) 나왔습니다.\n", r);
			if (r <= 5) {
				printf("친밀도가 높아집니다.\n");
				relationship++;
				if (relationship > 4) {
					relationship = 4;
				}
				printf("현재 친밀도: %d", relationship);

			}
			else {
				printf("친밀도는 그대로 입니다.\n");
				printf("현재 친밀도: %d", relationship);
			}
		}
		Sleep(2500);
		system("cls");

	}
	return 0;
}
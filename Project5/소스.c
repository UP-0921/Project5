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
	int hasToyMouse = 0;
	int hasLaser = 0;
	int buyChoice;
	int turn = 0;
	system("cls");
	system("cls");
	while (1) {
		printf("==================== 현재상태===================\n현재까지만든수프: %d개\nCP : %d 포인트\n   %s의 기분(0~3): %d\n", soup, cp, str, mood);
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
		if (cat == HME_POS && beforeCat == HME_POS) {
			printf("%s은(는) 집에서 편안히 쉽니다.\n", str);
			if (mood < 3) {
				mood++;
				printf("기분이 조금 좋아졌습니다: %d -> %d\n", mood - 1, mood);
			}
		}
		else if (cat == BWL_POS) {
			r = rand() % 3;
			switch (r) {
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
		else if (cat == scratcherPos) {
			if (mood < 3) {
				mood++;
				printf("%s은(는) 스크래처를 긁고 놀았습니다.\n기분이 조금 좋아졌습니다: %d -> %d\n", str, mood - 1, mood);
			}
		}
		else if (cat == towerPos) {
			int before = mood;
			mood += 2;
			if (mood > 3) mood = 3;
			printf("%s은(는) 캣타워를 뛰어다닙니다.\n기분이 제법 좋아졌습니다: %d -> %d\n", before, mood);
		}
		for (int i = 0; i < ROOM_WIDTH; i++) printf("#");
		printf("\n");
		for (int i = 0; i < ROOM_WIDTH; i++) {
			if (i == 0 || i == ROOM_WIDTH - 1) printf("#");
			else if (i == HME_POS) printf("H");
			else if (i == BWL_POS) printf("B");
			else if (i == scratcherPos) printf("S");
			else if (i == towerPos) printf("T");
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
		printf("어떤 상호작용을 하시겠습니까?\n");
		printf("0. 아무것도 하지 않음\n");
		printf("1. 긁어주기\n");
		if (hasToyMouse) {
			printf("%d. 장난감 쥐로 놀아 주기\n", option + 1);
		}
		if (hasLaser) {
			printf("%d. 레이저 포인터로 놀아 주기\n", option + (hasToyMouse ? 2 : 1));
		}
		printf(">> ");
		int interaction;
		scanf("%d", &interaction);

		int maxOption = 1 + hasToyMouse + hasLaser;
		while (interaction < 0 || interaction > maxOption) {
			printf("잘못된 입력입니다. 다시 입력해주세요:\n>> ");
			scanf("%d", &interaction);
		}

		if (interaction == 0) {
			printf("아무것도 하지 않았습니다.\n");
			mood--;
			if (mood < 0) mood = 0;
			printf("기분이 나빠졌습니다: %d\n", mood);
			r = rand() % 6 + 1;
			printf("주사위를 굴립니다... %d\n", r);
			if (r <= 5) {
				relationship--;
				if (relationship < 0) relationship = 0;
				printf("집사와의 관계가 나빠졌습니다: %d\n", relationship);
			}
			else {
				printf("다행히 관계는 그대로입니다.\n");
			}
		}
		else if (interaction == 1) {
			printf("%s의 턱을 긁어주었습니다.\n", str);
			r = rand() % 6 + 1;
			printf("주사위를 굴립니다... %d\n", r);
			if (r >= 5) {
				relationship++;
				if (relationship > 4) relationship = 4;
				printf("집사와의 관계가 조금 좋아졌습니다: %d\n", relationship);
			}
			else {
				printf("관계는 그대로입니다.\n");
			}
		}
		else if (interaction == 2 && hasToyMouse) {
			printf("장난감 쥐로 %s와 놀아 주었습니다.\n", str);
			mood++;
			if (mood > 3) mood = 3;
			printf("기분이 조금 좋아졌습니다: %d\n", mood);
			r = rand() % 6 + 1;
			printf("주사위를 굴립니다... %d\n", r);
			if (r >= 4) {
				relationship++;
				if (relationship > 4) relationship = 4;
				printf("집사와의 관계가 좋아졌습니다: %d\n", relationship);
			}
			else {
				printf("관계는 그대로입니다.\n");
			}
		}
		else {
			printf("레이저 포인터로 %s와 신나게 놀아 주었습니다.\n", str);
			mood += 2;
			if (mood > 3) mood = 3;
			printf("기분이 꽤 좋아졌습니다: %d\n", mood);
			r = rand() % 6 + 1;
			printf("주사위를 굴립니다... %d\n", r);
			if (r >= 2) {
				relationship++;
				if (relationship > 4) relationship = 4;
				printf("집사와의 관계가 좋아졌습니다: %d\n", relationship);
			}
			else {
				printf("관계는 그대로입니다.\n");
			}
		}

		int gainedCP = (mood > 1 ? mood - 1 : 0) + relationship;
		cp += gainedCP;
		printf("%s의 기분과 친밀도에 따라서 CP가 %d 포인트 생산되었습니다.\n", str, gainedCP);
		printf("보유 CP: %d 포인트\n", cp);
		printf("\n상점에서 물건을 살 수 있습니다.\n어떤 물건을 구매할까요?\n");
		printf("0. 아무 것도 사지 않는다.\n");
		printf("1. 장난감 쥐: 1 CP %s\n", hasToyMouse ? "(품절)" : "");
		printf("2. 레이저 포인터: 2 CP %s\n", hasLaser ? "(품절)" : "");
		printf("3. 스크래처: 4 CP %s\n", hasScratcher ? "(품절)" : "");
		printf("4. 캣 타워: 6 CP %s\n", hasTower ? "(품절)" : "");
		printf(">> ");
		scanf("%d", &buyChoice);

		if (buyChoice == 0) {
			break;
		}
		else if (buyChoice == 1) {
			if (hasToyMouse) {
				printf("장난감 쥐는 이미 구매했습니다.\n");
			}
			else if (cp < 1) {
				printf("CP가 부족합니다.\n");
			}
			else {
				hasToyMouse = 1;
				cp -= 1;
				printf("장난감 쥐를 구매했습니다. 보유 CP: %d 포인트\n", cp);
			}
		}
		else if (buyChoice == 2) {
			if (hasLaser) {
				printf("레이저 포인터는 이미 구매했습니다.\n");
			}
			else if (cp < 2) {
				printf("CP가 부족합니다.\n");
			}
			else {
				hasLaser = 1;
				cp -= 2;
				printf("레이저 포인터를 구매했습니다. 보유 CP: %d 포인트\n", cp);
			}
		}
		else if (buyChoice == 3) {
			if (hasScratcher) {
				printf("스크래처는 이미 구매했습니다.\n");
			}
			else if (cp < 4) {
				printf("CP가 부족합니다.\n");
			}
			else {
				hasScratcher = 1;
				cp -= 4;

				do {
					scratcherPos = rand() % (ROOM_WIDTH - 2) + 1;
				} while (scratcherPos == HME_POS || scratcherPos == BWL_POS || scratcherPos == towerPos);
				printf("스크래처를 구매했습니다. 위치: %d\n보유 CP: %d 포인트\n", scratcherPos, cp);
			}
		}
		else if (buyChoice == 4) {
			if (hasTower) {
				printf("캣 타워는 이미 구매했습니다.\n");
			}
			else if (cp < 6) {
				printf("CP가 부족합니다.\n");
			}
			else {
				hasTower = 1;
				cp -= 6;
				do {
					towerPos = rand() % (ROOM_WIDTH - 2) + 1;
				} while (towerPos == HME_POS || towerPos == BWL_POS || towerPos == scratcherPos);
				printf("캣 타워를 구매했습니다. 위치: %d\n보유 CP: %d 포인트\n", towerPos, cp);
			}
		}
		else {
			printf("잘못된 입력입니다.\n");
		}
		
		if (turn % 3 == 0) {
			int answer;
			printf("\n🎯 돌발 퀘스트 발생! 🎯\n");
			printf("%s이(가) 방 안에서 수상한 벌레를 발견했습니다!\n", str);
			printf("어떻게 하시겠습니까?\n");
			printf("1. 직접 잡아준다 (집사의 용기 증가)\n");
			printf("2. 고양이에게 맡긴다 (고양이의 기분이 올라갈 수도...?)\n>> ");
			scanf("%d", &answer);
			if (answer == 1) {
				r = rand() % 6 + 1;
				printf("주사위를 굴립니다... %d\n", r);
				if (r >= 4) {
					relationship++;
					if (relationship > 4) relationship = 4;
					printf("용기 있는 집사! 관계가 좋아졌습니다. 관계: %d\n", relationship);
				}
				else {
					printf("벌레를 못 잡아서 오히려 실망했습니다...\n");
					relationship--;
					if (relationship < 0) relationship = 0;
				}
			}
			else if (answer == 2) {
				r = rand() % 6 + 1;
				printf("주사위를 굴립니다... %d\n", r);
				if (r >= 4) {
					mood++;
					if (mood > 3) mood = 3;
					printf("%s이(가) 벌레를 사냥하고 기분이 좋아졌습니다! 기분: %d\n", str, mood);
				}
				else {
					printf("벌레를 놓쳐서 기분이 나빠졌습니다.\n");
					mood--;
					if (mood < 0) mood = 0;
				}
			}
			else {
				printf("잘못된 입력이라서 아무것도 하지 않았습니다. 기분이 나빠졌습니다.\n");
				mood--;
				if (mood < 0) mood = 0;
			}
			Sleep(2500);
			system("cls");

		}
	
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char player_name[17], char_team[300][300][17], char_temp[17];

int main() {
	int player_num, team_num, player_level, int_team[300][300], team_cnt = 0, team_idx[300] = { 0, }, i, j, k, check = 0, int_temp;
	scanf("%d %d", &player_num, &team_num);
	for (i = 0; i < player_num; i++) {
		scanf("%d %s", &player_level, player_name);
		if (i == 0) {
			int_team[0][0] = player_level;
			strcpy(char_team[0][0], player_name);
			team_cnt++;
			team_idx[0]++;
		}
		else {
			for (j = 0; j < team_cnt; j++) {
				int level_gap = int_team[j][0] - player_level;
				if ((level_gap >= -10 && level_gap <= 10) && team_idx[j] < team_num) {
					int_team[j][team_idx[j]] = player_level;
					strcpy(char_team[j][team_idx[j]], player_name);
					team_idx[j]++;
					check = 1;
					break;
				}
			}
			if (check == 0) {
				int_team[team_cnt][0] = player_level;
				strcpy(char_team[team_cnt][0], player_name);
				team_idx[team_cnt]++;
				team_cnt++;
			}
			check = 0;
		}
	}

	for (i = 0; i < team_cnt; i++) {
		for (j = 0; j < team_idx[i]; j++) {
			for (k = j; k < team_idx[i] - 1; k++) {
				if (strcmp(char_team[i][j], char_team[i][k + 1]) > 0) {
					strcpy(char_temp, char_team[i][j]);
					strcpy(char_team[i][j], char_team[i][k + 1]);
					strcpy(char_team[i][k + 1], char_temp);

					int_temp = int_team[i][j];
					int_team[i][j] = int_team[i][k + 1];
					int_team[i][k + 1] = int_temp;
				}
			}
		}
	}

	for (i = 0; i < team_cnt; i++) {
		if (team_idx[i] == team_num) printf("Started!\n");
		else printf("Waiting!\n");
		for (j = 0; j < team_idx[i]; j++)printf("%d %s\n", int_team[i][j], char_team[i][j]);
	}

	return 0;
}

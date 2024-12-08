#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct player {
    int level;
    char name[17];
} Player;

typedef struct room {
    int minlevel, maxlevel, count;
    Player players[300];
} Room;

void addplayerroom(Player player, Room rooms[], int* room_count, int max_players);
void roomstatus(Room room, int max_players);
void sortroom(Room* room);

int main(void) {
    Player player;
    int p, m;
    scanf("%d %d", &p, &m);

    Room rooms[300];
    int room_count = 0;

    for (int i = 0; i < p; i++) {
        scanf("%d %s", &player.level, player.name);
        addplayerroom(player, rooms, &room_count, m);
    }

    for (int i = 0; i < room_count; i++) {
        roomstatus(rooms[i], m);
        sortroom(&rooms[i]);


        for (int j = 0; j < rooms[i].count; j++) {
            printf("%d %s\n", rooms[i].players[j].level, rooms[i].players[j].name);
        }
    }

    return 0;
}

void addplayerroom(Player player, Room rooms[], int* room_count, int max_players) {
    int placed = 0;

    for (int j = 0; j < *room_count; j++) {
        if (rooms[j].count < max_players && rooms[j].minlevel <= player.level && player.level <= rooms[j].maxlevel) {
            rooms[j].players[rooms[j].count] = player;
            rooms[j].count++;
            placed = 1;
            break;
        }
    }

    if (!placed) {
        rooms[*room_count].minlevel = player.level - 10;
        rooms[*room_count].maxlevel = player.level + 10;
        rooms[*room_count].count = 1;
        rooms[*room_count].players[0] = player;
        (*room_count)++;
    }
}

void roomstatus(Room room, int max_players) {
    if (room.count == max_players) {
        printf("Started!\n");
    }
    else {
        printf("Waiting!\n");
    }
}

void sortroom(Room* room) {

    // ¨ù¡¾?? ?¢´¡¤? ??¢¯?
    for (int j = 0; j < room->count - 1; j++) {
        for (int k = j + 1; k < room->count; k++) {
            if (strcmp(room->players[j].name, room->players[k].name) > 0) {
                Player temp = room->players[j];
                room->players[j] = room->players[k];
                room->players[k] = temp;
            }
        }
    }
}
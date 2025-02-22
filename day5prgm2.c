#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SONG_NAME 50

struct Song {
    char name[MAX_SONG_NAME];
    struct Song *next;
};

struct Playlist {
    struct Song *current;
    int size;
};

void initPlaylist(struct Playlist *playlist) {
    playlist->current = NULL;
    playlist->size = 0;
}

void addSong(struct Playlist *playlist, char *songName) {
    struct Song *newSong = (struct Song *)malloc(sizeof(struct Song));
    strcpy(newSong->name, songName);
    
    if (playlist->size == 0) {
        newSong->next = newSong;
        playlist->current = newSong;
    } else {
        newSong->next = playlist->current->next;
        playlist->current->next = newSong;
    }
    playlist->size++;
}

void playNext(struct Playlist *playlist) {
    if (playlist->current != NULL) {
        playlist->current = playlist->current->next;
        printf("Current Song: %s\n", playlist->current->name);
    } else {
        printf("Playlist is empty!\n");
    }
}

void displayCurrent(struct Playlist *playlist) {
    if (playlist->current != NULL) {
        printf("Current Song: %s\n", playlist->current->name);
    } else {
        printf("Playlist is empty!\n");
    }
}

int main() {
    struct Playlist playlist;
    initPlaylist(&playlist);
    char songName[MAX_SONG_NAME];
    int choice;

    while (1) {
        printf("\n1. Add Song\n2. Play Next\n3. Show Current\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter song name: ");
                fgets(songName, MAX_SONG_NAME, stdin);
                songName[strcspn(songName, "\n")] = 0;
                addSong(&playlist, songName);
                break;
            case 2:
                playNext(&playlist);
                break;
            case 3:
                displayCurrent(&playlist);
                break;
            case 4:
                return 0;
        }
    }
}

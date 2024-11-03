#include <raylib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define COLOR_BLACK (Color) {0, 0, 0, 255}
#define COLOR_WHITE (Color) {255, 255, 255, 255}

static char* buffer = NULL;
uint32_t buffer_capacity = 1024;
uint32_t buffer_size = 0;

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1280, 720, "My Text Editor");
    SetTargetFPS(60);

    buffer = malloc(sizeof(char) * buffer_capacity);
    assert(buffer != NULL);
    buffer[buffer_size++] = '\0';

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_A)) {
            buffer[buffer_size - 1] = 'A';
            buffer[buffer_size++] = '\0';
        }

        if (IsKeyPressedRepeat(KEY_A)) {
            buffer[buffer_size - 1] = 'A';
            buffer[buffer_size++] = '\0';
        }

        BeginDrawing();
        ClearBackground(COLOR_BLACK);
        DrawText(buffer, 0, 0, 20, COLOR_WHITE);
        EndDrawing();
    }

    return 0;
}

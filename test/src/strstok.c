#include <stdio.h>
#include <string.h>

char *my_strtok(char *str, const char *delim) {
    static char *next = NULL; // Biến tĩnh giữ vị trí tiếp theo
    if (str != NULL) {
        next = str;
    }

    if (next == NULL) {
        return NULL;
    }

    // Bỏ qua ký tự phân tách đầu tiên
    while (*next && strchr(delim, *next)) {
        next++;
    }

    if (*next == '\0') {
        return NULL;
    }

    char *start = next;

    // Tìm kết thúc token
    while (*next && !strchr(delim, *next)) {
        next++;
    }

    if (*next) {
        *next = '\0';     // Kết thúc token
        next++;           // Di chuyển đến ký tự tiếp theo
    } else {
        next = NULL;
    }

    // In ra địa chỉ biến tĩnh (để quan sát)
    printf("[DEBUG] next = %p\n", next);

    return start;
}

int main() {
    char str[] = "A,B,C";
    char *token = my_strtok(str, ",");  // "A"
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = my_strtok(NULL, ",");
    }
    return 0;
}

#include "StrList.h"
#include <stdio.h>
#include <string.h>

struct _StrList {
    char** data;
    size_t size;
    size_t capacity;
};

#define INITIAL_CAPACITY 10

StrList* StrList_alloc() {
    StrList* list = (StrList*)malloc(sizeof(StrList));
    if (list == NULL) {
        return NULL; // Out of memory
    }
    list->data = (char**)malloc(INITIAL_CAPACITY * sizeof(char*));
    if (list->data == NULL) {
        free(list);
        return NULL; // Out of memory
    }
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    return list;
}

void StrList_free(StrList* list) {
    if (list == NULL) return;
    for (size_t i = 0; i < list->size; ++i) {
        free(list->data[i]);
    }
    free(list->data);
    free(list);
}

size_t StrList_size(const StrList* list) {
    if (list == NULL) return 0;
    return list->size;
}

void StrList_insertLast(StrList* list, const char* data) {
    if (list == NULL) return;
    if (list->size >= list->capacity) {
        size_t new_capacity = list->capacity * 2;
        char** new_data = (char**)realloc(list->data, new_capacity * sizeof(char*));
        if (new_data == NULL) {
            // Failed to reallocate memory
            return;
        }
        list->data = new_data;
        list->capacity = new_capacity;
    }
    list->data[list->size] = strdup(data);
    list->size++;
}

void StrList_insertAt(StrList* list, const char* data, int index) {
    if (list == NULL || index < 0 || index > list->size) return;
    if (list->size >= list->capacity) {
        size_t new_capacity = list->capacity * 2;
        char** new_data = (char**)realloc(list->data, new_capacity * sizeof(char*));
        if (new_data == NULL) {
            // Failed to reallocate memory
            return;
        }
        list->data = new_data;
        list->capacity = new_capacity;
    }
    memmove(&list->data[index + 1], &list->data[index], (list->size - index) * sizeof(char*));
    list->data[index] = strdup(data);
    list->size++;
}

char* StrList_firstData(const StrList* list) {
    if (list == NULL || list->size == 0) return NULL;
    return list->data[0];
}

void StrList_print(const StrList* list) {
    if (list == NULL) return;
    for (size_t i = 0; i < list->size; ++i) {
        printf("%s ", list->data[i]);
    }
    printf("\n");
}

void StrList_printAt(const StrList* list, int index) {
    if (list == NULL || index < 0 || index >= list->size) return;
    printf("%s\n", list->data[index]);
}

int StrList_printLen(const StrList* list) {
    int count = 0;
    if (list == NULL) return count;
    for (size_t i = 0; i < list->size; ++i) {
        count += strlen(list->data[i]);
    }
    return count;
}

int StrList_count(StrList* list, const char* data) {
    int count = 0;
    if (list == NULL) return count;
    for (size_t i = 0; i < list->size; ++i) {
        if (strcmp(list->data[i], data) == 0) {
            count++;
        }
    }
    return count;
}

void StrList_remove(StrList* list, const char* data) {
    if (list == NULL) return;
    for (size_t i = 0; i < list->size; ++i) {
        if (strcmp(list->data[i], data) == 0) {
            free(list->data[i]);
            memmove(&list->data[i], &list->data[i + 1], (list->size - i - 1) * sizeof(char*));
            list->size--;
            i--; // Adjust index because elements shifted left
        }
    }
}

void StrList_removeAt(StrList* list, int index) {
    if (list == NULL || index < 0 || index >= list->size) return;
    free(list->data[index]);
    memmove(&list->data[index], &list->data[index + 1], (list->size - index - 1) * sizeof(char*));
    list->size--;
}

int StrList_isEqual(const StrList* list1, const StrList* list2) {
    if (list1 == NULL || list2 == NULL) return 0;
    if (list1->size != list2->size) return 0;
    for (size_t i = 0; i < list1->size; ++i) {
        if (strcmp(list1->data[i], list2->data[i]) != 0) {
            return 0;
        }
    }
    return 1;
}

StrList* StrList_clone(const StrList* list) {
    if (list == NULL) return NULL;
    StrList* clone = StrList_alloc();
    if (clone == NULL) return NULL;
    for (size_t i = 0; i < list->size; ++i) {
        StrList_insertLast(clone, list->data[i]);
    }
    return clone;
}

void StrList_reverse(StrList* list) {
    if (list == NULL) return;
    for (size_t i = 0; i < list->size / 2; ++i) {
        char* temp = list->data[i];
        list->data[i] = list->data[list->size - i - 1];
        list->data[list->size - i - 1] = temp;
    }
}

static int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void StrList_sort(StrList* list) {
    if (list == NULL) return;
    qsort(list->data, list->size, sizeof(char*), compareStrings);
}

int StrList_isSorted(StrList* list) {
    if (list == NULL || list->size <= 1) return 1;
    for (size_t i = 1; i < list->size; ++i) {
        if (strcmp(list->data[i - 1], list->data[i]) > 0) {
            return 0;
        }
    }
    return 1;
}


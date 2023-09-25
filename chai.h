// Copyright 2023 Alexandros F. G. Kapretsos
// SPDX-License-Identifier: Apache-2.0

// TODO(AlexandrosKap): Write macro function generator for simple lists.

#ifndef CHAI_HEADER
#define CHAI_HEADER

#ifndef CHAI_NO_STD
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#endif // CHAI_NO_STD

#ifdef CHAI_BASIC_TYPES
typedef signed char        i8;
typedef short              i16;
typedef int                i32;
typedef long long          i64;
typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef float              f32;
typedef double             f64;
typedef size_t             su64;
typedef ssize_t            si64;
#endif // CHAI_BASIC_TYPES

#ifndef CHAI_CAPACITY_UNIT
#define CHAI_CAPACITY_UNIT 32
#endif // CHAI_CAPACITY_UNIT

#define CHAI_CAST(type) (type)
#define CHAI_PANIC(message) assert(message && 0)
#define CHAI_PANIC_INDEX() CHAI_PANIC("index out of range")

typedef struct {
    char *items;
    size_t length;
    size_t capacity;
} Chai_String;

typedef struct {
    int *items;
    size_t length;
    size_t capacity;
} Chai_List_I32;

typedef struct {
    float *items;
    size_t length;
    size_t capacity;
} Chai_List_F32;

// --- List macros

// Dependencies:
// * proc: calloc
// * proc: realloc
// * proc: chai_calculate_capacity

#define CHAI_GEN_IMP_LIST_NEW(Type_List, Type_Item, value_length)                  \
    Type_List result;                                                              \
    do {                                                                           \
        size_t capacity = chai_calculate_capacity(value_length, 0);                \
        result.items = CHAI_CAST(Type_Item *) calloc(capacity, sizeof(Type_Item)); \
        result.length = value_length;                                              \
        result.capacity = capacity;                                                \
    } while (0)                                                                    \

#define CHAI_GEN_IMP_LIST_CLONE(Type_List, Type_Item, value_other)   \
    CHAI_GEN_IMP_LIST_NEW(Type_List, Type_Item, value_other.length); \
    do {                                                             \
        for (size_t i = 0; i < value_other.length; i += 1) {         \
            result.items[i] = value_other.items[i];                  \
        }                                                            \
    } while (0)                                                      \

#define CHAI_GEN_IMP_LIST_APPEND(Type_List, Type_Item, value_list, value_item)                                   \
    do {                                                                                                         \
        value_list->length += 1;                                                                                 \
        if (value_list->length > value_list->capacity) {                                                         \
            size_t capacity = chai_calculate_capacity(value_list->length, value_list->capacity);                 \
            value_list->items = CHAI_CAST(Type_Item *) realloc(value_list->items, capacity * sizeof(Type_Item)); \
            value_list->capacity = capacity;                                                                     \
        }                                                                                                        \
        value_list->items[value_list->length - 1] = value_item;                                                  \
    } while (0)                                                                                                  \

#define CHAI_GEN_IMP_LIST_FREE(value_list) \
    do {                                   \
        free(value_list->items);           \
        value_list->items = NULL;          \
        value_list->length = 0;            \
        value_list->capacity = 0;          \
    } while (0)                            \

// --- Definitions

size_t chai_calculate_capacity(size_t length, size_t start_capacity);

Chai_String chai_string_new(size_t length);
Chai_String chai_string_clone(Chai_String other);
Chai_String chai_string_clone_str(const char *str);
char chai_string_get(Chai_String *list, size_t index);
void chai_string_set(Chai_String *list, size_t index, const char item);
void chai_string_append(Chai_String *list, const char item);
void chai_string_append_str(Chai_String *list, const char *str);
void chai_string_insert(Chai_String *list, const char item);     // TODO(AlexandrosKap): Not done.
void chai_string_insert_str(Chai_String *list, const char *str); // TODO(AlexandrosKap): Not done.
void chai_string_resize(Chai_String *list, size_t length);       // TODO(AlexandrosKap): Not done.
void chai_string_reserve(Chai_String *list, size_t capacity);    // TODO(AlexandrosKap): Not done.
void chai_string_remove(Chai_String *list, size_t index);        // TODO(AlexandrosKap): Not done.
void chai_string_clear(Chai_String *list);                       // TODO(AlexandrosKap): Not done.
void chai_string_free(Chai_String *list);

Chai_List_I32 chai_list_i32_new(size_t length);
Chai_List_I32 chai_list_i32_clone(Chai_List_I32 other);
int chai_list_i32_get(Chai_List_I32 *list, size_t index);            // TODO(AlexandrosKap): Not done.
void chai_list_i32_set(Chai_List_I32 *list, size_t index, int item); // TODO(AlexandrosKap): Not done.
void chai_list_i32_append(Chai_List_I32 *list, int item);
void chai_list_i32_insert(Chai_List_I32 *list, int item);            // TODO(AlexandrosKap): Not done.
void chai_list_i32_resize(Chai_List_I32 *list, size_t length);       // TODO(AlexandrosKap): Not done.
void chai_list_i32_reserve(Chai_List_I32 *list, size_t capacity);    // TODO(AlexandrosKap): Not done.
void chai_list_i32_remove(Chai_List_I32 *list, size_t index);        // TODO(AlexandrosKap): Not done.
void chai_list_i32_clear(Chai_List_I32 *list);                       // TODO(AlexandrosKap): Not done.
void chai_list_i32_free(Chai_List_I32 *list);

Chai_List_F32 chai_list_f32_new(size_t length);
Chai_List_F32 chai_list_f32_clone(Chai_List_F32 other);
float chai_list_f32_get(Chai_List_F32 *list, size_t index);            // TODO(AlexandrosKap): Not done.
void chai_list_f32_set(Chai_List_F32 *list, size_t index, float item); // TODO(AlexandrosKap): Not done.
void chai_list_f32_append(Chai_List_F32 *list, float item);
void chai_list_f32_insert(Chai_List_F32 *list, float item);            // TODO(AlexandrosKap): Not done.
void chai_list_f32_resize(Chai_List_F32 *list, size_t length);         // TODO(AlexandrosKap): Not done.
void chai_list_f32_reserve(Chai_List_F32 *list, size_t capacity);      // TODO(AlexandrosKap): Not done.
void chai_list_f32_remove(Chai_List_F32 *list, size_t index);          // TODO(AlexandrosKap): Not done.
void chai_list_f32_clear(Chai_List_F32 *list);                         // TODO(AlexandrosKap): Not done.
void chai_list_f32_free(Chai_List_F32 *list);

// --- Implementations

size_t chai_calculate_capacity(size_t length, size_t start_capacity) {
    size_t result = start_capacity;
    while (result < length) {
        result += CHAI_CAPACITY_UNIT;
    }
    return result;
}

Chai_String chai_string_new(size_t length) {
    CHAI_GEN_IMP_LIST_NEW(Chai_String, char, length + 1);
    result.items[result.length - 1] = '\0';
    result.length -= 1;
    return result;
}

Chai_String chai_string_clone(Chai_String other) {
    Chai_String result = chai_string_new(other.length);
    for (size_t i = 0; i < other.length; i += 1) {
        result.items[i] = other.items[i];
    }
    return result;
}

Chai_String chai_string_clone_str(const char *str) {
    Chai_String result = chai_string_new(0);
    chai_string_append_str(&result, str);
    return result;
}

char chai_string_get(Chai_String *list, size_t index) {
    if (index >= list->length) {
        CHAI_PANIC_INDEX();
    }
    return list->items[index];
}

void chai_string_set(Chai_String *list, size_t index, const char item) {
    if (index >= list->length) {
        CHAI_PANIC_INDEX();
    }
    list->items[index] = item;
}

void chai_string_append(Chai_String *list, const char item) {
    CHAI_GEN_IMP_LIST_APPEND(Chai_String, char, list, item);
    CHAI_GEN_IMP_LIST_APPEND(Chai_String, char, list, '\0');
    list->length -= 1;
}

void chai_string_append_str(Chai_String *list, const char *str) {
    while (*str != '\0') {
        chai_string_append(list, *str);
        str += 1;
    }
}

void chai_string_free(Chai_String *list) {
    CHAI_GEN_IMP_LIST_FREE(list);
}

Chai_List_I32 chai_list_i32_new(size_t length) {
    CHAI_GEN_IMP_LIST_NEW(Chai_List_I32, int, length);
    return result;
}

Chai_List_I32 chai_list_i32_clone(Chai_List_I32 other) {
    CHAI_GEN_IMP_LIST_CLONE(Chai_List_I32, int, other);
    return result;
}

void chai_list_i32_append(Chai_List_I32 *list, int item) {
    CHAI_GEN_IMP_LIST_APPEND(Chai_List_I32, int, list, item);
}

void chai_list_i32_free(Chai_List_I32 *list) {
    CHAI_GEN_IMP_LIST_FREE(list);
}

Chai_List_F32 chai_list_f32_new(size_t length) {
    CHAI_GEN_IMP_LIST_NEW(Chai_List_F32, float, length);
    return result;
}

Chai_List_F32 chai_list_f32_clone(Chai_List_F32 other) {
    CHAI_GEN_IMP_LIST_CLONE(Chai_List_F32, float, other);
    return result;
}

void chai_list_f32_append(Chai_List_F32 *list, float item) {
    CHAI_GEN_IMP_LIST_APPEND(Chai_List_F32, float, list, item);
}

void chai_list_f32_free(Chai_List_F32 *list) {
    CHAI_GEN_IMP_LIST_FREE(list);
}

#endif // CHAI_HEADER
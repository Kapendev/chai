// Copyright 2023 Alexandros F. G. Kapretsos
// SPDX-License-Identifier: Apache-2.0

// TODO(AlexandrosKap): Change maybe the API and think about str procedures.
// TODO(AlexandrosKap): Write macros for malloc, realloc, free, assert.
// TODO(AlexandrosKap): Write macro procedure generator for simple lists.

#ifndef CHAI_HEADER
#define CHAI_HEADER

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define CHAI_WHITESPACE " \t\v\r\n\f"
#define CHAI_LIST_START_CAPACITY 16

#define CHAI_CAST(type) (type)
#define CHAI_TODO(message) assert("TODO" && message && 0)
#define CHAI_PANIC(message) assert("ERROR" && message && 0)
#define CHAI_PANIC_INDEX() CHAI_PANIC("Index is out of range.")

typedef struct Chai_View {
    const char *data;
    size_t length;
} Chai_View;

typedef struct Chai_List {
    void *items;
    size_t length;
    size_t capacity;
    size_t item_size;
} Chai_List;

typedef struct Chai_List_I32 {
    Chai_List data;
} Chai_List_I32;

typedef struct Chai_List_F32 {
    Chai_List data;
} Chai_List_F32;

typedef struct Chai_String {
    Chai_List data;
} Chai_String;

// --- Definitions

size_t chai_find_capacity(size_t length);
bool chai_is_upper_case(char c);
bool chai_is_lower_case(char c);
bool chai_is_alphabetic(char c);
bool chai_is_whitespace(char c);
bool chai_is_digit(char c);
char chai_to_upper_case(char c);
char chai_to_lower_case(char c);

Chai_View chai_view_new(const char *str);
Chai_View chai_view_from_str(const char *str, size_t a, size_t b);
Chai_View chai_view_from_string(Chai_String list, size_t a, size_t b);
Chai_View chai_view_from_view(Chai_View view, size_t a, size_t b);
const char * chai_view_item(Chai_View view, size_t index);
bool chai_view_equals(Chai_View a, Chai_View b);
bool chai_view_equals_ignore_case(Chai_View a, Chai_View b);
bool chai_view_starts_with(Chai_View view, Chai_View start);
bool chai_view_ends_with(Chai_View view, Chai_View end);
int chai_view_count(Chai_View view, Chai_View item);
int chai_view_find_left(Chai_View view, Chai_View item);
int chai_view_find_right(Chai_View view, Chai_View item);
Chai_View chai_view_trim_left(Chai_View view);
Chai_View chai_view_trim_right(Chai_View view);
Chai_View chai_view_trim(Chai_View view);

Chai_List chai_list_new(size_t length, size_t item_size);
Chai_List chai_list_copy(Chai_List other);
void * chai_list_item(Chai_List list, size_t index);
void chai_list_fill(Chai_List *list, void *item);
void chai_list_append(Chai_List *list, void *item);
void chai_list_insert(Chai_List *list, size_t index, void *item);
void chai_list_remove(Chai_List *list, size_t index);
void chai_list_remove_swap(Chai_List *list, size_t index);
void chai_list_resize(Chai_List *list, size_t length);
void chai_list_reserve(Chai_List *list, size_t additional);
void chai_list_shrink(Chai_List *list);
void chai_list_clear(Chai_List *list);
void chai_list_free(Chai_List *list);

Chai_List_I32 chai_list_i32_new(size_t length);
Chai_List_I32 chai_list_i32_copy(Chai_List_I32 other);
int * chai_list_i32_item(Chai_List_I32 list, size_t index);
void chai_list_i32_fill(Chai_List_I32 *list, int item);
void chai_list_i32_append(Chai_List_I32 *list, int item);
void chai_list_i32_insert(Chai_List_I32 *list, size_t index, int item);
void chai_list_i32_remove(Chai_List_I32 *list, size_t index);
void chai_list_i32_remove_swap(Chai_List_I32 *list, size_t index);
void chai_list_i32_resize(Chai_List_I32 *list, size_t length);
void chai_list_i32_reserve(Chai_List_I32 *list, size_t additional);
void chai_list_i32_shrink(Chai_List_I32 *list);
void chai_list_i32_clear(Chai_List_I32 *list);
void chai_list_i32_free(Chai_List_I32 *list);

Chai_List_F32 chai_list_f32_new(size_t length);
Chai_List_F32 chai_list_f32_copy(Chai_List_F32 other);
float * chai_list_f32_item(Chai_List_F32 list, size_t index);
void chai_list_f32_fill(Chai_List_F32 *list, float item);
void chai_list_f32_append(Chai_List_F32 *list, float item);
void chai_list_f32_insert(Chai_List_F32 *list, size_t index, float item);
void chai_list_f32_remove(Chai_List_F32 *list, size_t index);
void chai_list_f32_remove_swap(Chai_List_F32 *list, size_t index);
void chai_list_f32_resize(Chai_List_F32 *list, size_t length);
void chai_list_f32_reserve(Chai_List_F32 *list, size_t additional);
void chai_list_f32_shrink(Chai_List_F32 *list);
void chai_list_f32_clear(Chai_List_F32 *list);
void chai_list_f32_free(Chai_List_F32 *list);

Chai_String chai_string_new(size_t length);
Chai_String chai_string_copy(Chai_String other);
char * chai_string_item(Chai_String list, size_t index);
void chai_string_fill(Chai_String *list, const char item);
void chai_string_append(Chai_String *list, const char item);
void chai_string_insert(Chai_String *list, size_t index, const char item);
void chai_string_remove(Chai_String *list, size_t index);
void chai_string_remove_swap(Chai_String *list, size_t index);
void chai_string_resize(Chai_String *list, size_t length);
void chai_string_reserve(Chai_String *list, size_t additional);
void chai_string_shrink(Chai_String *list);
void chai_string_clear(Chai_String *list);
void chai_string_free(Chai_String *list);
Chai_String chai_string_copy_view(Chai_View view);
void chai_string_append_view(Chai_String *list, Chai_View view);
void chai_string_insert_view(Chai_String *list, size_t index, Chai_View view);
Chai_String chai_string_copy_str(const char *str);
void chai_string_append_str(Chai_String *list, const char *str);
void chai_string_insert_str(Chai_String *list, size_t index, const char *str);

// --- Implementations

size_t chai_find_capacity(size_t length) {
    size_t result = CHAI_LIST_START_CAPACITY;
    while (result < length) {
        result *= 2;
    }
    return result;
}

bool chai_is_upper_case(char c) {
    return c >= 65 && c <= 90;
}

bool chai_is_lower_case(char c) {
    return c >= 97 && c <= 122;
}

bool chai_is_alphabetic(char c) {
    return chai_is_upper_case(c) || chai_is_lower_case(c);
}

bool chai_is_whitespace(char c) {
    const char *whitespace = CHAI_WHITESPACE;
    while (*whitespace != '\0') {
        if (c == *whitespace) {
            return true;
        }
        whitespace += 1;
    }
    return false;
}

bool chai_is_digit(char c) {
    return c >= 48 && c <= 57;
}

char chai_to_upper_case(char c) {
    if (chai_is_lower_case(c)) {
        return c - 32;
    } else {
        return c;
    }
}

char chai_to_lower_case(char c) {
    if (chai_is_upper_case(c)) {
        return c + 32;
    } else {
        return c;
    }
}

Chai_View chai_view_new(const char *str) {
    Chai_View result;
    result.data = str;
    result.length = strlen(str);
    return result;
}

Chai_View chai_view_from_str(const char *str, size_t a, size_t b) {
    Chai_View result;
    result.data = NULL;
    result.length = 0;
    size_t str_length = strlen(str);
    if (a > b || a > str_length || b > str_length) {
        CHAI_PANIC_INDEX();
        return result;
    }
    result.data = str + a;
    result.length = b - a;
    return result;
}

Chai_View chai_view_from_string(Chai_String list, size_t a, size_t b) {
    Chai_View result;
    result.data = NULL;
    result.length = 0;
    if (a > b || a > list.data.length || b > list.data.length) {
        CHAI_PANIC_INDEX();
        return result;
    }
    result.data = list.data.items + a;
    result.length = b - a;
    return result;
}

Chai_View chai_view_from_view(Chai_View view, size_t a, size_t b) {
    Chai_View result;
    result.data = NULL;
    result.length = 0;
    if (a > b || a > view.length || b > view.length) {
        CHAI_PANIC_INDEX();
        return result;
    }
    result.data = view.data + a;
    result.length = b - a;
    return result;
}

const char * chai_view_item(Chai_View view, size_t index) {
    if (index >= view.length) {
        CHAI_PANIC_INDEX();
        return NULL;
    }
    return view.data + index;
}

bool chai_view_equals(Chai_View a, Chai_View b) {
    if (a.length != b.length) {
        return false;
    }
    return memcmp(a.data, b.data, b.length) == 0;
}

bool chai_view_equals_ignore_case(Chai_View a, Chai_View b) {
    if (a.length != b.length) {
        return false;
    }
    for (size_t i = 0; i < a.length; i += 1) {
        if (chai_to_lower_case(a.data[i]) != chai_to_lower_case(b.data[i])) {
            return false;
        }
    }
    return true;
}

bool chai_view_starts_with(Chai_View view, Chai_View start) {
    if (view.length < start.length) {
        return false;
    }
    return memcmp(view.data, start.data, start.length) == 0;
}

bool chai_view_ends_with(Chai_View view, Chai_View end) {
    if (view.length < end.length) {
        return false;
    }
    return memcmp(view.data + view.length - end.length, end.data, end.length) == 0;
}

int chai_view_count(Chai_View view, Chai_View item) {
    size_t result = 0;
    if (view.length < item.length || item.length == 0) {
        return result;
    }
    for (size_t i = 0; i <= view.length - item.length; i += 1) {
        if (memcmp(view.data + i, item.data, item.length) == 0) {
            result += 1;
            i += item.length - 1;
        }
    }
    return result;
}

int chai_view_find_left(Chai_View view, Chai_View item) {
    if (view.length < item.length || item.length == 0) {
        return -1;
    }
    for (size_t i = 0; i <= view.length - item.length; i += 1) {
        if (memcmp(view.data + i, item.data, item.length) == 0) {
            return i;
        }
    }
    return -1;
}

int chai_view_find_right(Chai_View view, Chai_View item) {
    if (view.length < item.length || item.length == 0) {
        return -1;
    }
    for (size_t i = view.length - item.length;; i -= 1) {
        if (memcmp(view.data + i, item.data, item.length) == 0) {
            return i;
        }
        if (i == 0) {
            return -1;
        }
    }
    return -1;
}

Chai_View chai_view_trim_left(Chai_View view) {
    Chai_View result = view;
    while (result.length > 0) {
        if (chai_is_whitespace(result.data[0])) {
            result.data += 1;
            result.length -= 1;
        } else {
            break;
        }
    }
    return result;
}

Chai_View chai_view_trim_right(Chai_View view) {
    Chai_View result = view;
    while (result.length > 0) {
        if (chai_is_whitespace(result.data[result.length - 1])) {
            result.length -= 1;
        } else {
            break;
        }
    }
    return result;
}

Chai_View chai_view_trim(Chai_View view) {
    return chai_view_trim_left(chai_view_trim_right(view));
}

Chai_List chai_list_new(size_t length, size_t item_size) {
    Chai_List result;
    if (length == 0) {
        result.items = NULL;
        result.length = 0;
        result.capacity = 0;
        result.item_size = item_size;
    } else {
        size_t capacity = chai_find_capacity(length);
        result.items = malloc(capacity * item_size);
        result.length = length;
        result.capacity = capacity;
        result.item_size = item_size;
        memset(result.items, 0, capacity * item_size);
    }
    return result;
}

Chai_List chai_list_copy(Chai_List other) {
    Chai_List result;
    if (other.capacity == 0) {
        result.items = NULL;
        result.length = 0;
        result.capacity = 0;
        result.item_size = other.item_size;
    } else {
        result.items = malloc(other.capacity * other.item_size);
        result.length = other.length;
        result.capacity = other.capacity;
        result.item_size = other.item_size;
        memcpy(result.items, other.items, other.capacity * other.item_size);
    }
    return result;
}

void * chai_list_item(Chai_List list, size_t index) {
    return (CHAI_CAST(char *) list.items) + index * list.item_size;
}

void chai_list_fill(Chai_List *list, void *item) {
    for (size_t i = 0; i < list->length; i += 1) {
        memcpy(chai_list_item(*list, i), item, list->item_size);
    }
}

void chai_list_append(Chai_List *list, void *item) {
    list->length += 1;
    if (list->length > list->capacity) {
        size_t new_capacity = chai_find_capacity(list->length);
        list->items = realloc(list->items, new_capacity * list->item_size);
        list->capacity = new_capacity;
    }
    memcpy(chai_list_item(*list, list->length - 1), item, list->item_size);
}

void chai_list_insert(Chai_List *list, size_t index, void *item) {
    list->length += 1;
    if (list->length > list->capacity) {
        size_t new_capacity = chai_find_capacity(list->length);
        list->items = realloc(list->items, new_capacity * list->item_size);
        list->capacity = new_capacity;
    }
    for (size_t i = list->length - 1; i > index; i -= 1) {
        memcpy(chai_list_item(*list, i), chai_list_item(*list, i - 1), list->item_size);
    }
    memcpy(chai_list_item(*list, index), item, list->item_size);
}

void chai_list_remove(Chai_List *list, size_t index) {
    if (list->length == 0) {
        return;
    }
    for (size_t i = index; i < list->length - 1; i += 1) {
        memcpy(chai_list_item(*list, i), chai_list_item(*list, i + 1), list->item_size);
    }
    list->length -= 1;
}

void chai_list_remove_swap(Chai_List *list, size_t index) {
    if (list->length == 0) {
        return;
    }
    memcpy(chai_list_item(*list, index), chai_list_item(*list, list->length - 1), list->item_size);
    list->length -= 1;
}

void chai_list_resize(Chai_List *list, size_t length) {
    size_t old_length = list->length;
    list->length = length;
    if (list->length > list->capacity) {
        size_t new_capacity = chai_find_capacity(list->length);
        list->items = realloc(list->items, new_capacity * list->item_size);
        list->capacity = new_capacity;
    }
    if (list->length > old_length) {
        memset(chai_list_item(*list, old_length), 0, (list->length - old_length) * list->item_size);
    }
}

void chai_list_reserve(Chai_List *list, size_t additional) {
    size_t temp_length = list->length;
    list->length = list->length + additional;
    if (list->length > list->capacity) {
        size_t new_capacity = chai_find_capacity(list->length);
        list->items = realloc(list->items, new_capacity * list->item_size);
        list->capacity = new_capacity;
    }
    list->length = temp_length;
}

void chai_list_shrink(Chai_List *list) {
    size_t new_capacity = chai_find_capacity(list->length);
    if (new_capacity != list->capacity) {
        list->items = realloc(list->items, new_capacity * list->item_size);
        list->capacity = new_capacity;
    }
}

void chai_list_clear(Chai_List *list) {
    chai_list_resize(list, 0);
}

void chai_list_free(Chai_List *list) {
    if (list->items != NULL) {
        free(list->items);
        list->items = NULL;
        list->length = 0;
        list->capacity = 0;
    }
}

Chai_List_I32 chai_list_i32_new(size_t length) {
    Chai_List_I32 result;
    result.data = chai_list_new(length, sizeof(int));
    return result;
}

Chai_List_I32 chai_list_i32_copy(Chai_List_I32 other) {
    Chai_List_I32 result;
    result.data = chai_list_copy(other.data);
    return result;
}

int * chai_list_i32_item(Chai_List_I32 list, size_t index) {
    if (index >= list.data.length) {
        CHAI_PANIC_INDEX();
        return NULL;
    }
    return CHAI_CAST(int *) chai_list_item(list.data, index);
}

void chai_list_i32_fill(Chai_List_I32 *list, int item) {
    chai_list_fill(&list->data, &item);
}

void chai_list_i32_append(Chai_List_I32 *list, int item) {
    chai_list_append(&list->data, &item);
}

void chai_list_i32_insert(Chai_List_I32 *list, size_t index, int item) {
    if (index > list->data.length) {
        CHAI_PANIC_INDEX();
        return;
    }
    chai_list_insert(&list->data, index, &item);
}

void chai_list_i32_remove(Chai_List_I32 *list, size_t index) {
    if (index >= list->data.length) {
        CHAI_PANIC_INDEX();
        return;
    }
    chai_list_remove(&list->data, index);
}

void chai_list_i32_remove_swap(Chai_List_I32 *list, size_t index) {
    if (index >= list->data.length) {
        CHAI_PANIC_INDEX();
        return;
    }
    chai_list_remove_swap(&list->data, index);
}

void chai_list_i32_resize(Chai_List_I32 *list, size_t length) {
    chai_list_resize(&list->data, length);
}

void chai_list_i32_reserve(Chai_List_I32 *list, size_t additional) {
    chai_list_reserve(&list->data, additional);
}

void chai_list_i32_shrink(Chai_List_I32 *list) {
    chai_list_shrink(&list->data);
}

void chai_list_i32_clear(Chai_List_I32 *list) {
    chai_list_clear(&list->data);
}

void chai_list_i32_free(Chai_List_I32 *list) {
    chai_list_free(&list->data);
}

Chai_List_F32 chai_list_f32_new(size_t length) {
    Chai_List_F32 result;
    result.data = chai_list_new(length, sizeof(float));
    return result;
}

Chai_List_F32 chai_list_f32_copy(Chai_List_F32 other) {
    Chai_List_F32 result;
    result.data = chai_list_copy(other.data);
    return result;
}

float * chai_list_f32_item(Chai_List_F32 list, size_t index) {
    if (index >= list.data.length) {
        CHAI_PANIC_INDEX();
        return NULL;
    }
    return CHAI_CAST(float *) chai_list_item(list.data, index);
}

void chai_list_f32_fill(Chai_List_F32 *list, float item) {
    chai_list_fill(&list->data, &item);
}

void chai_list_f32_append(Chai_List_F32 *list, float item) {
    chai_list_append(&list->data, &item);
}

void chai_list_f32_insert(Chai_List_F32 *list, size_t index, float item) {
    if (index > list->data.length) {
        CHAI_PANIC_INDEX();
        return;
    }
    chai_list_insert(&list->data, index, &item);
}

void chai_list_f32_remove(Chai_List_F32 *list, size_t index) {
    if (index >= list->data.length) {
        CHAI_PANIC_INDEX();
        return;
    }
    chai_list_remove(&list->data, index);
}

void chai_list_f32_remove_swap(Chai_List_F32 *list, size_t index) {
    if (index >= list->data.length) {
        CHAI_PANIC_INDEX();
        return;
    }
    chai_list_remove_swap(&list->data, index);
}

void chai_list_f32_resize(Chai_List_F32 *list, size_t length) {
    chai_list_resize(&list->data, length);
}

void chai_list_f32_reserve(Chai_List_F32 *list, size_t additional) {
    chai_list_reserve(&list->data, additional);
}

void chai_list_f32_shrink(Chai_List_F32 *list) {
    chai_list_shrink(&list->data);
}

void chai_list_f32_clear(Chai_List_F32 *list) {
    chai_list_clear(&list->data);
}

void chai_list_f32_free(Chai_List_F32 *list) {
    chai_list_free(&list->data);
}

Chai_String chai_string_new(size_t length) {
    Chai_String result;
    result.data = chai_list_new(length + 1, sizeof(char));
    result.data.length -= 1;
    return result;
}

Chai_String chai_string_copy(Chai_String other) {
    Chai_String result;
    result.data = chai_list_copy(other.data);
    return result;
}

char * chai_string_item(Chai_String list, size_t index) {
    if (index >= list.data.length) {
        CHAI_PANIC_INDEX();
        return NULL;
    }
    return CHAI_CAST(char *) chai_list_item(list.data, index);
}

void chai_string_fill(Chai_String *list, const char item) {
    chai_list_fill(&list->data, CHAI_CAST(char *) &item);
}

void chai_string_append(Chai_String *list, const char item) {
    const char cute_zero = '\0';
    chai_list_append(&list->data, CHAI_CAST(char *) &item);
    chai_list_append(&list->data, CHAI_CAST(char *) &cute_zero);
    list->data.length -= 1;
}

void chai_string_insert(Chai_String *list, size_t index, const char item) {
    if (index > list->data.length) {
        CHAI_PANIC_INDEX();
        return;
    }
    if (index == list->data.length) {
        const char cute_zero = '\0';
        chai_list_append(&list->data, CHAI_CAST(char *) &item);
        chai_list_append(&list->data, CHAI_CAST(char *) &cute_zero);
        list->data.length -= 1;
    } else {
        chai_list_insert(&list->data, index, CHAI_CAST(char *) &item);
    }
}

void chai_string_remove(Chai_String *list, size_t index) {
    if (index >= list->data.length) {
        CHAI_PANIC_INDEX();
        return;
    }
    chai_list_remove(&list->data, index);
}

void chai_string_remove_swap(Chai_String *list, size_t index) {
    if (index >= list->data.length) {
        CHAI_PANIC_INDEX();
        return;
    }
    chai_list_remove_swap(&list->data, index);
}

void chai_string_resize(Chai_String *list, size_t length) {
    chai_list_resize(&list->data, length + 1);
    *(CHAI_CAST(char *) chai_list_item(list->data, length)) = '\0';
    list->data.length -= 1;
}

void chai_string_reserve(Chai_String *list, size_t additional) {
    chai_list_reserve(&list->data, additional + 1);
}

void chai_string_shrink(Chai_String *list) {
    chai_list_shrink(&list->data);
}

void chai_string_clear(Chai_String *list) {
    chai_list_clear(&list->data);
    chai_list_resize(&list->data, 1);
    list->data.length -= 1;
}

void chai_string_free(Chai_String *list) {
    chai_list_free(&list->data);
}

Chai_String chai_string_copy_view(Chai_View view) {
    Chai_String result = chai_string_new(view.length);
    result.data.length = 0;
    for (size_t i = 0; i < view.length; i += 1) {
        chai_string_append(&result, view.data[i]);
    }
    return result;
}

void chai_string_append_view(Chai_String *list, Chai_View view) {
    for (size_t i = 0; i < view.length; i += 1) {
        chai_string_append(list, view.data[i]);
    }
}

void chai_string_insert_view(Chai_String *list, size_t index, Chai_View view) {
    for (size_t i = 0; i < view.length; i += 1) {
        chai_string_insert(list, index, view.data[i]);
        index += 1;
    }
}

Chai_String chai_string_copy_str(const char *str) {
    size_t str_length = strlen(str);
    Chai_String result;
    result.data = chai_list_new(str_length + 1, sizeof(char));
    result.data.length -= 1;
    for (size_t i = 0; i < str_length; i += 1) {
        *(CHAI_CAST(char *) chai_list_item(result.data, i)) = str[i];
    }
    return result;
}

void chai_string_append_str(Chai_String *list, const char *str) {
    while (*str != '\0') {
        chai_string_append(list, *str);
        str += 1;
    }
}

void chai_string_insert_str(Chai_String *list, size_t index, const char *str) {
    while (*str != '\0') {
        chai_string_insert(list, index, *str);
        index += 1;
        str += 1;
    }
}

#endif // CHAI_HEADER

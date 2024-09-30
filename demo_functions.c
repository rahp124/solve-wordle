// A nice place for you to mess with the functions, while you're developing.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "search_util.h"

void test_score_letter() {
    char *vocabulary[] = {"stalk", "scrap", "shear", "batch", "motif", "tense", "ultra", "vital", "ether", "nadir"};
    size_t num_words = 10;
    
    printf("Testing score_letter...\n");
    printf("Score for letter 'a': %d (expected: 7)\n", score_letter('a', vocabulary, num_words));
    printf("Score for letter 'e': %d (expected: 3)\n", score_letter('e', vocabulary, num_words));
    printf("Score for letter 'z': %d (expected: 0)\n", score_letter('z', vocabulary, num_words));
}

void test_score_word() {
    char *vocabulary[] = {"stalk", "scrap", "shear", "batch", "motif", "tense", "ultra", "vital", "ether", "nadir"};
    int letter_scores[26] = {6, 1, 1, 1, 3, 1, 0, 1, 2, 0, 1, 1, 1, 2, 1, 1, 0, 2, 2, 3, 1, 1, 1, 0, 1, 0};
    
    printf("Testing score_word...\n");
    printf("Score for word 'stalk': %d (expected: 13)\n", score_word(vocabulary[0], letter_scores));
    printf("Score for word 'shear': %d (expected: 14)\n", score_word(vocabulary[2], letter_scores));
    printf("Score for word 'vital': %d (expected: 13)\n", score_word(vocabulary[7], letter_scores));
}

void test_filter_vocabulary_gray() {
    char *vocabulary[] = {"stalk", "scrap", "shear", "batch", "motif", "tense", "ultra", "vital", "ether", "nadir"};
    size_t num_words = 10;

    // Make a dynamically-allocated copy of the vocabulary
    char **dyn_vocabulary = calloc(num_words, sizeof(char *));
    for (size_t i = 0; i < num_words; i++) {
        dyn_vocabulary[i] = strdup(vocabulary[i]);
    }

    printf("Testing filter_vocabulary_gray...\n");
    size_t filtered_count = filter_vocabulary_gray('a', dyn_vocabulary, num_words);
    printf("Filtered words containing 'a': %zu (expected: 7)\n", filtered_count);

    // Print the remaining words
    for (size_t i = 0; i < num_words; i++) {
        if (dyn_vocabulary[i] != NULL) {
            printf("%s ", dyn_vocabulary[i]);
        }
    }
    printf("\n");

    free_vocabulary(dyn_vocabulary, num_words);
}

void test_filter_vocabulary_yellow() {
    char *vocabulary[] = {"stalk", "scrap", "shear", "batch", "motif", "tense", "ultra", "vital", "ether", "nadir"};
    size_t num_words = 10;

    // Make a dynamically-allocated copy of the vocabulary
    char **dyn_vocabulary = calloc(num_words, sizeof(char *));
    for (size_t i = 0; i < num_words; i++) {
        dyn_vocabulary[i] = strdup(vocabulary[i]);
    }

    printf("Testing filter_vocabulary_yellow...\n");
    size_t filtered_count = filter_vocabulary_yellow('t', 2, dyn_vocabulary, num_words);
    printf("Filtered words for 't' not at position 2: %zu (expected: 7)\n", filtered_count);

    // Print the remaining words
    for (size_t i = 0; i < num_words; i++) {
        if (dyn_vocabulary[i] != NULL) {
            printf("%s ", dyn_vocabulary[i]);
        }
    }
    printf("\n");

    free_vocabulary(dyn_vocabulary, num_words);
}

void test_filter_vocabulary_green() {
    char *vocabulary[] = {"stalk", "scrap", "shear", "batch", "motif", "tense", "ultra", "vital", "ether", "nadir"};
    size_t num_words = 10;

    // Make a dynamically-allocated copy of the vocabulary
    char **dyn_vocabulary = calloc(num_words, sizeof(char *));
    for (size_t i = 0; i < num_words; i++) {
        dyn_vocabulary[i] = strdup(vocabulary[i]);
    }

    printf("Testing filter_vocabulary_green...\n");
    size_t filtered_count = filter_vocabulary_green('t', 1, dyn_vocabulary, num_words);
    printf("Filtered words with 't' at position 1: %zu (expected: 8)\n", filtered_count);

    // Print the remaining words
    for (size_t i = 0; i < num_words; i++) {
        if (dyn_vocabulary[i] != NULL) {
            printf("%s ", dyn_vocabulary[i]);
        }
    }
    printf("\n");

    free_vocabulary(dyn_vocabulary, num_words);
}

int main(void) {
    // Test each function
    test_score_letter();
    test_score_word();
    test_filter_vocabulary_gray();
    test_filter_vocabulary_yellow();
    test_filter_vocabulary_green();

    return 0;
}




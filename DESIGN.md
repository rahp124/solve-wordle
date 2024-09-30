int score_letter(char letter, char **vocabulary, size_t num_words): 
	initialize count to 0
	for each word in vocabulary:
        		if word is not NULL:
           			if letter is in word:
                			increment count
 	return count

int score_word(char *word, int *letter_scores):
    initialize score to 0
    create a boolean array initialized to 26 false
    for each letter in word:
        if seen[letter - 'a'] is false:
            add letter_scores[letter - 'a'] to score
            set seen[letter - 'a'] to true
    return score

size_t filter_vocabulary_gray(char letter, char **vocabulary, size_t num_words):
    initialize int to 0
    for each word in vocabulary:
        if word is not NULL:
            if letter is in word:
                free word
                set word to NULL
                increment int
    return int

size_t filter_vocabulary_yellow(char letter, int position, char **vocabulary, size_t num_words):
    initialize int to 0
    for each word in vocabulary:
        if word is not NULL:
            if letter is not in word or word at position is letter:
                free word
                set word to NULL
                increment int
    return int

size_t filter_vocabulary_green(char letter, int position, char **vocabulary, size_t num_words):
    initialize int to 0
    for each word in vocabulary:
        if word is not NULL:
            if word at position is not letter:
                free word
                set word to NULL
                increment int
    return int





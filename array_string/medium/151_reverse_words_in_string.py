class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.split()
        ret = ""
        for i in range(1, len(s) + 1):
            if i == len(s):
                ret += s[-i]
            else:
                ret += s[-i] + " "
        return ret
    
"""
C
char* reverseWords(char* s) {
    int capacity = 16;
    char **word_list = (char **)malloc(sizeof(char *) * capacity);

    char *token = strtok(s, " ");
    int word_count = 0;
    while (token != NULL) {
        if (capacity == word_count) {
            capacity *= 2;
            word_list = realloc(word_list, capacity * sizeof(char *));
            if (word_list == NULL) {
                return 1;
            }
        }
        word_list[word_count] = token;

        word_count++;
        token = strtok(NULL, " ");
    }
    int str_len = 0;
    for (int i=0; i<word_count; i++) {
        str_len += strlen(word_list[i]) + 1;
    }
    char *ret = (char *)malloc(sizeof(char) * str_len);
    ret[0] = '\0';
    for (int i=0; i<word_count; i++) {
        strcat(ret, word_list[word_count-i-1]);
        if (i != word_count-1) {
            strcat(ret, " ");
        }
    }

    return ret;
}"""
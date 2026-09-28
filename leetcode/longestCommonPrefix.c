char* longestCommonPrefix(char** strs, int strsSize) {
    char * lcp = calloc(200,sizeof(char));

    int i=0;
    while (i < (int)strlen(strs[0])) {

        char at = strs[0][i];
        for (int j=1; j<strsSize; j++) {
            if (strs[j][i]!=at) return lcp;
        }
        lcp[i++] = at;
    }
    
    return lcp;
}
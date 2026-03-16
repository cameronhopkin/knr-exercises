/* squeeze: delete each char in s1 that matches any char in s2 */
void squeeze(char s1[], char s2[])
{
    int i, j, k;
    int match;

    for (i = k = 0; s1[i] != '\0'; i++) {
        match = 0; /* Assume no match for this char */
        
        /* Check current s1[i] against all of s2 */
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                match = 1; /* Found a match, mark for deletion */
                break;
            }
        }

        /* If no match was found, keep the character */
        if (!match) {
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0'; /* Don't forget the null terminator */
}

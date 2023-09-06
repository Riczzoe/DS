#include <stdio.h>
#include <string.h>

#define     NOT_MATCH   -1

/*
 * brute_force_search() - Performs a brute-force search to find the position
 * of a pattern string within a text string.This implementation uses pointer 
 * arithmetic
 *
 * @pat:    Pointer to the pattern string
 * @txt:    Pointer to the text string
 *
 * Return:  
 *  -1  if the pattern string is not found
 *  >=0 the position of the pattern string within the text string
 */
int brute_force_search(char *pat, char *txt) 
{
    char *pp = pat, *tp;
    int i, j, patlen = 0;
    
    /* calculate the length of the pattern string */
    while (*pp++)
        patlen++;
    
    for (i = 0; *txt != '\0'; txt++, i++) {
        /* for each strating position in the txt, attempt to match it
         * with the pattern string
         */
        for (j = 0, pp = pat, tp = txt; *pp != '\0' && *tp != '\0';
                pp++, tp++, j++) {
            /* if characters don't match, break out */
            if (*pp != *tp)
                break;
        }
        /* if we've reached the end of the pattern string, a match is found */
        if (*pp == '\0')
            return i;
        /* if we've reached the end of the text string, that means no match */
        if (*tp == '\0')
            return NOT_MATCH;
    }

    return NOT_MATCH;
}

/*
 * brute_force_search_without_point() - Performs a brute-force search to find
 * the position of a pattern string within a text string.This implementation 
 * uses array indexing.
 *
 * @pat:    Pointer to the pattern string
 * @txt:    Pointer to the text string
 *
 * Return:
 *  -1  if the pattern string is not found
 *  >=0 the position of the pattern string within the text string
 */
int brute_force_search_without_point(char *pat, char *txt) 
{
    int plen = strlen(pat);
    int tlen = strlen(txt);
    int i, j;

    for (i = 0; i < tlen; i++) {
        for (j = 0; j < plen; j++) {
            if (pat[j] != txt[i + j])
                break;
        }
        if (j == plen)
            return i;
    }
    return NOT_MATCH;
}

/*
 * explicit_backup_search() - Performs a brute-force search to find the 
 * position of a pattern string within a text string. This implementation 
 * uses explicit backup to reset the search position.
 *
 * @pat:    Pointer to the pattern string
 * @txt:    Pointer to the text string
 *
 * Return:
 *  -1  if the pattern string is not found
 *  >=0 the position of the pattern string within the text string
 */
int explicit_backup_search(char *pat, char *txt)
{
    int plen = strlen(pat);
    int tlen = strlen(txt);
    int i, j;
    
    for (i = 0, j = 0; i < tlen && j < plen; i++) {
        /* if the current character in the txt matches the current
         * character in the pat, move to the next character in both
         */
        if (txt[i] == pat[j]) {
            j++;
        } else {
            /* if the characters don't match, reset the position by
             * backing up
             */
            i -= j;
            j = 0;
        }
    }

    if (j == plen)
        return i - plen;
    return NOT_MATCH;
}

/*
 * test_brute_force_search - test brute force search
 *
 * @search: brute force search function
 */
void test_brute_force_search(int (*search)(char *, char *))
{
    int res;
    char *txt = 
        "Man, Myth and Magic exists in several different versions "
        "along with a number of spin-off books which mined its texts "
        "for information and reused its picture archive. The first "
        "edition was the “Illustrated Encyclopedia of the Supernatural” "
        "which appeared in the UK each week from 1970 to 1971 as 112 "
        "magazine-sized issues, a series that built eventually into a "
        "collection of seven volumes. The first issue famously used a "
        "detail of a picture by Austin Osman Spare on its cover, giving "
        "Spare and his art a prominence unlike anything he received "
        "during his lifetime. The same part-work was published a couple "
        "of years later in the USA with an accompanying TV ad. Magic "
        "and the supernatural was the selling point but the encyclopedia "
        "was as much about religion and general anthropology as the occult,"
        "with the editorial stance being unsensational, factual and neutral. "
        "The seven-volume set was later republished in book form as 24 "
        "hardcover volumes, then revised in 1995 as a new set of 21 volumes "
        "with a different subtitle, “The Illustrated Encyclopedia of "
        "Mythology, Religion and the Unknown”. In the early 1970s you could "
        "also find a hardback collection of the first six issues bearing "
        "the subtitle “The most unusual book ever published”, a rather "
        "unrealistic claim. My mother bought one of these, giving me my "
        "first encounter with the encyclopedia itself and many other things "
        "besides, not least the Austin Spare drawings in Kenneth Grant’s "
        "piece of borderline cosmic horror about Spare and “resurgent "
        "atavisms”.";
    char *pat = "a new set of 21";
    int patlen = strlen(pat);

    res = search(pat, txt);
    if (res < 0) {
        printf("Pattern not found.\n");
    } else {
        printf("Pattern found at index %d.\n", res);
        printf("pat:  %s\n", pat);
        printf("find: %.*s\n", patlen, txt + res);
    }
}

int main(void) 
{
    printf("test brute_force_search:\n");
    test_brute_force_search(brute_force_search);

    printf("\ntest brute_force_search_without_point:\n");
    test_brute_force_search(brute_force_search_without_point);

    printf("\ntest explicit_backup_search:\n");
    test_brute_force_search(explicit_backup_search);
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                            |\              */
/*   palindrome_measure.c                               ------| \----         */
/*                                                      |    \`  \  |  p      */
/*   By: cshepard6055 <cshepard6055@floridapoly.edu>    |  \`-\   \ |  o      */
/*                                                      |---\  \   `|  l      */
/*   Created: 2017/11/19 19:59:50 by cshepard6055       | ` .\  \   |  y      */
/*   Updated: 2017/11/20 14:26:51 by cshepard6055       -------------         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int strl(char *s){
    int i;
    while(s[i]){
        i++;
    }

    return i;
}

int vi(i, l){
    if(i >= 0 && i< l)
        return 1;
    return 0;
}

int evens(char *s, int l, int i, int t){
    int q;
    q = t;

    if(!vi(i-t, l) || !vi(i+1+t, l))
        return 0;

    if(s[i-t] == s[i+1+t])
        q++;

    else
        return 0;

    return q;
}

int odds(char *s, int l, int i, int y){
    int q;
    q = y++;

    if(!vi(i+y, l) || !vi(i-y, l))
        return 0;

    if(s[i+y] == s[i-y])
        q++;

    else
        return 0;

    return q;
}

int longest(char *s){
    int i, l, r;
    int odd_t, even_t;
    int odd_s, even_s;

    l = strl(s);
    r = 0;

    even_t = 0;
    odd_t = 0;

    odd_s = 0;
    even_s = 0;

    i = 0;
    while(s[i]){
        // set r to the greatest result after calculating

        if(((even_s) * 2) > r)
            r = (even_s) * 2;
        if((odd_s * 2 + 1) > r )
            r = odd_s * 2 + 1;

        even_t = evens(s, l, i, even_s);
        odd_t = odds(s, l, i, odd_s);

        even_s = even_t;
        odd_s = odd_t;

        if(!even_t)
            even_s = 0;

        if(!odd_t)
            odd_s = 0;

        if(!even_t && !odd_t){
            odd_s = 0;
            even_s = 0;
            i++;
        }
    }

    return r;
}

int main(int argc, char **argv){
    if(argc < 2){
        printf("Enter an argument.\n");
        return 0;
    }

    printf(""); // delete this line and you'll get segfaulted.
    printf("Longest palindrome in %s is %d\n", argv[1], longest(argv[1]));

    return 0;
}

/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task07
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n < 0)
        n = (-n);
    while (i < n) {
        if ((s1[i] - s2[i]) != 0) {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (0);
}

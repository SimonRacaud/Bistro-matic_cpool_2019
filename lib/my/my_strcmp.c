/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task06
*/

int my_strncmp(char const *s1, char const *s2, int n);

int my_strcmp(char const *s1, char const *s2)
{
    int size;

    if (sizeof(s1) > sizeof(s2))
        size = sizeof(s1);
    else
        size = sizeof(s2);
    return (my_strncmp(s1, s2, size));
}

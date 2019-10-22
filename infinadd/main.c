/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Main file of the project that contain the main function.
*/

void infinadd(char *str1, char *str2);

int main(int ac, char **av)
{
    if (ac == 3)
        infinadd(av[1], av[2]);

    return (0);
}

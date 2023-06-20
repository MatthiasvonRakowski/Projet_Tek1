/*
** EPITECH PROJECT, 2023
** antman
** File description:
** struct_lzss
*/

#ifndef STRUCT_LZSS_H
    #define STRUCT_LZSS_H
    #define DICO_SIZE 2047

/*----------------------------------STRUCT----------------------------------*/
typedef struct lz_s {
    int buff_pos;
    int dico_pos;
    int pos_f_buff;
    char *buff;
    char *final_str;
    char *dico;
    struct stat st;
} lz_t;

/*---------------------------------PROGRAMME--------------------------------*/
void analyse_buffer(char c, lz_t *lz);
int check_char(lz_t *lz);

/* write programme */
    int write_one_char(char c, lz_t *lz);
    int write_coord_buff(int pos, int size, lz_t *lz);
#endif //STRUCT_LZSS_H

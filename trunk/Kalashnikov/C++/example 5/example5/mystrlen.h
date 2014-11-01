#ifndef MYSTRLEN_H
#define MYSTRLEN_H

int mystrlen (char *str){
    int i;

    for (i = 0; str[i]; i++);

    return i-1;
}

#endif // MYSTRLEN_H

void clear_screen(){
    #ifdef __unix__
    system("clear");

    #elif _Win32
    system("cls");
    
    else
    printf("Não conseguimos detectar seus sistema operacional");
}
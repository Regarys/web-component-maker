#include <stdio.h>
#include <sys/stat.h>
#include "index_html.h"
#include <unistd.h>

void template_maker_html(){
    FILE *file = fopen("index.html", "wb");
    if (file == NULL){
        perror("fopen");
        return;
    }

    fwrite(templates_index_html, 1, templates_index_html_len, file);

    fclose(file);
}

void template_maker_css(){
    FILE *file = fopen("style.css", "wb");
    if (file == NULL){
        perror("fopen");
        return;
    }
    fclose(file);
}

void template_maker_js(){
    FILE *file = fopen("script.js", "wb");
    if (file == NULL){
        perror("fopen");
        return;
    }
    fclose(file);
}


int main (int argc, char *argv[]) {
    if (argc < 2) {
        printf("How to use :%s <project-name>\n", argv[0]);
        return 1;
    }

    mkdir(argv[1], 0755);
    if (chdir(argv[1])!=0){
        perror("chdir");
        return 1;
    }
    template_maker_html();
    template_maker_css();
    template_maker_js();
    printf("html, css, js > created! Happy coding!\n");
    return 0;
}

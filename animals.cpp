#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)

using namespace std;

int main() {
    char* query_string = getenv("QUERY_STRING");
    char* name = NULL;
    char* animal = NULL;

    char* token = strtok(query_string, "&");

    while (token != NULL) {
        char* equal_sign = strchr(token, '=');
        if (equal_sign != NULL) {
            char* value = equal_sign + 1;
            if (strncmp(token, "name", equal_sign - token) == 0) {
                name = value;
            }
            else if (strncmp(token, "animal", equal_sign - token) == 0) {
                animal = value;
            }
        }
        token = strtok(NULL, "&");
    }

    printf("Content-type: text/html\n\n");
    printf("<html>\n");
    printf("<head>\n");
    printf("<link rel=\"stylesheet\" href=\"style.css\">\n");
    printf("</head>\n");
    printf("<body>\n");
    printf("<div class=\"headerArea\">Pet Facts!</div>\n");
    printf("<div class=\"division-line\"></div>\n");
    printf("<div class=\"greetingArea\">\n");
    printf("Hello, %s! You selected to learn more about the %s.\n", name, animal);
    printf("<br>Look how amazing they can be!\n");
    printf("</div>\n");
    printf("<div class=\"division-line\"></div>\n");
    printf("<div class=\"imageArea\">\n");
    printf("<img src=\"theZoo/%s.png\" alt=\"image\">\n", animal);
    printf("</div>\n");
    
    //////////////////////////////////////////

    //char filePath[256] = { NULL };
    //snprintf(filePath, sizeof(filePath), "theZoo/%s.txt", animal);
   // printf("<br>TESTTEST: %s:\n", filePath);
    
    FILE* fp = NULL;
    char line[256] = { '\0' };
    int lineCount = 1;
    int arrLineCount = 0;
    
    fp = fopen("C:/localWebSite/WDD/ZOO/theZoo/fox.txt", "r");

    if (fp == NULL)
    {
        printf("Error-fopen function: Can't open file for reading\n");
        return -1;
    }

    int count = 1;
    printf("<div class=\"description-line\">");
    while (fgets(line, sizeof(line), fp)) {
        
        if (count == 1) {
            printf("<div class=\"description-line-first\" style='font-size: 18px;'>%s</div>\n", line);
        }
        else if (count == 2) {
            printf("<div class=\"description-line-second\" style='font-size: 20px;'>%s</div>\n", line);
        }
        else {
            printf("<div class=\"description-line-third\" style='font-size: 16px;'>%s</div>\n", line);
        }
        count++;
    }
    printf("</div>\n");

    printf("</body>\n</html>");
    fclose(fp);
    return 0;
}
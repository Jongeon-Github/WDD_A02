/*
* Filename: animals.cpp
* Project: Assignment 2
* By: Jongeon Lee
* Student number: 8790144
* Date: Oct 14, 2023
* Description: A CGI script that displays information about a selected animal based on user input.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#pragma warning(disable : 4996)

using namespace std;

int main() {
    // Get query parameters from the URL
    char* query_string = getenv("QUERY_STRING");

    // Initialize variables to store user input
    char* name = NULL;
    char* animal = NULL;

    // Parsing the name and animals
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

    // Output the HTTP header
    printf("Content-type: text/html\n\n");

    // Start the HTML content
    printf("<html>\n");
    printf("<head>\n");
    printf("<link rel=\"stylesheet\" href=\"style.css\">\n");
    printf("<title>Animal Serve in CGI</title>\n");
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

    // TXT file open and read function
    char filePath[256] = { NULL };
    snprintf(filePath, sizeof(filePath), "theZoo/%s.txt", animal);

    FILE* fp = fopen(filePath, "r");

    // Error check
    char line[256] = { '\0' };
    if (fp == NULL)
    {
        printf("Error-fopen function: Can't open file for reading\n");
        return -1;
    }

    // Read file contents
    int count = 1;
    printf("<div class=\"description-line\">");
    while (fgets(line, sizeof(line), fp)) {

        if (count == 1) {
            printf("<div class=\"description-line-first\" style='font-size: 22px;'>%s</div>\n", line);
        }
        else if (count == 2) {
            printf("<div class=\"description-line-second\" style='font-size: 25px;'>%s</div>\n", line);
        }
        else {
            printf("<div class=\"description-line-third\" style='font-size: 18px;'>%s</div>\n", line);
        }
        count++;
    }
    printf("</div>\n");

    printf("</body>\n</html>");

    // File close
    fclose(fp);
    return 0;
}
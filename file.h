#include <stdio.h>

#include "globals.h"
#include "errors.h"
#include "structs.h" /* for word nodes in writeObject() */

/* The file extentions */
#define SRC_ET ".as"
#define OBJ_ET ".ob"
#define ENT_ET ".ent"
#define EXT_ET ".ext"


/* The file open mode */
#define READ_ONLY "r"
#define READ_WRITE "r+"
#define WRITE_ONLY "w"
#define WRITE_READ "w+"
#define UPDATE_ONLY "a"
#define UPDATE_READ "a+"

extern IC;
extern DC;


/* file object - will hold raw file name without extenstions and all related file handlers (FILE *) */
typedef struct
{
    char *rawName;
    FILE *src, *ent, *ext, *obj;
}fileObject;


/*                                                                                                           *\
********************************************* FUNCTION PROTOTYPE **********************************************
\*                                                                                                           */

void fetchLine(FILE *, char **);
void writeEntry(fileObject *, char *, int);
void writeExtern(fileObject *, char *, int);
void writeObjectHeadLine(fileObject *, int, int);
void writeObject(fileObject *);
void writeDtListToObject(fileObject *);
fileObject *fetchFile(char *, char *);
void closeFile(fileObject *);
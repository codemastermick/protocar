#ifndef ERRORS_H /* include guards */
#define ERRORS_H

extern char *erroredSystem;
extern char *errorMessage;

void throwError(char *system, char *msg);
void printError();

#endif /* ERRORS_H */
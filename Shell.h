#include <elf.h>

#include "linker.h"

#ifndef _SHELL_H_
#define _SHELL_H_

#define MAX_NAME_LENGTH 256

#ifdef __cplusplus
extern "C" {
#endif

/*__attribute__((constructor)) */void init();

#ifdef __cplusplus
}
#endif

class Shell {
private:
    char libraryName[MAX_NAME_LENGTH];
    soinfo backupShellSoInfo;
    soinfo *shellSoInfo;
    soinfo *clientSoInfo;

public:
    Shell();
    ~Shell();
    void loadClientLibrary();
    void syncSoInfo();
};

#endif
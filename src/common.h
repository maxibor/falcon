#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include "models.h"
#include "defs.h"
#include "param.h"

typedef struct{
  uint64_t size;
  uint64_t bytes;
  }
INF;

/*
uint8_t PackLT[5][10] = {
  { 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29 },
  { 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33 },
  { 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D },
  { 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47 },
  { 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51 }
  };
*/
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef struct{
  uint8_t sym;
  uint8_t value;
  }
SymValue;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void        Fclose           (FILE *);
void        Fseeko           (FILE *, off_t, int32_t);
uint64_t    Ftello           (FILE *);
double      BoundDouble      (double, double, double);
double      BPBB             (double, uint64_t);
unsigned    QuadQuantization (double);
uint8_t     PackByte         (double, uint8_t);
void        UnPackByte       (SymValue *, uint8_t);
FILE        *Fopen           (const char *, const char *);
uint64_t    SumWriteBits     (uint8_t **, int, uint64_t, FILE *, FILE *);
void        ShiftBuffer      (uint8_t *, int, uint8_t);
void        FillLogTable     (uint32_t, uint32_t, uint32_t);
double      SearchLog        (uint32_t );
double      Power            (double, double);
uint32_t    FLog2            (uint64_t );
char        *ReplaceSubStr   (char *, char *, char *);
int         FileExists       (const char *);
uint8_t     DNASymToNum      (uint8_t  );
uint8_t     NumToDNASym      (uint8_t  );
uint8_t     GetCompNum       (uint8_t  );
uint8_t     GetCompSym       (uint8_t  );
uint64_t    NDNASyminFile    (FILE *);
uint64_t    NDNASymInFastq   (FILE *);
uint64_t    NDNASymInFasta   (FILE *);
uint64_t    NBytesInFile     (FILE *);
uint64_t    FopenBytesInFile (const char *);
uint8_t     *ReverseStr      (uint8_t *, uint32_t);
char        *CloneString     (char *   );
char        *RepString       (const char *, const char *, const char *);
uint32_t    ArgsNum          (uint32_t , char *[], uint32_t, char *, uint32_t,
                              uint32_t);
uint64_t    ArgsNum64        (uint64_t , char *[], uint32_t, char *, uint64_t,
                              uint64_t);
ModelPar    ArgsUniqModel    (char *, uint8_t);
ModelPar    ArgsModel        (uint32_t , char *[], uint32_t, char *);
double      ArgsDouble       (double, char *[], uint32_t, char *);
uint8_t     ArgsState        (uint8_t  , char *[], uint32_t, char *);
char        *ArgsString      (char    *, char *[], uint32_t, char *);
char        *ArgsFiles       (char *[], uint32_t, char *);
void        TestReadFile     (char *);
uint8_t     CmpCheckSum      (uint32_t, uint32_t);
void        FAccessWPerm     (char    *);
inline void CalcProgress     (uint64_t , uint64_t);
void        PrintArgs        (Parameters *, Threads, char *, char *, uint32_t);
void        PrintArgsFilter  (EYEPARAM *);
void        PrintArgsEye     (EYEPARAM *);
char        *concatenate     (char *, char *);
int32_t     StrToArgv        (char *, char ***);
char        *ArgsFilesImg    (char *[], uint32_t, char *);
char        *ArgsFile        (char *[], uint32_t, char *);
char        *ArgsFileGen     (char *[], uint32_t, char *, char *, char *);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#endif

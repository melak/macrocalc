/* mcolor.c */

#include <string.h>
#include <stdlib.h>
#include <arx_def.h>
#include <cur_def.h>
#include "mc.h"
#include "mcolor.h"

typedef struct attrel {
  int ccode;
  int cattr;
  int foreg;
  int backg;
} attrel;

static attrel attrels[] = {
  { COL_BLACK, A_NORMAL, COLOR_BLACK, COLOR_WHITE },
  { COL_RED, A_NORMAL, COLOR_RED, COLOR_WHITE },
  { COL_GREEN, A_NORMAL, COLOR_GREEN, COLOR_WHITE },
  { COL_YELLOW, A_NORMAL, COLOR_YELLOW, COLOR_WHITE },
  { COL_BLUE, A_NORMAL, COLOR_BLUE, COLOR_WHITE },
  { COL_MAGENTA, A_NORMAL, COLOR_MAGENTA, COLOR_WHITE },
  { COL_CYAN, A_NORMAL, COLOR_CYAN, COLOR_WHITE },
  { COL_WHITE, A_NORMAL, COLOR_WHITE, COLOR_WHITE },
  { TEXTCOLOR, A_NORMAL, 0, 0 },
  { EOFCOLOR, A_BOLD, 0, 0 },
  { ERRORCOLOR, A_BLINK, 0, 0 },
  { VALUECOLOR, A_NORMAL, 0, 0 },
  { FORMULACOLOR, A_NORMAL, 0, 0 },
  { STRINGCOLOR, A_NORMAL, 0, 0 },
  { BLANKCOLOR, A_NORMAL, 0, 0 },
  { HEADERCOLOR, A_REVERSE, COLOR_BLACK, COLOR_CYAN },
  { CURHEADERCOLOR, A_BOLD, 0, 0 },
  { HIGHLIGHTCOLOR, A_REVERSE, 0, 0 },
  { HIGHLIGHTERRORCOLOR, A_REVERSE|A_BLINK, 0, 0 },
  { MARKCOLOR, A_REVERSE, 0, 0 },
  { AUTOCALCCOLOR, A_REVERSE, 0, 0 },
  { FORMDISPLAYCOLOR, A_REVERSE, 0, 0 },
  { MESSAGECOLOR, A_BOLD|A_BLINK, 0, 0 },
  { PROMPTCOLOR, A_BOLD, 0, 0 },
  { INPUTCOLOR, A_REVERSE, 0, 0 },
  { COMMANDCOLOR, A_UNDERLINE, 0, 0 },
  { CELLCONTENTSCOLOR, A_NORMAL, 0, 0 },
  {	BOLDCOLOR, A_BOLD, 0, 0 },
  {	ITALICOLOR, A_UNDERLINE, 0, 0 },
  { COL_UNDEF, 0, 0, 0 }
};

int mcode2att(int colcode) {
return attrels[colcode].cattr;
}

void mcolor0(void) {
int i;

for (i=0; i<COL_UNDEF; i++) {
  init_pair(i, attrels[i].backg, attrels[i].foreg);
}
}

void setcolor(int pairi) {
if (colors) {
 if (attrels[pairi].foreg + attrels[pairi].backg) {
  attron(COLOR_PAIR(pairi));
 }
}
}

void uncolor(int pairi) {
if (colors) {
 if (attrels[pairi].foreg + attrels[pairi].backg) {
  attroff(COLOR_PAIR(pairi));
 }
}
}

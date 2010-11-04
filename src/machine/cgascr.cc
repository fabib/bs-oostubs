/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                             C G A _ S C R E E N                           *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "machine/cgascr.h"
#include "machine/io_port.h"

#define SCR_HEIGHT 25
#define SCR_WIDTH  80
#define VROFF(x,y) (SCR_WIDTH*2*(y)+(x)*2)

CGA_Screen::CGA_Screen() : cursor_idx(0x3D4), cursor_dta(0x3D5) {
  vram = (char*) 0xB8000;
  setpos(0,0);
  clear();
}
CGA_Screen::~CGA_Screen() {}

void CGA_Screen::clear() {
  for (int i = 0; i <= VROFF(SCR_WIDTH - 1, SCR_HEIGHT); i++) vram[i] = 0;
}

void CGA_Screen::getpos(unsigned short & x, unsigned short & y) const {
  UShort offset;
  cursor_idx.outb(14);
  offset.byte.high = cursor_dta.inb();
  cursor_idx.outb(15);
  offset.byte.low = cursor_dta.inb();
  y = offset.value / SCR_WIDTH;
  x = offset.value % SCR_WIDTH;
}

void CGA_Screen::setpos(unsigned short x, unsigned short y) {
  UShort offset;
  offset.value = SCR_WIDTH * y + x;
  cursor_idx.outb(14);
  cursor_dta.outb(offset.byte.high);
  cursor_idx.outb(15);
  cursor_dta.outb(offset.byte.low);
}

void CGA_Screen::show(unsigned short x, unsigned short y, char c, unsigned char attrib) {
  vram[VROFF(x, y)]     = c;
  vram[VROFF(x, y) + 1] = attrib;
}

void CGA_Screen::print(const char* string, unsigned int n, unsigned char attrib) {
  unsigned short x, y;
  getpos(x, y);
  for (int i = 0; i <= (int) n; i++) {
    if (x > SCR_WIDTH) { y++; x = 0; }
    if (string[i] == '\n') {
      y++; x = 0;
    } else {
      show(x, y, string[i], attrib);
      x++;
    }
  }
  setpos(x, y);
}

void CGA_Screen::scrollup() {
  int i;
  for (i = SCR_WIDTH*2; i <= VROFF(SCR_WIDTH, SCR_HEIGHT - 1); i++)
      vram[i - SCR_WIDTH*2] = vram[i];
  for (i = 0; i <= SCR_WIDTH; i++)
      show(i, SCR_HEIGHT - 1, ' ', 0);
}

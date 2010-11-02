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

CGA_Screen::CGA_Screen() : cursor_idx(0x3D4), cursor_dta(0x3D5) {
  vram = (char*) 0xB8000;
  setpos(0,0);
}
CGA_Screen::~CGA_Screen() {}

void CGA_Screen::clear() {
  for (int i = 0; i <= (SCR_HEIGHT * SCR_WIDTH * 2); i++) {
    vram[i] = 0;
  }
}

void CGA_Screen::getpos(unsigned short & x, unsigned short & y) const {
  unsigned short offset;
  cursor_idx.outb(14);
  offset = cursor_dta.inb() << 8;
  cursor_idx.outb(15);
  offset += cursor_dta.inb();

  y = offset / SCR_WIDTH;
  x = offset % SCR_WIDTH;
}

void CGA_Screen::setpos(unsigned short x, unsigned short y) {
  unsigned short offset = SCR_WIDTH * y + x;
  cursor_idx.outb(15);
  cursor_dta.outb(offset);
  cursor_idx.outb(14);
  cursor_dta.outb(offset >> 8);
}

void CGA_Screen::show(unsigned short x, unsigned short y, char c, unsigned char attrib) {
  int offset = (SCR_WIDTH * y * 2) + (x * 2);
  vram[offset] = c;
  vram[offset + 1] = attrib;
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

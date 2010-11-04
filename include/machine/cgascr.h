/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                             C G A _ S C R E E N                           *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __screen_include__
#define __screen_include__

/* INCLUDES */
#include "machine/io_port.h"

/** \brief CGA-Dispaly driver
 *
 * CGA_Screen enables the basic control of the screen of a computer by accessing
 * the screen memory and I/O ports directly.
 */
class CGA_Screen {
public:
  /** \brief Constructor
   **/
  CGA_Screen();

  /** \brief Destructor
   **/
  ~CGA_Screen();

  /** \brief set the cursor position
   * \param x column number of new position
   * \param y row number of new position
   */
  void setpos(unsigned short x, unsigned short y);

  /** \brief get the cursor position
   * \param x reference for column number of current position
   * \param y reference for row number of curent position
   */
  void getpos(unsigned short& x, unsigned short& y) const;

  /** \brief print a character to a specific position
   * \param x column number of display position
   * \param y row number of display position
   * \param c character to be displayed
   * \param attrib display attributs
   */
  void show(unsigned short x, unsigned short y, char c, unsigned char attrib);

  /** \brief print a string to the current position
   * \param string string of characters to be displayed
   * \param n number auf characters in string
   * \param attrib display attributs
   */
  void print(const char* string, unsigned int n, unsigned char attrib);

  /** \brief scroll the display one line upwards
   **/
  void scrollup();

  /** \brief clear the screen
   **/
  void clear();

private:
  char* vram;
  IO_Port cursor_idx, cursor_dta;

  union UShort {
    unsigned short value;
    struct {
      unsigned char low;
      unsigned char high;
    } byte;
  };
};

#endif

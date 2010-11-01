/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                             C G A _ S C R E E N                           *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __screen_include__
#define __screen_include__

/** \brief CGA-Dispaly driver
 *
 * CGA_Screen enables the basic control of the screen of a computer by accessing
 * the screen memory and I/O ports directly.
 */
class CGA_Screen {

public:

  /** \brief Constructor
   *
   * \todo write implementation
   **/
  CGA_Screen();

  /** \brief Destructor
   *
   * \todo write implementation
   **/
  ~CGA_Screen();

  /**
   * Method setpos() sets a new position for the screen cursor.
   *
   * \todo write implementation
   *
   * @param x column number of new position 
   * @param y row number of new position
   */
  void setpos(unsigned short x, unsigned short y);

  /**
   * Method getpos() gets the current position of the screen cursor.
   *
   * \todo write implementation
   *
   * @param x reference for column number of current position
   * @param y reference for row number of curent position
   */
  void getpos(unsigned short& x, unsigned short& y) const;

  /**
   * Method show() displays a character at a given position using the 
   * specified attributs.
   *
   * \todo write implementation
   *
   * @param x column number of display position
   * @param y row number of display position
   * @param c character to be displayed
   * @param attrib display attributs
   */
  void show(unsigned short x, unsigned short y, char c, unsigned char attrib);

  /**
   * Method print() displays a string of characters starting at the current 
   * position of the cursor.
   * 
   * \todo write implementation
   *
   * @param string string of characters to be displayed
   * @param n number auf characters in string
   * @param attrib display attributs
   */
  void print(const char* string, unsigned int n, unsigned char attrib);

  /**
   * Method scrollup() scrolls the screen one row up. 
   * The new row at the bottom of the screen contains only spaces.
   *
   *  \todo write implementation
   */
  void scrollup();

  /** \brief clears the screen
   *
   *  \todo write implementation
   **/
  void clear();
};

#endif

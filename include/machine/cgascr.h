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

  /** \brief set the cursor position
   *
   * \todo write implementation
   *
   * \param x column number of new position 
   * \param y row number of new position
   */
  void setpos(unsigned short x, unsigned short y);

  /** \brief get the cursor position
   *
   * \todo write implementation
   *
   * \param x reference for column number of current position
   * \param y reference for row number of curent position
   */
  void getpos(unsigned short& x, unsigned short& y) const;

  /** \brief print a character to a specific position
   *
   * \todo write implementation
   *
   * \param x column number of display position
   * \param y row number of display position
   * \param c character to be displayed
   * \param attrib display attributs
   */
  void show(unsigned short x, unsigned short y, char c, unsigned char attrib);

  /** \brief print a string to the current position
   * 
   * \todo write implementation
   *
   * \param string string of characters to be displayed
   * \param n number auf characters in string
   * \param attrib display attributs
   */
  void print(const char* string, unsigned int n, unsigned char attrib);

  /** \brief scroll the display one line upwards
   *
   * \todo write implementation
   *
   * The new row at the bottom of the screen is filled with spaces.
   **/
  void scrollup();

  /** \brief clear the screen
   *
   * \todo write implementation
   **/
  void clear();
};

#endif

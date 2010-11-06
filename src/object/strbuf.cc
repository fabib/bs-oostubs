/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                       S T R I N G B U F F E R                             *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "object/strbuf.h"



Stringbuffer::Stringbuffer()
{
pos = buffer;

}

Stringbuffer::~Stringbuffer(){
}

void Stringbuffer::put(char c)
{
if(pos >= buffer+16){
flush();
pos=buffer;
}
*pos = c;
pos++;
}

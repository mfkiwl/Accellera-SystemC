/*****************************************************************************

  The following code is derived, directly or indirectly, from the SystemC
  source code Copyright (c) 1996-2014 by all Contributors.
  All Rights reserved.

  The contents of this file are subject to the restrictions and limitations
  set forth in the SystemC Open Source License (the "License");
  You may not use this file except in compliance with such restrictions and
  limitations. You may obtain instructions on how to receive a copy of the
  License at http://www.accellera.org/. Software distributed by Contributors
  under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
  ANY KIND, either express or implied. See the License for the specific
  language governing rights and limitations under the License.

 *****************************************************************************/

/*****************************************************************************

  test.cpp -- 

  Original Author: Martin Janssen, Synopsys, Inc., 2002-02-15

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/

/* 
   Verifies directive line_label.
   Author: PRP 
   From PR 358 - Check that directive is accepted when followed
   by a labelled statement
*/

#include "systemc.h"
#include "test.h"

void test::entry() 
{
  int y,j,i;

     y = 3;

      i = 3;

      switch (i) {
      case 0:
	y = 1;
      j = 2;
      case 1:
	y = y + 1;
	break;
      case 2:
	y = y + 1;
      j = 2;
      default:
	y = y + 1;
	break;
      }
      j = 4;
      j = 2;
 pp: j = 8;
  wait();
 
}

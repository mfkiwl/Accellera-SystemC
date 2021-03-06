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

  tb.h -- 

  Original Author: Martin Janssen, Synopsys, Inc., 2002-02-15

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/

/******************************************************************************/
/***************************   Testbench Function        **********************/
/******************************************************************************/
/*									      */
/*	The testbench module has the following hierarchy:		      */
/*									      */
/*	testbench							      */
/*	  - RESET_STIM							      */
/*	  - DATA_GEN							      */
/*									      */
/******************************************************************************/

struct testbench : public sc_module {
  sc_signal<int>	addr;	     // Address of input memory 
  sc_signal<bool>     	reset;
  sc_signal<bool>     	ready;
  signal_bool_vector8  	data;
  signal_bool_vector4   sum;
  RESET_STIM	    	rd1;
  DATA_GEN		dg1;
  ADD_CHAIN		ac1;
  DISPLAY		d1;

  /*** Constructor ***/ 
  testbench ( const sc_module_name& NAME,
	      sc_clock&   TICK  )

    : sc_module(),
  	rd1 ("RD1", TICK, ready, reset, addr),
	dg1 ("DG1", TICK, ready, data, addr),
	ac1 ("AC1", TICK, reset, data, sum, ready),
	d1  ("D1",  ready, data, sum)		
	 
    {
	end_module();
    }
};

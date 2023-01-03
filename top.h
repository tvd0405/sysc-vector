/*
 * top.h
 *
 *  Created on: Dec 29, 2022
 *      Author: user5
 */

#ifndef TOP_H_
#define TOP_H_
#include "defines.h"
#include "tb.h"
#include "fir.h"

SC_MODULE(top) {
   sc_clock clk;
   sc_signal<bool> rst_n;

   sc_vector < sc_signal < input_t > > input;
   sc_vector < sc_signal <output_t > > output;

   tb m_tb;
   fir m_fir;

   SC_CTOR(top):
      clk ("clk", CLK_PERIOD, CLK_UNIT),
	  rst_n("rst_n"),
	  input("input", PSIZE),
	  output("output", PSIZE),
      m_tb("m_tb"),
      m_fir("fir")
   {
      m_fir.clk(clk);
      m_tb.clk(clk);
      m_fir.rst_n(rst_n);
      m_tb.rst_n(rst_n);

	  m_fir.input(input);
	  m_tb.input(input);
	  m_fir.output(output);
	  m_tb.output(output);
   }
};
#endif /* TOP_H_ */

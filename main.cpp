/*
 * main.cpp
 *
 *  Created on: Dec 29, 2022
 *      Author: user5
 */
#include <systemc>
#include "top.h"
#include <cstring>

int sc_main(int, char*[])
{
   top m_top("m_top");
   sc_trace_file* tfile = sc_create_vcd_trace_file("trace");
   sc_trace(tfile, m_top.clk, "clk");
   sc_trace(tfile, m_top.rst_n, "rst_n");
   sc_trace(tfile, m_top.input[0], "input0");
   sc_trace(tfile, m_top.output[0], "output0");
#if PSIZE == 2
   sc_trace(tfile, m_top.input[1], "input1");
   sc_trace(tfile, m_top.output[1], "output1");
#endif
   sc_start();
   sc_close_vcd_trace_file(tfile);
   return(0);
}

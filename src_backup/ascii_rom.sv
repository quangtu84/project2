// *************************************************************
// Created by David J. Marion aka FPGA Dude
// A ROM containing patterns for ASCII values.
//
// Non-printable characters 00 - 1f, and 7f
// Printable characters 20 - 7e
//
// Not all character ROMs have been patterned.
// Only numbers, capital letters, some spec chars. 
//		Numbers       30 - 39
//   	Letters       41 - 5a 
//      (smiley face)   01
//		(space)         20
//		   .            2e
// 		   :            3a
//		   |	        7c	
//
// The 7-bit ASCII code for each character is used as
// the MSB of the address. The 4-bit LSB is the row value.
// *************************************************************

module ascii_rom(
	input logic [9:0] addr_i,
	output logic [7:0] data_o
);
    localparam ADDRESS = 10;

    reg [7:0] mem [0:(1<<ADDRESS)-1]; // (1<<A)xD bit memory

    assign data_o = mem[addr_i]; // read memory to dout (async)

    initial begin
    $readmemb("pixel/ascii_text_mod.bin", mem);
    end
endmodule

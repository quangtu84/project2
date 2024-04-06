module mem_tile #(
  parameter ADDRESS = 13,
  parameter COLOR_BITS = 24
) (
  input  logic [ADDRESS-1:0]    addr,	// address
  output logic [COLOR_BITS-1:0] dout	// data output
);
  
  reg [COLOR_BITS-1:0] mem [0:(1<<ADDRESS)-1]; // (1<<A)xD bit memory
  
  assign dout = mem[addr]; // read memory to dout (async)
  
  initial begin
    if (COLOR_BITS == 24) $readmemh("pixel/24bit_rgb.txt",mem);
    else if(COLOR_BITS == 12) $readmemh("pixel/12bit_rgb.txt",mem);
  end
endmodule

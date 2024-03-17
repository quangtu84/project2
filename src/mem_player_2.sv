module mem_player_2 #(
  parameter ADDRESS = 11,
  parameter COLOR_BITS = 24
) (
  input  logic [ADDRESS-1:0]    addr,	// address
  output logic [COLOR_BITS-1:0] dout	// data output
);
  
  reg [COLOR_BITS-1:0] mem [0:(1<<ADDRESS)-1]; // (1<<A)xD bit memory
  
  assign dout = mem[addr]; // read memory to dout (async)
  
  initial begin
    if (COLOR_BITS == 24) $readmemh("24bit_rgb_player_2.txt",mem);
    else if(COLOR_BITS == 12) $readmemh("12bit_rgb_player.txt",mem);
  end
endmodule

module clk_reduce (
    input logic clk_i,
    output logic VGA_clk_o
);
    logic a;

    always_ff @(posedge clk_i) begin
        a <= ~a;
        VGA_clk_o <= a;
    end
endmodule

module pulse_gen (
    input logic clk,               // Input clock (250Hz)
    input logic reset,             // Active high reset
    input logic enable,            // Active high enable signal
    output logic random_pulse      // Random pulse output
);
    // Parameters
    parameter int LFSR_WIDTH = 7;  // Width of LFSR (7 bits)
    parameter int RANDOM_OUTPUT_FREQ = 125; // Desired output frequency (125 Hz)

    // Clock division to generate 125 Hz from 250 Hz
    logic clk_div;
    int counter = 0;

    // LFSR state
    logic [LFSR_WIDTH-1:0] lfsr;
    logic feedback;
    logic continue_gen; // Control signal to continue generation of random pulse

    // Generate 125 Hz clock from 250 Hz clock
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            counter <= 0;
            clk_div <= 0;
        end else begin
            counter <= counter + 1;
            if (counter >= (250 / RANDOM_OUTPUT_FREQ) - 1) begin
                clk_div <= ~clk_div;  // Toggle the clock signal to get 125 Hz
                counter <= 0;
            end
        end
    end
    assign feedback = lfsr[6] ^ lfsr[5] ^ lfsr[4] ^ lfsr[3];
    // LFSR feedback logic
    always_ff @(posedge clk_div or posedge reset) begin
        if (reset) begin
            lfsr <= 7'b1010101; // Initial seed value for LFSR (can be any non-zero value)
            random_pulse <= 0; // Initialize output to 0
            continue_gen <= 1; // Enable generation initially
        end else if (continue_gen) begin
            // Generate feedback for LFSR
             // Example taps for 7-bit LFSR
            lfsr <= {lfsr[LFSR_WIDTH-2:0], feedback}; // Shift LFSR

            // Generate output pulse
            if (lfsr[LFSR_WIDTH-1] == 1) begin
                random_pulse <= 1; // Output logic 1 if MSB is 1
                continue_gen <= 0; // Pause generation after producing '1'
            end else begin
                random_pulse <= 0; // Output logic 0 if MSB is 0
            end
        end
        if (!continue_gen && enable) begin
            continue_gen <= 1; // Continue generating after receiving enable
        end
    end

endmodule

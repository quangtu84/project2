

void set_random(Vtop *dut, vluint64_t sim_unit) {
    dut->reset_i = sim_unit == 1;
};

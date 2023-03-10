-- Copyright (C) 2018  Intel Corporation. All rights reserved.
-- Your use of Intel Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Intel Program License 
-- Subscription Agreement, the Intel Quartus Prime License Agreement,
-- the Intel FPGA IP License Agreement, or other applicable license
-- agreement, including, without limitation, that your use is for
-- the sole purpose of programming logic devices manufactured by
-- Intel and sold by Intel or its authorized distributors.  Please
-- refer to the applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus Prime"
-- VERSION "Version 18.1.0 Build 625 09/12/2018 SJ Lite Edition"

-- DATE "03/09/2023 15:52:58"

-- 
-- Device: Altera EP4CE22F17C6 Package FBGA256
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	hard_block IS
    PORT (
	devoe : IN std_logic;
	devclrn : IN std_logic;
	devpor : IN std_logic
	);
END hard_block;

-- Design Ports Information
-- ~ALTERA_ASDO_DATA1~	=>  Location: PIN_C1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_FLASH_nCE_nCSO~	=>  Location: PIN_D2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_DCLK~	=>  Location: PIN_H1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_DATA0~	=>  Location: PIN_H2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_nCEO~	=>  Location: PIN_F16,	 I/O Standard: 2.5 V,	 Current Strength: 8mA


ARCHITECTURE structure OF hard_block IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL \~ALTERA_ASDO_DATA1~~padout\ : std_logic;
SIGNAL \~ALTERA_FLASH_nCE_nCSO~~padout\ : std_logic;
SIGNAL \~ALTERA_DATA0~~padout\ : std_logic;
SIGNAL \~ALTERA_ASDO_DATA1~~ibuf_o\ : std_logic;
SIGNAL \~ALTERA_FLASH_nCE_nCSO~~ibuf_o\ : std_logic;
SIGNAL \~ALTERA_DATA0~~ibuf_o\ : std_logic;

BEGIN

ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
END structure;


LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	exercicio_1 IS
    PORT (
	A : IN std_logic;
	B : IN std_logic;
	Carry_IN : IN std_logic;
	SUM : OUT std_logic;
	Carry_OUT : OUT std_logic
	);
END exercicio_1;

-- Design Ports Information
-- SUM	=>  Location: PIN_A15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Carry_OUT	=>  Location: PIN_A13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A	=>  Location: PIN_M1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B	=>  Location: PIN_T8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Carry_IN	=>  Location: PIN_B9,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF exercicio_1 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_A : std_logic;
SIGNAL ww_B : std_logic;
SIGNAL ww_Carry_IN : std_logic;
SIGNAL ww_SUM : std_logic;
SIGNAL ww_Carry_OUT : std_logic;
SIGNAL \SUM~output_o\ : std_logic;
SIGNAL \Carry_OUT~output_o\ : std_logic;
SIGNAL \A~input_o\ : std_logic;
SIGNAL \B~input_o\ : std_logic;
SIGNAL \Carry_IN~input_o\ : std_logic;
SIGNAL \SUM~0_combout\ : std_logic;
SIGNAL \Carry_OUT~0_combout\ : std_logic;

COMPONENT hard_block
    PORT (
	devoe : IN std_logic;
	devclrn : IN std_logic;
	devpor : IN std_logic);
END COMPONENT;

BEGIN

ww_A <= A;
ww_B <= B;
ww_Carry_IN <= Carry_IN;
SUM <= ww_SUM;
Carry_OUT <= ww_Carry_OUT;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
auto_generated_inst : hard_block
PORT MAP (
	devoe => ww_devoe,
	devclrn => ww_devclrn,
	devpor => ww_devpor);

-- Location: IOOBUF_X38_Y34_N16
\SUM~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \SUM~0_combout\,
	devoe => ww_devoe,
	o => \SUM~output_o\);

-- Location: IOOBUF_X49_Y34_N2
\Carry_OUT~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Carry_OUT~0_combout\,
	devoe => ww_devoe,
	o => \Carry_OUT~output_o\);

-- Location: IOIBUF_X0_Y16_N22
\A~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A,
	o => \A~input_o\);

-- Location: IOIBUF_X27_Y0_N15
\B~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B,
	o => \B~input_o\);

-- Location: IOIBUF_X25_Y34_N8
\Carry_IN~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Carry_IN,
	o => \Carry_IN~input_o\);

-- Location: LCCOMB_X31_Y30_N24
\SUM~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \SUM~0_combout\ = \A~input_o\ $ (\B~input_o\ $ (\Carry_IN~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010101011010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A~input_o\,
	datac => \B~input_o\,
	datad => \Carry_IN~input_o\,
	combout => \SUM~0_combout\);

-- Location: LCCOMB_X31_Y30_N10
\Carry_OUT~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Carry_OUT~0_combout\ = (\A~input_o\ & ((\B~input_o\) # (\Carry_IN~input_o\))) # (!\A~input_o\ & (\B~input_o\ & \Carry_IN~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A~input_o\,
	datac => \B~input_o\,
	datad => \Carry_IN~input_o\,
	combout => \Carry_OUT~0_combout\);

ww_SUM <= \SUM~output_o\;

ww_Carry_OUT <= \Carry_OUT~output_o\;
END structure;



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

-- DATE "03/09/2023 15:48:50"

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

ENTITY 	exercicio_3 IS
    PORT (
	in_vec : IN std_logic_vector(0 TO 3);
	s_vec : IN std_logic_vector(0 TO 1);
	SAIDA : BUFFER std_logic
	);
END exercicio_3;

-- Design Ports Information
-- SAIDA	=>  Location: PIN_A15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- in_vec[1]	=>  Location: PIN_T8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- s_vec[1]	=>  Location: PIN_E1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- in_vec[2]	=>  Location: PIN_B9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- s_vec[0]	=>  Location: PIN_J15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- in_vec[0]	=>  Location: PIN_M1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- in_vec[3]	=>  Location: PIN_M15,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF exercicio_3 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_in_vec : std_logic_vector(0 TO 3);
SIGNAL ww_s_vec : std_logic_vector(0 TO 1);
SIGNAL ww_SAIDA : std_logic;
SIGNAL \SAIDA~output_o\ : std_logic;
SIGNAL \in_vec[1]~input_o\ : std_logic;
SIGNAL \in_vec[0]~input_o\ : std_logic;
SIGNAL \s_vec[0]~input_o\ : std_logic;
SIGNAL \s_vec[1]~input_o\ : std_logic;
SIGNAL \in_vec[2]~input_o\ : std_logic;
SIGNAL \SAIDA~0_combout\ : std_logic;
SIGNAL \in_vec[3]~input_o\ : std_logic;
SIGNAL \SAIDA~1_combout\ : std_logic;

COMPONENT hard_block
    PORT (
	devoe : IN std_logic;
	devclrn : IN std_logic;
	devpor : IN std_logic);
END COMPONENT;

BEGIN

ww_in_vec <= in_vec;
ww_s_vec <= s_vec;
SAIDA <= ww_SAIDA;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
auto_generated_inst : hard_block
PORT MAP (
	devoe => ww_devoe,
	devclrn => ww_devclrn,
	devpor => ww_devpor);

-- Location: IOOBUF_X38_Y34_N16
\SAIDA~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \SAIDA~1_combout\,
	devoe => ww_devoe,
	o => \SAIDA~output_o\);

-- Location: IOIBUF_X27_Y0_N15
\in_vec[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_in_vec(1),
	o => \in_vec[1]~input_o\);

-- Location: IOIBUF_X0_Y16_N22
\in_vec[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_in_vec(0),
	o => \in_vec[0]~input_o\);

-- Location: IOIBUF_X53_Y14_N1
\s_vec[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_s_vec(0),
	o => \s_vec[0]~input_o\);

-- Location: IOIBUF_X0_Y16_N8
\s_vec[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_s_vec(1),
	o => \s_vec[1]~input_o\);

-- Location: IOIBUF_X25_Y34_N8
\in_vec[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_in_vec(2),
	o => \in_vec[2]~input_o\);

-- Location: LCCOMB_X26_Y16_N24
\SAIDA~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \SAIDA~0_combout\ = (\s_vec[0]~input_o\ & (((\s_vec[1]~input_o\) # (\in_vec[2]~input_o\)))) # (!\s_vec[0]~input_o\ & (\in_vec[0]~input_o\ & (!\s_vec[1]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111011000010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \in_vec[0]~input_o\,
	datab => \s_vec[0]~input_o\,
	datac => \s_vec[1]~input_o\,
	datad => \in_vec[2]~input_o\,
	combout => \SAIDA~0_combout\);

-- Location: IOIBUF_X53_Y17_N15
\in_vec[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_in_vec(3),
	o => \in_vec[3]~input_o\);

-- Location: LCCOMB_X26_Y16_N2
\SAIDA~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \SAIDA~1_combout\ = (\SAIDA~0_combout\ & (((\in_vec[3]~input_o\) # (!\s_vec[1]~input_o\)))) # (!\SAIDA~0_combout\ & (\in_vec[1]~input_o\ & (\s_vec[1]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110110000101100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \in_vec[1]~input_o\,
	datab => \SAIDA~0_combout\,
	datac => \s_vec[1]~input_o\,
	datad => \in_vec[3]~input_o\,
	combout => \SAIDA~1_combout\);

ww_SAIDA <= \SAIDA~output_o\;
END structure;



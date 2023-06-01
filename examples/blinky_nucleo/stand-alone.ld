flash_start       = 0x08000000;
total_flash       = 512K;
header_length     = 256;
bootloader_length = 0K;
bank_length       = 512K;
bank_offset       = 0 * bank_length + bootloader_length;
program_start     = flash_start + bank_offset;
program_length    = bank_length - header_length;
header_start      = program_start + program_length;

ram_start  = 0x20000000;
ram_length = 144K;

MEMORY
{
	PROGRAM(rx) : ORIGIN = program_start, LENGTH = program_length
	HEADER(rx)  : ORIGIN = header_start,  LENGTH = header_length
	RAM(xrx)    : ORIGIN = ram_start,    LENGTH = ram_length
}

/* output sections */
SECTIONS
{
	/* Program code into PROGRAM */
	.text : ALIGN(4)
	{
		*(.isr_vector)
		*(.text)
		*(.text*)
		KEEP(*(.isr_vector))
	} >PROGRAM

    .header :
    {
        KEEP(*(.header.APP_HEADER));
    } > HEADER

	.data : ALIGN(4)
	{
		. = ALIGN(4);
		LINKER_start_data = .; /* Start of data memory in RAM*/

		*(.data)
		*(.data*)

		. = ALIGN(4);
		LINKER_end_data = .; /* End of data memory in RAM*/
		PROVIDE(end = .);
	} >RAM AT>PROGRAM
	/* .data for ram and copy of initialized data AT (in) PROGRAM */

	/* Load address of initial global variable values */
	LINKER_load_data = LOADADDR(.data);
}

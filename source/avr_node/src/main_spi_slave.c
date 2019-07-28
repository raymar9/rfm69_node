#define F_CPU 8000000UL

#include <avr/io.h>
#include <avrhal/io.h>
#include <avrhal/usi_spi.h>

int main (void) {

    Io_SetOutput(PB4);
    Io_SetLow(PB4);

    UsiSpi spi;
    UsiSpi_InitializeSlave(&spi, PB3);

    uint8_t  data_in = UsiSpi_Receive(&spi);

    if (data_in == data_out) {
        Io_SetHigh(PB4);
    }

    return 0;
}

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avrhal/io.h>
#include <avrhal/usi_spi.h>

int main (void) {

    Io_SetOutput(PB4);
    Io_SetLow(PB4);

    UsiSpi spi;
    UsiSpi_InitializeMaster(&spi, PB3);

    uint8_t data_out = 0b10101010;
    UsiSpi_Send(&spi, data_out);
    _delay_ms(1000);
    uint8_t  data_in = UsiSpi_Receive(&spi);

    if (data_in == data_out) {
        Io_SetHigh(PB4);
    }

    return 0;
}

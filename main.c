#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "boards.h"

int main()
{
    bsp_board_init( BSP_INIT_LEDS );

    int leds_blink_times[] = { 6, 6, 0, 3 };

    while (true)
    {
        for( int led_id = 0; led_id < LEDS_NUMBER; ++led_id )
        {
            for ( int blink_count = 0; blink_count < 2 * leds_blink_times[ led_id ]; ++blink_count )
            {
                bsp_board_led_invert( led_id );
                nrf_delay_ms( 500 );
            }
        }
    }
}

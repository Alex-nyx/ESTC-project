#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "boards.h"
#include "nrf_gpio.h"

void init_board_leds( const uint32_t* leds, const int leds_size, const int value );
void led_blink( const int pin, const int blink_time, const int blink_times );

int main()
{
    const int leds_blink_times[] = { 6, 6, 0, 3 };

    const uint32_t leds[] = { NRF_GPIO_PIN_MAP( 0,  6 ), // led 1 - green
                              NRF_GPIO_PIN_MAP( 0,  8 ), // led 2 - red
                              NRF_GPIO_PIN_MAP( 0, 12 ), // led 2 - blue
                              NRF_GPIO_PIN_MAP( 1,  9 )  // led 2 - green
                            };

    init_board_leds( leds, LEDS_NUMBER, true );
    
    while (true)
    {
        for( int led_id = 0; led_id < LEDS_NUMBER; ++led_id )
        {
            led_blink( leds[ led_id ], 500, leds_blink_times[ led_id ] );
        }
    }
}

void init_board_leds( const uint32_t* leds, const int leds_size, const int value )
{
    for ( int i = 0; i < leds_size; ++i )
    {
        nrf_gpio_cfg_output( leds[i] );
        nrf_gpio_pin_write( leds[i], value );
    }
}

void led_blink( const int pin, const int blink_time, const int blink_times )
{
    for ( int blink_count = 0; blink_count <  2 * blink_times; ++blink_count )
    {
        nrf_delay_ms( blink_time );
        nrf_gpio_pin_toggle( pin );
    }
}

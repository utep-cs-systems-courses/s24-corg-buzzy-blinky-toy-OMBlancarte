	.arch msp430g2553
	.p2align 1,0
	.text

	.global led_init
	.global green_on
	.global red_on
	.global toggle_red
	.global toggle_green
	.global lights_on

	.extern P1DIR
	.extern LEDS
	.extern P1OUT
	.extern LED_RED
	.extern LED_GREEN

led_init:

green_on:			;turn green light on if 1 otherwise off
	cmp #0, r12		;r12 will either be 0 or 1
	jz green_off		;jump if Z==1
	bis #64, &P1OUT		;bit 6 is green led
	pop r0			
	
green_off:
	and #~64, &P1OUT	;complement 64 so bit 6 is 0 and no other bits change
	pop r0
red_on:
	cmp #0, r12
	jz red_off
	bis #1, &P1OUT
	pop r0
red_off:
	and #~1, &P1OUT
	pop r0
toggle_red:
	xor #1, &P1OUT
	pop r0
toggle_green:
	xor #64, &P1OUT
	pop r0
lights_on:
	cmp #0, r12
	jz lights_off
	bis #65, &P1OUT
	pop r0
lights_off:
	and #~65, &P1OUT
	pop r0




	

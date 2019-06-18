/*
 * I2C_LCD.h
 *
 * Created: 2018-09-03 오후 12:41:01
 *  Author: 6층교수실PC
 */ 


#ifndef I2C_LCD_H_
#define I2C_LCD_H_

#include "stm32f4xx_hal.h"

#define COMMAND_CLEAR_DISPLAY	0X01
#define COMMAND_DISPLAY_ON_OFF_BIT	2
#define COMMAND_CURSOR_ON_OFF_BIT	1
#define COMMAND_BLINK_ON_OFF_BIT	0

#define START 0x08
//#define SLA_W 0x7e
//#define SLA_W 0x27
#define SLA_W (0x27<<1)

extern I2C_HandleTypeDef hi2c2;

void I2C_LCD_init(void);
void I2C_LCD_write_data(uint8_t data);
void I2C_LCD_write_command(uint8_t command);
void I2C_LCD_clear(void);
void I2C_LCD_write_string(char *string);
void I2C_LCD_goto_XY(uint8_t row, uint8_t col);
void I2C_LCD_write_string_XY(uint8_t row, uint8_t col, char *string);

#endif /* I2C_LCD_H_ */

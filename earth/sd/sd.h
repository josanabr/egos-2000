#pragma once

#include "egos.h"

/* SD card library interface */
#define SD_BLOCK_SIZE 512

enum {
      SD_CARD_TYPE_SD1,
      SD_CARD_TYPE_SD2,
      SD_CARD_TYPE_SDHC,
      SD_CARD_TYPE_UNKNOWN
};
extern int SD_CARD_TYPE;

void sdinit();
int sdread(int offset, int nblock, char* dst);
int sdwrite(int offset, int nblock, char* src);

char sd_exec_cmd(char*);
char sd_exec_acmd(char*);
char recv_data_byte();
char send_data_byte(char);

/* 
 * definitions for controlling SPI1 in FE310
 * see chapter19 of the SiFive FE310-G002 Manual
 */

#define SPI1_BASE     0x10024000UL

#define SPI1_SCKDIV   0UL
#define SPI1_SCKMODE  4UL
#define SPI1_CSID     16UL
#define SPI1_CSDEF    20UL
#define SPI1_CSMODE   24UL
#define SPI1_FMT      64UL
#define SPI1_TXDATA   72UL
#define SPI1_RXDATA   76UL
#define SPI1_FCTRL    96UL

#define ACCESS_ONCE(x) (*(__typeof__(*x) volatile *)(x))
#define SPI_REG(offset) (SPI1_BASE + offset)
#define SPI_REGB(offset) (ACCESS_ONCE((unsigned char*)SPI_REG(offset)))
#define SPI_REGW(offset) (ACCESS_ONCE((unsigned int*)SPI_REG(offset)))

#include "fm33lr0xx.h"

/*停振检测处理中断函数*/
void ECCC_RAMP_FDET_IRQHandler(void)
{                          
  CMU->IER &= ~CMU_IER_HFDET_IE;        
  CMU->ISR = CMU_ISR_HFDET_IF;
  CMU->SYSCLKCR &= ~(0X7<<8); 
  CMU->RCHFTR = RCHF8M_TRIM;                                                   
  CMU->RCHFCR = BIT0;		
  CMU->SYSCLKCR &= ~(0X7<<0);   
}	
/***************************************************************************************************/

/*BSTIM16定时中断函数*/
void BSTIM_IRQHandler(void)
{                          
    BSTIM16->ISR = BIT0;                     /* 清中断标志 */  
    /*****用户操作****/
    //。。。。。。。。。。。
}

/***************************************************************************************************/

/*LPTIM16定时中断函数*/
void LPTIM_IRQHandler(void)
{                          
    LPTIM16->ISR = BIT6;                     /* 清中断标志 */  
    /*****用户操作****/
    //。。。。。。。。。。。
}
/***************************************************************************************************/
/*UART1中断函数*/
uint8_t TX_BUFFER[10]={0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa};
volatile uint8_t RX_BUFFER[100] = {0};
struct UARTOpStruct
{
    uint8_t  *TxBuf;    /* 发送数据指针 */
    uint16_t TxLen;     /* 待发送数据长度 */
    uint8_t  TxOpc;     /* 已发送数据长度 */
    uint8_t  *RxBuf;    /* 接收数据指针 */
    uint16_t RxLen;     /* 待接收数据长度 */
    uint8_t  RxOpc;     /* 已接收数据长度 */
    volatile uint8_t  RxState;   /* 接收状态标志 */
};

struct UARTOpStruct UARTxOp = 
{
    (uint8_t *)TX_BUFFER,
    10,
    0,
    (uint8_t *)RX_BUFFER,
    100,
    0,
    0
};


void MUX4_IRQHandler(void)
{

    /* 接收中断处理 */
    if(UART1->ISR & UART_ISR_RXBF)
    {
        /* 中断处理程序 */
        {        
            /* 判断是否溢出BUFFER可接收最大数据量 */
            if(UARTxOp.RxOpc > UARTxOp.RxLen)
            return;
            
            UARTxOp.RxBuf[UARTxOp.RxOpc] = UART4->RXBUF;
            UARTxOp.RxOpc++;
        }
        
    }
    
    /* 发送中断处理 */
    if(UART1->ISR & UART_ISR_TXBE)
    {
        /* TXBE发送中断标志可通过写txreg寄存器清除 */
        
        /* 发送指定长度的数据 */
        if(UARTxOp.TxOpc < UARTxOp.TxLen)
        {
            UART1->TXBUF = UARTxOp.TxBuf[UARTxOp.TxOpc]; /* 发送一个数据 */            
        }
        /* 发送是否完毕检查 */
        if(UARTxOp.TxOpc == UARTxOp.TxLen)
        {
            UARTxOp.TxOpc = 0;
            /* 发送完毕后关闭中断 */
            UART1->IER &= ~UART_IER_TXBEIE;
        }
        UARTxOp.TxOpc++;
    }
}

/***************************************************************************************************/

void MUX0_IRQHandler(void)
{
    if (TAU0->T1ISR & TAU_ISR_OVIF)
    {
        TAU0->T1ISR |= TAU_ISR_OVIF;    
      
    }
}


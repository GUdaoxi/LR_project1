#include "main.h"

void Hardware_Init(void)
{
    uint32_t count=0;																										                                                  
 		/* Reset PLL & SYSCLK selection */					                              
    CMU->SYSCLKCR = 0x02000000U;  
// 		/* BOR configration */					                              
//    RMU->BORCR &= ~RMU_PDRCR_EN_Msk;
//    RMU->BORCR &= ~RMU_BORCR_CFG_Msk;
//    RMU->BORCR |= FL_RMU_BOR_THRESHOLD_3P0V;   
    /* SVD configration */					                              
    CMU->PCLKCR1 |= FL_CMU_GROUP1_BUSCLK_SVD;
    SVD->VSR = 0x4;
    SVD->CFGR &= ~SVD_CFGR_LVL_Msk;
    SVD->CFGR |= FL_SVD_WARNING_THRESHOLD_GROUP5;
    SVD->CFGR |= SVD_CFGR_DFEN;
    SVD->CR = FL_SVD_Mode_UNDERVOLTAGE_RESET;   
    /*enable IWDT*/   
    CMU->PCLKCR1 |= FL_CMU_GROUP1_BUSCLK_IWDT;
//    IWDT->SERV = 0x12345A5AU;
//    IWDT->CR |= FL_IWDT_PERIOD_1000MS;
    IWDT->SERV = 0x12345A5AU;  
    /*trim load register*/    
		CMU->RCHFTR = RCHF8M_TRIM; 
		CMU->RCLPTR = RCLP_TRIM;   			                                                                
    /*pad bus clock enable*/     
    /* Enable PAD Operation Clock */
    CMU->PCLKCR1 |= FL_CMU_GROUP1_BUSCLK_PAD;                                                                    
		GPIOA->FCR = 0x00000280;                                                                                              
		GPIOB->FCR = 0;                                                                                                       
		GPIOC->FCR = 0;                                                                                                       
		GPIOD->FCR = 0x00200000;                                                                                              
		GPIOE->FCR = 0;  
    /*reset peripheral*/     
		RMU->PRSTEN = 0X13579BDF;                                                                        
		RMU->AHBRSTCR = 0Xffffffff;                                                                                           
		RMU->APBRSTCR1 = 0Xffffffff;                                                                                          
		RMU->APBRSTCR2 = 0Xffffffff;                                                                                          
		RMU->AHBRSTCR = 0;                                                                                                    
		RMU->APBRSTCR1 = 0;                                                                                                   
		RMU->APBRSTCR2 = 0;                                                                                                   
		RMU->PRSTEN = 0;     
    /* Enable SWD port pull up */
    GPIOA->PUDEN |= (0x3U << 3);
    /* DMA Flash Channel: Flash->RAM */
    CMU->PCLKCR2 |= (0x1U << 4);
    DMA->CH7CR |= (0x1U << 10);
    CMU->PCLKCR2 &= ~(0x1U << 4); 
    /* XTHF Enable */    
		GPIOA->FCR |= 0XF<<16;                    
		CMU->XTHFCR = 0X0000EA01;                         
		while((!(CMU->XTHFCR & CMU_XTHFCR_RDY)) && (count < 48000))                       
		{                                                                                                                     
			count++;                                                                                                            
		}                                                                                                                     
		if(count<48000)                                                                                                       
		{                                                                                                                     
			count = 0;    
      /*PLL selection XTHF,and Multiple 32M*/ 
			CMU->PLLCR = 0X00073813;                                                     
			while((!(CMU->PLLCR & CMU_PLLCR_LOCKED)) && (count < 8000))                        
			{                                                                                                                   
				count++;                                                                                                          
			}                                                                                                                   
			CMU->ISR = CMU_ISR_HFDET_IF;                   
			if(count<8000)                                                                                                      
			{                
        /*AHBCLK config 4 prescaler*/  
        CMU->SYSCLKCR &= ~CMU_SYSCLKCR_AHBPRES_Msk; 
				CMU->SYSCLKCR |= FL_CMU_AHBCLK_PSC_DIV4;
        /*PLL is main Clock*/
				CMU->SYSCLKCR &= ~CMU_SYSCLKCR_SYSCLKSEL_Msk;         
				CMU->SYSCLKCR |= FL_CMU_SYSTEM_CLK_SOURCE_PLL;      
        /*OSC Detection enable*/  
				CMU->IER |= CMU_IER_HFDET_IE;                                                          
				NVIC_DisableIRQ(ECCC_RAMP_FDET_IRQn);                                                                             
				NVIC_SetPriority(ECCC_RAMP_FDET_IRQn, 0);                                                                         
				NVIC_EnableIRQ(ECCC_RAMP_FDET_IRQn);                                                                              
			}                                                                                                                   
		}      

    __enable_irq();    
}
void IWDT_Init(uint32_t period)
{
    CMU->PCLKCR1 |= FL_CMU_GROUP1_BUSCLK_IWDT;
    IWDT->SERV = 0x12345A5AU;
    IWDT->CR &= ~IWDT_CR_CFG_Msk;  
    IWDT->CR |= period;
    IWDT->SERV = 0x12345A5AU;  
}  

void AD_Init(void)                                                                          
{  
    uint32_t i = 0, Calibration_Flag; 
  
    CMU->PCLKCR2 |= FL_CMU_GROUP2_BUSCLK_ADC;  /* ADC总线时钟使能 */ 
    ADC->CFGR1 &= ~ADC_CFGR1_APBCLK_PSC_Msk;
    ADC->CFGR1 |= FL_ADC_APBCLK_PSC_DIV8;      /* ADC工作时钟--8分频 */ 
    PMU->PTATCR |= BIT0;
    /* ADC校准 */ 
    ADC->CR1 &= ~ADC_CR1_ADEN_Msk;
    ADC->CFGR2 &= ~ADC_CFGR2_OVSEN_Msk;        /* 关闭过采样 */ 
    ADC->CR1 |= ADC_CR1_ADEN;                  /* 使能ADC */ 
    ADC->CALCR |= ADC_CALCR_CALEN;             /* 使能校准 */ 
    i = 0;
    do
    {
        Calibration_Flag = ADC->ISR & BIT4;
        i++;
    } while((i != 0xFFFFU) && (Calibration_Flag == 0U));           /*等待转换完成*/
    if(Calibration_Flag == BIT4)
    {
        ADC->ISR = BIT4;
        ADC->CR1 &= ~ADC_CR1_ADEN_Msk;
    }
    
    ADC->SMTR = FL_ADC_CH_SAMPLING_TIME_128_ADCCLK;               /* 采样时间设置 */   
//    /* 中断配置 */                         \
//    ADC->IER |= ADC_IER_EOCIE;                  /* 使能通道转换完成中断 */ \
//    NVIC_DisableIRQ(ADC_IRQn);
//    NVIC_SetPriority(ADC_IRQn, 2);              /* 中断优先级配置 */\
//    NVIC_EnableIRQ(ADC_IRQn);   
  
}

uint16_t AD_GetResult(uint32_t channel)
{   
    uint32_t i = 0,EOC_Flag = 0;
    uint16_t ADCresult = 0;
  
    ADC->ISR = ADC_ISR_EOC_Msk; 
    ADC->CHER = channel;
    ADC->CR1 |= ADC_CR1_ADEN;                     /* 使能ADC */  
    ADC->CR1 |= ADC_CR1_SWTRIG;                   /* 使能转换 */
    do
    {
        EOC_Flag = ADC->ISR & ADC_ISR_EOC_Msk;
        i++;
    } while((i != 0xFFFFU) && (EOC_Flag == 0U)); /*等待转换完成*/   
    ADC->ISR = ADC_ISR_EOC_Msk;
    ADCresult = ADC->DR;
    
    return ADCresult;
}
extern uint8_t TX_BUFFER[10];

void Init__UART1_(uint32_t UARTBaudrate)                                 
{                                                                                     
    CMU->PCLKCR1 |= FL_CMU_GROUP1_BUSCLK_PAD;              /*  打开PAD总线时钟   */             
    CMU->PCLKCR3 |= FL_CMU_GROUP3_BUSCLK_UART1;            /*  打开UART1总线时钟 */ 
    CMU->OPCCR3=0x1<<9;
    CMU->PCLKCR1 |= BIT7;
  GPIOB->FCR |= 0XA<<26;
  GPIOB->DFS|=0x2<<26|0x3<<28;
    UART1->BGR = 8000000/UARTBaudrate - 1;                 /*  波特率配置        */                                                                                                                                                                 
 /*  帧格式设置 */              
   UART1->CSR &= ~UART_CSR_PDSEL_Msk;                                           
   UART1->CSR |= FL_UART_DATA_WIDTH_8B;                    /*数据长度选择位bit6-bit7：00--7位数据，01--8位数据，10--9位数据，11--6位数据 */                                                              
   UART1->CSR &= ~UART_CSR_STOPCFG_Msk;                           
   UART1->CSR |= FL_UART_STOP_BIT_WIDTH_1B;                /*停止位长度：0--1位，1--2位 */                      
   UART1->CSR &= ~UART_CSR_PARITY_Msk;                            
   UART1->CSR |= FL_UART_PARITY_NONE;                      /*校验位配置：00--无校验位，01--偶校验，10--奇校验，11--空 */                 
                  
   UART1->ISR = UART_ISR_RXBF;                   /*清除接收满标志*/                     
   UART1->ISR = UART_ISR_TXBE;                   /*清除发送缓冲器空标志*/   
    UART1->IER |= UART_IER_RXBFIE;                /*使能接收缓冲器满中断*/                      
   UART1->IER |= UART_IER_TXBEIE;                /*使能发送缓冲器空中断*/   
//   INTMUX->CR &= ~INTMUX_CR_MUX4SEL_Msk;   
//   NVIC_DisableIRQ(MUX4_IRQn);                      
//   NVIC_SetPriority(MUX4_IRQn, 1);                    
//   NVIC_EnableIRQ(MUX4_IRQn);                   
   UART1->CSR |= UART_CSR_TXEN;                 /*发送使能位bit0：1--使能，0--禁止*/                      
   UART1->CSR |= UART_CSR_RXEN;                 /*接收使能位bit8：1--使能，0--禁止*/                      
}

void IO__Init_(void)
{
  CMU->PCLKCR1 |= BIT7;
  GPIOD->FCR |= 0x1<<10;
  GPIOD->FCR |= 0x3<<4;//PD2 adc采样
}

/* ===== 协议/ID ===== */
#define PROTO_HEAD              (0xB2)
#define DEV_ID_FILTER_DETECT    (0x02u)

/* ===== 缓冲大小 ===== */
#define RX_BUF_SIZE             (100u)
#define TX_BUF_SIZE             (16u)

/* ===== 监控：抓原始接收字节流（环形缓冲）===== */
#define RX_MON_SIZE             (256u)   /* 你想更大：512/1024都行 */

volatile uint8_t  g_rx_mon_buf[RX_MON_SIZE];
volatile uint16_t g_rx_mon_wr  = 0;
volatile uint32_t g_rx_mon_cnt = 0;

static inline void RX_MON_PUT(uint8_t b)
{
    g_rx_mon_buf[g_rx_mon_wr] = b;
    g_rx_mon_wr++;
    if(g_rx_mon_wr >= RX_MON_SIZE) g_rx_mon_wr = 0;
    g_rx_mon_cnt++;
}

void RX_MON_Clear(void)
{
    for(uint16_t i = 0; i < RX_MON_SIZE; i++) g_rx_mon_buf[i] = 0;
    g_rx_mon_wr  = 0;
    g_rx_mon_cnt = 0;
}

/* ===== 监控：上一帧快照（方便直接看一帧）===== */
volatile uint8_t  g_last_frame[RX_BUF_SIZE];
volatile uint16_t g_last_frame_len = 0;
volatile uint32_t g_frame_cnt = 0;

void LAST_FRAME_Clear(void)
{
    for(uint16_t i = 0; i < RX_BUF_SIZE; i++) g_last_frame[i] = 0;
    g_last_frame_len = 0;
    g_frame_cnt = 0;
}

/* ===== 原有全局 ===== */
static volatile uint8_t RX_BUFFER[RX_BUF_SIZE];
static uint16_t rx_opc = 0;

static uint8_t  TX_FRAME[TX_BUF_SIZE];
static uint16_t tx_len  = 0;
static uint16_t tx_opc  = 0;
static uint8_t  tx_busy = 0;

static uint8_t  in_frame = 0;
static uint16_t expect_total = 0;
static volatile uint8_t frame_ready = 0;
static uint16_t CRC8_07_FF(const uint8_t *buf, uint16_t len)
{
    uint16_t crc = 0xFFFF;
    for(uint16_t i=0; i<len; i++)
    {
        crc ^= buf[i];
        for(uint8_t b=0; b<8; b++)
        {
           if (crc & 0x0001)
             {
                 // 右移1位后与多项式 0x1021 异或
                 crc = (crc >> 1) ^ 0x1021;
             }
             else
             {
                 // 最低位为0，直接右移1位
                 crc = crc >> 1;
             }
        }
    }
    return crc;
}

/* ===== CRC ===== */
static uint8_t CRC8_07(const uint8_t *buf, uint16_t len)
{
    uint8_t crc = 0xFF;
    for(uint16_t i = 0; i < len; i++)
    {
        crc ^= buf[i];
        for(uint8_t b = 0; b < 8; b++)
        {
            crc = (crc & 0x80) ? (uint8_t)((crc << 1) ^ 0x07) : (uint8_t)(crc << 1);
        }
    }
    return crc;
}
uint16_t Protocol_CalculateCRC16(const uint8_t* data, uint16_t len)
{
    uint16_t crc = 0xFFFF; // 初始值

    for (size_t i = 0; i < len; i++) {
        crc ^= (uint16_t)data[i] << 8; // 将数据异或到 CRC 的高字节

        for (int j = 0; j < 8; j++) {
            // 如果最高位为 1，则左移并异或多项式
            if (crc & 0x8000) {
                crc = (crc << 1) ^ 0x1021;
            } else {
                crc <<= 1;
            }
        }
    }

    return crc;
}
/* ===== 单线方向控制 ===== */
static inline void UART1_TX(void)
{
    UART1->CSR &= ~UART_CSR_RXEN;   /* 关接收 */
    UART1->CSR |=  UART_CSR_TXEN;   /* 开发送 */
}

static inline void UART1_RX(void)
{
    UART1->CSR &= ~UART_CSR_TXEN;   /* 关发送（释放单线） */
    UART1->CSR |=  UART_CSR_RXEN;   /* 开接收 */
}


void UART1_PollRx(void)
{
    while(UART1->ISR & (0x1<<8))
    {
        uint8_t ch = (uint8_t)UART1->RXBUF;

        /* <<< 监控：旁路记录每一个收到的字节（无论是否成帧） >>> */
        RX_MON_PUT(ch);

        if(!in_frame)
        {
            if(ch != PROTO_HEAD) continue;
            in_frame = 1;
            rx_opc = 0;
            expect_total = 0;
        }

        /* 存字节 */
        if(rx_opc < RX_BUF_SIZE)
        {
            RX_BUFFER[rx_opc++] = ch;
        }
        else
        {
            /* 溢出丢帧 */
            in_frame = 0;
            rx_opc = 0;
            expect_total = 0;
            frame_ready = 0;
            continue;
        }

        /* total = 3 + LEN + 2 */
        if(rx_opc == 3)
        {
            uint8_t len = RX_BUFFER[2];
            expect_total = (uint16_t)(3u + len + 2u);
            if(expect_total > RX_BUF_SIZE)
            {
                in_frame = 0;
                rx_opc = 0;
                expect_total = 0;
                frame_ready = 0;
            }
        }

        /* 收够一帧：打标志，等待主循环解析 */
        if(expect_total != 0 && rx_opc >= expect_total)
        {
            
            g_last_frame_len = rx_opc;
            if(g_last_frame_len > RX_BUF_SIZE) g_last_frame_len = RX_BUF_SIZE;
            for(uint16_t i = 0; i < g_last_frame_len; i++)
            {
                g_last_frame[i] = RX_BUFFER[i];
            }
            g_frame_cnt++;

            frame_ready = 1;
            in_frame = 0;
            expect_total = 0;

            /* 建议：这里 break，避免继续读把下一帧字节混进来 */
            break;
        }
    }
}


static void UART1_PollTx(void)
{
    if(!tx_busy) return;

    while((UART1->ISR &(0x1<<1))&& (tx_opc < tx_len))
    {
        UART1->TXBUF=TX_FRAME[tx_opc++];
    }

    if(tx_opc >= tx_len)
    {
        /* 关键：等“移位寄存器空/发送真正完成(含stop bit)” */
        if(UART1->ISR &(0x1<<0))  
        {
            tx_busy = 0;
            tx_len  = 0;
            tx_opc  = 0;
            UART1_RX();
        }
    }
}

static void Proto_Send(uint8_t id, const uint8_t *data, uint8_t data_len)
{
    if(tx_busy) return;

    uint16_t total = (uint16_t)(3u + data_len + 2u);
    if(total > TX_BUF_SIZE) return;

    TX_FRAME[0] = PROTO_HEAD;
    TX_FRAME[1] = id;
    TX_FRAME[2] = data_len;

    for(uint8_t i = 0; i < data_len; i++)
    {
        TX_FRAME[3u + i] = data[i];
    }

    /* CRC */
//    TX_FRAME[3u + data_len] = CRC8_07_FF(TX_FRAME, (uint16_t)(3u + data_len))>>8;
//    TX_FRAME[4u + data_len] = CRC8_07_FF(TX_FRAME, (uint16_t)(3u + data_len));
    uint16_t crc = Protocol_CalculateCRC16(&TX_FRAME[1], (uint16_t)(2u + data_len)); // 从ID开始
    TX_FRAME[3u + data_len] = (uint8_t)(crc >> 8);
    TX_FRAME[4u + data_len] = crc;
    UART1_TX();
    tx_len  = total;
    tx_opc  = 0;
    tx_busy = 1;
}

/* ===== ID2 ===== */
static void Proto_TryParseAndReply_ID2(void)
{
    if(!frame_ready) return;
    frame_ready = 0;

    uint8_t id  = RX_BUFFER[1];
    uint8_t len = RX_BUFFER[3];
    uint16_t total = (uint16_t)(4u + len + 2u);

    if(total > RX_BUF_SIZE || rx_opc < total)
    {
        rx_opc = 0;
        return;
    }
    
    /* CRC check: compare CRC from frame tail with locally calculated CRC. */
    uint16_t crc_rx  = RX_BUFFER[total - 1] | (RX_BUFFER[total - 2] << 8);
    uint16_t crc_cal = Protocol_CalculateCRC16((const uint8_t*)&RX_BUFFER[1], (uint16_t)(2u + len));
    if(crc_rx != crc_cal)
    {
        rx_opc = 0;
        return;
    }

    if(id == DEV_ID_FILTER_DETECT && len >= 1)
    {
        uint8_t data0 = RX_BUFFER[3];
        uint16_t adc = AD_GetResult(FL_ADC_EXTERNAL_CH8); /* 你这里先用固定值测试 */

        uint8_t data[3];
        data[0] =0x01;
        data[1] = (uint8_t)(adc & 0xFF);
        data[2] = (uint8_t)((adc >> 8) & 0xFF);

        Proto_Send(DEV_ID_FILTER_DETECT, data, 3);
    }

    rx_opc = 0;
}
/* ===== 主循环调用 ===== */
void Proto_PollOnce(void)
{
    UART1_PollRx();
    Proto_TryParseAndReply_ID2();
    UART1_PollTx();
}

int main(void)
{    
    Hardware_Init();
    IWDT_Init(FL_IWDT_PERIOD_1000MS);
    AD_Init();
    IO__Init_();
    GPIOD->DO |= 0x1<<5;//开启发射管
    Init__UART1_(9600);

    while(1)
    {
        IWDT->SERV = 0x12345A5AU;
        Proto_PollOnce();
    }
}


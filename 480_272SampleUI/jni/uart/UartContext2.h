/*
 * UartContext.h
 *
 *  Created on: Sep 5, 2017
 *      Author: guoxs
 */

#ifndef _UART_UARTCONTEXT2_H_
#define _UART_UARTCONTEXT2_H_

#include <vector>
#include "system/Thread.h"
#include "CommDef.h"

class UartContext2 : public Thread {
public:
	virtual ~UartContext2();

	bool openUart(const char *pFileName, UINT baudRate);
	void closeUart();

	bool isOpen() { return mIsOpen; }

	bool send(const BYTE *pData, UINT len);

	static UartContext2* getInstance();

protected:
	virtual bool readyToRun();
	virtual bool threadLoop();

private:
	UartContext2();

private:
	bool mIsOpen;
	int mUartID;

	// 用于拼接缓存数据，可能存在上一包数据解析未完全，残留有数据
	BYTE *mDataBufPtr;
	int mDataBufLen;
};

#define UARTCONTEXT2		UartContext2::getInstance()

#endif /* _UART_UARTCONTEXT2_H_ */

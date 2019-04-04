#pragma once

typedef struct IP_H
{
	char ifl : 4;
	char ver : 4;
	
	unsigned char tos;
	unsigned short length;
	unsigned short id;
	unsigned short fragment;
	unsigned char ttl;
	unsigned char protocol;
	unsigned short checksum;

	unsigned int src;
	unsigned int dst;
} IP_H;

typedef struct TCP_H
{
	unsigned short scrport;
	unsigned short dstport;
	unsigned int seq;
	unsigned int ack;

	unsigned char reserved	: 4;	//bitfield = reverse
	unsigned char hrdlen	: 4;
	
	unsigned char flags;
	unsigned short windowsize;
	unsigned short checksum;
	unsigned short urgptr;
} TCP_H;

typedef struct PPT_H
{
	//PPT 4bit
	unsigned char pptOption : 1;
	unsigned char pptModify : 1;
	unsigned char pptDelete : 1;
	unsigned char pptNew	: 1;

	//Head 4bit, 2byte
	unsigned char firstOption	: 1;
	unsigned char bmpFlag		: 1;
	unsigned char chatFlag		: 1;
	unsigned char pptFlag		: 1;

	//Color 4bit
	unsigned char blkColor : 1;
	unsigned char bluColor : 1;
	unsigned char grnColor : 1;
	unsigned char redColor : 1;
	
	//Shape Menu 4bit, 2byte
	unsigned char penMenu : 1;
	unsigned char pieMenu : 1;
	unsigned char triMenu : 1;
	unsigned char recMenu : 1;

	//extra 4bit
	unsigned char extraField : 4;

	//Line 4bit, 3byte
	unsigned char line40: 1;
	unsigned char line30: 1;
	unsigned char line20: 1;
	unsigned char line10: 1;

	//first Mouse Point
	unsigned int firstPointX;
	unsigned int firstPointY;

	//second Mouse Point
	unsigned int secondPointX;
	unsigned int secondPointY;

	//third Mouse Point
	unsigned int thirdPointX;
	unsigned int thirdPointY;

	//chat message
	int strlen;
	TCHAR sourceip[16];
} PPT_H;
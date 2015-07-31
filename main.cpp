/***************************************************************************
*                                                                          *
*       This file is Copyright (C) 2000, Stephen Makonin                   *
*       All Rights Reserved.                                               *
*                                                                          *
***************************************************************************/ 

#include <stdio.h>
#include <string.h>
#include "c_error.h"
#include "c_filelib.h"
#include "c_gfat.h"

c_gfat gfat;
c_filelib filelib;

void main(int argc, char *argv[])
{
	unsigned char *buf = NULL;
	long size;

	printf("gfat3 v1.0.2 (C) 2000 Makonin Consulting Corp.\n\n");

	if(argc < 2) goto show_usage;

	if(!strcmp(argv[1], "-add") && argc == 4)
	{
		printf("Adding %s to gfat", argv[2]);
		if(!filelib.load_file(argv[2], &buf, &size))
		{
			printf("File %s does not exist.\n", argv[2]);
			return;
		}		
		printf(".");
		
		gfat.add(argv[3], buf, size);
		printf(".");
		gfat.add(NULL, NULL, 0);
		printf(".DONE!\n\n");
	}
	else
	{
		goto show_usage;
	}

	if(buf) free(buf);
	return;
show_usage:
	printf("USAGE:  gfat3.exe -add [file to add] [alias name]\n\n");
}

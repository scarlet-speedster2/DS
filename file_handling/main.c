#include <stdio.h>
#include<stdlib.h>
#include "student_info.h"
#include"file.h"



void main()
{
	int choice;
	while(1)
	{
		printf("\n1.Display\n2.Insert\n3.Search\n4.Update.\n5.Delete.\n6.Department wise.\n7.Exit.");
		scanf("%d",&choice);
		switch(choice)
		{
			case 2:
				insert_stud("demo.bin");
			break;
			
			case 1:
				display_file("demo.bin");
			break;
			
			case 3:
				search("demo.bin");
			break;
			
			case 4:
				update("demo.bin");
			break;
			
			case 5:
				delete_stud("demo.bin");
			break;
			
			case 6:
				dept_vise_cnt("demo.bin");
			break;
			
			case 7:
				return;
			break;
			
			default:
				printf("\nwrongchoice...!");
		}
	}
	
	return;
}

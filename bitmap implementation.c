#include<stdio.h>
#include<stdlib.h>
#define EXIT 100
#define BITMAP_LEN 2
#define BYTE_LEN   8
void printTheDebugOutput(unsigned char *bit_array)
{
   int i, j;
   for (i=0 ; i<BITMAP_LEN; i++)
   {
     for(j=1; j<=BYTE_LEN; j++)
     {
        if(bit_array[i] & (1 << (j-1)))
        {
           printf("In BIT_MAP[%d] the position of Bit SET : %d\n",
                                   i, j);
        }
     }
   }
}
int main()
{

  unsigned int bit_position, setOrUnsetBit, ch;
  unsigned char bit_Map_array_index, shift_index;
  unsigned char bit_map[BITMAP_LEN] = { 0 };
 do
 {
    printf("Enter the Bit position (bit starts from 1 and Ends at 16) \n");
    scanf("%d", &bit_position); 
    printf(" Do you want to set/unset the Bit (1 or 0) \n");
    scanf("%d", &setOrUnsetBit);
    bit_Map_array_index = (bit_position-1) / 8;
    shift_index =  (bit_position-1) % 8;
    printf("The bit_position : %d shift Index : %d\n", bit_position, shift_index);
    if( setOrUnsetBit)
     {        
       bit_map[bit_Map_array_index] |= 1<<shift_index;                
     }
    else
     {  
        bit_map[bit_Map_array_index] &= ~(1<<shift_index);        
     }
    printf(" The Bit MAP Array : %d\n", bit_map[bit_Map_array_index]);
    printTheDebugOutput(bit_map);
    printf(" Do You want to Continue then Enter any Number"
           "and for Exit then enter 100\n");
    scanf("%d", &ch);
  }while(ch != 100);
 return 0;
}
# Pointers in C

Before proceeding to direct register access that we need to understand what are pointers in C:
`A pointer is a variable whose value is the address of another variable`

```
#include <stdio.h>

int main () {

   int  var1;
   int *var2; //Declare a pointer
   var2 = &var1 //Use '&' to get the address of a variable

   printf("Address of var1 variable: %x\n", &var1); //Address of Variable 'var1'
   printf("Address of var1 variable: %x\n", *var2); //Value of 'var1'

   return 0;
}
```
From the above code, we saved the address of the variable 'var1' by using '&', in a pointer variable 'var2', by using '*' operator we can printout the value stored at an address

```
Address of var1 variable: bff5a400
Address of var2 variable: bff5a3f6
```

# Direct Register Access
```
typedef          uint32_t   VALUE;
typedef volatile uint32_t* ADDRESS;


VALUE register_read(ADDRESS  address) {
    return *address;                                    //Reading and returing the register value
}

void register_write(ADDRESS address, VALUE value) {
    *address = value;                                   //Writing value to register
}
```

We create two functions, first one to read, we pass the address as an argument, using the '*' operator we return the value stored at that address. For the second function
we pass the address and the value to be written at that address, using the same operator we put the value at that address

# Reading BOOT Button and Blinking Neopixel
To find which register to read, we need to find the base register, from the addressmap.h file, we find the SIO_BASE_u variable which is defined as 0xd0000000



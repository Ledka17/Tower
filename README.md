# Tower Sastantua 42
### **Compiling**
The project currently only has the functions for creating the pyramid. To compile, you will need a main.

```
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return 0;

	sastantua(atoi(argv[1]));
}
```

### **Usage**
Compiling this into a sastantua executable, you will get:

```
$ ./sastantua 3

               /*\
              /***\
             /*****\
          /***********\
         /*************\
        /***************\
       /*****************\
    /***********************\
   /*************************\
  /************|||************\
 /*************|||*************\
/**************|||**************\
```

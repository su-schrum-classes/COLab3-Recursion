## Computer Organization, Dr. J. Schrum

# Setup

Before running any assembly project in GitHub codespaces, you will need to install NASM, the Netwide Assembler. Execute these commands:
```
sudo apt-get update
sudo apt-get -y install nasm
```

# Lab 2: Addressing Modes

After installing NASM, execute the code by running the command `bash run.sh`. It should initially output the following:
```
arr[3] = 23 which is 17 in hex
```
Try changing the `index` variable in the `main` function of `Main.c` and it should be clear what this code is doing when it calls `sendArray`. In the assembly code under `sendArray` we have the line:
```
mov eax, [rdi + 4*rsi]
```
There is a lot happening on this one line. Register `rdi` is a pointer to the base of the array, which is where the element at index 0 is stored. Register `rsi` represents the array index. Although the 32-bit `int` parameter is entirely contained within `esi`, we have to use `rsi` here because assembly only allows us to add registers of the same length. Fortunately, the upper 32 bits of `rsi` will be 0. The last component of the formula is multiplying the index by 4. This is done because a 32-bit integer consists of 4 bytes, so moving up one index in the array means moving up 4 memory addresses. This code gets us the element stored at the desired index of the array. Interestingly, although the memory address we designate only corresponds to a single byte, because the target register `eax` has a size of 4 bytes (32 bits), the contents of the designated address and the following three addresses are all combined into one 32-bit chuck of data that is stored in the register.

There is also an assembly procedure called `readAssemblyIntArray` and at the bottom of the assembly file is a `section .data` that contains `intArray`. The `dd` specifies that the data stored consists of 32-bit elements, and then there is a list of the contents of the array. Specifically, `dd` means "*D*efine *D*ouble Word" where a word is 16 bits. Add this line to the `main` function of the C program to see what it outputs:
```
printf("readAssemblyIntArray(%d) = %d\n", index, readAssemblyIntArray(index));
```
There are also some additional arrays of different data types defined in the `.data` segment: `quadArray` and `charArray`. Write two new procedures named `readAssemblyQuadArray` and `readAssemblyCharArray`. These procedures should retrieve and return values from a specific index in each of the corresponding arrays.

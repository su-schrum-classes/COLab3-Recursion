## Computer Organization, Dr. J. Schrum

# Setup

Before running any assembly project in GitHub codespaces, you will need to install NASM, the Netwide Assembler. Execute these commands:
```
sudo apt-get update
sudo apt-get -y install nasm
```

# Lab 3: Recursion

After installing NASM, execute the code by running the command `bash run.sh`. It will compute the first 10 Fibonacci numbers:
```
fibRecursive(0) = 1
fibRecursive(1) = 1
fibRecursive(2) = 2
fibRecursive(3) = 3
fibRecursive(4) = 5
fibRecursive(5) = 8
fibRecursive(6) = 13
fibRecursive(7) = 21
fibRecursive(8) = 34
fibRecursive(9) = 55
```
This is accomplished via the recursive `fibRecursive` procedure defined in assembly. Before explaining this in detail, attempt to create a procedure `fibIterative` that computes a Fibonacci number using a loop instead. Add all needed code to both the Assembly and C files to run and test this code. To aid you, there is already a C function named `fibCIterative` that computes the `n`-th Fibonacci number using a loop. Your task it to attempt writing an assembly procedure that works the same way.

Getting back to the recursive `fibRecursive` procedure, let's analyze how it works. The first thing that happens is a comparison with the parameter `rdi` to see if we are in a base case. If `rdi` is 0 or 1 then the code returns 1 right away. Otherwise, we jump to the `recursiveCase` label. Since we will be calling `fibRecursive` again, we will need to modify `rdi` to be used as the parameter again. However, when our recursive call returns (potentially after a long series of calls), we're going to want to remember what the original value of `rdi` was, so we save it on a stack with the `push` command. This makes it safe to decrement `rdi` with `dec` before the first recursive call, using the `call` command. Eventually, the recursive call will return to this point and resume execution, at which point we `pop` the previously saved value from the stack back in to `rdi`. It is important that `push` and `pop` commands match up so that things pushed are eventually popped, and definitely so that we never pop from an empty stack. Also note that after the first recursive call, we have a partial result stored in `rax`, but we need to add this to the result of the following recursive call in order to get the final result. Therefore, we use `push rax` to save this result so that it will not be overwritten when the second recursive call returns. Note that we do not save `rdi` again before subtracting 2 from it because after the second recursive call, we will no longer need the original value of `rdi`. However, we do need the result from the first recursive call, but we don't want to overwrite the result of the second recursive call which is now in `rax`. So, we use `pop rbx` to store the previously pushed value of `rax` (result of first recursive call) in register `rbx`. Note that you do not need to pop a value into the same place you pushed it from. All that is left is to add the two recursive results so that the final result can be returned in `rax`.

Given the above explanation, attempt writing a `sumRecursive` procedure that computes the sum of all integers from 1 up to and including some integer parameter.

If you can successfully compute the recursive sum, then take a shot at `factorialRecursive`, which will require you to figure out the assembly multiplication instruction.
